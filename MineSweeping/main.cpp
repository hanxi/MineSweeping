#include "test/test.h"
#include "gui/gui.h"
#include <iostream>
using namespace std;

extern const int SCREEN_WIDTH=800;//后面实现时候改为读取config配置文件
extern const int SCREEN_HEIGHT=600;

int main(void)
{
	GUI gui;
	//测试拷贝构造函数
/*	GameObject t1;
	t1.setImage("res/images/bg.jpg");
	GameObject t2(t1);
	Test::test_copy_construdtor(t1,t2);
	ImageBox imageBox("res/images/bg.jpg");
	Test::test_ImageBox(imageBox);
	*/

	gui.show();
	return Fl::run();
}