#ifndef FIC
#define FIC
#include "CMatrices.h"
#include <iostream>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cctype>

class Cfichier {
public:
	CMatrices<double> FICLireMatrice(char* pcChemin);
	//Fonctions de handle mauvaise mise en forme

};

#endif