#ifndef GLOBAL_VAL_H_
#define GLOBAL_VAL_H_

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const char const* imageName[];
extern const int initMinesCount;//初始地雷个数
extern const int initColumns;//初始行数
extern const int initLines;
extern const float initBlockWidth;//初始格子像素大小
extern const float initBlockHeight;


//用于传递点开的格子的位置和数字的消息结构体
struct OpenGridMsg 
{
	int i;
	int j;
	int state;//图片对应的数字[0~9]
};


//在GUI::clickOpen()函数中会调用下面的接口
//核心算法中给GUI提供的接口
//void clickOpen(int i, int j, vector<OpenGridMsg>& msg)

//格子最后显示状态的枚举类型
enum ImageName
{
	zero=0,one=1,two=2,three=3,four=4,five=5,six=6,seven=7,eight=8,
	mineBoom=9,mineInit=10,mineOut=11,mark=12,markWrong=13,markUnknow=14
};

#endif