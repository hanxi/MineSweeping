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
extern const int timeShowBoxWidth = initLines*initBlockWidth;//和窗口一样宽
extern const int timeShowBoxHeight = 60;
int g_useTime = 0;
bool g_isPauseTime = false;//是否暂停计算时间
extern int minH=3;//自定义雷区的范围
extern int maxH=20;
extern int minW=10;
extern int maxW=40;

extern const char *const imageName[]=
{
	"res/images/zero.png",		//0
	"res/images/one.png",		//1
	"res/images/two.png",		//2
	"res/images/three.png",		//3
	"res/images/four.png",		//4
	"res/images/five.png",		//5
	"res/images/six.png",		//6
	"res/images/seven.png",		//7
	"res/images/eight.png",		//8
	"res/images/mineBoom.png",	//9
	"res/images/mineInit.png",	//10
	"res/images/mineOut.png",	//11
	"res/images/mark.png",		//12
	"res/images/markWrong.png",	//13
	"res/images/markUnknow.png",//14
	"res/images/clock.jpg",		//15
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

extern const char *const dialogWindowStr[] = 
{
	"　自定义雷区　",
	"　高度(3~20)　",
	"　宽度(10~40)　",
	"　雷数(<W*H)　",
	"　确定　",
	"　取消　",
	"　输入的数据不符合范围要求，请重新输入！　",
};
extern const char *const GUIStr[] = 
{
	"　扫雷（FLTK版）　",	//0
	"　游戏失败　",			//1
	"　再玩一局？　",		//2
	"　退出　",				//3
	"　重玩　",				//4
	"　排行榜　",			//5
	"　确定退出？　",		//6
	"　扫雷排行榜　",		//7
	"　胜利　",				//8
	"　恭喜你在　%d　秒内扫完所以雷，请留下您的大名！　",	//9
	"　恭喜你在　%d　秒内扫完所以雷！　",					//10
	"Record.txt",			//11
	"　匿名　",				//12
	"初级：　",				//13
	"中级：　",				//14
	"高级：　",				//15
	"　秒　\t",				//16
};

extern const char *const TimeShowBoxStr[] = 
{
	"　剩余：　%d",
	"　标记：　%d",
	"　用时：　%d",
};
