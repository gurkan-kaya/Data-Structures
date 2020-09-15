/**
* @file gurkan_kaya_odev
* @description cift yonlu dairesel bagli liste odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 1. odev
* @date 09.08.2020
* @author Gürkan Kaya
*/
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "Node.hpp"

class Iterator
{
public:
	Node* current;
	Iterator(Node* node = NULL);
	bool IsEndNode();
	void StepNext();
	void StepBack();
	const int& GetCurrentData() const;
};



#endif
