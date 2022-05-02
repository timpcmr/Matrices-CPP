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
	**** Entr�es : char* pcChemin																	   ****
	**** N�cessite :																		  	       ****
	**** Sorties :	CMatrice MATretour																   ****
	**** Entra�ne : Renvoie la matrice du fichier texte dont le chemin pcChemin est pass� en param�tre ****
	******************************************************************************************************/
	static CMatrices<double> FICLireFichier(char* pcChemin);

	//Fonctions de handle mauvaise mise en forme

	/***********************************************************************************************************************
	**** Entr�es : char* pcChaine																					    ****
	**** N�cessite :																		  							****
	**** Sorties :	char* pcChaine																						****
	**** Entra�ne : Renvoie la chaine pcChaine pass�e en param�tre et dont toutes les lettres sont pass�es en minuscule ****
	***********************************************************************************************************************/
	static char * FICMinuscule(char* pcChaine);

	/******************************************************************************************************************
	**** Entr�es : char* pcChaine																				   ****
	**** N�cessite :																		  					   ****
	**** Sorties :																								   ****
	**** Entra�ne : Supprime les tabulations ou les espaces d'une chaine de caract�re pcChaine pass�e en param�tre ****
	******************************************************************************************************************/
	static void FICSupp_Tab_Espace(char* pcChaine);
};

#endif