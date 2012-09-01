#include "globalVal.h"
#include "FLTK.h"

extern const int dialogWindowWidth = 300;//对话框大尿
extern const int dialogWindowHeight = 300;
extern const int initMinesCount = 15;//初始地雷个数
extern const int initColumns = 10;//初始行数
extern const int initLines = 10;
extern const float initBlockWidth = 30;//初始格子像素大小
extern const float initBlockHeight = 30;
extern const int SCREEN_WIDTH=800;//后面实现时候改为读取config配置文件
extern const int SCREEN_HEIGHT=600;
extern const int menuBarHeight = 30;//菜单栏高度
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

extern const Fl_Menu_Item menuItems[] = {
	{"游戏(&G)",FL_ALT+'g',0,0,FL_SUBMENU},
		{"开局(&N)",FL_F+2,0,0,FL_MENU_DIVIDER},
		{"初级(&B)",0,0,(void *)1,0},
		{"中级(&I)",0,0,(void *)2,0},
		{"高级(&E)",0,0,(void *)3,0},
		{"自定义　(&C)",0,0,0,FL_MENU_DIVIDER},
		{"扫雷英雄榜　(&T)",0,0,0,FL_MENU_DIVIDER},
		{"退出　(&X)",FL_Escape,0,0,0},
		{0},
	{0}
};

extern const char const* dialogWindowStr[] = 
{
	"　自定义雷区　",
	"　高度(5~20)　",
	"　宽度(5~30)　",
	"　雷数(<W*H)　",
	"　确定　",
	"　取消　",
	"　输入的数据不符合范围要求，请重新输入！　",
};
extern const char const* GUIStr[] = 
{
	"　扫雷（FLTK版）　",
	"　游戏失败　",
	"　再玩一局？　",
	"　退出　",
	"　重玩　",
	"　排行榜　",
	"　确定退出？　",
	"　扫雷排行榜　",
	"　胜利　",
	"　恭喜你在　%d　秒内扫完所以雷，请留下您的大名！　",
	"　恭喜你在　%d　秒内扫完所以雷！　",
	"Record.txt",
};