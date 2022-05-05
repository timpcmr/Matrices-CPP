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
	**** Entr�es : uiParam1, uiParam2 : unsigned int                      	         ****
	**** N�cessite :															     ****
	**** Sorties : CMatrices														 ****
	**** Entra�ne : La construction d'un objet CMatrices uiParam1 * uiParam2		 ****
	*************************************************************************************/
	CMatrices<MType>();

	/***********************************************************************************
	**** Entr�es :                         											****
	**** N�cessite :																****
	**** Sorties : CMatrices														****
	**** Entra�ne : La construction d'un objet CMatrices 1x1						****
	************************************************************************************/
	CMatrices<MType>(const unsigned int uiParam1, const unsigned int uiParam2);


	/************************************************************************************
	**** Entr�es : MATparam : r�f�rence vers un objet CMatrices						 ****
	**** N�cessite :															     ****
	**** Sorties : CMatrices														 ****
	**** Entra�ne : La construction d'un objet CMatrices copi� de MATparam  		 ****
	*************************************************************************************/
	CMatrices<MType>(const CMatrices<MType> &MATparam);

	/************************************************************************************
	**** Entr�es :									                     	         ****
	**** N�cessite :															     ****
	**** Sorties :																	 ****
	**** Entra�ne : La destruction de la matrice									 ****
	*************************************************************************************/
	~CMatrices<MType>();

	//Accesseurs

	/************************************************************************************
	**** Entr�es :										                   	         ****
	**** N�cessite :															     ****
	**** Sorties : unsigned int	: uiMATNbLignes										 ****
	**** Entra�ne : Le retour du nombre de lignes de la matrice						 ****
	*************************************************************************************/
	unsigned int MATLireNbLignes()const;

	/************************************************************************************
	**** Entr�es :										                   	         ****
	**** N�cessite :															     ****
	**** Sorties : unsigned int	: uiMATNbColonnes									 ****
	**** Entra�ne : Le retour du nombre de colonnes de la matrice					 ****
	*************************************************************************************/
	unsigned int MATLireNbColonnes()const;

	/************************************************************************************
	**** Entr�es : unsigned int uiLigne, unsigned int uiColonne		                 ****
	**** N�cessite :															     ****
	**** Sorties : MType : pMTPMATContenu[uiLigne][uiColonne]						 ****
	**** Entra�ne : Le retour de l'�l�ment de la matrice souhait�					 ****
	*************************************************************************************/
	MType MATLireElement(const unsigned int uiLigne, const unsigned int uiColonne)const;
	
	//Modifieurs

	/************************************************************************************
	**** Entr�es : unsigned int uiLigne, unsigned int uiColonne, MType MATParam      ****
	**** N�cessite :															     ****
	**** Sorties :																	 ****
	**** Entra�ne : Le changement de valeur de l'�l�ment de la matrice souhait�		 ****
	*************************************************************************************/
	void MATModifierCase(const unsigned int uiLigne, const unsigned int uiColonne, MType MTPparam);

	/************************************************************************************
	**** Entr�es : unsigned int uiColonne, unsigned int uiColonne		             ****
	**** N�cessite :															     ****
	**** Sorties :																	 ****
	**** Entra�ne : Modification des dimensions de la matrice actuelle				 ****
	*************************************************************************************/
	void MATModifierDimensions(const unsigned int uiLigne, const unsigned int uiColonne);


	//Surcharges d'op�rateurs

	/****************************************************************************************************************************
	**** Entr�es : CMatrice MATadd																							 ****
	**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entra�ne : Renvoie une matrice r�sultant de l'addition de 2 matrices												 ****
	****************************************************************************************************************************/
	CMatrices<MType> operator+(const CMatrices<MType> MATadd)const;

	/****************************************************************************************************************************
	**** Entr�es : CMatrice MATdiff																							 ****
	**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entra�ne : Renvoie une matrice r�sultant de la soustraction de 2 matrices											 ****
	****************************************************************************************************************************/
	CMatrices<MType> operator-(const CMatrices<MType> MATdiff)const;

	/****************************************************************************************************************************
	**** Entr�es : CMatrice MATmult																							 ****
	**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entra�ne : Renvoie une matrice r�sultant de la multiplication de 2 matrices										 ****
	****************************************************************************************************************************/
	CMatrices<MType> operator*(const CMatrices<MType> MATmult)const;

	/****************************************************************************************************************************
	**** Entr�es : const double dComposante																				     ****
	**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
	**** Sorties :	CMatrice MATretour																						 ****
	**** Entra�ne : Renvoie une matrice r�sultant de la multiplication entre la matrice actuelle et la constante dComposante ****
	****************************************************************************************************************************/
	CMatrices<MType> operator*(const double dComposante)const;

	/********************************************************************************************************************
	**** Entr�es : const double dComposante																			 ****
	**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char	 ****
	**** Sorties :	CMatrice MATretour																				 ****
	**** Entra�ne : Renvoie une matrice r�sultant de la division de la matrice actuelle par la constante dComposante ****
	********************************************************************************************************************/
	CMatrices<MType> operator/(const double dComposante)const;

	/************************************************************************************
	**** Entr�es : CMatrice MATegal											         ****
	**** N�cessite :															     ****
	**** Sorties :	CMatrice* this													 ****
	**** Entra�ne :	Affecte les valeurs de la matrice MATegal � la matrice actuelle  ****
	************************************************************************************/
	CMatrices<MType> & operator=(const CMatrices<MType> MATegal);

	//M�thodes

	/************************************************************************************
	**** Entr�es : CMatrice MATMatrice											     ****
	**** N�cessite :															     ****
	**** Sorties :	CMatrice MATretour												 ****
	**** Entra�ne : Renvoie la transpos�e de la matrice MATMatrice					 ****
	************************************************************************************/
	CMatrices<MType> MATTransposer();

	/************************************************************************************
	**** Entr�es :															         ****
	**** N�cessite : Une matrice avec un contenu initialis�						     ****
	**** Sorties : 																	 ****
	**** Entra�ne : L'affichage de la matrice dans la sortie standard				 ****
	*************************************************************************************/
	void MATAfficherMatrice()const;
};

