#ifndef FIC
#define FIC
#include "CMatrices.h"
#include "CException.h"
#include <iostream>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cctype>

#define STR_LENGTH 256

#define CheminNul 1
#define FichierNonOuvert 2
#define ErrTypeMat 3

class Cfichier {
public:
	CMatrices<double> FICLireMatrice(char* pcChemin);
	//Fonctions de handle mauvaise mise en forme
	char * FICMinuscule(char* pcChaine);
};

#endif