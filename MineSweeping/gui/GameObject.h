#ifndef GAME_OBJECT_H_H
#define GAME_OBJECT_H_H

#include "../FLTK.h"
#include <cassert>
#include <memory>
#include <iostream>
#include "../globalVal.h"

//mineInit=10, mark=12, markUnknow=14
const int markImage[] = {10,12,14};
using std::auto_ptr;

//用于放置图片的图片框
class GridBlock:public Fl_Box
{
public:
	GridBlock(void);
	GridBlock(const char* filename);
	GridBlock(const GridBlock& a_rightSide);
	GridBlock& operator=(const GridBlock& a_rightSide);

	//设置图片
	void setImage(const char *filename);
	void setDisable() {m_enable = false;}

	int getX(void)const {return x();}
	int getY(void)const {return y();}
	int getWidth(void)const {return w();}
	int getHeight(void)const {return h();}
	void setPosition(int a_x, int a_y) {position(a_x,a_y);}
	void setSize(int a_width, int a_height);
	void setLineColumn(int i, int j) {m_lineNumber=i;m_columnNumber=j;}

	//Event处理
	int handle(int event);

	//单击事件处理
	void leftClick(void);
	void rightClick(void);

private:
	auto_ptr<Fl_Image> m_pImage;//图片
	Fl_Shared_Image* m_pSharedImage;//共享区图片
	int m_x,m_y;
	int m_width,m_height;
	bool m_enable;//是否可以响应事件（当点开数字后就设为false）
	bool m_isableLeftClick;//是否可以响应左击事件
	int m_lineNumber;//所在行号
	int m_columnNumber;//所在列号
	int m_rightClickNumber;//右键点击次数，用于右击更换图片
};

inline GridBlock::GridBlock(void)
:Fl_Box(0,0,0,0,0),m_pSharedImage(NULL),m_x(0),m_y(0),m_width(0),m_height(0),
m_enable(true),m_isableLeftClick(true),m_lineNumber(0),m_columnNumber(0),
m_rightClickNumber(0)
{

}
inline GridBlock::GridBlock(const char* filename)
:Fl_Box(0,0,0,0,0),m_pSharedImage(NULL),m_x(0),m_y(0),m_width(0),m_height(0),
m_enable(true),m_isableLeftClick(true),m_lineNumber(0),m_columnNumber(0),
m_rightClickNumber(0)
{
	setImage(filename);
}
inline GridBlock::GridBlock(const GridBlock& a_rightSide)
:Fl_Box(0,0,0,0,0),m_pSharedImage(NULL),m_x(0),m_y(0),m_width(0),m_height(0),
m_enable(true),m_isableLeftClick(true),m_lineNumber(0),m_columnNumber(0),
m_rightClickNumber(0)
{
	*this = a_rightSide;
}
inline GridBlock& GridBlock::operator=(const GridBlock& a_rightSide)
{
	m_x = a_rightSide.getX();
	m_y = a_rightSide.getY();
	m_width = a_rightSide.getWidth();
	m_height = a_rightSide.getHeight();
	m_enable = a_rightSide.m_enable;
	m_isableLeftClick = a_rightSide.m_isableLeftClick;
	m_lineNumber = a_rightSide.m_lineNumber;
	m_columnNumber = a_rightSide.m_columnNumber;
	m_rightClickNumber = a_rightSide.m_rightClickNumber;
	resize(m_x,m_y,m_width,m_height);
	if (a_rightSide.m_pSharedImage != NULL)//Fl_Shared_Image不存在的情况下不能调用它的方法
	{
		m_pSharedImage = Fl_Shared_Image::get(a_rightSide.m_pSharedImage->name());//获取相同的sharedImage
		m_pImage.reset(m_pSharedImage->copy(m_width,m_height));//构建一幅大小相同的Image
		image(m_pImage.get());
		redraw();
	}
	return *this;
}

//设置图片
inline void GridBlock::setImage(const char *filename)
{
	fl_register_images();
	m_pSharedImage = Fl_Shared_Image::get(filename);
	m_pImage.reset(m_pSharedImage->copy(m_width,m_height));
	image(m_pImage.get());
	redraw();
}

//更改图片大小
inline void GridBlock::setSize(int a_width, int a_height)
{
	m_width = a_width;
	m_height = a_height;
	size(m_width,m_height);
	m_pImage.reset(m_pSharedImage->copy(m_width,m_height));
	image(m_pImage.get());//重新修改image,因为之前的image会自动销毁
	redraw();
}


//Event处理
inline int GridBlock::handle(int event)
{
	if (!m_enable) return (0);//点开数字后失去操作权
	using std::cout;
	using std::endl;
	switch (event)
	{
	case FL_PUSH:
		switch (Fl::event_button())//只处理单击事件
		{
		case FL_LEFT_MOUSE:
			if (m_isableLeftClick)
			{
				cout << "你点击了鼠标左键" << endl;
				cout << "i=" << m_lineNumber << ",j=" << m_columnNumber << endl;
				leftClick();//鼠标左击事件处理
			}
			break;
		case FL_RIGHT_MOUSE:
			rightClick();//处理右击事件
			break;
		}
		break;
	}
	return 0;
}

//处理右击事件：状体转换，更换图片。如果是“红旗”和“问号”状体则置不可响应左击事件，否则置可响应左击事件
inline void GridBlock::rightClick(void)
{
	m_rightClickNumber++;
	if (m_rightClickNumber>2)
	{
		m_rightClickNumber=0;
	}
	setImage(imageName[markImage[m_rightClickNumber]]);
	//在标记状态下停止响应左击事件
	if (m_rightClickNumber == 0)
	{
		m_isableLeftClick = true;
	}
	else
	{
		m_isableLeftClick = false;		
	}
}

#endif