/**
* @file gurkan_kaya_odev_final
* @description avl ve stack veri yapilari odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 2. odev (final)
* @date 30.08.2020
* @author Gürkan Kaya
*/
#include <cmath>
#include <iostream>
#include<algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include"Stack.hpp"
#include"Dugum.hpp"
#include"Kisi.hpp"
#include"AVL.hpp"

using namespace std;

	Dugum* AVLTree::DegistirSol(Dugum* dugumParam)
	{
		Dugum* tmp = dugumParam->sol;

		dugumParam->sol = tmp->sag;

		tmp->sag = dugumParam;

		dugumParam->yukseklik = Yukseklik(dugumParam);

		tmp->yukseklik = max(Yukseklik(tmp->sol), dugumParam->yukseklik) + 1;

		return tmp;

	}

	Dugum* AVLTree::DegistirSag(Dugum* dugumParam)
	{
		Dugum* tmp = dugumParam->sag;

		dugumParam->sag = tmp->sol;

		tmp->sol = dugumParam;

		dugumParam->yukseklik = Yukseklik(dugumParam);

		tmp->yukseklik = max(Yukseklik(tmp->sag), dugumParam->yukseklik) + 1;

		return tmp;
	}


	Dugum* AVLTree::YeniEkle(Dugum* dugumParam, const int& yeni)
	{

		if (dugumParam == NULL)
		{
			dugumParam = new Dugum(yeni, ks->isim, ks->kilo, ks->dogumyili);
		}

		else if (yeni <= dugumParam->veri)
		{
			dugumParam->sol = YeniEkle(dugumParam->sol, yeni);

			if (Yukseklik(dugumParam->sol) - Yukseklik(dugumParam->sag) == 2)
			{

				if (yeni <= dugumParam->sol->veri)
				{
					dugumParam = DegistirSol(dugumParam);
				}

				else
				{
					dugumParam->sol = DegistirSag(dugumParam->sol);
					dugumParam = DegistirSol(dugumParam);
				}

			}

		}
		else if (yeni > dugumParam->veri)
		{
			dugumParam->sag = YeniEkle(dugumParam->sag, yeni);

			if (Yukseklik(dugumParam->sag) - Yukseklik(dugumParam->sol) == 2)
			{

				if (yeni > dugumParam->sag->veri)
				{

					dugumParam = DegistirSag(dugumParam);

				}

				else
				{

					dugumParam->sag = DegistirSol(dugumParam->sag);

					dugumParam = DegistirSag(dugumParam);

				}

			}


		}

		dugumParam->yukseklik = Yukseklik(dugumParam);

		return dugumParam;


	}


	AVLTree::AVLTree() 
	{
		root = NULL;

		ifstream dosyaOku("Kisiler.txt");
		
		if (dosyaOku.is_open())
		{

			while (getline(dosyaOku, ks->isim, '#'))
			{

				dosyaOku >> ks->dogumyili;

				getline(dosyaOku, ks->kilo);

				ks->kilo.erase(0, 1);

				Ekle(2020 - ks->dogumyili);
			
			}

		}

		dosyaOku.close();

	}

	void AVLTree::Ekle(const int& yeni)
	{

		root = YeniEkle(root, yeni);

		DerinlikGuncelle(root, 0);

	}

	void AVLTree:: DerinlikGuncelle(Dugum* dugumParam, int depth)
	{
		if (dugumParam != NULL)
		{

			int oncekiseviye = dugumParam->seviye;

			dugumParam->seviye = depth;

			if (dugumParam->stck->IsEmpty())
			{

				dugumParam->stck->Push("O");

			}

			else if (oncekiseviye == dugumParam->seviye)
			{
				dugumParam->stck->Push("D");
			}

			else if (oncekiseviye < dugumParam->seviye)
			{
				dugumParam->stck->Push("A");
			}

			else if (oncekiseviye > dugumParam->seviye)
			{
				dugumParam->stck->Push("Y");
			}

			DerinlikGuncelle(dugumParam->sol, depth + 1);

			DerinlikGuncelle(dugumParam->sag, depth + 1);

		}


	}

	void AVLTree:: Postorder(Dugum* dugumParam) const
	{
		if (dugumParam != NULL)
		{
			Postorder(dugumParam->sol);

			Postorder(dugumParam->sag);

			cout << dugumParam->isim1 << "," << dugumParam->dogumyil << "," << dugumParam->kilo1;

			cout << "  Yigit: ";

			dugumParam->stck->StackYazdir(dugumParam->stck);

			cout << endl;



		}
	}

	int AVLTree::Yukseklik(Dugum* dugumParam) const
	{
		if (dugumParam == NULL)

			return -1;

		return 1 + max(Yukseklik(dugumParam->sol), Yukseklik(dugumParam->sag));
	}

	bool AVLTree:: DugumSil(Dugum*& dugumParam)
	{
		Dugum* bunuSil = dugumParam;

		if (dugumParam->sag == NULL)
		{
			dugumParam = dugumParam->sol;
		}
			
		else if (dugumParam->sol == NULL)
		{
			dugumParam = dugumParam->sag;
		}
			
		else
		{
			bunuSil = dugumParam->sol;

			Dugum* parent = dugumParam;

			while (bunuSil->sag != NULL) 
			{
				parent = bunuSil;

				bunuSil = bunuSil->sag;
			}

			dugumParam->veri = bunuSil->veri;

			if (parent == dugumParam)

				dugumParam->sol = bunuSil->sol;

			else

				parent->sag = bunuSil->sol;
		}

		delete bunuSil;

		return true;
	}
	
	void AVLTree:: Temizle()
	{
		while (root!=NULL)
		{
			DugumSil(root);
		}
	}
	
	AVLTree:: ~AVLTree()
	{
		
		Temizle();
		
	}