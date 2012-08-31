#include "GameObject.h"
#include "GUI.h"

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
