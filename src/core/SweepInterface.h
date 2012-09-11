#ifndef SWEEP_INTERFACE_H_
#define SWEEP_INTERFACE_H_

#include <vector>
#include "../globalVal.h"
#include "Mines.h"

using std::vector;

class SweepInterface
{
public:
	SweepInterface(void);
	void initMines(int a_lines, int a_columns, int a_minesCount);
	void clickOpen(int i, int j, vector<OpenGridMsg>& msg);

	bool isMine(int i, int j) { return m_mines.isMine(i,j);}
	int roundMines(int i, int j) {return m_mines.countRoundMines(i,j);}

private:
	Mines m_mines;
	int m_minesCount;//雷的个数
	int m_numberLines,m_numberColumns;//行数和列数
};

inline SweepInterface::SweepInterface(void)
:m_minesCount(initMinesCount),m_numberLines(initLines),m_numberColumns(initColumns)
{
}

inline void SweepInterface::initMines(int a_lines, int a_columns, int a_minesCount)
{
	assert(a_minesCount<a_lines*a_columns);
	m_minesCount = a_minesCount;
	m_numberLines = a_lines;
	m_numberColumns = a_columns;
	m_mines.initMines(m_numberLines,m_numberColumns,m_minesCount);
}

#endif