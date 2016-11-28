#include "stdafx.h"
#include "ListaCanales.h"


ListaCanales::ListaCanales()
{
	this->setCabeza(NULL);
	this->setUltimo(NULL);
	this->setLongitud(0);
}

int ListaCanales::getlongitud(void) const
{
	return this->longitud;
}

void ListaCanales::setLongitud(int l)
{
	this->longitud = l;
}

NodoCanal *& ListaCanales::getCabeza(void)
{
	return this->cabeza;
}

void ListaCanales::setCabeza(NodoCanal * cabeza)
{
	this->cabeza = cabeza;
}

NodoCanal *& ListaCanales::getUltimo(void)
{
	return this->ultimo;
}

void ListaCanales::setUltimo(NodoCanal * ultimo)
{
	this->ultimo = ultimo;
}

void ListaCanales::addItem(NodoCanal * c)
{
	NodoCanal * nuevo = c;

	if (this->getCabeza() == NULL) {
		this->setCabeza(nuevo);
		this->getCabeza()->setSig(this->getCabeza());
		this->setUltimo(this->getCabeza());
		this->getCabeza()->setAnt(this->getUltimo());
	}
	else {
		this->getUltimo()->setSig(nuevo);
		nuevo->setSig(this->getCabeza());
		nuevo->setAnt(this->getUltimo());
		this->setUltimo(nuevo);
		this->getCabeza()->setAnt(this->getUltimo());

		longitud++;
	}
}

string ListaCanales::toString_StartToEnd(void) {
	NodoCanal * aux = this->cabeza;
	string s = "";
	if (cabeza != NULL) {
		do {
			s += aux->toString() + "\n";
			aux = aux->getSig();
		} while (aux != this->cabeza);
	}
	else {
		return "*/!*/!*/! No hay datos !/*!/*!/* \n";
	}
	return s;
}

string ListaCanales::toString_EndToStart(void)
{
	NodoCanal * aux = this->ultimo;
	string s = "";
	if (cabeza != NULL) {
		do {
			s += aux->toString() + "\n";
			aux = aux->getAnt();
		} while (aux != this->ultimo);
	}
	else {
		return "*/!*/!*/! No hay datos !/*!/*!/* \n";
	}
	return s;
}


