#include "test/test.h"
#include "gui/gui.h"
#include <iostream>
using namespace std;

extern const int initMinesCount = 15;//初始地雷个数
extern const int initColumns = 10;//初始行数
extern const int initLines = 10;
extern const float initBlockWidth = 30;//初始格子像素大小
extern const float initBlockHeight = 30;
extern const int SCREEN_WIDTH=800;//后面实现时候改为读取config配置文件
extern const int SCREEN_HEIGHT=600;
extern const char const* imageName[]=
{
	"res/images/zero.png",
	"res/images/one.png",
	"res/images/two.png",
	"res/images/three.png",
	"res/images/four.png",
	"res/images/five.png",
	"res/images/six.png",
	"res/images/seven.png",
	"res/images/eight.png",
	"res/images/mineBoom.png",
	"res/images/mineInit.png",
	"res/images/mineOut.png",
	"res/images/mark.png",
	"res/images/markWrong.png",
	"res/images/markUnknow.png"
};

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
	gui->show();
	return Fl::run();
}