/************************************************************************************
**** Entr�es : uiParam1, uiParam2 : unsigned int                      	         ****
**** N�cessite :															     ****
**** Sorties : CMatrices														 ****
**** Entra�ne : La construction d'un objet CMatrices uiParam1 * uiParam2		 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices(const unsigned int uiParam1, const unsigned int uiParam2)
{
	unsigned int uiboucle1, uiboucle2;

	uiMATNbLignes = uiParam1;
	uiMATNbColonnes = uiParam2;

	//Cr�ation de la matrice avec n lignes
	pMTPMATContenu = new MType * [uiMATNbLignes];

	//Ajout de uiNbColonnes cases dans chaque ligne et affectation � la valeur par d�faut
	for (uiboucle1 = 0; uiboucle1 < uiMATNbLignes; uiboucle1++) {
		pMTPMATContenu[uiboucle1] = new MType[uiMATNbColonnes];
		for (uiboucle2 = 0; uiboucle2 < uiMATNbColonnes; uiboucle2++) {
			pMTPMATContenu[uiboucle1][uiboucle2] = MType();
		}
	}
}

/***********************************************************************************
**** Entr�es :                         											****
**** N�cessite :																****
**** Sorties : CMatrices														****
**** Entra�ne : La construction d'un objet CMatrices 1x1						****
************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices()
{
	uiMATNbLignes = 1;
	uiMATNbColonnes = 1;
	//Initialisation de la matrice
	pMTPMATContenu = new MType * [uiMATNbLignes];
	pMTPMATContenu[0] = new MType[uiMATNbColonnes];

	//On affecte une valeur par d�faut selon le type � la seule case de cette matrice 1x1
	**pMTPMATContenu = MType();
}

/************************************************************************************
**** Entr�es : MATparam : r�f�rence vers un objet CMatrices						 ****
**** N�cessite :															     ****
**** Sorties : CMatrices														 ****
**** Entra�ne : La construction d'un objet CMatrices copi� de MATparam  		 ****
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
**** Entr�es :									                     	         ****
**** N�cessite :															     ****
**** Sorties :																	 ****
**** Entra�ne : La destruction de la matrice									 ****
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
**** Entr�es :										                   	         ****
**** N�cessite :															     ****
**** Sorties : unsigned int	: uiMATNbLignes										 ****
**** Entra�ne : Le retour du nombre de lignes de la matrice						 ****
*************************************************************************************/
template<class MType>
unsigned int CMatrices<MType>::MATLireNbLignes()const
{
	return uiMATNbLignes;
}

/************************************************************************************
**** Entr�es :										                   	         ****
**** N�cessite :															     ****
**** Sorties : unsigned int	: uiMATNbColonnes									 ****
**** Entra�ne : Le retour du nombre de colonnes de la matrice					 ****
*************************************************************************************/
template<class MType>
unsigned int CMatrices<MType>::MATLireNbColonnes()const
{
	return uiMATNbColonnes;
}

/************************************************************************************
**** Entr�es : unsigned int uiLigne, unsigned int uiColonne		                 ****
**** N�cessite :															     ****
**** Sorties : MType : pMTPMATContenu[uiLigne][uiColonne]						 ****
**** Entra�ne : Le retour de l'�l�ment de la matrice souhait�					 ****
*************************************************************************************/
template<class MType>
MType CMatrices<MType>::MATLireElement(const unsigned int uiLigne, const unsigned int uiColonne)const
{
	return pMTPMATContenu[uiLigne][uiColonne];
}

