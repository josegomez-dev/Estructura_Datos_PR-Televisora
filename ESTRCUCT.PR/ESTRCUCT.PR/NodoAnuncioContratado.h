#ifndef NODOANUNCIOCONTRATADO_H
#define NODOANUNCIOCONTRATADO_H

#include <string>

using namespace std;

class NodoAnuncioContratado
{
private:
	unsigned long codigoAnuncio;
	double costoTotal;

	NodoAnuncio *origen;
	NodoAnuncioContratado *sig;
public:
	NodoAnuncioContratado(unsigned long, double c = 0.0);

	unsigned long getCodigoAnuncio(void);
	void setCodigoAnuncio(unsigned long);

	double getCostoTotal(void);
	void setCostoTotal(double);	

	NodoAnuncioContratado *& getSig(void);
	void setSig(NodoAnuncioContratado *);

	NodoAnuncio * getOrigen(void);
	void setOrigen(NodoAnuncio *);

	string toString(void);
};

#endif // NODOANUNCIOCONTRATADO_H