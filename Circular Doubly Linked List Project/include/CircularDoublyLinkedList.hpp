/**
* @file gurkan_kaya_odev
* @description cift yonlu dairesel bagli liste odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 1. odev
* @date 09.08.2020
* @author Gürkan Kaya
*/
#ifndef CIRCULARDOUBLYLINKEDLIST_HPP
#define CIRCULARDOUBLYLINKEDLIST_HPP
#include "Iterator.hpp"
using namespace std;

class CircularDoublyLinkedList
{


public:

	Node* head;
	int size;
	Iterator IterateFromFirstNode() const;
	Iterator IterateFromPrevIndex(int index) const;
	void UpdateLastNode();
	CircularDoublyLinkedList();
	bool IsEmpty() const;
	int Count() const;
	const int& First() const;
	const int& Last() const;
	void Add(const int& obj);
	void Insert(int index, const int& obj);
	void Remove(const int& obj);
	void RemoveAt(int index);
	int IndexOf(const int& obj) const;
	void Clear();
	~CircularDoublyLinkedList();
};




#endif
