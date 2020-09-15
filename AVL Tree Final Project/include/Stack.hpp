/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#ifndef STACKLIST_HPP
#define STACKLIST_HPP

#include <iostream>
#include"StackDugum.hpp"

using namespace std;

class Stack
{
private:

	StackDugum* head;

public:

	Stack();

	bool IsEmpty() const;

	const string& Top() const;

	void Pop();

	void Push(const string& obj);

	void StackYazdir(Stack* s1);

	void Clear();

	~Stack();
};

#endif