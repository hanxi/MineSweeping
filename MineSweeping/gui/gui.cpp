#include "gui.h"

#include <fstream>
#include <sstream>

GUI* GUI::m_pGUI = NULL;
const int SETLEVELDIALOG=100;

void GUI::setLevel(int a_level)
{
	m_level = a_level;
	switch(m_level)
	{
	case 1:
		m_minesCount = initMinesCount;
		m_numberLines = initLines;//行数
		m_numberColumns = initColumns;//列数
		break;
	case 2:
		m_minesCount = initMinesCount*4;
		m_numberLines = initLines*2;//行数
		m_numberColumns = initColumns*2;//列数
		break;
	case 3:
		m_minesCount = initMinesCount*8;
		m_numberLines = initLines*2;//行数
		m_numberColumns = initColumns*3;//列数
		break;
	default:
		assert("a_level must be [1~3]");
		return;
	}
	updateWindow();
}

void GUI::updateWindow(void)
{
	m_width=initBlockWidth*m_numberColumns;
	m_height=initBlockHeight*m_numberLines;
	m_pWindow->size(m_width,m_height+menuBarHeight+timeShowBoxHeight);
	m_pMenuBar->size(m_width,menuBarHeight);
	m_pTimeShowBox->resize(0,menuBarHeight,m_width,timeShowBoxHeight);
	m_pWindow->begin();//往窗体里面添加对象
	createGameObjects();
	m_pWindow->end();
	m_pWindow->show();
	m_pTimeShowBox->setMarkMines(0);
	m_pTimeShowBox->setRemainMines(m_minesCount);
	updateMap();
}

void GUI::setLevelSelf(int a_H, int a_W, int a_C)
{
	m_level=0;
	m_minesCount = a_C;
	m_numberLines = a_H;//行数
	m_numberColumns = a_W;//列数
	updateWindow();
}

void GUI::rightClick(int a_line, int a_colum)
{
	countMarkMines();
	if (strcmp(m_grid[a_line][a_colum].getImageName(),
		imageName[markUnknow]) != 0)//如果不是问号就做判断
	{
		int i=0,j=0;
		for (; i<m_numberLines; i++)
		{
			j=0;//最开始的时候忘记这句了
			for (; j<m_numberColumns; j++)
			{
				if (strcmp(m_grid[i][j].getImageName(),imageName[mineInit]) == 0)
				{//如果还有没标记点开或者没标记的
					break;
				}
				if (strcmp(m_grid[i][j].getImageName(),imageName[mark]) == 0
					&& !m_coreMines.isMine(i,j))//该位置被标记，且该位置不是雷
				{
					break;
				}
				if (strcmp(m_grid[i][j].getImageName(),imageName[markUnknow]) == 0)//如果有问号
				{
					break;
				}
			}
			if (j<m_numberColumns) break;//很重要的一句话，跳出双重循环
		}
		if (i==m_numberLines && j==m_numberColumns)
		{//胜利
			winnerDialog();//胜利对话框
		}
	}
}

void GUI::countMarkMines(void)
{
	//已标记雷数
	int markCount=0;
	for (int i=0; i<m_numberLines; i++)
	{
		for (int j=0; j<m_numberColumns; j++)
		{
			if (strcmp(m_grid[i][j].getImageName(),imageName[mark]) == 0) markCount++;
		}
	}
	//显示标记的雷的数量
	m_pTimeShowBox->setMarkMines(markCount);
	m_pTimeShowBox->setRemainMines(m_minesCount-markCount);
}
void GUI::winnerDialog(void)
{
	g_isPauseTime=true;//暂停时间
	int hotspot = fl_message_hotspot();
	fl_message_hotspot(0);
	fl_beep(FL_BEEP_MESSAGE);
	fl_message_hotspot(hotspot);
	fl_message_title(GUIStr[8]);
	int time = g_useTime;				//使用的是全局变量计算时间
	char name[20]="";
	if (m_level != 0)
	{
		const char* str = fl_input(GUIStr[9],"",time);
		if (strlen(name)==0)
		{
			strcpy(name,GUIStr[12]);//匿名
		}
		else
		{
			strcpy(name,str);
		}
	}
	else
	{
		fl_message(GUIStr[10],time);
		return;
	}
	saveRecord(time,name);//保存记录
}
void GUI::saveRecord(int a_useTime, const char* a_userName)
{
	assert(m_level!=0);
	using std::ofstream;
	using std::ifstream;
	ofstream writeFile;
	ifstream readFile;

	//备份
	string text;
	string str;
	readFile.open(GUIStr[11]);
	while (getline(readFile,str))
	{
		text += str+"\n";
	}
//	cout <<"text:"<< text;
	readFile.close();

	writeFile.open(GUIStr[11]);
	for (int i=1; i<4; i++)
	{
		int b = text.find_first_of('\n',0);
		str = text.substr(0,b);
//		cout <<"str:"<< str;
		text = text.substr(b+1,text.length()-b);
//		cout <<"text:"<< text;
//		cout << i << ":" << str << endl;
		if (i==m_level)
		{
//			cout << m_level << "级:" << str;
			if (str.length()==0)
			{
				writeFile<<a_useTime<<"\t"<<a_userName<<"\n";
			}
			else
			{
				int index = str.find('\t');
				string s = str.substr(0,index);//记住后面的参数是num
				int time = atoi(s.c_str());
//				cout << "old:" << time << endl;
//				cout << "new:" << a_useTime << endl;
				if (time>a_useTime)//更新记录
				{
					writeFile<<a_useTime<<"\t"<<a_userName<<"\n";
				}
				else
				{
					writeFile<<str<<"\n";
				}
			}
		}
		else
		{
			writeFile<<str<<"\n";
		}
	}
	writeFile.close();
}

