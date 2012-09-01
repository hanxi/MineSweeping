#include "test/test.h"
#include "gui/gui.h"
#include "gui/GameObject.h"
#include "globalVal.h"
#include <iostream>
using namespace std;


//
int main(void)
{
	cout << imageName[0] << endl;

	GUI* gui = GUI::getInstance();
	//测试拷贝构造函数
/*	GameObject t1;
	t1.setImage("res/images/bg.jpg");
	GameObject t2(t1);
	Test::test_copy_construdtor(t1,t2);
	ImageBox imageBox("res/images/bg.jpg");
	Test::test_ImageBox(imageBox);
	*/
//	vector<vector<GridBlock> > vv;
//	Test::test_GridBlock(vv);
//	Test::test_GridBlock(vv);

	return Fl::run();
}