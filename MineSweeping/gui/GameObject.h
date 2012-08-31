#ifndef GAME_OBJECT_H_H
#define GAME_OBJECT_H_H

#include "../FLTK.h"
#include <cassert>
#include <memory>
#include <iostream>
using std::auto_ptr;

//用于放置图片的图片框
class GridBlock:public Fl_Box
{
public:
	GridBlock(void):Fl_Box(0,0,0,0,0) {}
	GridBlock(const char* filename):Fl_Box(0,0,0,0,0)
	{
		setImage(filename);
	}
	GridBlock(const GridBlock& a_rightSide)
	:Fl_Box(a_rightSide.getX(),a_rightSide.getY(),a_rightSide.getWidth(),a_rightSide.getHeight(),0)
	{
		m_x = a_rightSide.getX();
		m_y = a_rightSide.getY();
		m_width = a_rightSide.getWidth();
		m_height = a_rightSide.getHeight();
		m_pSharedImage = Fl_Shared_Image::get(a_rightSide.m_pSharedImage->name());//获取相同的sharedImage
		m_pImage.reset(m_pSharedImage->copy(m_width,m_height));//构建一幅大小相同的Image
		image(m_pImage.get());
		redraw();
	}
	GridBlock& operator=(const GridBlock& a_rightSide)
	{
		m_x = a_rightSide.getX();
		m_y = a_rightSide.getY();
		m_width = a_rightSide.getWidth();
		m_height = a_rightSide.getHeight();
		resize(m_x,m_y,m_width,m_height);
		m_pSharedImage = Fl_Shared_Image::get(a_rightSide.m_pSharedImage->name());//获取相同的sharedImage
		m_pImage.reset(m_pSharedImage->copy(m_width,m_height));//构建一幅大小相同的Image
		image(m_pImage.get());
		redraw();
		return *this;
	}

	//设置图片
	void setImage(const char *filename)
	{
		fl_register_images();
		m_pSharedImage = Fl_Shared_Image::get(filename);
		m_pImage.reset(m_pSharedImage->copy());
		image(m_pImage.get());
		redraw();
	}

	int getX(void)const {return x();}
	int getY(void)const {return y();}
	int getWidth(void)const {return w();}
	int getHeight(void)const {return h();}
	void setPosition(int a_x, int a_y) {position(a_x,a_y);}
	void setSize(int a_width, int a_height)
	{
		m_width = a_width;
		m_height = a_height;
		size(m_width,m_height);
		m_pImage.reset(m_pSharedImage->copy(m_width,m_height));
		image(m_pImage.get());//重新修改image,因为之前的image会自动销毁
		redraw();
	}

	//Event处理
	int handle(int event)
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
				cout << "你点击了鼠标左键" << endl;
				cout << "x=" << Fl::event_x() << ",y=" << Fl::event_y() << endl;
				//m_pSharedImage = Fl_Shared_Image::get("res/images/bg.jpg");
				//m_pImage.reset(m_pSharedImage->copy(m_width,m_height));
				//image(m_pImage.get());//重新修改image,因为之前的image会自动销毁
				//redraw();
				leftClick();//鼠标左击事件处理
				break;
			case FL_RIGHT_MOUSE:
				rightClick();//处理右击事件
				break;
			}
			break;
		}
		return 0;
	}

	void leftClick(void)
	{
//		pGUI->clickOpen(m_lineNumber,m_columnNumber);
		;//过程如下：
		;//传递该消息(包括行号和列号)给GUI => GUI调用核心算法获取点开的所有格子和对应的数字 => 根据地图调用setImage(image[k]).k属于[0,9]，并置格子为不可响应事件setDisable()
		;//GUI自身有一张数字地图，-1表示初始态，0~9表示点开后的数字。各个数字对应着各个图片,9表示点到了地雷，GameOver
		;//
		;//处理左击事件：置该格子为不可响应事件状态，调用核心算法（传递行列值），获取更新后的地图状体，更换图片
		;//需要想想怎么把这个事件传递给GUI,让GUI来控制所有图片的更换。
	}
	void rightClick(void)
	{
		;//处理右击事件：状体转换，更换图片。如果是“红旗”和“问号”状体则置不可响应左击事件，否则置可响应左击事件
	}

private:
	auto_ptr<Fl_Image> m_pImage;//图片
	Fl_Shared_Image* m_pSharedImage;//共享区图片
	int m_x,m_y;
	int m_width,m_height;
	bool m_enable;//是否可以响应事件（当点开数字后就设为false）
	bool m_isableLeftClick;//是否可以响应左击事件
	int m_lineNumber;//所在行号
	int m_columnNumber;//所在列号
};
#endif