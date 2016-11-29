
#include "stdafx.h"
#include "ListaAnuncios.h"

ListaAnuncios::ListaAnuncios()
{
	this->setCabeza(NULL);
}

NodoAnuncio *& ListaAnuncios::getCabeza(void)
{
	return this->cabeza;
}

void ListaAnuncios::setCabeza(NodoAnuncio * cab)
{
	this->cabeza = cab;
}

int ListaAnuncios::getlongitud(void) const
{
	return this->longitud;
}

void ListaAnuncios::setLongitud(int l)
{
	this->longitud = l;
}

void ListaAnuncios::addItem(NodoAnuncio * item)
{
	NodoAnuncio * aux = item;

	if (aux == NULL) {
		this->setCabeza(aux);
	}
	else {
		aux->setSig(cabeza);
		this->setCabeza(aux);

		longitud++;
	}
}

void ListaAnuncios::addItemASC(NodoAnuncio * item)
{
	NodoAnuncio * aux = item;

	if (cabeza == NULL) {
		cabeza = aux;
	}
	else {
		if (aux->getCodigoAnuncio() < cabeza->getCodigoAnuncio()) {
			aux->setSig(cabeza);
			cabeza = aux;
		}
		else {
			NodoAnuncio *ant = NULL;
			NodoAnuncio *act = NULL;

			ant = cabeza;
			act = cabeza->getSig();

			while ((act != NULL) && (act->getCodigoAnuncio() < aux->getCodigoAnuncio())) {
				ant = ant->getSig();
				act = act->getSig();
			}
			aux->setSig(act);
			ant->setSig(aux);
		}
	}
	longitud++;
}

int ListaAnuncios::searchItem(NodoAnuncio * item)
{
	NodoAnuncio *aux;
	int pos;

	for (aux = cabeza, pos = 0; aux != NULL; aux = aux->getSig(), pos++) {
		if (aux->getCodigoAnuncio() == item->getCodigoAnuncio()) {
			return pos;
		}
	}
	if (aux == 0) {
		pos = -1;
	}

	return pos;
}

NodoAnuncio * ListaAnuncios::retrieveItem(unsigned long codigo)
{
	NodoAnuncio *aux;
	int pos;
	
	for (aux = cabeza, pos = 0; aux != NULL; aux = aux->getSig(), pos++) {
		if (aux->getCodigoAnuncio() == codigo) {
			return aux;
		}
	}

	return nullptr;
}

bool ListaAnuncios::deleteItem(NodoAnuncio * item)
{
	NodoAnuncio *ant, *aux;

	int i, pos = searchItem(item);

	if (pos == -1) {
		return false;
	}
	else {
		for (i = 0, ant = 0, aux = cabeza; i<pos; i++) {
			ant = aux;
			aux = aux->getSig();
		}
		if (ant != 0) {
			ant->setSig(aux->getSig());
		}
		else {
			cabeza = aux->getSig();
		}
		delete aux;
		longitud--;

		return true;
	}

	return false;
}

string ListaAnuncios::toString(void)
{
	NodoAnuncio * aux = this->getCabeza();
	string s = "";
	if (aux != NULL) {
		while (aux != NULL) {
			s += aux->toString() + "\n";
			aux = aux->getSig();
		}
	}
	else {
		return "*/!*/!*/! No hay datos !/*!/*!/* \n"; 
	}
	return s;
}
