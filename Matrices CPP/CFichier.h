#ifndef FIC
#define FIC
#include "CMatrices.h"
#include "CException.h"
#include <iostream>
#include <cstring>
#include <cstdio>
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
#define EXCTokenNulMinuscule 7
#define EXCTokenNulSuppEspace 8
#define EXCColonneDimSup 9
#define EXCColonneDimInf 10
#define EXCLigneDimSup 11
#define EXCLigneDimInf 12

class Cfichier {
public:
	//Parseur

	/******************************************************************************************************
	**** Entrées : char* pcChemin																	   ****
	**** Nécessite :																		  	       ****
	**** Sorties :	CMatrice MATretour																   ****
	**** Entraîne : Renvoie la matrice du fichier texte dont le chemin pcChemin est passé en paramètre ****
	******************************************************************************************************/
	static CMatrices<double> FICLireFichier(char* pcChemin);

	//Fonctions de handle mauvaise mise en forme

	/***********************************************************************************************************************
	**** Entrées : char* pcChaine																					    ****
	**** Nécessite :																		  							****
	**** Sorties :	char* pcChaine																						****
	**** Entraîne : Renvoie la chaine pcChaine passée en paramètre et dont toutes les lettres sont passées en minuscule ****
	***********************************************************************************************************************/
	static char * FICMinuscule(char* pcChaine);

	/******************************************************************************************************************
	**** Entrées : char* pcChaine																				   ****
	**** Nécessite :																		  					   ****
	**** Sorties :																								   ****
	**** Entraîne : Supprime les tabulations ou les espaces d'une chaine de caractère pcChaine passée en paramètre ****
	******************************************************************************************************************/
	static void FICSupp_Tab_Espace(char* pcChaine);
};

#endif