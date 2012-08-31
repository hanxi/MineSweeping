#include "test/test.h"
#include "gui/gui.h"
#include <iostream>
using namespace std;

extern const int WIN_WIDTH=800;//后面实现时候改为读取config配置文件
extern const int WIN_HEIGHT=600;

int main(void)
{
	GUI gui;

	return Fl::run();
}