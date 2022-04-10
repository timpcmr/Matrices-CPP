#include "CMatrices.h"

/***********************************************************************************
**** Entrées :                         											****
**** Nécessite :																****
**** Sorties : CMatrices														****
**** Entraîne : La construction d'un objet CMatrices 1x1						****
************************************************************************************/
template<class MType>
inline CMatrices<MType>::CMatrices()
{
	uiNbLignes = 1;
	uiNbColonnes = 1;
	//Initialisation de la matrice
	pMTPContenu = new MType * [uiNbLignes];
	pMTPContenu[0] = new MType[uiNbColonnes];

	//On affecte une valeur par défaut selon le type à la seule case de cette matrice 1x1
	**pMTPContenu= MType();
}


/************************************************************************************
**** Entrées : uiParam1, uiParam2 : unsigned int                      	         ****
**** Nécessite : Le nombre de lignes et de colonnes de la matrice à construire   ****
**** Sorties : CMatrices														 ****
**** Entraîne : La construction d'un objet CMatrices uiParam1 * uiParam2		 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices(unsigned int uiParam1, unsigned int uiParam2)
{
	unsigned int uiboucle1, uiboucle2;

	uiNbLignes = uiParam1;
	uiNbColonnes = uiParam2;

	//Création de la matrice avec n lignes
	pMTPContenu = new MType * [uiNbLignes];

	//Ajout de uiNbColonnes cases dans chaque ligne et affectation à la valeur par défaut
	for (uiboucle1 = 0; uiboucle1 < uiNbLignes; uiboucle1++) {
		pMTPContenu[uiboucle1] = new MType[uiNbColonnes];
		for (uiboucle2 = 0; uiboucle2 < uiNbColonnes; uiboucle2++) {
			pMTPContenu[uiboucle1][uiboucle2] = MType();
		}
	}
}

/************************************************************************************
**** Entrées : MATparam : référence vers un objet CMatrices						 ****
**** Nécessite : Un objet CMatrices à recopier								     ****
**** Sorties : CMatrices														 ****
**** Entraîne : La construction d'un objet CMatrices copié de MATparam  		 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices(CMatrices<MType> &MATparam)
{
	unsigned int uiboucle1, uiboucle2;
	uiNbColonnes = MATparam.MATLireNbColonnes();
	uiNbLignes = MATparam.MATLireNbLignes();

	pMTPContenu = new MType * [uiNbLignes];


	for (uiboucle1 = 0; uiboucle1 < uiNbLignes; uiboucle1++) {
		pMTPContenu[uiboucle1] = new MType[uiNbColonnes];
		for (uiboucle2 = 0; uiboucle2 < uiNbColonnes; iboucle2++) {
			pMTPContenu[uiboucle1][uiboucle2] = MATparam.MATLireElement(uiboucle1, uiboucle2);
		}
	}
}
