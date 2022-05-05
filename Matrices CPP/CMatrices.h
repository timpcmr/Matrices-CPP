#ifndef MAT
#define MAT

#pragma warning(disable : 6011)
#pragma warning(disable : 6386)

#include <iostream>
#include <cstdio>
#include <typeinfo>
#include "CException.h"

#define EXCDimMatMult 15
#define EXCDivZero 16
#define EXCMATDimLigneNeg 17
#define EXCMATDimColonneNeg 18
#define EXCMATDimLigne 19
#define EXCMATDimColonne 20

using namespace std;


template<class MType> class CMatrices {
private:
	//Attributs
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;
	MType** pMTPMATContenu;

public:
	//Constructeurs et destructeurs

	/************************************************************************************
	**** Entrées : uiParam1, uiParam2 : unsigned int                      	         ****
	**** Nécessite :															     ****
	**** Sorties : CMatrices														 ****
	**** Entraîne : La construction d'un objet CMatrices uiParam1 * uiParam2		 ****
	*************************************************************************************/
	CMatrices<MType>();

	/***********************************************************************************
	**** Entrées :                         											****
	**** Nécessite :																****
	**** Sorties : CMatrices														****
	**** Entraîne : La construction d'un objet CMatrices 1x1						****
	************************************************************************************/
	CMatrices<MType>(const unsigned int uiParam1, const unsigned int uiParam2);


	/************************************************************************************
	**** Entrées : MATparam : référence vers un objet CMatrices						 ****
	**** Nécessite :															     ****
	**** Sorties : CMatrices														 ****
	**** Entraîne : La construction d'un objet CMatrices copié de MATparam  		 ****
	*************************************************************************************/
	CMatrices<MType>(const CMatrices<MType> &MATparam);

	/************************************************************************************
	**** Entrées :									                     	         ****
	**** Nécessite :															     ****
	**** Sorties :																	 ****
	**** Entraîne : La destruction de la matrice									 ****
	*************************************************************************************/
	~CMatrices<MType>();

	//Accesseurs

	/************************************************************************************
	**** Entrées :										                   	         ****
	**** Nécessite :															     ****
	**** Sorties : unsigned int	: uiMATNbLignes										 ****
	**** Entraîne : Le retour du nombre de lignes de la matrice						 ****
	*************************************************************************************/
	unsigned int MATLireNbLignes()const;

	/************************************************************************************
	**** Entrées :										                   	         ****
	**** Nécessite :															     ****
	**** Sorties : unsigned int	: uiMATNbColonnes									 ****
	**** Entraîne : Le retour du nombre de colonnes de la matrice					 ****
	*************************************************************************************/
	unsigned int MATLireNbColonnes()const;

	/************************************************************************************
	**** Entrées : unsigned int uiLigne, unsigned int uiColonne		                 ****
	**** Nécessite :															     ****
	**** Sorties : MType : pMTPMATContenu[uiLigne][uiColonne]						 ****
	**** Entraîne : Le retour de l'élément de la matrice souhaité					 ****
	*************************************************************************************/
	MType MATLireElement(const unsigned int uiLigne, const unsigned int uiColonne)const;
	
	//Modifieurs

	/************************************************************************************
	**** Entrées : unsigned int uiLigne, unsigned int uiColonne, MType MATParam      ****
	**** Nécessite :															     ****
	**** Sorties :																	 ****
	**** Entraîne : Le changement de valeur de l'élément de la matrice souhaité		 ****
	*************************************************************************************/
	void MATModifierCase(const unsigned int uiLigne, const unsigned int uiColonne, MType MTPparam);

	/************************************************************************************
	**** Entrées : unsigned int uiColonne, unsigned int uiColonne		             ****
	**** Nécessite :															     ****
	**** Sorties :																	 ****
	**** Entraîne : Modification des dimensions de la matrice actuelle				 ****
	*************************************************************************************/
	void MATModifierDimensions(const unsigned int uiLigne, const unsigned int uiColonne);


	//Surcharges d'opérateurs

	/****************************************************************************************************************************
	**** Entrées : CMatrice MATadd																							 ****
	**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entraîne : Renvoie une matrice résultant de l'addition de 2 matrices												 ****
	****************************************************************************************************************************/
	CMatrices<MType> operator+(const CMatrices<MType> MATadd)const;

	/****************************************************************************************************************************
	**** Entrées : CMatrice MATdiff																							 ****
	**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entraîne : Renvoie une matrice résultant de la soustraction de 2 matrices											 ****
	****************************************************************************************************************************/
	CMatrices<MType> operator-(const CMatrices<MType> MATdiff)const;

	/****************************************************************************************************************************
	**** Entrées : CMatrice MATmult																							 ****
	**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entraîne : Renvoie une matrice résultant de la multiplication de 2 matrices										 ****
	****************************************************************************************************************************/
	CMatrices<MType> operator*(const CMatrices<MType> MATmult)const;

	/****************************************************************************************************************************
	**** Entrées : const double dComposante																				     ****
	**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entraîne : Renvoie une matrice résultant de la multiplication entre la matrice actuelle et la constante dComposante ****
	****************************************************************************************************************************/
	CMatrices<MType> operator*(const double dComposante)const;

	/********************************************************************************************************************
	**** Entrées : const double dComposante																			 ****
	**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char	 ****
	**** Sorties :	CMatrice MATretour																				 ****
	**** Entraîne : Renvoie une matrice résultant de la division de la matrice actuelle par la constante dComposante ****
	********************************************************************************************************************/
	CMatrices<MType> operator/(const double dComposante)const;

	/************************************************************************************
	**** Entrées : CMatrice MATegal											         ****
	**** Nécessite :															     ****
	**** Sorties :	CMatrice* this													 ****
	**** Entraîne :	Affecte les valeurs de la matrice MATegal à la matrice actuelle  ****
	************************************************************************************/
	CMatrices<MType> & operator=(const CMatrices<MType> MATegal);

	//Méthodes

	/************************************************************************************
	**** Entrées : CMatrice MATMatrice											     ****
	**** Nécessite :															     ****
	**** Sorties :	CMatrice MATretour												 ****
	**** Entraîne : Renvoie la transposée de la matrice MATMatrice					 ****
	************************************************************************************/
	CMatrices<MType> MATTransposer();

	/************************************************************************************
	**** Entrées :															         ****
	**** Nécessite : Une matrice avec un contenu initialisé						     ****
	**** Sorties : 																	 ****
	**** Entraîne : L'affichage de la matrice dans la sortie standard				 ****
	*************************************************************************************/
	void MATAfficherMatrice()const;
};

