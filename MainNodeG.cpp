#include <iostream>
#include "LinkedListG.h"
using namespace std;
int main()
{
	LinkedList<int> obj1;
	Iterador <int> it;
	cout<<"<<<<LISTA SIMPLEMENTE ENLAZADA>>>>"<<endl;
	int opc, valor;
	do
	{
		cout<<"1)Insertar\n2)Remover\n3)Mostrar\n4)MostrarI\n5)Salir\nOpc:";
		cin>>opc;
		if(opc==1)
		{
			cout<<"Valor:";
			cin>>valor;
			obj1.insert(valor);
		}
		else if(opc==2)
		{
			cout<<"Valor:";
			cin>>valor;
			obj1.remove(valor);
		}
		else if(opc==3)
		{
			obj1.print();
		}
		else if(opc==4)
		{
			cout<<"Elementos:"<<endl;
		    for (it=obj1.begin(); it!=obj1.end(); ++it) 
		    { 
		        cout<<*it<<" "; 
		    } 
		    cout<<endl;
		}
		
	}
	while(opc!=5);
}
