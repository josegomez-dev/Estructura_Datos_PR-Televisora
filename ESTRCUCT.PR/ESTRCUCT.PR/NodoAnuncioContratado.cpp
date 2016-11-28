#include "stdafx.h"
#include "NodoAnuncioContratado.h"


NodoAnuncioContratado::NodoAnuncioContratado(unsigned long codigoA, double c)
{
	this->setCodigoAnuncio(codigoA);
	this->setCostoTotal(c);
	this->setSig(NULL);
	this->setOrigen(NULL);
}

unsigned long NodoAnuncioContratado::getCodigoAnuncio(void)
{
	return this->codigoAnuncio;
}

void NodoAnuncioContratado::setCodigoAnuncio(unsigned long codigoA)
{
	this->codigoAnuncio = codigoA;
}

double NodoAnuncioContratado::getCostoTotal(void)
{
	return this->costoTotal;
}

void NodoAnuncioContratado::setCostoTotal(double ct)
{
	this->costoTotal = ct;
}

NodoAnuncioContratado *& NodoAnuncioContratado::getSig(void)
{
	return this->sig;
}

void NodoAnuncioContratado::setSig(NodoAnuncioContratado * s)
{
	this->sig = s;
}

NodoAnuncioContratado *& NodoAnuncioContratado::getOrigen(void)
{
	return this->sig;
}

void NodoAnuncioContratado::setOrigen(NodoAnuncioContratado * o)
{
	this->sig = o;
}

string NodoAnuncioContratado::toString(void)
{
	string s = "#Anuncio: " + std::to_string(this->getCodigoAnuncio()) + " (seg)\n";
		   s += "Costo Total: " + std::to_string(this->getCostoTotal()) + "\n";
	return s;
}
