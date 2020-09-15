/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#include <iostream>
#include"Stack.hpp"
#include"StackDugum.hpp"

using namespace std;

	Stack::Stack()
	{
		head = NULL;
	}

	bool Stack::IsEmpty() const
	{
		return head == NULL;
	}

	const string& Stack::Top() const
	{
		return head->data;
	}

	void Stack::Pop()
	{
		if (IsEmpty())
			return;
		StackDugum* tmp = head;
		head = head->next;
		delete tmp;
	}

	void Stack::Push(const string& obj)
	{
		head = new StackDugum(obj, head);
	}


	void Stack::StackYazdir(Stack* s1)
	{
		while (!s1->IsEmpty())
		{
			cout << s1->Top()<<" ";
			Pop();
		}

	}

	void Stack::Clear()
	{
		while (!IsEmpty())
		{
			Pop();
		}
	}

	Stack::~Stack()
	{
		Clear();
	}

