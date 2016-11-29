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

bool ListaCanales::incluirContrato(unsigned long s, unsigned int codigoC)
{
	NodoCanal * aux = this->retrieveItem(codigoC);

	NodoAnuncioContratado * contrato = new NodoAnuncioContratado(s);
	contrato->setOrigen(this->retrieveAnuncio(s)); 

	if (aux != NULL) {
		if (aux->getSub() == NULL) {
			aux->setSub(contrato);
		}
		else {
			aux->getSub()->setSig(contrato);
		}
	}
	else {
		return false;
	}
	return true;
}

ListaCanales * ListaCanales::actualizarCobros()
{
	NodoCanal * cn = this->getCabeza();
	NodoAnuncioContratado * contrato = cn->getSub();

	if (cn != NULL) {
		do {
			// aux on canales
			if (contrato != NULL) {
				while (contrato != NULL) {
					// sub on contratos
					NodoAnuncio * an = this->retrieveAnuncio(contrato->getCodigoAnuncio());
					
					if (an->getTiempoDuracion() < cn->getTTransmicionMinima()) {
						cout << an->toString() << "Se le cobrara el minimo: " << cn->getMontoMinimo() << "$" << endl;
						contrato->setCostoTotal(cn->getMontoMinimo());
					}
					else if (an->getTiempoDuracion() > cn->getTTransmicionMaxima()) {
						cout << an->toString() << "Se le cobrara el doble del costo por minuto, a los minutos extras: (Monto minimo: " << cn->getMontoMinimo() << " $)" << endl;
						int extras = an->getTiempoDuracion() - cn->getTTransmicionMaxima();
						for (int i = 0; i < extras;i++) { // costo al double por minuto extra
							contrato->setCostoTotal(contrato->getCostoTotal() + (cn->getCostoPorMinuto()*2));
						}
						for (int i = 0; i < (an->getTiempoDuracion() - extras); i++) { // Costo por minuto
							contrato->setCostoTotal(contrato->getCostoTotal() + cn->getCostoPorMinuto());
						}
					}else {
						cout << an->toString() << "Costo por minuto: " << cn->getCostoPorMinuto() << "$" << endl;
						for (int i = 0; i < ((int)an->getTiempoDuracion()/60); i++) { // Costo por minuto
							contrato->setCostoTotal(contrato->getCostoTotal() + cn->getCostoPorMinuto());
						}
					}
					contrato = contrato->getSig();
				}
			}
			cn = cn->getSig();
			contrato = cn->getSub();
		} while (cn != this->getCabeza());
	}
	else {
		return NULL;
	}
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
					s += sub->toString() + "\n";
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


