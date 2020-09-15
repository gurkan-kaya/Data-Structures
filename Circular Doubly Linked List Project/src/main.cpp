/**
* @file gurkan_kaya_odev
* @description cift yonlu dairesel bagli liste odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 1. odev
* @date 09.08.2020
* @author Gürkan Kaya
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "CircularDoublyLinkedList.hpp"
using namespace std;

int main()
{
    CircularDoublyLinkedList* numbers = new CircularDoublyLinkedList();
    string* dizi = new string[500];
    int index = 0;
    int sayi = 0; 
    int ebob = 0;
    ifstream dosyaOku("Sayilar.txt");
		system("CLS");
    if (dosyaOku.is_open())
    {
        string line;
        while (getline(dosyaOku, line))
        {
            dizi[index] = line;

            index++;
        }

        dosyaOku.close();
    }


    for (int i = 0; i < index; i++)
    {
        istringstream is(dizi[i]);
        int n;

        while (is >> n)
        {

            numbers->Add(n);
			
			 if (n == 0)
            {
                 cout << "Odev dokumaninda '0-255 ARASINDAKI POZITIF sayilar bulunacak.' cumlesi yer aldigindan,"<<endl
                      <<"ayrica bir sayinin sifira bolumu tanimsiz olacagindan"<<endl
                     <<"ve dolayisiyla modu olmayacagindan dolayi  program POZITIF degerlere uygun hazirlanmistir." << endl
                     <<"Lutfen 0 icermeyen bir Sayilar.txt dosyasi ile tekrar deneyiniz. " << endl;
                 return 0;

            }
			
            if (numbers->IsEmpty() || numbers->Count() == 1)
            {
                ebob = 0;
            }

            
            if (numbers->Count() > 1)
            {
                int kackez = 0;
                int sayi1, sayi2, buyukSayi, kucukSayi;

                Iterator itr = numbers->IterateFromFirstNode();

                for (itr; kackez < numbers->Count()-1 ; itr.StepNext())
                {
                    sayi1 = itr.GetCurrentData();
                    sayi2 = n;
                    if (sayi1 > sayi2)
                    {
                        buyukSayi = sayi1;
                        kucukSayi = sayi2;
                    }
                    else
                    {
                        buyukSayi = sayi2;
                        kucukSayi = sayi1;
                    }
                    int  ebobSon = buyukSayi;
                   
                    for (ebobSon; ebobSon > 0; ebobSon--)
                    {
                             if ((sayi1 % ebobSon == 0) && (sayi2 % ebobSon == 0))
                             {
                                 int mod = buyukSayi % kucukSayi;

                                 if (ebobSon < ebob && kackez == numbers->Count() -2 )
                                 {

                                     if (kackez - mod >= 0 )
                                     {

                                         numbers->Insert(kackez - mod +1 , sayi2);
                                         numbers->RemoveAt(numbers->Count() - 1);
                                     }
                                     else  if (kackez - mod < 0 )
                                     {
                                         numbers->Insert(0, sayi2);
                                         numbers->RemoveAt(numbers->Count() - 1);
                                     }

                                 }

                                 if (ebobSon >= ebob)
                                 {

                                     if (kackez - mod >= 0 )
                                     {

                                         numbers->Insert(kackez - mod + 1, sayi2);
                                         numbers->RemoveAt(numbers->Count() - 1);
                                     }

                                     else if (kackez - mod < 0 )
                                     {
                                         numbers->Insert(0, sayi2);
                                         numbers->RemoveAt(numbers->Count() - 1);
                                     }

                                     ebob = ebobSon;
									 kackez = numbers->Count() - 1;
                                 }
                                 ebobSon = 0;
                             }
                    }                  
                    kackez++;
                }
            }
            sayi++;
        }
        int j = 0;
        cout << "Sifre:";
        for (Iterator itr = numbers->IterateFromFirstNode(); j<numbers->Count(); itr.StepNext())
        {

           cout<<(char)itr.current->data;
           j++;
        }
        cout << endl;
        numbers->Clear();

    }
    delete[] dizi;
    return 0;
}
