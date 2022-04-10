#include "CMatrices.h"

/***********************************************************************************
**** Entr�es :                         											****
**** N�cessite :																****
**** Sorties : CMatrices														****
**** Entra�ne : La construction d'un objet CMatrices 1x1						****
************************************************************************************/
template<class MType>
inline CMatrices<MType>::CMatrices()
{
	uiNbLignes = 1;
	uiNbColonnes = 1;
	//Initialisation de la matrice
	pMTPContenu = new MType * [uiNbLignes];
	pMTPContenu[0] = new MType[uiNbColonnes];

	//On affecte une valeur par d�faut selon le type � la seule case de cette matrice 1x1
	**pMTPContenu= MType();
}


/************************************************************************************
**** Entr�es : uiParam1, uiParam2 : unsigned int                      	         ****
**** N�cessite : Le nombre de lignes et de colonnes de la matrice � construire   ****
**** Sorties : CMatrices														 ****
**** Entra�ne : La construction d'un objet CMatrices uiParam1 * uiParam2		 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices(unsigned int uiParam1, unsigned int uiParam2)
{
	unsigned int uiboucle1, uiboucle2;

	uiNbLignes = uiParam1;
	uiNbColonnes = uiParam2;

	//Cr�ation de la matrice avec n lignes
	pMTPContenu = new MType * [uiNbLignes];

	//Ajout de uiNbColonnes cases dans chaque ligne et affectation � la valeur par d�faut
	for (uiboucle1 = 0; uiboucle1 < uiNbLignes; uiboucle1++) {
		pMTPContenu[uiboucle1] = new MType[uiNbColonnes];
		for (uiboucle2 = 0; uiboucle2 < uiNbColonnes; uiboucle2++) {
			pMTPContenu[uiboucle1][uiboucle2] = MType();
		}
	}
}

/************************************************************************************
**** Entr�es : MATparam : r�f�rence vers un objet CMatrices						 ****
**** N�cessite : Un objet CMatrices � recopier								     ****
**** Sorties : CMatrices														 ****
**** Entra�ne : La construction d'un objet CMatrices copi� de MATparam  		 ****
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
