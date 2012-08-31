#ifndef GLOBAL_VAL_H_
#define GLOBAL_VAL_H_

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;


//用于传递点开的格子的位置和数字的消息结构体
struct OpenGridMsg 
{
	int i;
	int j;
	int stat;//图片状态
};


//在GUI::clickOpen()函数中会调用下面的接口
//核心算法中给GUI提供的接口
//void clickOpen(int i, int j, vector<OpenGridMsg>& msg)

//格子最后显示状态的枚举类型
enum {init=-1,one=1,two=2,three=3,four=4,five=5,six=6,seven=7,eight=8,mine=9};

#endif