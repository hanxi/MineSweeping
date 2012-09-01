#include "test.h"
#include <iostream>
#include "../globalVal.h"

using namespace std;

void Test::test_globalval(void)
{
	cout << "SCREEN_WIDTH=" << SCREEN_WIDTH << endl;
	cout << "SCREEN_HEIGHT=" << SCREEN_HEIGHT << endl;
}
void Test::test_GridBlock(vector<vector<GridBlock> >& vv)
{
	vv.clear();
	vv.resize(10);
	vector<GridBlock> v;
	v.resize(10);
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<10; j++)
		{
			GridBlock t(imageName[mineBoom]);
			t.setPosition(initBlockWidth,initBlockHeight);
			t.setSize(initBlockWidth,initBlockHeight);
			v[j] = t;
		}
		vv[i] = v;
	}
}