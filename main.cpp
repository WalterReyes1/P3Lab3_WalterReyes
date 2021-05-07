#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int opcion = 0;
int menu();

int main(int argc, char** argv) {
	return 0;
}

int menu() {
	while(true) {
		cout<<"Bienvenido "<<endl;
		cout<<"1.Ejercicio 1"<<endl;
		cout<<"2.Ejercicio 2"<<endl;
		cout<<"3.Ejercicio 3"<<endl;
		cout<<"4.Ejercicio 4"<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"Eliga una opcion: ";
		cin>>opcion;
		if(opcion >0 && opcion <6) {
			return opcion;
		}

	}
}