/************************************************************************************
**** Entr�es : unsigned int uiLigne, unsigned int uiColonne, MType MATParam      ****
**** N�cessite :															     ****
**** Sorties :																	 ****
**** Entra�ne : Le changement de valeur de l'�l�ment de la matrice souhait�		 ****
*************************************************************************************/
template<class MType>
void CMatrices<MType>::MATModifierCase(const unsigned int uiLigne, const unsigned int uiColonne, MType MATParam)
{
	pMTPMATContenu[uiLigne][uiColonne] = MATParam;
}

/************************************************************************************
**** Entr�es : unsigned int uiColonne, unsigned int uiColonne		             ****
**** N�cessite :															     ****
**** Sorties :																	 ****
**** Entra�ne : Modification des dimensions de la matrice actuelle				 ****
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

	//Si fonction appel�e inutilement
	if (uiLigne == MATLireNbLignes() && uiColonne == MATLireNbColonnes()) {
		return;
	}

	unsigned int uiBoucle1, uiBoucle2;

	//Initialisation du nouveau tableau de contenu de la matrice aux bonnes dimensions
	MType** pMTPtmp = new MType * [uiLigne];
	for (uiBoucle1 = 0; uiBoucle1 < uiLigne; uiBoucle1++) {
		pMTPtmp[uiBoucle1] = new MType[uiColonne];
	}

	//Si les dimensions sont inf�rieures ou �gales aux pr�c�dentes dimensions, on copie les anciennes valeurs et on tronque
	//les valeurs �xc�dentaires. Si on agrandit la matrice, on remplit les nouvelles cases avec la valeuir par d�faut
	//du type d'�l�ment.
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

	//On d�salloue l'ancien contenu
	for (uiBoucle1 = 0; uiBoucle1 < MATLireNbLignes(); uiBoucle1++) {
		delete[] pMTPMATContenu[uiBoucle1];
	}
	delete[] pMTPMATContenu;

	//On ajoute le nouveau contenu
	pMTPMATContenu = pMTPtmp;

	//On change le nombre de colonnes et de lignes stock�
	uiMATNbLignes = uiLigne;
	uiMATNbColonnes = uiColonne;

}

/****************************************************************************************************************************
**** Entr�es : CMatrice MATadd																							 ****
**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entra�ne : Renvoie une matrice r�sultant de l'addition de 2 matrices												 ****
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
**** Entr�es : CMatrice MATdiff																							 ****
**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entra�ne : Renvoie une matrice r�sultant de la soustraction de 2 matrices											 ****
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
**** Entr�es : CMatrice MATmult																							 ****
**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entra�ne : Renvoie une matrice r�sultant de la multiplication de 2 matrices										 ****
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
**** Entr�es : const double dComposante																				     ****
**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entra�ne : Renvoie une matrice r�sultant de la multiplication entre la matrice actuelle et la constante dComposante ****
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

//Surcharge d�clar�e hors de la classe

/****************************************************************************************************************************
**** Entr�es : const double dComposante, const CMatrice MATMult															 ****
**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char			 ****
**** Sorties :	CMatrice MATretour																						 ****
**** Entra�ne : Renvoie une matrice r�sultant de la multiplication entre la constante dComposante et la matrice MATMult	 ****
****************************************************************************************************************************/
template<class MType>
inline CMatrices<MType> operator*(const double dComposante, const CMatrices<MType> MATmult)
{
	return MATmult * dComposante;
}

/********************************************************************************************************************
**** Entr�es : const double dComposante																			 ****
**** N�cessite : MType est type de base, un objet avec la surcharge adapt�e ou diff�rent d'un pointeur ou char	 ****
**** Sorties :	CMatrice MATretour																				 ****
**** Entra�ne : Renvoie une matrice r�sultant de la division de la matrice actuelle par la constante dComposante ****
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
**** Entr�es : CMatrice MATegal											         ****
**** N�cessite :															     ****
**** Sorties :	CMatrice this													 ****
**** Entra�ne :	Affecte les valeurs de la matrice MATegal � la matrice actuelle  ****
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
**** Entr�es : CMatrice MATMatrice											     ****
**** N�cessite :															     ****
**** Sorties :	CMatrice MATretour												 ****
**** Entra�ne : Renvoie la transpos�e de la matrice MATMatrice					 ****
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
**** Entr�es :															         ****
**** N�cessite : Une matrice avec un contenu initialis�						     ****
**** Sorties : 																	 ****
**** Entra�ne : L'affichage de la matrice dans la sortie standard				 ****
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
