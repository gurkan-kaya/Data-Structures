/**
* @file gurkan_kaya_odev
* @description cift yonlu dairesel bagli liste odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 1. odev
* @date 09.08.2020
* @author Gürkan Kaya
*/
#include "Iterator.hpp"
#include "Node.hpp"

	Iterator::Iterator(Node* node)
	{
		current = node;
	}

	bool Iterator:: IsEndNode()
	{
		return current == NULL;
	}

	void Iterator:: StepNext()
	{
		if (!IsEndNode())
		{
			current = current->next;
		}
	}
	void Iterator:: StepBack()
	{
		if (!IsEndNode())
		{
			current = current->prev;
		}
	}

	const int& Iterator:: GetCurrentData() const
	{
		return current->data;
	}


