/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <cmath>
#include <iostream>
#include<algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include"Dugum.hpp"
#include"Kisi.hpp"
#include"Stack.hpp"

using namespace std;

class AVLTree 
{
private:

	Dugum* DegistirSol(Dugum* dugumParam) ;

	Dugum* DegistirSag(Dugum* dugumParam);

	Dugum* YeniEkle(Dugum* dugumParam, const int& yeni);
	

public:

	Kisi* ks = new Kisi;

	Stack* s1 = new Stack();

	Dugum* root;
	
	AVLTree();

	void Ekle(const int& yeni) ;
	
	void DerinlikGuncelle(Dugum* node, int depth);
	
	void Postorder(Dugum* dugumParam) const;

	int Yukseklik(Dugum* dugumParam) const;

	bool DugumSil(Dugum*& dugumParam) ;
	
	void Temizle();

	~AVLTree();

};

#endif
