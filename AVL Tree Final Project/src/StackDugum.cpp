/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#include"StackDugum.hpp"


StackDugum::StackDugum(const string& data, StackDugum* next)
{

	this->data = data;

	this->next = next;

}