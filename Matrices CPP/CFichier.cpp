#include "CFichier.h"
#pragma warning(disable : 4996)

using namespace std;

CMatrices<double> Cfichier::FICLireMatrice(char* pcChemin)
{
	if (pcChemin == nullptr) {
		throw CException(EXCCheminNul);
	}
	ifstream fichier(pcChemin);
	//Exceptions à rajouter
	unsigned int uiparsedLignes, uiparsedColonnes, uiboucle1, uiboucle2;

	if (fichier.is_open()) {

		char* pcLigne = new char[STR_LENGTH];
		char* pcToken = new char[STR_LENGTH];

		//On récupère le type de données
		do
		{
			fichier.getline(pcLigne, STR_LENGTH);
			FICSupp_Tab_Espace(pcLigne);
		} while (pcLigne[0] == '\n' || pcLigne[0] == '\r' || pcLigne[0] == '\0');
		pcToken = strtok(pcLigne, "=");
		pcToken = strtok(NULL, "=");
		if (pcToken == nullptr) {
			delete[] pcLigne;
			delete[] pcToken;
			throw CException(EXCParserPointeurNul);
		}
		//Traitement d'éventuels espaces dans le type de fichiers
		//FICSupp_Tab_Espace(pcToken);

		if (strcmp(FICMinuscule(pcToken), "double") == 0) {

			//On récupère le nombre de lignes
			do
			{
				fichier.getline(pcLigne, STR_LENGTH);
				FICSupp_Tab_Espace(pcLigne);
			} while (pcLigne[0] == '\n' || pcLigne[0] == '\r' || pcLigne[0] == '\0');
			pcToken = strtok(pcLigne, "=");
			pcToken = strtok(NULL, "=");
			if (pcToken == nullptr) {
				delete[] pcLigne;
				delete[] pcToken;
				throw CException(EXCParserPointeurNul);
			}
			else if (atoi(pcToken) < 0) {
				delete[] pcLigne;
				delete[] pcToken;
				throw CException(EXCDimLigneNeg);
			}
			uiparsedLignes = (unsigned int)(atoi(pcToken));

			//On récupère le nombre de colonnes
			do
			{
				fichier.getline(pcLigne, STR_LENGTH);
				FICSupp_Tab_Espace(pcLigne);
			} while (pcLigne[0] == '\n' || pcLigne[0] == '\r' || pcLigne[0] == '\0');
			pcToken = strtok(pcLigne, "=");
			pcToken = strtok(NULL, "=");
			if (pcToken == nullptr) {
				delete[] pcLigne;
				delete[] pcToken;
				throw CException(EXCParserPointeurNul);
			}
			else if (atoi(pcToken) < 0) {
				delete[] pcLigne;
				delete[] pcToken;
				throw CException(EXCDimColonneNeg);
			}
			uiparsedColonnes = (unsigned int)(atoi(pcToken));

			//Instanciation de la matrice de retour aux bonnes dimensions

			CMatrices<double> MATretour(uiparsedLignes, uiparsedColonnes);

			//On saute la ligne Matrice=[
			do
			{
				fichier.getline(pcLigne, STR_LENGTH);
				FICSupp_Tab_Espace(pcLigne);
			} while (pcLigne[0] == '\n' || pcLigne[0] == '\r' || pcLigne[0] == '\0');

			//Et on commence à récupérer les valeurs
			

			for (uiboucle1 = 0; uiboucle1 < uiparsedLignes; uiboucle1++) {
				//On cherche la première/suivante ligne de valeurs non nulle

				do {
					fichier.getline(pcLigne, STR_LENGTH);
				} while (pcLigne[0] == '\n' || pcLigne[0] == '\r' || pcLigne[0] == '\0');
				
				//On teste si il y a un tab en début de ligne, si oui on le supprime et ceux 
				//dans la ligne, sinon, on ne supprimme pas les espaces entre les valeurs
				
				if (pcLigne[0] == '\t') {
					FICSupp_Tab_Espace(pcLigne);
				}
								
				pcToken = strtok(pcLigne, " ");
				if (pcToken[0] == ']') {
					delete[] pcLigne;
					delete[] pcToken;
					throw CException(EXCLigneDimSup);
				}
				MATretour.MATModifierCase(uiboucle1, 0, atof(pcToken));
				for (uiboucle2 = 1; uiboucle2 < uiparsedColonnes; uiboucle2++) {
					pcToken = strtok(NULL, " ");
					if (pcToken == nullptr) {
						delete[] pcLigne;
						delete[] pcToken;
						throw CException(EXCColonneDimSup);
					}
					MATretour.MATModifierCase(uiboucle1, uiboucle2, atof(pcToken));
				}
				pcToken = strtok(NULL, " ");
				if (pcToken != nullptr) {
					delete[] pcLigne;
					delete[] pcToken;
					throw CException(EXCColonneDimInf);
				}

			}

			do
			{
				fichier.getline(pcLigne, STR_LENGTH);
				FICSupp_Tab_Espace(pcLigne);
			} while (pcLigne[0] == '\n' || pcLigne[0] == '\r' || pcLigne[0] == '\0');

			if (pcLigne[0] != ']') {
				delete[] pcLigne;
				delete[] pcToken;
				throw CException(EXCLigneDimInf);
			}

			return MATretour;
		}
		else {
			delete[] pcLigne;
			delete[] pcToken;
			throw CException(EXCErrTypeMat);
		}
		delete[] pcLigne;
		delete[] pcToken;
	}
	else {
		throw CException(EXCFichierNonOuvert);
	}
	//Cas impossible mais nécéssaire à la compilation

	CMatrices<double> MATretour;
	return MATretour;
	

}


char * Cfichier::FICMinuscule(char* pcChaine)
{
	if (pcChaine == nullptr) {
		throw CException(EXCTokenNulMinuscule);
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
		throw CException(EXCTokenNulSuppEspace);
	}
	unsigned int uiboucle1 = 0, uiboucle2;

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
	else {
		for (uiboucle1 = 0; pcChaine[uiboucle1] != '\0'; uiboucle1++) {
			if (pcChaine[uiboucle1] == ' ') {
				for (uiboucle2 = uiboucle1; pcChaine[uiboucle2] != '\0'; uiboucle2++) {
					pcChaine[uiboucle2] = pcChaine[uiboucle2 + 1];
				}
				uiboucle1--;
			}
		}
	}
	pcChaine[uiboucle1] = '\0';
}
