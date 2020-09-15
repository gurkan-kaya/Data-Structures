/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include<iostream>
#include"Stack.hpp"
#include"Kisi.hpp"
class Dugum
{
public:

	int veri;

	int yukseklik;

	int dogumyil;

	int seviye;

	Dugum* sol;

	Dugum* sag;

	string isim1;

	string kilo1;

	Kisi* k = new Kisi();

	Stack* stck = new Stack();

	Dugum(const int& vr, string is, string ki, int dy, Dugum* sl = NULL, Dugum* sg = NULL);
	

	

};

#endif
