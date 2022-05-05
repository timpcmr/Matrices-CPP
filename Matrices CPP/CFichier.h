#ifndef FIC
#define FIC
#include "CMatrices.h"
#include "CException.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cctype>

#define STR_LENGTH 1024
#define MAX_LOOPING 1000

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
#define EXCBoucleInfinie 21
#define EXCLigneNulle 22


class Cfichier {
public:
	//Parseur

	/******************************************************************************************************
	**** Entr�es : char* pcChemin																	   ****
	**** N�cessite :																		  	       ****
	**** Sorties :	CMatrice MATretour																   ****
	**** Entra�ne : Renvoie la matrice du fichier texte dont le chemin pcChemin est pass� en param�tre ****
	******************************************************************************************************/
	static CMatrices<double> FICLireFichier(const char* pcChemin);

	/***********************************************************************************************************************
	**** Entr�es : char* pcChaine, ifstream& fichier																    ****
	**** N�cessite : Un fichier ouvert et une chaine non nulle								  							****
	**** Sorties :																										****
	**** Entra�ne : Renvoie la chaine pcChaine pass�e en param�tre et dont tous les tabh et espaces sont supprim�s	    ****
	***********************************************************************************************************************/
	static void FICLigneSuivante(char* pcLigne, ifstream& fichier);

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
	**** Entra�ne : Supprime un charact�re c d'une chaine de caract�re pcChaine pass�e en param�tre				   ****
	******************************************************************************************************************/
	static void FICSupp_char(char* pcChaine, const char cCharactere);
};

#endif