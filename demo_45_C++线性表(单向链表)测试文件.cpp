#include"demo_45_C++���Ա�(��������)ͷ�ļ�.h"
#include<iostream>
#include<string>
using namespace std;

struct Teacher
{
	string name;
	int age;
};

void main1(void)
{
	LinkList<Teacher> list;
	Teacher t1, t2, t3;
	Teacher tmp;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	
	list.insert(t1, 0);
	list.insert(t2, 0);
	list.insert(t3, 0);
	
	for(int i = 0; i < list.getlen(); i++)
	{
		list.get(i, tmp);
		cout << "age:" << tmp.age;
	}
	
	while(list.getlen() > 0)
	{
		list.del(0, tmp);
		cout << "age:" << tmp.age;
	}
} 

int main(void)
{
	main1();
	
	return 0;
}
