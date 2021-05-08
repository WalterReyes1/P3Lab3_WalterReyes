#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <stdio.h>  // Para sscanf
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int opcion = 0;
int menu();
char* ejercicio1(char*,int);
char** ejercicio2(int,int,int);
void freeMatriz(char**&, int);
int main() {

	while(opcion != 4) {
		switch(opcion=menu()) {
			case 1: {
				char cadena[1000];
				int t = 0;
				do {
					cout<<"Ingrese el tamaño de la cadena: ";
					cin>>t;
				} while(t <0 || t>1000);
				char* a = new char[t];
				for(int i = 0; i < t; i++) {
					cout<<"Ingrese caracter: ";
					cin>>cadena[i];
					a[i]=cadena[i];
				}
				char* b =ejercicio1(a,t);
				delete b;
				break;
			}
			case 2: {
				int filas =0;
				int columnas=0;
				int k = 0;
				cout<<"Ingrese filas: ";
				cin>>filas;
				cout<<"Ingrese Columnas: ";
				cin>>columnas;
				cout<<"Ingrese bombas: ";
				cin>>k;
				char** a = ejercicio2(filas,columnas,k);
				freeMatriz(a,filas);
				delete a;
				break;
			}
			case 3: {

				break;
			}
			case 4: {
				cout<<"Salir"<<endl;
				break;
			}
		}//fin switch

	}// fin while menu
	return 0;
}

int menu() {
	while(true) {
		cout<<"Bienvenido "<<endl;
		cout<<"1.Ejercicio 1"<<endl;
		cout<<"2.Ejercicio 2"<<endl;
		cout<<"3.Ejercicio 3"<<endl;
		cout<<"4.Salir"<<endl;
		cout<<"Eliga una opcion: ";
		cin>>opcion;
		if(opcion >0 && opcion <5) {
			return opcion;
		}

	}
}

char* ejercicio1(char* a,int size) {

	cout<<endl;
	int valor_actual = 0;
	int f = 0;
	string aux;
	for(int i = 0; i<size; i++) {
		int cont = 0;
		if( (a[i]- '0')>0 &&  (a[i]- '0')<=9) {
			int cant = a[i]- '0';
			cont = i+1;
			if(i==0) {
				aux+=a[i];
			}
			 

				while(((a[cont]-'0')>0) && ((a[cont]-'0')<=9) && i==0) {
					aux+=a[cont];
					cont++;
				}

				f= atoi(aux.c_str());
				for(int j = 0; j<f; j++) {
					cout<<a[cont]<<" ";
				}
				aux="";
				if(((a[i]-'0')>0) && ((a[i]-'0')<=9) && ((a[cont]-'0')<0) && ((a[cont]-'0')>9)) {
					aux= a[i];
					f= atoi(aux.c_str());
				for(int j = 0; j<f; j++) {
					cout<<a[cont]<<" ";
				}
				cout<<endl;
			}
		}
	}
	cout<<f<<endl;
	return a;
}


char** ejercicio2(int fila,int columna,int k) {

	char** retval = new char* [fila];
	for(int i = 0; i<fila; i++) {
		retval[i]=new char[columna];
	}

	for(int i = 0; i<fila; i++) {
		for(int j = 0; j<columna; j++) {
			retval[i][j]='-';
		}
	}

	for(int i = 0; i<fila; i++) {
		for(int j = 0; j<columna; j++) {
			while(k>0) {
				srand(time(NULL));
				int x= 1+rand() % fila-1;
				srand(time(NULL));
				int y=1+rand()% columna-1;
				if(retval[x][y]=='-') {
					retval[x][y]='#';
					k--;
				}
			}
		}
	}

	for(int i = 0; i<fila; i++) {
		cout<<"| ";
		for(int j = 0; j<columna; j++) {
			cout<<retval[i][j]<<" ";;
		}
		cout<<" |";
		cout<<endl;
	}
	cout<<endl;
	return retval;
}

void freeMatriz(char**& m,int fila) {
	if(m!=NULL) {
		for(int i = 0; i<fila; i++) {
			if(m[i] != NULL) {
				delete[] m[i];
				m[i]=NULL;
			}
		}
		delete[] m;
		m= NULL;
	}
}