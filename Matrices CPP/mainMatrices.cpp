// Matrices CPP.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//



#include <iostream>
#include "CFichier.h"
#include "CException.h"
#include "CMatrices.h"
#include "COperations.h"

using namespace std;


int main(int argc, char* argv[])
{
    /*char test[] = "M1.txt";
    CMatrices<double> mattest;
    mattest = Cfichier::FICLireMatrice(test);
    mattest.MATAfficherMatrice();
    Cfichier::FICLireMatrice(test);
    cout << "Hello World!\n";
    system("pause");*/
    unsigned int uiBoucleLire;
    for (uiBoucleLire = 0; uiBoucleLire < argc - 1; uiBoucleLire++) {
        try {
            CFichier::FICLireMatrice(argv[uiBoucleLire]);
        }
        catch (CException CEXCException) {
            if(CEXCException.EXCLireErreur == EXCCheminNul){
                cout << "Le chemin du fichier" + argv[uiBoucleLire] + " est nul !\n";
                return 1;
            }
				
            if(CEXCException.EXCLireErreur == EXCParserPointeurNul){
                cout << "Erreur pointeur parser sur le fichier" + argv[uiBoucleLire] + "!\n";
                return 1;
            }
            if(CEXCException.EXCLireErreur == EXCDimLigneNeg){
                cout << "La dimension de la ligne est négative sur le fichier" + argv[uiBoucleLire] + "!\n";
                return 1;
            }
            if(CEXCException.EXCLireErreur == EXCDimColonneNeg){
                cout << "La dimension de la colonne est négative sur le fichier" + argv[uiBoucleLire] + "!\n";
                return 1;
            }
        }
    }
}
