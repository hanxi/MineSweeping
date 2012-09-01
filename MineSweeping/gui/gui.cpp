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
		cout << "Game Over!" << endl;
		openAll();
		m_grid[m_leftClickMsg[0].i][m_leftClickMsg[0].j].setImage(imageName[mineBoom]);
		//然后给出"重来退出对话框"
		replayDialog();
		return;
	}
	for (vector<OpenGridMsg>::iterator it=m_leftClickMsg.begin();
		it != m_leftClickMsg.end(); it++)
	{
		m_grid[it->i][it->j].setImage(imageName[it->state]);
		m_grid[it->i][it->j].setDisable();
	}
}

void GUI::replayDialog(void)//GameOver对话框
{
	int hotspot = fl_message_hotspot();
	fl_message_hotspot(0);
	fl_message_title("Game Over!");
	int rep = fl_choice("重新开始？",
		"Level", "Replay", "Exit");
	fl_message_hotspot(hotspot);
	if (rep==2) 
		exit(0);
	else if (rep == 1)
	{
		m_coreMines.initMines(m_numberLines,m_numberColumns,m_minesCount);
		for (int i=0; i<m_numberLines; i++)
		{
			for (int j=0; j<m_numberColumns; j++)
			{
				m_grid[i][j].init();
				m_grid[i][j].setImage(imageName[mineInit]);
			}
		}
	}
}

//打开所有的，GameOver
void GUI::openAll(void)
{
	for (int i=0; i<m_numberLines; i++)
	{
		for (int j=0; j<m_numberColumns; j++)
		{
			if (m_grid[i][j].isEnable())
			{
				if (m_coreMines.isMine(i,j))
				{
					m_grid[i][j].setImage(imageName[mineOut]);
				}
				else if (m_grid[i][j].isMark())//标记错误
				{
					m_grid[i][j].setImage(imageName[markWrong]);
				}
				else
				{
					m_grid[i][j].setImage(imageName[m_coreMines.roundMines(i,j)]);
				}
			}
		}
	}
}

void window_callback(Fl_Widget*, void*)
{
	int hotspot = fl_message_hotspot();
	fl_message_hotspot(0);
	fl_message_title("Exit");
	int rep = fl_ask("确定退出？");
	fl_message_hotspot(hotspot);
	if (rep==1) 
		exit(0);
}
