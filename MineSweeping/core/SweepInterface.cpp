#include "SweepInterface.h"

inline bool notInMsg(int i, int j, vector<OpenGridMsg>& msg)
{
	for (vector<OpenGridMsg>::iterator it=msg.begin();
		it != msg.end(); it++)
	{
		if (i==it->i && j==it->j)
		{
			return false;
		}
	}
	return true;
}

//前置条件：msg为空
void SweepInterface::clickOpen(int i, int j, vector<OpenGridMsg>& msg)
{
	OpenGridMsg amsg;
	if (m_mines.isMine(i,j))//踩到雷了
	{
		amsg.i = i;
		amsg.j = j;
		amsg.state = mineBoom;//雷
		msg.push_back(amsg);
		return;
	}
	if (notInMsg(i,j,msg))//检测该位置是否进来过
	{
		amsg.i = i;
		amsg.j = j;
		amsg.state = m_mines.countRoundMines(i,j);
//		cout << "(" << i << "," << j <<")周围雷数：" << amsg.state << endl;
		msg.push_back(amsg);
		if (amsg.state == 0)//如果周围没有雷，继续点开周围的
		{
			if (i-1>=0 && j-1>=0)						clickOpen(i-1,j-1,msg);
			if (j-1>=0)									clickOpen(i,j-1,msg);
			if (i+1<m_numberLines && j-1>=0)			clickOpen(i+1,j-1,msg);
			if (i-1>=0)									clickOpen(i-1,j,msg);
			if (i+1<m_numberLines)						clickOpen(i+1,j,msg);
			if (i-1>=0 && j+1<m_numberColumns)			clickOpen(i-1,j+1,msg);
			if (j+1<m_numberColumns)						clickOpen(i,j+1,msg);
			if (i+1<m_numberLines && j+1<m_numberColumns)	clickOpen(i+1,j+1,msg);
		}
	}
}
