#ifndef MINES_H_
#define MINES_H_

#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <iostream>
#include "../globalVal.h"

using std::vector;
using std::cout;
using std::endl;
class Mines
{
public:
	Mines(void);
	void initMines(int a_lines, int a_columns, int a_minesCount);
	bool isMine(int a_line, int a_column);//不考虑边界外情况（即不能出现越界情况）
	int countRoundMines(int i, int j);//统计周围的地雷数量

private:
	vector<vector<bool> > m_minesMap;//雷的布局图
	int m_minesCount;//雷的个数
	int m_numberLines,m_numberColumns;//行数和列数

	bool isMine2(int a_line, int a_column);//考虑边界外情况（即可以越界一格）
};
inline Mines::Mines(void):m_minesCount(initMinesCount),
m_numberLines(initLines),m_numberColumns(initColumns)
{
	initMines(m_numberLines,m_numberColumns,m_minesCount);
}

//外部使用，不能出现越界情况
inline bool Mines::isMine(int a_line, int a_column)
{
	assert(a_line>-1);
	assert(a_column>-1);
	assert(a_line<m_numberLines);
	assert(a_column<m_numberColumns);
	return m_minesMap[a_line][a_column];
}

//内部使用，可以越界一格
inline bool Mines::isMine2(int a_line, int a_column)
{
	assert(a_line>-2);
	assert(a_column>-2);
	assert(a_line<m_numberLines+1);
	assert(a_column<m_numberColumns+1);
	if (a_line==-1 || a_line==m_numberLines
		|| a_column==-1 || a_column==m_numberColumns)//边界情况
	{
//		cout << "边界情况" << endl;
		return false;
	}
	return m_minesMap[a_line][a_column];
}

inline int Mines::countRoundMines(int i, int j)
{
	int count=0;
	if (isMine2(i-1,j-1))	count++;
	if (isMine2(i,j-1))		count++;
	if (isMine2(i+1,j-1))	count++;
	if (isMine2(i-1,j))		count++;
	if (isMine2(i+1,j))		count++;
	if (isMine2(i-1,j+1))	count++;
	if (isMine2(i,j+1))		count++;
	if (isMine2(i+1,j+1))	count++;
	assert(count<9);
	return count;
}
#endif