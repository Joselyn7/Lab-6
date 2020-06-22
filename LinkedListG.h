#include <iostream>
#include "NodeG.h"
using namespace std;
template <class T>
class LinkedList
{
	int size;
	Node<T> *head; //mi cabecita
	public:
		LinkedList();
		void insert(T valor);
		Node<T> *begin();
		Node<T> *end();
		void remove(T valor);
		void print();
		void printI();
		~LinkedList();
};
template<typename T>
LinkedList<T>::LinkedList()
{
	size=0;
	head=NULL;
}
template<typename T>
void LinkedList<T>::insert(T valor)
{
	Node<T> *nodo_n=new Node<T>(valor);
	Node<T> *prim=this->head;
	Node<T> *secu;
	while((prim!=NULL)&&(prim->elem<valor))
	{
		secu=prim;
		prim=prim->next;
	}
	if(head==prim){
		head=nodo_n;
	}
	else
		secu->next=nodo_n;	
	nodo_n->next=prim;
	size++;
}
template<typename T>
Node<T>* LinkedList<T>::begin()
{
    Node<T> *pos1=this->head;
	//cout<<pos1->elem<<endl;	
	return pos1;//->elem;
}
template<typename T>
Node<T>* LinkedList<T>::end()
{
    Node<T> *pos2=this->head;
    while(pos2->next!=NULL)
        pos2=pos2->next;
    pos2=pos2->next;	
    return pos2;//->elem;
}
template<typename T>
void LinkedList<T>::remove(T valor)
{	
	if(this->head==NULL)
	{
		cout<<"Lista Vacia"<<endl;
		return;
	}
	if(this->head->elem==valor)
	{
		Node<T> *eliminar=this->head;
		this->head=this->head->next;
		delete(eliminar);
		cout<<"Se elimino"<<endl;
		size--;
		return;
	}
	Node<T> *ptr=this->head;
	while(ptr->next!=NULL && ptr->next->elem!=valor)
		ptr=ptr->next;
	if(ptr->next==NULL)	
	{
		cout<<"No se encontro"<<endl;
		return;		
	}
	Node<T> *eliminar=ptr->next;
	ptr->next=ptr->next->next;
	size--;
	delete(eliminar);
	cout<<"Se elimino"<<endl;
}
template<typename T>
void LinkedList<T>::print()
{
	cout<<"Elementos:"<<endl;
	Node<T> *ptr=this->head;
	while(ptr!=NULL)
	{
		cout<<ptr->elem<<"->";
		ptr=ptr->next;
	}
	cout<<"NULL"<<endl;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Node<T> *ptr=this->head;
	Node<T> *next1=NULL;
	while(ptr!=NULL)
	{
		next1=ptr->next;
		delete(ptr);
		ptr=next1;
	}
}

template <class T>
class Iterador
{
	Node<T> *ptr_n;
	public:
		void operator=(Node<T>*Nodo);
		void operator ++();
		bool operator !=(Node<T>*Nodo);
		T operator *();
};
template<typename T>
void Iterador<T>::operator=(Node<T> *Nodo)
{
	ptr_n=Nodo;
}
template<typename T>
void Iterador<T>::operator ++()
{
	ptr_n=ptr_n->next;
}
template<typename T>
bool Iterador<T>::operator!=(Node<T>*Nodo)
{
	return ptr_n != Nodo;
}
template<typename T>
T Iterador<T>::operator *()
{
	return ptr_n->elem;
}

