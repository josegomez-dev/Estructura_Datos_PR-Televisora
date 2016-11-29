// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

#include <iostream>
#include <string>
#include "ListaAnuncios.h"
#include "ListaCanales.h"

#include <conio.h> // Just for WaitKey() routine
#include <windows.h>

using namespace std;

void mostrarMenu(void);
int leerOpcion(void);
bool ejecutarAccion(int);
void desplegarInformacionListas(void);

void crearContrato(void);
NodoAnuncio * crearAnuncio(void);
NodoCanal *& crearCanal(void);
void fillBaseData(void);