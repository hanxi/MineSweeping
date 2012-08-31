#include "test.h"
#include <iostream>
#include "../globalVal.h"

using namespace std;

void Test::test_globalval(void)
{
	cout << "SCREEN_WIDTH=" << SCREEN_WIDTH << endl;
	cout << "SCREEN_HEIGHT=" << SCREEN_HEIGHT << endl;
}
/*
void Test::test_copy_construdtor(GameObject& t1, GameObject& t2)
{
	//²âÊÔ¿½±´¹¹Ôìº¯Êý
	t2.setSize(800,500);
	t1 = t2;
	t2.setSize(300,400);
//	t1.setSize(800,300);
	t2 = t1;
	t1.setSize(700,500);
	t1 = t2;
	t2.setSize(700,400);
}
void Test::test_ImageBox(ImageBox& t)
{
	t.setSize(250,250);
}
*/
