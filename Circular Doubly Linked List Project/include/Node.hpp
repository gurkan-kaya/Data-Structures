/**
* @file gurkan_kaya_odev
* @description cift yonlu dairesel bagli liste odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 1. odev
* @date 09.08.2020
* @author Gürkan Kaya
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node* prev;
	Node(const int& data = int(), Node* next = NULL, Node* prev = NULL);
};

#endif
