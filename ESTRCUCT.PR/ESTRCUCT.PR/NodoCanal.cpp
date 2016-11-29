#include "stdafx.h"
#include "NodoCanal.h"


NodoCanal::NodoCanal(unsigned int codigoC)
{
	this->setAnt(NULL);
	this->setSig(NULL);
	this->setSub(NULL);

	this->setCodigoCanal(codigoC);
	this->setNombreCanal("");
	this->setTelefono("");
	this->setMontoMinimo(0.0);
	this->setTTransmicionMinima(0);
	this->setTTransmicionMaxima(0);
	this->setCostoPorMinuto(0);
}

NodoCanal::NodoCanal(unsigned int codigoC, string n, string tel, double mm, int tmin, int tmax, double c)
{
	this->setAnt(NULL);
	this->setSig(NULL);
	this->setSub(NULL);

	this->setCodigoCanal(codigoC);
	this->setNombreCanal(n);
	this->setTelefono(tel);
	this->setMontoMinimo(mm);
	this->setTTransmicionMinima(tmin);
	this->setTTransmicionMaxima(tmax);
	this->setCostoPorMinuto(c);
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

NodoCanal * NodoCanal::getAnt(void)
{
	return this->ant;
}

void NodoCanal::setAnt(NodoCanal *a)
{
	this->ant = a;
}

NodoCanal * NodoCanal::getSig(void)
{
	return this->sig;
}

void NodoCanal::setSig(NodoCanal *s)
{
	this->sig = s;
}


NodoAnuncioContratado * NodoCanal::getSub(void)
{
	return this->sub;
}

void NodoCanal::setSub(NodoAnuncioContratado *sl)
{
	this->sub = sl;
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

