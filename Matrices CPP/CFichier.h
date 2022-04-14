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

#define EXCCheminNul 1
#define EXCFichierNonOuvert 2
#define EXCErrTypeMat 3
#define EXCDimLigneNeg 4
#define EXCDimColonneNeg 5
#define EXCParserPointeurNul 6


class Cfichier {
public:
	static CMatrices<double> FICLireMatrice(char* pcChemin);
	//Fonctions de handle mauvaise mise en forme
	static char * FICMinuscule(char* pcChaine);
	static void FICSupp_Tab_Espace(char* pcChaine);
};

#endif