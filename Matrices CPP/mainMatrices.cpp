
#pragma warning(disable : 6385)


#include <iostream>
#include <cstdlib>
#include "CFichier.h"
#include "CException.h"
#include "CMatrices.h"

using namespace std;

/******************************************************************************************************************
**** Entrées : argc : int, argv : char **					    											   ****
**** Nécessite : Arguments passés en paramètre											  					   ****
**** Sorties :	int : Code de sortie de programme															   ****
**** Entraîne :  L'exécution de l'algorithme principal du programme                                            ****
******************************************************************************************************************/
int main(int argc, char* argv[])
{
    //Si au moins un chemin de fichier est donne
    if (argc > 1) {

        //PARSAGE DES FICHIERS

        int iBoucleLire; //int et pas unsigned int car sinon impossible de faire comparaison avec argc dans le for 
        CMatrices<double>* pMATmatrices = new CMatrices<double>[argc - 1];

        for (iBoucleLire = 0; iBoucleLire < argc - 1; iBoucleLire++) {
            try {
                pMATmatrices[iBoucleLire] = Cfichier::FICLireFichier(argv[iBoucleLire + 1]);
            }
            catch (CException EXCException) {

                //Gestion des exceptions du parseur

                cout << "Erreur parseur : " << endl;

                if (EXCException.EXCLireErreur() == EXCCheminNul) {
                    cout << "Le chemin du fichier " << argv[iBoucleLire + 1] << " est nul !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCParserPointeurNul) {
                    cout << "Erreur pointeur sur le fichier " << argv[iBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCDimLigneNeg) {
                    cout << "Le nombre de lignes indique est negatif ou nul sur le fichier " << argv[iBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "Le nombre de colonnes indique est negatif sur le fichier " << argv[iBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCErrTypeMat) {
                    cout << "Le type de valeurs donnees pour la matrice " << argv[iBoucleLire + 1] << " n'est pas de type double !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCFichierNonOuvert) {
                    cout << "Le chemin donne pour le fichier " << argv[iBoucleLire + 1] << " n'est pas valide !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "La dimension de la colonne est négative sur le fichier " << argv[iBoucleLire + 1] << "!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCColonneDimInf) {
                    cout << "Le nombre de colonnes indique sur le fichier " << argv[iBoucleLire + 1] << " est inferieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCColonneDimSup) {
                    cout << "Le nombre de colonnes indique sur le fichier " << argv[iBoucleLire + 1] << " est superieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCLigneDimInf) {
                    cout << "Le nombre de lignes indique sur le fichier " << argv[iBoucleLire + 1] << " est inferieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCLigneDimSup) {
                    cout << "Le nombre de lignes indique sur le fichier " << argv[iBoucleLire + 1] << " est superieur au nombre de valeurs presentes!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCTokenNulMinuscule) {
                    cout << "Erreur interne : L'argument passe a la fonction FICMinuscule est nul lors de l'utilisation du fichier  " << argv[iBoucleLire + 1] << " ! (Aucun type de donnees specifie)" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCTokenNulSuppEspace) {
                    cout << "Erreur interne : L'argument passe a la fonction FICSupp_Tab_Espace est nul lors de l'utilisation du fichier  " << argv[iBoucleLire + 1] << " !" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCBoucleInfinie) {
                    cout << "Erreur interne : Boucle infinie declenchee : Fichier incomplet ou manque du charactere ']' en fin de fichier!" << endl;
                }
                else if (EXCException.EXCLireErreur() == EXCLigneNulle) {
                    cout << "Erreur interne : Aucune ligne passee en parametre de FICLigneSuivante !" << endl;
                }

                //Gestion fuites memoires
                delete[] pMATmatrices;
                return 1;
            }
        }



        //SAISIE DE LA VALEUR C

        //Passage par un char* puis atof pour empecher la possibilité de saisir des valeurs non-numeriques
		//Car atof renvoie 0 si la valeur saisie n'est pas un nombre. Néanmoins il est possible de saisir un mélange de lettres et de chiffres, 
        //seuls les chiffres seront extraits si ils sont placés avant les lettres.
		
        double dC;
        char pcC[STR_LENGTH];
        cout << "Saisissez une valeur et appuyez sur entree :" << endl;
        cin >> pcC;
		dC = atof(pcC);
		
        if (dC == 0) {
            cout << "La valeur entree est 0 ou non numerique, les operations sont impossibles a realiser. " << endl;
            while (dC == 0) {
                cout << "Veuillez entrer une valeur valide pour les operations :" << endl;
                cin >> pcC;
				dC = atof(pcC);
            }
        }
        
		

        //CALCULS AVEC LA VALEUR C SAISIE
        //MULTIPLICATION

        cout << "----- RESULTATS DE LA MULTIPLICATION PAR " << dC << " -----" << endl;

        CMatrices<double> matMatriceTampon;
        int iBoucle; //int et pas unsigned int car sinon impossible de faire comparaison avec argc dans le for 
        for (iBoucle = 0; iBoucle < argc - 1; iBoucle++) {
            try {
                cout << "Matrice " << iBoucle + 1 << " :" << endl;
                matMatriceTampon = dC * pMATmatrices[iBoucle];
                matMatriceTampon.MATAfficherMatrice();
                cout << endl;
            }
            catch (CException EXCCexception) {

                //Gestion erreurs (que la surcharge operateur *)

                cout << "Erreur lors de la multiplication par la constante C :" << endl;

                if (EXCCexception.EXCLireErreur() == EXCMATDimColonneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de colonnes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de lignes negatif !" << endl;
                }

                //Gestion memoire
                delete[] pMATmatrices;
                return 1;
            }
        }

        //DIVISION

        cout << "----- RESULTATS DE LA DIVISION PAR " << dC << " -----" << endl;

        for (iBoucle = 0; iBoucle < argc - 1; iBoucle++) {
            try {
                cout << "Matrice " << iBoucle + 1 << " :" << endl;
                matMatriceTampon = pMATmatrices[iBoucle] / dC;
                matMatriceTampon.MATAfficherMatrice();
                cout << endl;
            }
            catch (CException EXCCexception) {

                //Gestion erreurs (que la fonction OPEDivision)

                cout << "Erreur lors de la multiplication par la constante C :" << endl;

                if (EXCCexception.EXCLireErreur() == EXCDimColonneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de colonnes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCDimLigneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de lignes negatif !" << endl;
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

        for (iBoucle = 0; iBoucle < argc - 1; iBoucle++) {
            try {
                matSomme = matSomme + pMATmatrices[iBoucle];
            }
            catch (CException EXCCexception) {

                //Gestion erreurs (que la surcharge operateur +)

                cout << "Erreur lors de l'addition des differentes matrices :" << endl;

                if (EXCCexception.EXCLireErreur() == EXCMATDimColonneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de colonnes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de lignes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigne) {
                    cout << "La matrice du fichier " << argv[1] << " a un nombre de lignes different de la matrice du fichier " << argv[iBoucle + 1] << "!" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimColonne) {
                    cout << "La matrice du fichier " << argv[1] << " a un nombre de colonnes different de la matrice du fichier " << argv[iBoucle + 1] << "!" << endl;
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

        //OPERATION ALTERNANCE ADDITION SOUSTRACTION

        CMatrices<double> matResultatAlternance(pMATmatrices[0].MATLireNbLignes(), pMATmatrices[0].MATLireNbColonnes());

        for (iBoucle = 0; iBoucle < argc - 1; iBoucle++) {
            try {
                if (iBoucle % 2 == 0) {
                    matResultatAlternance = matResultatAlternance + pMATmatrices[iBoucle];
                }
                else {
                    matResultatAlternance = matResultatAlternance - pMATmatrices[iBoucle];
                }
            }
            catch (CException EXCCexception) {

                //Gestion erreurs (que la surcharge operateur + et -)

                cout << "Erreur lors de l'addition des differentes matrices :" << endl;

                if (EXCCexception.EXCLireErreur() == EXCMATDimColonneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de colonnes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigneNeg) {
                    cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de lignes negatif !" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigne) {
                    cout << "La matrice du fichier " << argv[1] << " a un nombre de lignes different de la matrice du fichier " << argv[iBoucle + 1] << "!" << endl;
                }
                else if (EXCCexception.EXCLireErreur() == EXCMATDimLigne) {
                    cout << "La matrice du fichier " << argv[1] << " a un nombre de colonnes different de la matrice du fichier " << argv[iBoucle + 1] << "!" << endl;
                }

                //Gestion memoire
                delete[] pMATmatrices;
                return 1;
            }
        }

        // Affichage du resultat final
        cout << "----- RESULTAT DE L'OPERATION ALTERNATIVE SUR LES MATRICES -----" << endl;
        matResultatAlternance.MATAfficherMatrice();
        cout << endl;

        //PRODUIT DES MATRICES

        CMatrices<double> matProduit(pMATmatrices[0]);
        if (argc > 2) {
            for (iBoucle = 1; iBoucle < argc - 1; iBoucle++) {
                try {
                    matProduit = matProduit * pMATmatrices[iBoucle];
                }
                catch (CException EXCCexception) {

                    //Gestion erreurs (que la surcharge operateur +)

                    cout << "Erreur lors de l'addition des differentes matrices :" << endl;

                    if (EXCCexception.EXCLireErreur() == EXCMATDimColonneNeg) {
                        cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de colonnes negatif !" << endl;
                    }
                    else if (EXCCexception.EXCLireErreur() == EXCMATDimLigneNeg) {
                        cout << "La matrice du fichier " << argv[iBoucle + 1] << " a un nombre de lignes negatif !" << endl;
                    }
                    else if (EXCCexception.EXCLireErreur() == EXCDimMatMult) {
                        cout << "La matrice du fichier " << argv[iBoucle - 1] << " a des dimensions incompatibles avec la matrice du fichier " << argv[iBoucle] << " pour les faire se multiplier !" << endl;
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


        delete[] pMATmatrices;
        return 0;
    }
    else {
        cout << "Aucun fichier passe en argument !" << endl;
        return 1;
    }

}
