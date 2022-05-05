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
	**** Entrées : char* pcChemin																	   ****
	**** Nécessite :																		  	       ****
	**** Sorties :	CMatrice MATretour																   ****
	**** Entraîne : Renvoie la matrice du fichier texte dont le chemin pcChemin est passé en paramètre ****
	******************************************************************************************************/
	static CMatrices<double> FICLireFichier(const char* pcChemin);

	/***********************************************************************************************************************
	**** Entrées : char* pcChaine, ifstream& fichier																    ****
	**** Nécessite : Un fichier ouvert et une chaine non nulle								  							****
	**** Sorties :																										****
	**** Entraîne : Renvoie la chaine pcChaine passée en paramètre et dont tous les tabh et espaces sont supprimés	    ****
	***********************************************************************************************************************/
	static void FICLigneSuivante(char* pcLigne, ifstream& fichier);

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
	**** Entraîne : Supprime un charactère c d'une chaine de caractère pcChaine passée en paramètre				   ****
	******************************************************************************************************************/
	static void FICSupp_char(char* pcChaine, const char cCharactere);
};

#endif