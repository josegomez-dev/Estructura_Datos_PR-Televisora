#ifndef NODOCANAL_H
#define NODOCANAL_H

#include "NodoAnuncioContratado.h"

#include <string>

using namespace std;

class NodoCanal
{
private:
	unsigned int codigoCanal;
	string nombreCanal;
	string telefono;
	double montoMinimo;
	unsigned int tTransmicionMinima;
	unsigned int tTransmicionMaxima;
	double costoPorMinuto;

	NodoAnuncioContratado *sub;

	NodoCanal *ant;
	NodoCanal *sig;
public:
	NodoCanal(unsigned int);
	NodoCanal(unsigned int, string, string, double, int, int, double);

	unsigned int getCodigoCanal(void);
	void setCodigoCanal(unsigned int);

	string getNombreCanal(void);
	void setNombreCanal(string);

	string getTelefono(void);
	void setTelefono(string);

	double getMontoMinimo(void);
	void setMontoMinimo(double);

	unsigned int getTTransmicionMinima(void);
	void setTTransmicionMinima(unsigned int);

	unsigned int getTTransmicionMaxima(void);
	void setTTransmicionMaxima(unsigned int);

	double getCostoPorMinuto(void);
	void setCostoPorMinuto(double);

	NodoCanal * getAnt(void);
	void setAnt(NodoCanal *);

	NodoCanal * getSig(void);
	void setSig(NodoCanal *);

	NodoAnuncioContratado * getSub(void);
	void setSub(NodoAnuncioContratado *);

	string toString(void);

};

#endif // NODOCANAL_H