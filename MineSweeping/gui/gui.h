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
	void clickOpen(int a_line, int a_colum);

	void show(void);

protected:
	void createGameObjects(void);

private:
	auto_ptr<Fl_Menu_Window> m_pWindow;//主窗体
	std::vector<std::vector<GridBlock> > m_grid;//网格

	int m_numberLines;//行数
	int m_numberColumns;//列数
	int m_minesCount;//雷的个数
	float m_width;
	float m_height;
	SweepInterface m_coreMines;//核心算法
	vector<OpenGridMsg> m_leftClickMsg;

	void replayDialog(void);//GameOver对话框
	void openAll(void);
};

//退出对话框
void window_callback(Fl_Widget*, void*);

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
m_minesCount(initMinesCount)
{
	m_numberColumns = initColumns;
	m_numberLines = initLines;
	m_pWindow.reset(new Fl_Menu_Window(m_width,m_height,"扫雷（FLTK版）"));
	m_pWindow->callback(window_callback);
	m_pWindow->begin();//往窗体里面添加对象
		createGameObjects();
	m_pWindow->end();
}
inline void GUI::show(void)
{
	m_pWindow->show();
}
inline void GUI::createGameObjects(void)
{
	//知道大小的情况下，优先使用resize()
	m_grid.resize(m_numberLines);
	std::vector<GridBlock> grids;
	grids.resize(m_numberColumns);
	for (int i=0; i<m_numberLines; i++)
	{
		for (int j=0; j<m_numberColumns; j++)
		{
			GridBlock gridBlock(imageName[mineInit]);
			gridBlock.setPosition(j*initBlockWidth,i*initBlockHeight);
			gridBlock.setSize(initBlockWidth,initBlockHeight);
			gridBlock.setLineColumn(i,j);//设置行号和列号
			grids[j] = gridBlock;
		}
		m_grid[i] = grids;
	}
}

#endif