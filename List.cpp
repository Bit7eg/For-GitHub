#include <iostream>

using namespace std;

template <class Type>
class list
{
protected:
	list<Type>* next{ nullptr };
public:
	Type value;
	list<Type>(Type* arr, int size)
	{
		value = arr[0];
		if (size > 1)
		{
			next = new list<Type>(arr + 1, size - 1);
		}
	}
	list<Type>* next_elem()
	{
		return next;
	}
	friend void push_front(list<Type>*&, Type);
	friend void push_back(list<Type>*&, Type);
	friend void insert_to_position(list<Type>*&, int, Type);
	friend void delete_list(list<Type>*&);
	friend void pop_front(list<Type>*&);
	friend void pop_back(list<Type>*&);
	friend void delete_elem(list<Type>*&, int);
};

template <class Type> void push_front(list<Type>*& chain, Type data)
{
	list<Type>* temp = new list<Type>;
	temp->value = data;
	temp->next = chain;
	chain = temp;
}

template <class Type> void push_back(list<Type>*& chain, Type data)
{
	if (chain != nullptr)
	{
		list<Type>* currient = chain;
		for (; currient->next != nullptr; currient = currient->next) {}
		currient->next = new list<Type>;
		currient->next->value = data;
	}
	else
	{
		list<Type>* temp = new list<Type>;
		temp->value = data;
		chain = temp;
	}
}

template <class Type> void insert_to_position(list<Type>*& chain, int position, Type data)
{
	list<Type>* temp = new list<Type>;
	if ((chain != nullptr) && (position > 1))
	{
		list<Type>* currient{ chain };
		temp->value = data;
		for (int i{ 1 }; (i < position - 1) && (currient->next != nullptr); i++, currient = currient->next) {}
		temp->next = currient->next;
		currient->next = temp;
	}
	else
	{
		temp->value = data;
		temp->next = chain;
		chain = temp;
	}
}

template <class Type> void delete_list(list<Type>*& chain)
{
	list<Type>* currient;
	while (chain != nullptr)
	{
		currient = chain->next;
		delete chain;
		chain = currient;
	}
}

template <class Type> void pop_front(list<Type>*& chain)
{
	if (chain != nullptr) {
		list<Type>* temp{ chain->next };
		delete chain;
		chain = temp;
	}
}

template <class Type> void pop_back(list<Type>*& chain)
{
	if ((chain != nullptr) && (chain->next != nullptr))
	{
		list<Type>* currient = chain;
		for (; currient->next->next != nullptr; currient = currient->next) {}
		delete currient->next;
		currient->next = nullptr;
	}
	else
	{
		delete chain;
		chain = nullptr;
	}
}

template <class Type> void delete_elem(list<Type>*& chain, int position)
{
	if (chain != nullptr)
	{
		if (position > 1) {
			list<Type>* currient{ chain };
			for (int i{ 1 }; (i < position - 1) && (currient->next->next != nullptr); i++, currient = currient->next) {}
			list<Type>* temp = currient->next->next;
			delete currient->next;
			currient->next = temp;
		}
		else
		{
			list<Type>* temp{ chain->next };
			delete chain;
			chain = temp;
		}
	}
}