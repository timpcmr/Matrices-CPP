// Matrices CPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//



#include <iostream>
#include "CFichier.h"
#include "CException.h"
#include "CMatrices.h"
#include "COperations.h"

using namespace std;


int main(int argc, char *argv[])
{
    char test[] = "M1.txt";
    /*CMatrices<double> mattest;
    mattest = Cfichier::FICLireMatrice(test);
    mattest.MATAfficherMatrice();*/
    Cfichier::FICLireMatrice(test);
    cout << "Hello World!\n";
    system("pause");
}
