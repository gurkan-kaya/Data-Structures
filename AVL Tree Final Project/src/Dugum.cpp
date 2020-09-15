/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#include<iostream>
#include"Dugum.hpp"

using namespace std;

	Dugum::Dugum(const int& vr, string is, string ki, int dy, Dugum* sl, Dugum* sg)
	{
		veri = vr;

		sol = sl;

		sag = sg;

		k->isim = is;

		isim1 = k->isim;

		k->kilo = ki;

		kilo1 = k->kilo;

		k->dogumyili = dy;

		dogumyil = k->dogumyili;

		yukseklik = 0;

		seviye = 0;
	}

