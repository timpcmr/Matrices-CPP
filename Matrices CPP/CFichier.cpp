#include "CFichier.h"

using namespace std;


/*

CMatrices<double> Cfichier::FICLireMatrice(char* pcChemin)
{
	if (pcChemin == nullptr) {
		throw CException(CheminNul);
	}
	ifstream fichier(pcChemin);
	//Exceptions � rajouter
	unsigned int uiparsedLignes, uiparsedColonnes;

	char* pcLigne = new char[STR_LENGTH];
	char pcToken[STR_LENGTH];

	if (fichier.is_open()) {

		//On r�cup�re le type de donn�es
		fichier.getline(pcLigne, STR_LENGTH);
		pcToken = strtok(pcLigne, '=');
		pcToken = strtok(NULL, '=');
		if (pcToken == nullptr) {
			throw CException(ParserPointeurNul);
		}
		if (strcmp(FICMinuscule(pcToken), "double") == 0){

			//On r�cup�re le nombre de lignes
			fichier.getline(pcLigne, STR_LENGTH);
			pcToken = strtok(pcLigne, '=');
			pcToken = strtok(NULL, '=');
			if (pcToken == nullptr) {
				throw CException(ParserPointeurNul);
			}
			else if (atoi(pcToken) < 0) {
				throw CException(DimLigneNeg);
			}
			uiparsedLignes = (unsigned int)(atoi(pcToken));

			//On r�cup�re le nombre de colonnes
			fichier.getline(pcLigne, STR_LENGTH);
			pcToken = strtok(pcLigne, '=');
			pcToken = strtok(NULL, '=');
			if (pcToken == nullptr) {
				throw CException(ParserPointeurNul);
			}
			else if (atoi(pcToken) < 0) {
				throw CException(DimColonneNeg);
			}
			uiparsedColonnes = (unsigned int)(atoi(pcToken));

			//Instanciation de la matrice de retour aux bonnes dimensions
			CMatrices<double> MATretour(uiparsedLignes, uiparsedColonnes);
			//fetch values to do


		}
		else {
			throw CException(ErrTypeMat);
		}
	}
	else {
		throw CException(FichierNonOuvert);
	}


	return MATretour;
	

}
*/

char * Cfichier::FICMinuscule(char* pcChaine)
{
	unsigned int uiboucle;

	for (uiboucle = 0; pcChaine[uiboucle] != '\0'; uiboucle++) {
		pcChaine[uiboucle] = tolower(pcChaine[uiboucle]);
	}
	return pcChaine;
}

void Cfichier::FICSupp_Tab_Espace(char* pcChaine)
{
	unsigned int uiboucle1, uiboucle2;

	//On supprime soit les tabulations soit les espaces sinon lors du parsage des valeurs de matrices on aura une corruption de donn�es.
	//Dans le cas des valeurs de matrices on a juste une tabulation au debut. On la supprime pour am�liorer le traitement par les flots.
	if (pcChaine[0] == '\t') {
		for (uiboucle1 = 0; pcChaine[uiboucle1] != '\0'; uiboucle1++) {
			if (pcChaine[uiboucle1] == '\t') {
				for (uiboucle2 = uiboucle1; pcChaine[uiboucle2] != '\0'; uiboucle2++) {
					pcChaine[uiboucle2] = pcChaine[uiboucle2 + 1];
				}
			}
		}
	}
	//Traitement des espaces dans le cas ou une tabulation n'est pas en d�but de ligne.
	if (pcChaine[0] == ' ') {
		for (uiboucle1 = 0; pcChaine[uiboucle1] != '\0'; uiboucle1++) {
			if (pcChaine[uiboucle1] == ' ') {
				for (uiboucle2 = uiboucle1; pcChaine[uiboucle2] != '\0'; uiboucle2++) {
					pcChaine[uiboucle2] = pcChaine[uiboucle2 + 1];
				}
			}
		}
	}
	pcChaine[uiboucle1] = '\0';
}