/************************************************************************************
**** Entrées : uiParam1, uiParam2 : unsigned int                      	         ****
**** Nécessite :															     ****
**** Sorties : CMatrices														 ****
**** Entraîne : La construction d'un objet CMatrices uiParam1 * uiParam2		 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices(const unsigned int uiParam1, const unsigned int uiParam2)
{
	unsigned int uiboucle1, uiboucle2;

	uiMATNbLignes = uiParam1;
	uiMATNbColonnes = uiParam2;

	//Création de la matrice avec n lignes
	pMTPMATContenu = new MType * [uiMATNbLignes];

	//Ajout de uiNbColonnes cases dans chaque ligne et affectation à la valeur par défaut
	for (uiboucle1 = 0; uiboucle1 < uiMATNbLignes; uiboucle1++) {
		pMTPMATContenu[uiboucle1] = new MType[uiMATNbColonnes];
		for (uiboucle2 = 0; uiboucle2 < uiMATNbColonnes; uiboucle2++) {
			pMTPMATContenu[uiboucle1][uiboucle2] = MType();
		}
	}
}

/***********************************************************************************
**** Entrées :                         											****
**** Nécessite :																****
**** Sorties : CMatrices														****
**** Entraîne : La construction d'un objet CMatrices 1x1						****
************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices()
{
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;
	//Initialisation de la matrice
	pMTPMATContenu = new MType * [uiMATNbLignes];
	pMTPMATContenu[0] = new MType[uiMATNbColonnes];

	//On affecte une valeur par défaut selon le type à la seule case de cette matrice 1x1
	**pMTPMATContenu = MType();
}

/************************************************************************************
**** Entrées : MATparam : référence vers un objet CMatrices						 ****
**** Nécessite :															     ****
**** Sorties : CMatrices														 ****
**** Entraîne : La construction d'un objet CMatrices copié de MATparam  		 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices(const CMatrices<MType>& MATparam)
{
	unsigned int uiboucle1, uiboucle2;
	uiMATNbColonnes = MATparam.MATLireNbColonnes();
	uiMATNbLignes = MATparam.MATLireNbLignes();

	pMTPMATContenu = new MType * [uiMATNbLignes];


	for (uiboucle1 = 0; uiboucle1 < uiMATNbLignes; uiboucle1++) {
		pMTPMATContenu[uiboucle1] = new MType[uiMATNbColonnes];
		for (uiboucle2 = 0; uiboucle2 < uiMATNbColonnes; uiboucle2++) {
			pMTPMATContenu[uiboucle1][uiboucle2] = MATparam.MATLireElement(uiboucle1, uiboucle2);
		}
	}
}

/************************************************************************************
**** Entrées :									                     	         ****
**** Nécessite :															     ****
**** Sorties :																	 ****
**** Entraîne : La destruction de la matrice									 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::~CMatrices()
{
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) {
		delete[] pMTPMATContenu[uiBoucle];
	}

	delete[] pMTPMATContenu;
}

/************************************************************************************
**** Entrées :										                   	         ****
**** Nécessite :															     ****
**** Sorties : unsigned int	: uiMATNbLignes										 ****
**** Entraîne : Le retour du nombre de lignes de la matrice						 ****
*************************************************************************************/
template<class MType>
unsigned int CMatrices<MType>::MATLireNbLignes()const
{
	return uiMATNbLignes;
}

