#ifndef NODOANUNCIO_H
#define NODOANUNCIO_H


#include "stdafx.h"
#include <string>

using namespace std;

class NodoAnuncio
{
private:
	unsigned static long cantAnuncios;
	unsigned long codigoAnuncio;
	unsigned int tiempoDuracion;
	unsigned long codigoEmpresa;
	string nombreEmpresa;

	NodoAnuncio *sig;
public:
	NodoAnuncio(unsigned long);
	NodoAnuncio(unsigned long, string);

	void setCodigoAnuncio(void);
	unsigned long getCodigoAnuncio(void);
	void setTiempoDuracion(unsigned int);
	unsigned int getTiempoDuracion(void); 
	void setCodigoEmpresa(unsigned long);
	unsigned long getCodigoEmpreas(void);
	void setNombreEmpresa(string);
	string getNombreEmpresa(void);
	
	NodoAnuncio * getSig(void);
	void setSig(NodoAnuncio *);

	string toString(void);
};

#endif // NODOANUNCIO_H