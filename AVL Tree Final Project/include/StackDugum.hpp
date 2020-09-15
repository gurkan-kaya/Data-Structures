/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#ifndef STACKDUGUM_HPP
#define STACKDUGUM_HPP

#include <iostream>

using namespace std;

class StackDugum
{
public:
	string data;
	StackDugum* next;
	StackDugum(const string& data, StackDugum* next = NULL);

};

#endif