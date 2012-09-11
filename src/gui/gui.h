#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include <cassert>
#include <memory>
#include <iostream>
#include "../FLTK.h"
#include "../globalVal.h"
#include "GameObject.h"
#include "../core/SweepInterface.h"

using std::auto_ptr;
using std::cout;
using std::endl;
using std::vector;

class GUI
{
private:
	static GUI* m_pGUI;
	GUI(void);
public:
	static GUI* getInstance();
	static void releaseInstance();
	~GUI(void) {releaseInstance();}

public:
	void setLevel(int a_level);//设置游戏的难度，即设置行数和列数
	void setLevelSelf(int a_H, int a_W, int a_C);//自定义行列
	void clickOpen(int a_line, int a_colum);
	void rightClick(int a_line, int a_colum);//右键事件

protected:
	void createGameObjects(void);

private:
	auto_ptr<Fl_Menu_Window> m_pWindow;//主窗体
	vector<vector<GridBlock> > m_grid;//网格
	auto_ptr<Fl_Menu_Bar> m_pMenuBar;//菜单
	TimeShowBox* m_pTimeShowBox;//时间显示器

	int m_level;//等级，等于0时为自定义
	int m_numberLines;//行数
	int m_numberColumns;//列数
	int m_minesCount;//雷的个数
	float m_width;
	float m_height;
	SweepInterface m_coreMines;//核心算法
	vector<OpenGridMsg> m_leftClickMsg;

	void winnerDialog(void);//胜利对话框
	int replayDialog(void);//GameOver对话框
	void openAll(void);
	void RankingsDialog(void);//排行榜对话框
	static void window_callback(Fl_Widget*, void*);	//退出对话框
	static void menuCB(Fl_Widget* w, void*);
	void updateMap(void);	//更新地图
	void updateWindow(void);
	void saveRecord(int a_useTime, const char* a_userName);//保存记录
	int countMarkMines(void);
};


inline GUI* GUI::getInstance()
{
	if(m_pGUI==NULL)
	{
		m_pGUI=new GUI();
	}
	return m_pGUI;
}
inline void GUI::releaseInstance()
{
	delete m_pGUI;
	m_pGUI = NULL;
}

inline GUI::GUI(void)
:m_width(initBlockWidth*initColumns),m_height(initBlockHeight*initLines),
m_minesCount(initMinesCount),m_level(1)
{
	g_useTime=0;
	g_isPauseTime=false;
	m_numberColumns = initColumns;
	m_numberLines = initLines;
	m_pWindow.reset(new Fl_Menu_Window(m_width,m_height+menuBarHeight+timeShowBoxHeight,GUIStr[0]));
	m_pMenuBar.reset(new Fl_Menu_Bar(0,0,m_width,menuBarHeight));
	m_pMenuBar->menu(menuItems);//载入MenuItem
	m_pMenuBar->callback(&GUI::menuCB);
	m_pWindow->callback(&GUI::window_callback);
	m_pTimeShowBox = TimeShowBox::getInstance();
	m_pTimeShowBox->resize(0,menuBarHeight,m_width,timeShowBoxHeight);
	m_pTimeShowBox->setMarkMines(0);
	m_pTimeShowBox->setRemainMines(m_minesCount);
	m_pWindow->add(m_pTimeShowBox);
	m_pWindow->begin();//往窗体里面添加对象
		createGameObjects();
	m_pWindow->end();
	m_pWindow->show();
}

inline void GUI::createGameObjects(void)
{
	//知道大小的情况下，优先使用resize()
	m_grid.resize(m_numberLines);
	vector<GridBlock> grids;
	grids.resize(m_numberColumns);
	for (int i=0; i<m_numberLines; i++)
	{
		for (int j=0; j<m_numberColumns; j++)
		{
			GridBlock gridBlock(imageName[mineInit]);
			gridBlock.setPosition(j*initBlockWidth,i*initBlockHeight+menuBarHeight+timeShowBoxHeight);
			gridBlock.setSize(initBlockWidth,initBlockHeight);
			gridBlock.setLineColumn(i,j);//设置行号和列号
			grids[j] = gridBlock;
		}
//		cout << "girds.size = " << grids.size() << endl;
//		cout << "m_gird[i].size = " << m_grid[i].size() << endl;
		m_grid[i] = grids;
	}
}

#endif
