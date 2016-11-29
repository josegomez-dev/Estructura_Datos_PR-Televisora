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

ListaAnuncios *& ListaCanales::getLstAnuncios(void)
{
	return this->lstAnuncios;
}

void ListaCanales::setLstAnuncios(ListaAnuncios * la)
{
	this->lstAnuncios = la;
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

NodoCanal * ListaCanales::retrieveItem(unsigned int codigoC)
{
	NodoCanal * aux = this->getCabeza();

	bool find = false;

	if (this->getCabeza() != NULL) {
		do {
			if (aux->getCodigoCanal() == codigoC) {
				return aux;
			}
			aux = aux->getSig();
		} while (aux != this->cabeza && !(find));
		if (!find) {
			return NULL;
		}
	}
	else {
		return NULL;
	}

}

NodoAnuncio * ListaCanales::retrieveAnuncio(unsigned long s)
{
	NodoAnuncio * aux = this->getLstAnuncios()->getCabeza();

	if (this->getLstAnuncios()->getCabeza() != NULL) {
		do {
			if (aux->getCodigoAnuncio() == s) {
				return aux;
			}
			aux = aux->getSig();
		} while (aux != this->getLstAnuncios()->getCabeza());
	}
	else {
		return NULL;
	}
	return NULL;
}

bool ListaCanales::incluirContrato(unsigned long s, unsigned int codigoC, ListaAnuncios * lst)
{
	NodoCanal * aux = this->retrieveItem(codigoC);

	NodoAnuncioContratado * contrato = new NodoAnuncioContratado(s);
	contrato->setOrigen(this->retrieveAnuncio(s)); // BUSCAR DE ANUNCIOS

	if (aux != NULL) {

		if (aux->getSub() == NULL) {
			aux->setSub(contrato);
		}
		else {
			aux->getSub()->setSig(contrato);
			//aux->setSub(contrato);
		}

	}
	else {
		return false;
	}

	return true;
}

string ListaCanales::toString_StartToEnd(void) {
	NodoCanal * aux = this->getCabeza();
	string s = "";
	if (aux != NULL) {
		do {
			s += aux->toString() + "\n";
			aux = aux->getSig();
		} while (aux != this->getCabeza());
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
	if (aux != NULL) {
		do {
			s += aux->toString() + "\n";
			aux = aux->getAnt();
		} while (aux != this->getUltimo());
	}
	else {
		return "*/!*/!*/! No hay datos !/*!/*!/* \n";
	}
	return s;
}

string ListaCanales::toString_Super(void)
{
	NodoCanal * aux = this->getCabeza();
	NodoAnuncioContratado * sub = aux->getSub();

	string s = "";
	if (aux != NULL) {
		do {
			s += aux->toString() + "\n";
			if (sub != NULL) {
				while (sub != NULL) {
					s += sub->toString();
					sub = sub->getSig();
				}
			}
			aux = aux->getSig();
			sub = aux->getSub();
			
		} while (aux != this->getCabeza());
	}
	else {
		return "*/!*/!*/! No hay datos !/*!/*!/* \n";
	}
	return s;
}


