#include "CFichier.h"

using namespace std;




CMatrices<double> Cfichier::FICLireMatrice(char* pcChemin)
{
	if (pcChemin == nullptr) {
		throw CException(CheminNul);
	}
	ifstream fichier(pcChemin);
	//Exceptions à rajouter
	CMatrices<double> MATretour;
	char* pcLigne = new char[STR_LENGTH];
	char* pcToken = new char[STR_LENGTH];

	if (fichier.is_open()) {
		fichier.getline(pcLigne, STR_LENGTH);
		pcToken = strtok(pcLigne, '=');
		pcToken = strtok(NULL, '=');
		if (strcmp(FICMinuscule(pcToken), "double") == 0){

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

	//On supprime soit les tabulations soit les espaces sinon lors du parsage des valeurs de matrices on aura une corruption de données.
	//Dans le cas des valeurs de matrices on a juste une tabulation au debut. On la supprime pour améliorer le traitement par les flots.
	if (pcChaine[0] == '\t') {
		for (uiboucle1 = 0; pcChaine[uiboucle1] != '\0'; uiboucle1++) {
			if (pcChaine[uiboucle1] == '\t') {
				for (uiboucle2 = uiboucle1; pcChaine[uiboucle2] != '\0'; uiboucle2++) {
					pcChaine[uiboucle2] = pcChaine[uiboucle2 + 1];
				}
			}
		}
	}
	//Traitement des espaces dans le cas ou une tabulation n'est pas en début de ligne.
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