/************************************************************************************
**** Entrées :										                   	         ****
**** Nécessite :															     ****
**** Sorties : unsigned int	: uiMATNbColonnes									 ****
**** Entraîne : Le retour du nombre de colonnes de la matrice					 ****
*************************************************************************************/
template<class MType>
unsigned int CMatrices<MType>::MATLireNbColonnes()const
{
	return uiMATNbColonnes;
}

/************************************************************************************
**** Entrées : unsigned int uiLigne, unsigned int uiColonne		                 ****
**** Nécessite :															     ****
**** Sorties : MType : pMTPMATContenu[uiLigne][uiColonne]						 ****
**** Entraîne : Le retour de l'élément de la matrice souhaité					 ****
*************************************************************************************/
template<class MType>
MType CMatrices<MType>::MATLireElement(const unsigned int uiLigne, const unsigned int uiColonne)const
{
	return pMTPMATContenu[uiLigne][uiColonne];
}

/************************************************************************************
**** Entrées : unsigned int uiLigne, unsigned int uiColonne, MType MATParam      ****
**** Nécessite :															     ****
**** Sorties :																	 ****
**** Entraîne : Le changement de valeur de l'élément de la matrice souhaité		 ****
*************************************************************************************/
template<class MType>
void CMatrices<MType>::MATModifierCase(const unsigned int uiLigne, const unsigned int uiColonne, MType MATParam)
{
	pMTPMATContenu[uiLigne][uiColonne] = MATParam;
}

/************************************************************************************
**** Entrées : unsigned int uiColonne, unsigned int uiColonne		             ****
**** Nécessite :															     ****
**** Sorties :																	 ****
**** Entraîne : Modification des dimensions de la matrice actuelle				 ****
*************************************************************************************/
template<class MType>
void CMatrices<MType>::MATModifierDimensions(const unsigned int uiLigne, const unsigned int uiColonne)
{
	if (uiColonne < 0) {
		throw CException(EXCMATDimColonneNeg);
	}
	if (uiColonne < 0) {
		throw CException(EXCMATDimLigneNeg);
	}

	//Si fonction appelée inutilement
	if (uiLigne == MATLireNbLignes() && uiColonne == MATLireNbColonnes()) {
		return;
	}

	unsigned int uiBoucle1, uiBoucle2;

	//Initialisation du nouveau tableau de contenu de la matrice aux bonnes dimensions
	MType** pMTPtmp = new MType * [uiLigne];
	for (uiBoucle1 = 0; uiBoucle1 < uiLigne; uiBoucle1++) {
		pMTPtmp[uiBoucle1] = new MType[uiColonne];
	}

	//Si les dimensions sont inférieures ou égales aux précédentes dimensions, on copie les anciennes valeurs et on tronque
	//les valeurs éxcédentaires. Si on agrandit la matrice, on remplit les nouvelles cases avec la valeuir par défaut
	//du type d'élément.
	for(uiBoucle1 = 0; uiBoucle1 < uiLigne; uiBoucle1++) {
		for (uiBoucle2 = 0; uiBoucle2 < uiColonne; uiBoucle2++) {
			if (uiBoucle1 < MATLireNbLignes() && uiBoucle2 < MATLireNbColonnes()) {
				pMTPtmp[uiBoucle1][uiBoucle2] = MATLireElement(uiBoucle1, uiBoucle2);
			}
			else {
				pMTPtmp[uiBoucle1][uiBoucle2] = MType();
			}
		}
	}

	//On traite le changement de tableau de contenu:

	//On désalloue l'ancien contenu
	for (uiBoucle1 = 0; uiBoucle1 < MATLireNbLignes(); uiBoucle1++) {
		delete[] pMTPMATContenu[uiBoucle1];
	}
	delete[] pMTPMATContenu;

	//On ajoute le nouveau contenu
	pMTPMATContenu = pMTPtmp;

	//On change le nombre de colonnes et de lignes stocké
	uiMATNbLignes = uiLigne;
	uiMATNbColonnes = uiColonne;

}

