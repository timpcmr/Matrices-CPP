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

    if (argc > 1) {

        unsigned int uiBoucleLire;
        CMatrices<double>* pMATmatrices = new CMatrices<double>[argc - 1];

        for (uiBoucleLire = 0; uiBoucleLire < argc - 1; uiBoucleLire++) {
            try {
                pMATmatrices[uiBoucleLire] = Cfichier::FICLireMatrice(argv[uiBoucleLire]);
            }
            catch (CException CEXCException) {

                //Gestion des exceptions du parseur

                cout << "Erreur parseur : " << endl;

                if (CEXCException.EXCLireErreur() == EXCCheminNul) {
                    cout << "Le chemin du fichier " << argv[uiBoucleLire] << " est nul !" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCParserPointeurNul) {
                    cout << "Erreur pointeur sur le fichier " << argv[uiBoucleLire] << "!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCDimLigneNeg) {
                    cout << "Le nombre de lignes indique est negatif sur le fichier " << argv[uiBoucleLire] << "!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "Le nombre de colonnes indique est negatif sur le fichier " << argv[uiBoucleLire] << "!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCErrTypeMat) {
                    cout << "Le type de valeurs donnees pour la matrice " << argv[uiBoucleLire] << " n'est pas de type double !" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCFichierNonOuvert) {
                    cout << "Le chemin donne pour le fichier " << argv[uiBoucleLire] << " n'est pas valide !" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "La dimension de la colonne est négative sur le fichier " << argv[uiBoucleLire] << "!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCColonneDimInf) {
                    cout << "Le nombre de colonnes indique sur le fichier " << argv[uiBoucleLire] << " est inferieur au nombre de valeurs presentes!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCColonneDimSup) {
                    cout << "Le nombre de colonnes indique sur le fichier " << argv[uiBoucleLire] << " est superieur au nombre de valeurs presentes!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCLigneDimInf) {
                    cout << "Le nombre de lignes indique sur le fichier " << argv[uiBoucleLire] << " est inferieur au nombre de valeurs presentes!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCLigneDimSup) {
                    cout << "Le nombre de lignes indique sur le fichier " << argv[uiBoucleLire] << " est superieur au nombre de valeurs presentes!" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCTokenNulMinuscule) {
                    cout << "Erreur interne : L'argument passe a la fonction FICMinuscule est nul lors de l'utilisation du fichier  " << argv[uiBoucleLire] << " !" << endl;
                }
                else if (CEXCException.EXCLireErreur() == EXCTokenNulSuppEspace) {
                    cout << "Erreur interne : L'argument passe a la fonction FICSupp_Tab_Espace est nul lors de l'utilisation du fichier  " << argv[uiBoucleLire] << " !" << endl;
                }

                //Gestion fuites memoires
                delete[] pMATmatrices;
                return 1;
            }
        }
    }
    else {
        cout << "Aucun fichier passe en argument !" << endl;
        return 1;
    }
}