void GUI::clickOpen(int a_line, int a_colum)
{
//	cout << "in GUI::clickOpen()" << endl;
	m_leftClickMsg.clear();
	m_coreMines.clickOpen(a_line, a_colum,m_leftClickMsg);
	if (m_leftClickMsg[0].state == mineBoom)//第一个是雷，GameOver
	{
		cout << "Game Over!" << endl;
		openAll();
		m_grid[m_leftClickMsg[0].i][m_leftClickMsg[0].j].setImage(imageName[mineBoom]);
		//然后给出"重来退出对话框"
		int rep = replayDialog();
		if (rep==0) exit(0);
		else if (rep == 2)//排行榜
		{
			RankingsDialog();
		}
		//更新雷区地图
		updateMap();
		return;
	}
	for (vector<OpenGridMsg>::iterator it=m_leftClickMsg.begin();
		it != m_leftClickMsg.end(); it++)
	{
		m_grid[it->i][it->j].setImage(imageName[it->state]);
		m_grid[it->i][it->j].setDisable();
	}
}

//更新地图
void GUI::updateMap(void)
{
	g_useTime=0;
	g_isPauseTime=false;
	m_coreMines.initMines(m_numberLines,m_numberColumns,m_minesCount);
	for (int i=0; i<m_numberLines; i++)
	{
		for (int j=0; j<m_numberColumns; j++)
		{
			m_grid[i][j].init();
			m_grid[i][j].setImage(imageName[mineInit]);
		}
	}
}
int GUI::replayDialog(void)//GameOver对话框
{
	g_isPauseTime=true;//暂停时间
	int hotspot = fl_message_hotspot();
	fl_message_hotspot(0);
	fl_message_title(GUIStr[1]);
	int rep = fl_choice(GUIStr[2],
		GUIStr[3], GUIStr[4], GUIStr[5]);
	fl_message_hotspot(hotspot);
	return rep;
}

//打开所有的，GameOver
void GUI::openAll(void)
{
	for (int i=0; i<m_numberLines; i++)
	{
		for (int j=0; j<m_numberColumns; j++)
		{
			if (m_grid[i][j].isEnable())
			{
				if (m_coreMines.isMine(i,j))
				{
					m_grid[i][j].setImage(imageName[mineOut]);
				}
				else if (m_grid[i][j].isMark())//标记错误
				{
					m_grid[i][j].setImage(imageName[markWrong]);
				}
				else
				{
					m_grid[i][j].setImage(imageName[m_coreMines.roundMines(i,j)]);
				}
			}
		}
	}
}

void GUI::window_callback(Fl_Widget*, void*)
{
	int hotspot = fl_message_hotspot();
	fl_message_hotspot(0);
	fl_message_title(GUIStr[3]);
	int rep = fl_ask(GUIStr[6]);
	fl_message_hotspot(hotspot);
	if (rep==1) 
		exit(0);
}

//排行榜对话框
void GUI::RankingsDialog(void)
{
	g_isPauseTime=true;//暂停时间
	int hotspot = fl_message_hotspot();
	fl_message_hotspot(0);
	fl_message_title(GUIStr[7]);

	using std::ifstream;
	ifstream readFile(GUIStr[11]);//读取文件中的数据
	string text;
	string str;
	while (getline(readFile,str))
	{
		text += str+"\n";
	}
	readFile.close();
	cout << text;

	string textout;
	//找到str为m_level行
	for (int i=0; i<3; i++)
	{
		int b = text.find_first_of('\n',0);
		str = text.substr(0,b);
		text = text.substr(b+1,text.length()-b);
		int index = str.find('\t');
		string time = str.substr(0,index);//记住后面的参数是num
		string name = str.substr(index+1,str.length()-index);
		cout << "time,name:" << time << "," << name << endl;
		textout+=GUIStr[13+i]+time+GUIStr[16]+name+"\n";
	}
/*		"初级：　",				//13
		"中级：　",				//14
		"高级：　",				//15
		"　秒　\t",				//16
*/
	fl_message("%s",textout.c_str());
	g_isPauseTime=false;//恢复时间
}

void GUI::menuCB(Fl_Widget* w, void*)
{
	Fl_Menu_* mw = (Fl_Menu_*)w;
	const Fl_Menu_Item* m = mw->mvalue();
	if (!m) printf("no MenuItem\n");
	else
	{
		GUI* gui = GUI::getInstance();
		if (strcmp(m->label(),menuItems[1].text)==0)
		{
			gui->updateMap();//
		}
		else if (strcmp(m->label(),menuItems[2].text)==0)
		{
			gui->setLevel(1);
		}
		else if (strcmp(m->label(),menuItems[3].text)==0)
		{
			gui->setLevel(2);
		}
		else if (strcmp(m->label(),menuItems[4].text)==0)
		{
			gui->setLevel(3);
		}
		else if (strcmp(m->label(),menuItems[5].text)==0)
		{
			DialogWindow* dialog = DialogWindow::getInstance();
			Fl_Group::current(dialog);
			dialog->show();
			dialog->set_visible();
			dialog->active();
		}
		else if (strcmp(m->label(),menuItems[6].text)==0)
		{
			//给出信息对话框
			gui->RankingsDialog();
		}
		else if (strcmp(m->label(),menuItems[7].text)==0)
		{//发送退出信息给主窗体
			Fl::handle_(FL_CLOSE,gui->m_pWindow.get());
		}
		printf("%s\n", m->label());
	}
}