/****************************************************************************************************************************
**** Entrées : CMatrice MATadd																							 ****
**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entraîne : Renvoie une matrice résultant de l'addition de 2 matrices												 ****
****************************************************************************************************************************/
template<class MType>
CMatrices<MType> CMatrices<MType>::operator+(const CMatrices<MType> MATadd) const
{
	if (MATLireNbLignes() != MATadd.MATLireNbLignes()) {
		throw CException(EXCMATDimLigne);
	}
	if (MATLireNbColonnes() != MATadd.MATLireNbColonnes()) {
		throw CException(EXCMATDimColonne);
	}
	if (MATLireNbLignes() < 0) {
		throw CException(EXCMATDimLigneNeg);
	}
	if (MATLireNbColonnes() < 0) {
		throw CException(EXCMATDimColonneNeg);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATLireNbLignes(), MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATLireElement(uiboucle1, uiboucle2) + MATadd.MATLireElement(uiboucle1, uiboucle2));
		}
	}
	return MATretour;
}

/****************************************************************************************************************************
**** Entrées : CMatrice MATdiff																							 ****
**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entraîne : Renvoie une matrice résultant de la soustraction de 2 matrices											 ****
****************************************************************************************************************************/
template<class MType>
CMatrices<MType> CMatrices<MType>::operator-(const CMatrices<MType> MATdiff) const
{
	if (MATLireNbLignes() != MATdiff.MATLireNbLignes()) {
		throw CException(EXCMATDimLigne);
	}
	if (MATLireNbColonnes() != MATdiff.MATLireNbColonnes()) {
		throw CException(EXCMATDimColonne);
	}
	if (MATLireNbLignes() < 0) {
		throw CException(EXCMATDimLigneNeg);
	}
	if (MATLireNbColonnes() < 0) {
		throw CException(EXCMATDimColonneNeg);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATLireNbLignes(), MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATLireElement(uiboucle1, uiboucle2) - MATdiff.MATLireElement(uiboucle1, uiboucle2));
		}
	}
	return MATretour;
}

/****************************************************************************************************************************
**** Entrées : CMatrice MATmult																							 ****
**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entraîne : Renvoie une matrice résultant de la multiplication de 2 matrices										 ****
****************************************************************************************************************************/
template<class MType>
CMatrices<MType> CMatrices<MType>::operator*(const CMatrices<MType> MATmult) const
{
	if(MATLireNbColonnes() != MATmult.MATLireNbLignes()) {
		throw CException(EXCDimMatMult);
	}
	if (MATLireNbLignes() < 0) {
		throw CException(EXCMATDimLigneNeg);
	}
	if (MATLireNbColonnes() < 0) {
		throw CException(EXCMATDimColonneNeg);
	}

	unsigned int uiboucle1, uiboucle2, uiboucle3;
	CMatrices<MType> MATretour(MATLireNbLignes(), MATmult.MATLireNbColonnes());
	MType MTPsomme;

	for (uiboucle1 = 0; uiboucle1 < MATretour.MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATretour.MATLireNbColonnes(); uiboucle2++) {
			MTPsomme = MType();
			for (uiboucle3 = 0; uiboucle3 < MATLireNbColonnes(); uiboucle3++) {
				MTPsomme += MATLireElement(uiboucle1, uiboucle3) * MATmult.MATLireElement(uiboucle3, uiboucle2);
			}
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MTPsomme);
		}
	}
	return MATretour;
}

/****************************************************************************************************************************
**** Entrées : const double dComposante																				     ****
**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entraîne : Renvoie une matrice résultant de la multiplication entre la matrice actuelle et la constante dComposante ****
****************************************************************************************************************************/
template<class MType>
CMatrices<MType> CMatrices<MType>::operator*(const double dComposante) const
{
	if (MATLireNbLignes() < 0) {
		throw CException(EXCMATDimLigneNeg);
	}
	if (MATLireNbColonnes() < 0) {
		throw CException(EXCMATDimColonneNeg);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATLireNbLignes(), MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATLireElement(uiboucle1, uiboucle2) * dComposante);
		}
	}
	return MATretour;
}

