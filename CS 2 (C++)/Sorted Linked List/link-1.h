//most of code is from textbook and little search from google.
#ifndef LINK_HPP
#define LINK_HPP
#include <iostream>
#include <memory>
using namespace std;
template <typename T>
class link{
private:	
	int size = 0;
	template <typename T>
	struct linkNode{
		T value;
		std::shared_ptr<linkNode<T>> next;
		//std::make_shared<linkNode<T>> next;

		linkNode(T valuel, std::shared_ptr<linkNode<T>> next1 = NULL)
		{
			value = valuel;
			next = next1;
		}
	};
	std::shared_ptr<linkNode<T>>head;



public:
	link(){ head = NULL;}

	link(link & or){
		auto cur = or.head;
		while (cur != NULL){
			this->add1(cur->value);
			cur = cur->next;
		}
	}

	
	void add(T value1)
	{
		std::shared_ptr<linkNode<T>>nodeptr, previousNodeptr;
		if (head == NULL || head->value >= value1)
		{
			head =std::make_shared<linkNode<T>>(value1, head);
		}
		else
		{ 
			previousNodeptr = head;
			nodeptr = head->next;
			while (nodeptr != NULL&&nodeptr->value < value1)
			{
				previousNodeptr = nodeptr;
				nodeptr = nodeptr->next;
			}
			previousNodeptr->next = make_shared <linkNode<T>>(value1, nodeptr);
		}
		size++;
	}

	void remove(T value){
		std::shared_ptr<linkNode<T>>nodeptr, previousNodeptr;
		if (!head)return;
		if (head->value == value){
			nodeptr = head;
			head = head->next;
			
		}
		else
		{
			nodeptr = head;
			while (nodeptr != NULL &&nodeptr->value != value)
			{
				previousNodeptr = nodeptr;
				nodeptr = nodeptr->next;
			}
			if (nodeptr){
				previousNodeptr->next = nodeptr->next;
				
			}
		} 
		--size;
	}

	int number()
	{
		return size;
	}

	void displaylist() const{
		std::shared_ptr<linkNode<T>> nodeptr = head;
		while (nodeptr){
			cout << nodeptr->value << "    ";
			nodeptr = nodeptr -> next;
		}
	}

	void add1(T value){
		if (head == NULL){
			head = std::make_shared<linkNode<T>>(value);

		}
		else
		{
			std::shared_ptr<linkNode<T>> nodeptr = head;
			while (nodeptr->next != NULL){
				nodeptr = nodeptr->next;
				
			}
			nodeptr->next = make_shared<linkNode<T>>(value);
		}
	}

	void clear(){
		head = nullptr;
	}

	

	

	
	link & operator= (const link & other)
	{
		clear();
		this.add1(other->value);
		

		return *this;
	}

	template<typename F>
	void foreach(F const& f)
	{
		for (auto cur = head; cur != nullptr; cur = cur->next)
			f(cur->value);
	}




};
#endif