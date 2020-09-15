/**
* @file gurkan_kaya_odev
* @description cift yonlu dairesel bagli liste odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 1. odev
* @date 09.08.2020
* @author Gürkan Kaya
*/
#include<iostream>
#include"Node.hpp"
using namespace std;

	Node::Node(const int& data, Node* next, Node* prev)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
