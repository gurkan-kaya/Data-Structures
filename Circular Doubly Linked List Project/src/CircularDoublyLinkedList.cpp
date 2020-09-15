/**
* @file gurkan_kaya_odev
* @description cift yonlu dairesel bagli liste odevi
* @course 2019-2020 yaz donemi A grubu
* @assignment 1. odev
* @date 09.08.2020
* @author Gürkan Kaya
*/

#include "Iterator.hpp"
#include "CircularDoublyLinkedList.hpp"
using namespace std;

	Iterator CircularDoublyLinkedList:: IterateFromFirstNode() const
	{
		if (!IsEmpty())
		{
			return Iterator(head->next);
		}
		return NULL;
	}

	Iterator CircularDoublyLinkedList:: IterateFromPrevIndex(int index) const
	{
		if (!(index<0 || index>Count()))
		{
			int i = 0;
			Iterator itr = head;
			while (!itr.IsEndNode() && index != i++)
				itr.StepNext();
			return itr;
		}
		return NULL;
	}

	void CircularDoublyLinkedList:: UpdateLastNode()
	{
		Node* lastNode = IterateFromPrevIndex(size).current;
		lastNode->next = head->next;
	}

	CircularDoublyLinkedList::CircularDoublyLinkedList()
	{
		head = new Node();
		size = 0;
	}

	bool CircularDoublyLinkedList:: IsEmpty() const
	{
		return head->next == NULL;
	}

	int CircularDoublyLinkedList:: Count() const
	{
		return size;
	}

	const int& CircularDoublyLinkedList:: First() const
	{
		if (!IsEmpty())
		{
			return head->next->data;
		}
	}

	const int& CircularDoublyLinkedList:: Last() const
	{
		if (!IsEmpty())
		{
			return head->next->prev->data;
		}
			

		//return NULL;
	}

	void CircularDoublyLinkedList:: Add(const int& obj)
	{
		Insert(Count(), obj);
	}


	void CircularDoublyLinkedList:: Insert(int index, const int& obj)
	{
		Iterator itr;
		itr = IterateFromPrevIndex(index);
		Node* newNext = itr.current->next;
		itr.current->next = new Node(obj, newNext, itr.current);
		if (newNext != NULL)
		{
			Node* last = newNext->prev;
			newNext->prev = itr.current->next;
			if (index == 0)
			{
				head->next->prev = last;
				last->next = head->next;
			}
		}
		if (size == 0)
		{
			head->next->next = head->next;
			head->next->prev = head->next;
		}
		size++;
	}

	void CircularDoublyLinkedList:: Remove(const int& obj)
	{
		int index = IndexOf(obj);
		RemoveAt(index);
	}

	void CircularDoublyLinkedList:: RemoveAt(int index)
	{
		Iterator itr;
		itr = IterateFromPrevIndex(index);
		if (itr.current->next != NULL)
		{
			Node* oldNode = itr.current->next;
			itr.current->next = itr.current->next->next;
			oldNode->next->prev = oldNode->prev;
			delete oldNode;
			//head->next->prev->next = head->next;
			size--;
			if (size == 0)
				itr.current->next = NULL;

		}
	}

	int CircularDoublyLinkedList:: IndexOf(const int& obj) const
	{
		int index = 0;
		for (Iterator itr(head->next); index < size; itr.StepNext())
		{
			if (itr.GetCurrentData() == obj)
				return index;
			index++;
		}
		return -1;
	}


	void CircularDoublyLinkedList:: Clear()
	{
		while (!IsEmpty())
			RemoveAt(0);
	}

	CircularDoublyLinkedList::~CircularDoublyLinkedList()
	{
		Clear();
		delete head;
	}

