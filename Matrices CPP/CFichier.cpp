#include "CFichier.h"

using namespace std;


/*

CMatrices<double> Cfichier::FICLireMatrice(char* pcChemin)
{
	if (pcChemin == nullptr) {
		throw CException(EXCCheminNul);
	}
	ifstream fichier(pcChemin);
	//Exceptions � rajouter
	unsigned int uiparsedLignes, uiparsedColonnes, uiboucle1, uiboucle2;

	char* pcLigne = new char[STR_LENGTH];
	char* pcToken = new char[STR_LENGTH];

	if (fichier.is_open()) {

		//On r�cup�re le type de donn�es
		fichier.getline(pcLigne, STR_LENGTH);
		pcToken = strtok(pcLigne, "=");
		pcToken = strtok(NULL, "=");
		if (pcToken == nullptr) {
			throw CException(EXCParserPointeurNul);
		}
		if (strcmp(FICMinuscule(pcToken), "double") == 0){

			//On r�cup�re le nombre de lignes
			fichier.getline(pcLigne, STR_LENGTH);
			pcToken = strtok(pcLigne, "=");
			pcToken = strtok(NULL, "=");
			if (pcToken == nullptr) {
				throw CException(EXCParserPointeurNul);
			}
			else if (atoi(pcToken) < 0) {
				throw CException(EXCDimLigneNeg);
			}
			uiparsedLignes = (unsigned int)(atoi(pcToken));

			//On r�cup�re le nombre de colonnes
			fichier.getline(pcLigne, STR_LENGTH);
			pcToken = strtok(pcLigne, "=");
			pcToken = strtok(NULL, "=");
			if (pcToken == nullptr) {
				throw CException(EXCParserPointeurNul);
			}
			else if (atoi(pcToken) < 0) {
				throw CException(EXCDimColonneNeg);
			}
			uiparsedColonnes = (unsigned int)(atoi(pcToken));

			//Instanciation de la matrice de retour aux bonnes dimensions
			//CMatrices<double> MATretour = CMatrices<double>(uiparsedLignes, uiparsedColonnes);
			CMatrices<double> MATretour(uiparsedLignes, uiparsedColonnes);

			//On saute la ligne Matrice=[
			fichier.getline(pcLigne, STR_LENGTH);

			//Et on commence � r�cup�rer les valeurs
			for (uiboucle1 = 0; uiboucle1 < uiparsedLignes; uiboucle1++) {
				fichier.getline(pcLigne, STR_LENGTH);
				FICSupp_Tab_Espace(pcLigne);
				pcToken = strtok(pcLigne, " ");
				MATretour.MATModifierCase(uiboucle1, 0, atof(pcToken));
				for (uiboucle2 = 1; uiboucle2 < uiparsedColonnes; uiboucle2++) {
					pcToken = strtok(NULL, " ");
					MATretour.MATModifierCase(uiboucle1, uiboucle2, atof(pcToken));
				}
			}
			return MATretour;
		}
		else {
			throw CException(EXCErrTypeMat);
		}
	}
	else {
		throw CException(EXCFichierNonOuvert);
	}
	//Cas impossible mais n�c�ssaire � la compilation

	CMatrices<double> MATRetour;
	return MATRetour;
	

}
*/

char * Cfichier::FICMinuscule(char* pcChaine)
{
	if (pcChaine == nullptr) {
		throw CException(EXCCheminNul);
	}
	unsigned int uiboucle;

	for (uiboucle = 0; pcChaine[uiboucle] != '\0'; uiboucle++) {
		pcChaine[uiboucle] = tolower(pcChaine[uiboucle]);
	}
	return pcChaine;
}

void Cfichier::FICSupp_Tab_Espace(char* pcChaine)
{
	if (pcChaine == nullptr) {
		throw CException(EXCCheminNul);
	}
	unsigned int uiboucle1 = 0, uiboucle2;

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
