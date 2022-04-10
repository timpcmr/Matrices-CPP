#include "CMatrices.h"


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
