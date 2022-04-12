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
