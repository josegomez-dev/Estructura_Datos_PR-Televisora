// STRUCTS.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include "windows.h"

#include "ListaAnuncios.h"
#include "Anuncio.h"
#include "ListaAnunciosContratados.h"
#include "AnuncioContratado.h"
#include "Canal.h"
#include "ListaCanales.h"

using namespace std;

ListaAnuncios *& chargeAnuncios(void);
ListaAnunciosContratados *& chargeAnunciosContratados(void);
ListaCanales *& chargeCanales(void);

void showNameList(string);

void showMenu(void);
int readOption(void);
bool runAction(int opc);

int main()
{
	showNameList("ANUNCIOS CONTRATADOS");
	ListaAnunciosContratados * lstAnunciosContratados = new ListaAnunciosContratados();	lstAnunciosContratados = chargeAnunciosContratados();
	cout << ((lstAnunciosContratados->toString() != "EMPTY") ? lstAnunciosContratados->toString() : "Lista Vacia") << endl;
	
	showNameList("ANUNCIOS");
	ListaAnuncios * lstAnuncios = new ListaAnuncios(); lstAnuncios = chargeAnuncios();
	cout << ((lstAnuncios->toString() != "EMPTY") ? lstAnuncios->toString() : "Lista Vacia") << endl;
	
	showNameList("CANALES TV");
	ListaCanales * lstCanales = new ListaCanales(); lstCanales = chargeCanales();
	cout << ((lstCanales->toString_StartToEnd() != "EMPTY") ? lstCanales->toString_StartToEnd() : "Lista Vacia") << endl;
	
	bool noSalir = true;
	int opc;
	do {
		showMenu();
		opc = readOption();
		noSalir = runAction(opc);
	} while (noSalir);

	cin.get();
    return 0;
}

void showMenu(void) {
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
}
int readOption(void) {
	return int();
}

bool runAction(int opc {

	bool noSalir = true;
		
	if (opc >= 2 && opc <=7) {
		return noSalir;
	}

	switch (opc) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << " */!*/! Opcion Invalida !/*!/* " << endl;
			break;
	}

	return noSalir;
}


ListaAnuncios *& chargeAnuncios(void) {
	ListaAnuncios * lst = new ListaAnuncios();
	Anuncio * a1 = new Anuncio("Somos Unidos", "001", 5);
	lst->addItemToBegin(a1);
	Anuncio * a2 = new Anuncio("PepsiMan", "002", 1);
	lst->addItemToBegin(a2);
	Anuncio * a3 = new Anuncio("Bonanza", "003", 4);
	lst->addItemToBegin(a3);
	return lst;
}

ListaAnunciosContratados *& chargeAnunciosContratados(void) {
	ListaAnunciosContratados * lst = new ListaAnunciosContratados();
	AnuncioContratado * a1 = new AnuncioContratado();
	lst->addItemToBegin(a1);
	AnuncioContratado * a2 = new AnuncioContratado(2500.26);
	lst->addItemToBegin(a2);
	AnuncioContratado * a3 = new AnuncioContratado(1500.0);
	lst->addItemToBegin(a3);
	return lst;
}

ListaCanales *& chargeCanales(void) {
	//Canal(nombre, telefono, precioBase, tiempoTransmisionMinimo, tiempoTransmicionMaximo, costoPorMinuto)
	ListaCanales * lst = new ListaCanales();
	Canal * a1 = new Canal("PUBLISOFT", "24378945", 1000.0, 1, 10, 10.0);
	lst->addItem(a1);
	Canal * a2 = new Canal("GREENCODE", "62402974", 500.0, 1, 3, 5.0);
	lst->addItem(a2);
	Canal * a3 = new Canal("CODE SOLUTIONS", "62402974", 10000.0, 10, 50, 23.0);
	lst->addItem(a3);
	return lst;
}

void showNameList(string s) {
	system("Color 0F");
	Sleep(1000);
	cout << "----------------------------------------------" << endl;
	cout << " */!*/!*/! " << s << " !/*!/*!/*!/* " << endl;
	cout << "----------------------------------------------" << endl;
	system("Color 0A");
}