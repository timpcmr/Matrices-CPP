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

        //PARSAGE DES FICHIERS

        unsigned int uiBoucleLire;
        CMatrices<double>* pMATmatrices = new CMatrices<double>[argc - 1];

        for (uiBoucleLire = 0; uiBoucleLire < argc - 1; uiBoucleLire++) {
            try {
                pMATmatrices[uiBoucleLire] = Cfichier::FICLireMatrice(argv[uiBoucleLire + 1]);
            }
            catch (CException EXCException) {

                //Gestion des exceptions du parseur

                cout << "Erreur parseur : " << endl;

                if (EXCException.EXCLireErreur() == EXCCheminNul) {
                    cout << "Le chemin du fichier " << argv[uiBoucleLire + 1] << " est nul !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCParserPointeurNul) {
                    cout << "Erreur pointeur sur le fichier " << argv[uiBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCDimLigneNeg) {
                    cout << "Le nombre de lignes indique est negatif sur le fichier " << argv[uiBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "Le nombre de colonnes indique est negatif sur le fichier " << argv[uiBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCErrTypeMat) {
                    cout << "Le type de valeurs donnees pour la matrice " << argv[uiBoucleLire + 1] << " n'est pas de type double !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCFichierNonOuvert) {
                    cout << "Le chemin donne pour le fichier " << argv[uiBoucleLire + 1] << " n'est pas valide !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "La dimension de la colonne est négative sur le fichier " << argv[uiBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCColonneDimInf) {
                    cout << "Le nombre de colonnes indique sur le fichier " << argv[uiBoucleLire + 1] << " est inferieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCColonneDimSup) {
                    cout << "Le nombre de colonnes indique sur le fichier " << argv[uiBoucleLire + 1] << " est superieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCLigneDimInf) {
                    cout << "Le nombre de lignes indique sur le fichier " << argv[uiBoucleLire + 1] << " est inferieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCLigneDimSup) {
                    cout << "Le nombre de lignes indique sur le fichier " << argv[uiBoucleLire + 1] << " est superieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCTokenNulMinuscule) {
                    cout << "Erreur interne : L'argument passe a la fonction FICMinuscule est nul lors de l'utilisation du fichier  " << argv[uiBoucleLire + 1] << " !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCTokenNulSuppEspace) {
                    cout << "Erreur interne : L'argument passe a la fonction FICSupp_Tab_Espace est nul lors de l'utilisation du fichier  " << argv[uiBoucleLire + 1] << " !" << endl;
                }

                //Gestion fuites memoires
                delete[] pMATmatrices;
                return 1;
            }
        }



        //SAISIE DE LA VALEUR C

        double dC;

        cout << "Saisissez une valeur et appuyez sur entree :" << endl;
        cin >> dC;

        //CALCULS AVEC LA VALEUR C SAISIE
        //MULTIPLICATION

        cout << "----- RESULTATS DE LA MULTIPLICATION PAR " << dC << " -----" << endl;

        CMatrices<double> matMatriceTampon;
        unsigned int uiBoucle;
        for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++) {
            try {
                cout << "Matrice " << uiBoucle << " :" << endl;
                matMatriceTampon = pMATmatrices[uiBoucle] * dC;
                matMatriceTampon.MATAfficherMatrice();
                cout << endl;
            }
            catch (CException EXCCexception) {

                //Gestion erreurs (que la surcharge operateur *)

                cout << "Erreur lors de la multiplication par la constante C :" << endl;

                if (EXCCexception.EXCLireErreur() == EXCMATDimColonneNeg) {
                    cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de colonnes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigneNeg) {
                    cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de lignes negatif !" << endl;
                }

                //Gestion memoire
                delete[] pMATmatrices;
                return 1;
            }
        }

        //DIVISION

        if (dC == 0) {
            cout << "La valeur entree est 0, la division est impossible. " << endl;
            while (dC == 0) {
                cout << "Veuillez entrer une valeur valide pour la division :" << endl;
                cin >> dC;
            }
        }

        cout << "----- RESULTATS DE LA DIVISION PAR " << dC << " -----" << endl;

        for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++) {
            try {
                cout << "Matrice " << uiBoucle << " :" << endl;
                matMatriceTampon = Coperations<double>::OPEDivision(pMATmatrices[uiBoucle], dC);
                matMatriceTampon.MATAfficherMatrice();
                cout << endl;
            }
            catch (CException EXCCexception) {

                //Gestion erreurs (que la fonction OPEDivision)

                cout << "Erreur lors de la multiplication par la constante C :" << endl;

                if (EXCCexception.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de colonnes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCDimLigneNeg) {
                    cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de lignes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCDivZero) {
                    cout << "La valeur entree est 0, la division est impossible. " << endl;
                }
                //Gestion memoire
                delete[] pMATmatrices;
                return 1;
            }
        }

        //ADDITION DE TOUTES LES MATRICES

        CMatrices<double> matSomme(pMATmatrices[0].MATLireNbLignes(), pMATmatrices[0].MATLireNbColonnes());

        for (uiBoucle = 0; uiBoucle < argc - 1; uiBoucle++) {
            try {
                matSomme = matSomme + pMATmatrices[uiBoucle];
            }
            catch (CException EXCCexception) {

                //Gestion erreurs (que la surcharge operateur +)

                cout << "Erreur lors de l'addition des differentes matrices :" << endl;

                if (EXCCexception.EXCLireErreur() == EXCMATDimColonneNeg) {
                    cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de colonnes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigneNeg) {
                    cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de lignes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigne) {
                    cout << "La matrice du fichier " << argv[0] << " a un nombre de lignes different de la matrice du fichier " << argv[uiBoucle] << "!" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigne) {
                    cout << "La matrice du fichier " << argv[0] << " a un nombre de colonnes different de la matrice du fichier " << argv[uiBoucle] << "!" << endl;
                }

                //Gestion memoire
                delete[] pMATmatrices;
                return 1;
            }
        }

        //Affichage du resultat final
        cout << "----- RESULTAT DE L'ADDITION DES MATRICES -----" << endl;
        matSomme.MATAfficherMatrice();
        cout << endl;

        //PRODUIT DES MATRICES

        CMatrices<double> matProduit(pMATmatrices[0]);
        if (argc > 2) {
            for (uiBoucle = 1; uiBoucle < argc - 1; uiBoucle++) {
                try {
                    matProduit = matProduit * pMATmatrices[uiBoucle];
                }
                catch (CException EXCCexception) {

                    //Gestion erreurs (que la surcharge operateur +)

                    cout << "Erreur lors de l'addition des differentes matrices :" << endl;

                    if (EXCCexception.EXCLireErreur() == EXCMATDimColonneNeg) {
                        cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de colonnes negatif !" << endl;
                    }
                    else if (EXCCexception.EXCLireErreur() == EXCMATDimLigneNeg) {
                        cout << "La matrice du fichier " << argv[uiboucle + 1] << " a un nombre de lignes negatif !" << endl;
                    }
                    else if (EXCCexception.EXCLireErreur() == EXCDimMatMult) {
                        cout << "La matrice du fichier " << argv[uiBoucle - 1] << " a des dimensions incompatibles avec la matrice du fichier " << argv[uiBoucle] << " pour les faire se multiplier !" << endl;
                    }

                    //Gestion memoire
                    delete[] pMATmatrices;
                    return 1;
                }
            }
        }
        //Affichage du resultat final
        cout << "----- RESULTAT DE LA MULTIPLICATION DES MATRICES -----" << endl;
        matProduit.MATAfficherMatrice();
        cout << endl;
    }
    else {
        cout << "Aucun fichier passe en argument !" << endl;
        return 1;
    }
    return 0;
}
