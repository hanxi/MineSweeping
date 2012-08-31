#ifndef GUI_H_
#define GUI_H_

#include "FLTK.h"
#include "globalVal.h"

class GUI
{
public:
	GUI(void);
	virtual ~GUI(void);

	void creatWindow(char* a_winName="É¨À×£¨FLTK°æ£©");
	void releaseWindow(void);

private:
	Fl_Window* m_pWindow;//Ö÷´°Ìå
};

inline GUI::GUI(void)
{
	creatWindow();
	m_pWindow->begin();
	m_pWindow->show();
}
inline GUI::~GUI(void)
{
	releaseWindow();
}

inline void GUI::creatWindow(char* a_winName)
{
	m_pWindow = new Fl_Window(WIN_WIDTH,WIN_HEIGHT,a_winName);
}
inline void GUI::releaseWindow(void)
{
	delete m_pWindow;
}
#endif