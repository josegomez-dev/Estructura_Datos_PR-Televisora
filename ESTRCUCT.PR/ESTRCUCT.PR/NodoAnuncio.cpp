#include "stdafx.h"
#include "NodoAnuncio.h"

unsigned long NodoAnuncio::cantAnuncios = 0;


NodoAnuncio::NodoAnuncio(unsigned long codigoE)
{
	this->setSig(NULL);

	this->setCodigoAnuncio();
	this->setTiempoDuracion(0);
	this->setCodigoEmpresa(codigoE);
	this->setNombreEmpresa("");
}

NodoAnuncio::NodoAnuncio(unsigned long codigoE, string ne)
{
	this->setSig(NULL);

	this->setCodigoAnuncio();
	this->setTiempoDuracion(0);
	this->setCodigoEmpresa(codigoE);
	this->setNombreEmpresa(ne);
}

void NodoAnuncio::setCodigoAnuncio(void)
{
	this->codigoAnuncio = ++cantAnuncios;
}

unsigned long NodoAnuncio::getCodigoAnuncio(void)
{
	return this->codigoAnuncio;
}

void NodoAnuncio::setTiempoDuracion(unsigned int td)
{
	this->tiempoDuracion = td;
}

unsigned int NodoAnuncio::getTiempoDuracion(void)
{
	return this->tiempoDuracion;
}

void NodoAnuncio::setCodigoEmpresa(unsigned long codigoE)
{
	this->codigoEmpresa = codigoE;
}

unsigned long NodoAnuncio::getCodigoEmpreas(void)
{
	return this->codigoEmpresa;
}

void NodoAnuncio::setNombreEmpresa(string nombreE)
{
	this->nombreEmpresa = nombreE;
}

string NodoAnuncio::getNombreEmpresa(void)
{
	return this->nombreEmpresa;
}

NodoAnuncio * NodoAnuncio::getSig(void)
{
	return this->sig;
}

void NodoAnuncio::setSig(NodoAnuncio *n)
{
	this->sig = n;
}

string NodoAnuncio::toString(void)
{
	string s = "Anuncio: [#" + std::to_string(this->getCodigoAnuncio()) + "] | Duracion: " + std::to_string(this->getTiempoDuracion()) + " (seg)\n"; 
		   s += "Empresa: " + this->getNombreEmpresa() + " [#" + std::to_string(this->getCodigoEmpreas()) + "]\n";
	return s;
}