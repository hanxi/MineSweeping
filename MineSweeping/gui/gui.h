#ifndef GUI_H_
#define GUI_H_

#include <vector>
#include <cassert>
#include <memory>
#include <iostream>
#include "FLTK.h"
#include "globalVal.h"
#include "GameObject.h"

const float initBlockWidth = 50;//初始格子像素大小
const float initBlockHeight = 50;
const int initColumns = 5;//初始行数
const int initLines = 5;
using std::auto_ptr;

class GUI
{
public:
	GUI(void);

	void loadSetting(void);//载入屏幕大小，暂时使用全局变量
	void setLevel(int a_level);//设置游戏的难度，即设置行数和列数

	void show(void);

protected:
	void createGameObjects(void);

private:
	auto_ptr<Fl_Window> m_pWindow;//主窗体
	std::vector<std::vector<GridBlock> > m_grid;//网格
	int m_numberLines;//行数
	int m_numberColumns;//列数
	float m_width;
	float m_height;
};

inline GUI::GUI(void)
:m_width(initBlockWidth*initColumns),m_height(initBlockHeight*initLines)
{
	m_numberColumns = initColumns;
	m_numberLines = initLines;
	m_pWindow.reset(new Fl_Window(m_width,m_height,"扫雷（FLTK版）"));
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
	m_grid.clear();
	std::vector<GridBlock> grids;
	for (int i=0; i<m_numberLines; i++)
	{
		grids.clear();
		for (int j=0; j<m_numberColumns; j++)
		{
			GridBlock gridBlock("res/images/grid.jpg");
			gridBlock.setPosition(i*initBlockWidth,j*initBlockHeight);
			gridBlock.setSize(initBlockWidth,initBlockHeight);
			grids.push_back(gridBlock);
		}
		m_grid.push_back(grids);
	}
	m_grid[0][0].setImage("res/images/grid.jpg");
	m_grid[0][0].setSize(initBlockWidth,initBlockHeight);
}

#endif