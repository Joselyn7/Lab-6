#include <iostream>
using namespace std;
template <class T>
class Node
{
	T elem;
	Node<T> *next; //mi colita
	public:	
		template<class U>friend class LinkedList; //clase LinkedList accederá a mis privates de clase Node
		template<class V>friend class Iterador;
		Node(T valor);
};
template<typename T>
Node<T>::Node(T valor)
{
	elem=valor;
	next=NULL;
}