//Surcharge déclarée hors de la classe

/****************************************************************************************************************************
**** Entrées : const double dComposante, const CMatrice MATMult															 ****
**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entraîne : Renvoie une matrice résultant de la multiplication entre la constante dComposante et la matrice MATMult	 ****
****************************************************************************************************************************/
template<class MType>
inline CMatrices<MType> operator*(const double dComposante, const CMatrices<MType> MATmult)
{
	return MATmult * dComposante;
}

/********************************************************************************************************************
**** Entrées : const double dComposante																			 ****
**** Nécessite : MType est type de base, un objet avec la surcharge adaptée ou différent d'un pointeur ou char	 ****
**** Sorties :	CMatrice MATretour																				 ****
**** Entraîne : Renvoie une matrice résultant de la division de la matrice actuelle par la constante dComposante ****
********************************************************************************************************************/
template<class MType>
CMatrices<MType> CMatrices<MType>::operator/(const double dComposante) const
{
	if (MATLireNbLignes() < 0) {
		throw CException(EXCMATDimLigneNeg);
	}
	if (MATLireNbColonnes() < 0) {
		throw CException(EXCMATDimColonneNeg);
	}
	if (dComposante == 0) {
		throw CException(EXCDivZero);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATLireNbLignes(), MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATLireElement(uiboucle1, uiboucle2) / dComposante);
		}
	}
	return MATretour;
}

/************************************************************************************
**** Entrées : CMatrice MATegal											         ****
**** Nécessite :															     ****
**** Sorties :	CMatrice this													 ****
**** Entraîne :	Affecte les valeurs de la matrice MATegal à la matrice actuelle  ****
************************************************************************************/
template<class MType>
CMatrices<MType> & CMatrices<MType>::operator=(const CMatrices<MType> MATegal)
{
	unsigned int uiBoucle1, uiBoucle2;

	if (MATLireNbLignes() != MATegal.MATLireNbLignes() || MATLireNbColonnes() != MATegal.MATLireNbColonnes()) {
		MATModifierDimensions(MATegal.MATLireNbLignes(), MATegal.MATLireNbColonnes());
	}
	
	for (uiBoucle1 = 0; uiBoucle1 < MATLireNbLignes(); uiBoucle1++) {
		for (uiBoucle2 = 0; uiBoucle2 < MATLireNbColonnes(); uiBoucle2++) {
			MATModifierCase(uiBoucle1, uiBoucle2, MATegal.MATLireElement(uiBoucle1, uiBoucle2));
		}
	}

	return *this;
}

/************************************************************************************
**** Entrées : CMatrice MATMatrice											     ****
**** Nécessite :															     ****
**** Sorties :	CMatrice MATretour												 ****
**** Entraîne : Renvoie la transposée de la matrice MATMatrice					 ****
************************************************************************************/
template<class MType>
CMatrices<MType> CMatrices<MType>::MATTransposer()
{
	CMatrices<MType> MATretour(MATLireNbColonnes(), MATLireNbLignes());
	unsigned int uiBoucle1, uiBoucle2;
	for (uiBoucle1 = 0; uiBoucle1 < MATLireNbLignes(); uiBoucle1++) {
		for (uiBoucle2 = 0; uiBoucle2 < MATLireNbColonnes(); uiBoucle2++) {
			MATretour.MATModifierCase(uiBoucle1, uiBoucle2, MATLireElement(uiBoucle2, uiBoucle1));
		}
	}

	return MATretour;
}

/************************************************************************************
**** Entrées :															         ****
**** Nécessite : Une matrice avec un contenu initialisé						     ****
**** Sorties : 																	 ****
**** Entraîne : L'affichage de la matrice dans la sortie standard				 ****
*************************************************************************************/
template<class MType>
void CMatrices<MType>::MATAfficherMatrice()const
{
	unsigned int uiboucle1, uiboucle2;

	cout << "Type des elements : " << typeid(MATLireElement(0, 0)).name() << endl;
	cout << "Nombre de lignes : " << MATLireNbLignes() << endl;
	cout << "Nombre de colonnes : " << MATLireNbColonnes() << endl << endl;

	for (uiboucle1 = 0; uiboucle1 < uiMATNbLignes; uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < uiMATNbColonnes; uiboucle2++) {
			cout << pMTPMATContenu[uiboucle1][uiboucle2] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

#endif
