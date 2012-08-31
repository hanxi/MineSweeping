#include "gui.h"

GUI* GUI::m_pGUI = NULL;

void GUI::setLevel(int a_level)
{

}

void GUI::clickOpen(int a_line, int a_colum)
{
	cout << "in GUI::clickOpen()" << endl;
	m_leftClickMsg.clear();
	m_coreMines.clickOpen(a_line, a_colum,m_leftClickMsg);
	if (m_leftClickMsg[0].state == mineBoom)//第一个是雷，GameOver
	{
		m_grid[m_leftClickMsg[0].i][m_leftClickMsg[0].j].setImage(imageName[mineBoom]);
		cout << "Game Over!" << endl;
		//然后给出"重来退出对话框"
	}
	for (vector<OpenGridMsg>::iterator it=m_leftClickMsg.begin();
		it != m_leftClickMsg.end(); it++)
	{
		m_grid[it->i][it->j].setImage(imageName[it->state]);
		m_grid[it->i][it->j].setDisable();
	}
}