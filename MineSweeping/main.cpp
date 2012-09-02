#include "test/test.h"
#include "gui/gui.h"
#include "gui/GameObject.h"
#include "globalVal.h"
#include <iostream>
using namespace std;


//
void callback(void*)
{
	g_useTime++;
	TimeShowBox::getInstance()->showTimer(g_useTime);
//	cout << "time:" << g_useTime << endl;
	if (g_useTime>10000)//放置溢出
	{
		g_useTime = 0;
	}
	if (g_isPauseTime) g_useTime--;
	Fl::repeat_timeout(1.0, callback);
}

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

	Fl::add_timeout(1.0, callback);

	return Fl::run();
}
