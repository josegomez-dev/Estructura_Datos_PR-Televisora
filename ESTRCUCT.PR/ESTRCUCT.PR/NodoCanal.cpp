#include "stdafx.h"
#include "NodoCanal.h"


NodoCanal::NodoCanal()
{
	this->setAnt(NULL);
	this->setSig(NULL);
	this->setSubLst(NULL);
}

unsigned int NodoCanal::getCodigoCanal(void)
{
	return this->codigoCanal;
}

void NodoCanal::setCodigoCanal(unsigned int codigoC)
{
	this->codigoCanal = codigoC;
}

string NodoCanal::getNombreCanal(void)
{
	return this->nombreCanal;
}

void NodoCanal::setNombreCanal(string n)
{
	this->nombreCanal = n;
}

string NodoCanal::getTelefono(void)
{
	return this->telefono;
}

void NodoCanal::setTelefono(string t)
{
	this->telefono = t;
}

double NodoCanal::getMontoMinimo(void)
{
	return this->montoMinimo;
}

void NodoCanal::setMontoMinimo(double mm)
{
	this->montoMinimo = mm;
}

unsigned int NodoCanal::getTTransmicionMinima(void)
{
	return this->tTransmicionMinima;
}

void NodoCanal::setTTransmicionMinima(unsigned int ttmin)
{
	this->tTransmicionMinima = ttmin;
}

unsigned int NodoCanal::getTTransmicionMaxima(void)
{
	return this->tTransmicionMaxima;
}

void NodoCanal::setTTransmicionMaxima(unsigned int ttmin)
{
	this->tTransmicionMaxima = ttmin;
}

double NodoCanal::getCostoPorMinuto(void)
{
	return this->costoPorMinuto;
}

void NodoCanal::setCostoPorMinuto(double cm)
{
	this->costoPorMinuto = cm;
}

NodoCanal *& NodoCanal::getAnt(void)
{
	return this->ant;
}

void NodoCanal::setAnt(NodoCanal *a)
{
	this->ant = a;
}

NodoCanal *& NodoCanal::getSig(void)
{
	return this->sig;
}

void NodoCanal::setSig(NodoCanal *s)
{
	this->sig = s;
}


NodoAnuncioContratado *& NodoCanal::getSubLst(void)
{
	return this->subLst;
}

void NodoCanal::setSubLst(NodoAnuncioContratado *sl)
{
	this->subLst = sl;
}

string NodoCanal::toString(void)
{
	string s = "Canal: " + this->getNombreCanal() + " [#" + std::to_string(this->getCodigoCanal()) + "]\n";
		   s += "Telefono: " + this->getTelefono() + "\n";
		   s += "Monto minimo: " + std::to_string(this->getMontoMinimo()) + "$\n";
		   s += "Tiempo de Transmicion min: " + std::to_string(this->getTTransmicionMinima()) + "(seg)\n";
		   s += "Tiempo de Transmicion max: " + std::to_string(this->getTTransmicionMaxima()) + "(seg)\n";
		   s += "Costo por minuto: " + std::to_string(this->getCostoPorMinuto()) + "$\n";
	return s;
}

