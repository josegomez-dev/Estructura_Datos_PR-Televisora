#include "stdafx.h"
#include "ListaCanales.h"


ListaCanales::ListaCanales()
{
}

int ListaCanales::getlongitud(void) const
{
	return this->longitud;
}

void ListaCanales::setLongitud(int l)
{
	this->longitud = l;
}

NodoCanal * ListaCanales::getCabeza(void) const
{
	return this->cabeza;
}

void ListaCanales::setCabeza(NodoCanal * cabeza)
{
	this->cabeza = cabeza;
}

NodoCanal * ListaCanales::getUltimo(void) const
{
	return this->ultimo;
}

void ListaCanales::setUltimo(NodoCanal * ultimo)
{
	this->ultimo = ultimo;
}

void ListaCanales::addItem(Canal *& c)
{
	NodoCanal * nuevo;
	nuevo = new NodoCanal(c);

	if (cabeza == NULL) {
		cabeza = nuevo;
		cabeza->setSig(cabeza);
		ultimo = cabeza;
		cabeza->setAnt(ultimo);
	}
	else {
		ultimo->setSig(nuevo);
		nuevo->setSig(cabeza);
		nuevo->setAnt(ultimo);
		ultimo = nuevo;
		cabeza->setAnt(ultimo);

		longitud++;
	}
}

string ListaCanales::toString_StartToEnd(void) {
	NodoCanal * aux = this->cabeza;
	string s = "";
	if (cabeza != NULL) {
		do {
			s += aux->getInfo()->toString() + "\n";
			aux = aux->getSig();
		} while (aux != this->cabeza);
	}
	else {
		return "EMPTY"; // LISTA VACIA
	}
	return s;
}

string ListaCanales::toString_EndToStart(void)
{
	NodoCanal * aux = this->ultimo;
	string s = "";
	if (cabeza != NULL) {
		do {
			s += aux->getInfo()->toString() + "\n";
			aux = aux->getAnt();
		} while (aux != this->ultimo);
	}
	else {
		return "EMPTY"; // LISTA VACIA
	}
	return s;
}