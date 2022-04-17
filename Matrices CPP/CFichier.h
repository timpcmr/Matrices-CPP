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



class Cfichier {
public:
	//Parseur
	static CMatrices<double> FICLireMatrice(char* pcChemin);
	//Fonctions de handle mauvaise mise en forme
	static char * FICMinuscule(char* pcChaine);
	static void FICSupp_Tab_Espace(char* pcChaine);
};

#endif