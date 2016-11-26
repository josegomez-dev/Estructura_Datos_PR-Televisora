#include "stdafx.h"
#include "Canal.h"

long Canal::cantCanales = 0;

Canal::Canal()
{
	this->setId();
}

Canal::Canal(string pnombre, string ptelefono)
{
	this->setId();
	this->setNombre(pnombre);
	this->setTelefono(ptelefono);
}

Canal::Canal(string pnombre, string ptelefono, double pcostoBase, int ptiempoTransMin, int ptiempoTransMax, double pcostoXMinuto)
{
	this->setId();
	this->setNombre(pnombre);
	this->setTelefono(ptelefono);
	this->setCostoBase(pcostoBase);
	this->setTiempoTransMin(ptiempoTransMin);
	this->setTiempoTransMax(ptiempoTransMax);
	this->setCostoXMinuto(pcostoXMinuto);
}

Canal::Canal(double pcostoBase, int ptiempoTransMin, int ptiempoTransMax)
{
	this->setId();
	this->setCostoBase(pcostoBase);
	this->setTiempoTransMin(ptiempoTransMin);
	this->setTiempoTransMax(ptiempoTransMax);
}

void Canal::setId()
{
	this->id = std::to_string(++cantCanales);
}

string Canal::getId()
{
	return this->id;
}

void Canal::setNombre(string pnombre)
{
	this->nombre = pnombre;
}

string Canal::getNombre()
{
	return this->nombre;
}

void Canal::setTelefono(string ptelefono)
{
	this->telefono = ptelefono;
}

string Canal::getTelefono()
{
	return this->telefono;
}

void Canal::setCostoBase(double pcostoBase)
{
	this->costoBase = pcostoBase;
}

double Canal::getCostoBase()
{
	return this->costoBase;
}

void Canal::setTiempoTransMin(int ptiempoTransMin)
{
	this->tiempoTransMin = ptiempoTransMin;
}

int Canal::getTiempoTransMin()
{
	return this->tiempoTransMin;
}

void Canal::setTiempoTransMax(int ptiempoTransMax)
{
	this->tiempoTransMax = ptiempoTransMax;
}

int Canal::getTiempoTransMax()
{
	return this->tiempoTransMax;
}

void Canal::setCostoXMinuto(double pcostoXMinuto)
{
	this->costoXminuto = pcostoXMinuto;
}

double Canal::getCostoXMinuto()
{
	return this->costoXminuto;
}

string Canal::toString(void)
{
	string s =  "ID: " + this->getId() + "\n";
	       s += "NOMBRE: " + this->getNombre() + "\n";
		   s += "TELEFONO" + this->getTelefono() + "\n";
		   s += "COSTO BASE: " + std::to_string(this->getCostoBase()) + "$\n";
		   s += "T MIN TRANSMICION: " + std::to_string(this->getTiempoTransMin()) + "min\n";
		   s += "T MAX TRANSMICION: " + std::to_string(this->getTiempoTransMax()) + "min\n";
		   s += "COSTO POR MINUTO: " + std::to_string(this->getCostoXMinuto()) + "$\n";
	return s;
}
