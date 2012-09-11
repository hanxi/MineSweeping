#include "GameObject.h"
#include "gui.h"

DialogWindow* DialogWindow::m_pDialogWindow = NULL;
TimeShowBox* TimeShowBox::m_pTimeShowBox = NULL;

//处理右击事件：状体转换，更换图片。如果是“红旗”和“问号”状体则置不可响应左击事件，否则置可响应左击事件
void GridBlock::rightClick(void)
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
	GUI::getInstance()->rightClick(m_lineNumber,m_columnNumber);
}

void GridBlock::leftClick(void)
{
	GUI::getInstance()->clickOpen(m_lineNumber,m_columnNumber);

	//过程如下：
	//传递该消息(包括行号和列号)给GUI => GUI调用核心算法获取点开的所有格子和对应的数字 => 根据地图调用setImage(image[k]).k属于[0,9]，并置格子为不可响应事件setDisable()
	//GUI自身有一张数字地图，-1表示初始态，0~9表示点开后的数字。各个数字对应着各个图片,9表示点到了地雷，GameOver
	//
	//处理左击事件：置该格子为不可响应事件状态，调用核心算法（传递行列值），获取更新后的地图状体，更换图片
	//需要想想怎么把这个事件传递给GUI,让GUI来控制所有图片的更换。
}

void DialogWindow::dialogWindowCB(Fl_Widget* w, void*)
{
	DialogWindow* dialog = DialogWindow::getInstance();
	dialog->m_pInputs[0]->value("");
	dialog->m_pInputs[1]->value("");
	dialog->m_pInputs[2]->value("");
	dialog->hide();
}

void DialogWindow::OkCB(Fl_Widget* w)
{
	DialogWindow* dialog = DialogWindow::getInstance();
	string strH(dialog->m_pInputs[0]->value());
	string strW(dialog->m_pInputs[1]->value());
	string strC(dialog->m_pInputs[2]->value());
	int H,W,C;
	H = atoi(strH.c_str());
	W = atoi(strW.c_str());
	C = atoi(strC.c_str());
	if (H>maxH || H<minH || W>maxW || W<minW || C>W*H)
	{
		fl_alert(dialogWindowStr[6]);
		dialog->m_pInputs[0]->value("");
		dialog->m_pInputs[1]->value("");
		dialog->m_pInputs[2]->value("");
		return;
	}
	dialog->hide();
	GUI* gui = GUI::getInstance();
	gui->setLevelSelf(H,W,C);
	dialog->m_pInputs[0]->value("");
	dialog->m_pInputs[1]->value("");
	dialog->m_pInputs[2]->value("");
}
void DialogWindow::CancelCB(Fl_Widget* w)
{
	DialogWindow* dialog = DialogWindow::getInstance();
	dialog->m_pInputs[0]->value("");
	dialog->m_pInputs[1]->value("");
	dialog->m_pInputs[2]->value("");
	dialog->hide();
}
