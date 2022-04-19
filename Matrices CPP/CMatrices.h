#ifndef MAT
#define MAT

#include <iostream>
#include <cstdio>
#include <typeinfo>
#include "CException.h"
//#include "COperations.h"

using namespace std;


template<class MType> class CMatrices {
private:
	//Atributs
	unsigned int uiMATNbLignes;
	unsigned int uiMATNbColonnes;
	MType** pMTPMATContenu;

public:
	//Constructeurs et destructeurs
	CMatrices<MType>();
	CMatrices<MType>(unsigned int uiParam1, unsigned int uiParam2);
	CMatrices<MType>(CMatrices<MType> &MATparam);
	~CMatrices<MType>();

	//Accesseurs
	unsigned int MATLireNbLignes();
	unsigned int MATLireNbColonnes();
	MType MATLireElement(unsigned int uiLigne, unsigned int uiColonne);
	void MATAfficherMatrice();
	
	//Modifieurs
	void MATModifierCase(unsigned int uiLigne, unsigned int uiColonne, MType MTPparam);
	void MATModifierNombreLignes(unsigned int uiLigne);
	void MATModifierNombreColonnes(unsigned int uiColonne);
	
	//Surcharges d'opérateurs
	CMatrices<MType> operator+(CMatrices<MType> MATadd)const;
	CMatrices<MType> operator-(CMatrices<MType> MATdiff)const;
	CMatrices<MType> operator*(CMatrices<MType> MATmult)const;
	CMatrices<MType> operator*(double dComposante)const;
	CMatrices<MType> operator=(CMatrices<MType> MATegal)const;

	//Méthodes Universelles (ne dépendent pas du type)
	CMatrices<MType> MATTransposer(CMatrices<MType> MATMatrice);

};

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
inline CMatrices<MType>::CMatrices()
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
**** Nécessite : Un objet CMatrices à recopier								     ****
**** Sorties : CMatrices														 ****
**** Entraîne : La construction d'un objet CMatrices copié de MATparam  		 ****
*************************************************************************************/
template<class MType>
CMatrices<MType>::CMatrices(CMatrices<MType>& MATparam)
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

template<class MType>
CMatrices<MType>::~CMatrices()
{
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < uiMATNbLignes; uiBoucle++) {
		delete[] pMTPMATContenu[uiBoucle];
	}

	delete[] pMTPMATContenu;
}



template<class MType>
inline unsigned int CMatrices<MType>::MATLireNbLignes()
{
	return uiMATNbLignes;
}

template<class MType>
inline unsigned int CMatrices<MType>::MATLireNbColonnes()
{
	return uiMATNbColonnes;
}

template<class MType>
MType CMatrices<MType>::MATLireElement(unsigned int uiLigne, unsigned int uiColonne)
{
	return pMTPMATContenu[uiLigne][uiColonne];
}

template<class MType>
void CMatrices<MType>::MATAfficherMatrice()
{
	unsigned int uiboucle1, uiboucle2;
	
	cout << "Type des elements : " << typeid(MATLireElement(0,0)).name() << endl;
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

template<class MType>
void CMatrices<MType>::MATModifierCase(unsigned int uiLigne, unsigned int uiColonne, MType MATParam)
{
	pMTPMATContenu[uiLigne][uiColonne] = MATParam;
}

template<class MType>
inline CMatrices<MType> CMatrices<MType>::operator+(CMatrices<MType> MATadd) const
{
	if (MATLireNbLignes() != MATadd.MATLireNbLignes()) {
		throw CException(EXCDimLigne);
	}
	if (MATLireNbColonnes() != MATadd.MATLireNbColonnes()) {
		throw CException(EXCDimColonne);
	}
	if (MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
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

template<class MType>
inline CMatrices<MType> CMatrices<MType>::operator-(CMatrices<MType> MATdiff) const
{
	if (MATLireNbLignes() != MATdiff.MATLireNbLignes()) {
		throw CException(EXCDimLigne);
	}
	if (MATLireNbColonnes() != MATdiff.MATLireNbColonnes()) {
		throw CException(EXCDimColonne);
	}
	if (MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
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

template<class MType>
inline CMatrices<MType> CMatrices<MType>::operator*(CMatrices<MType> MATmult) const
{
	if(MATLireNbColonnes() != MATmult.MATLireNbLignes()) {
		throw CException(EXCDimMatMult);
	}
	if (MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
	}

	unsigned int uiboucle1, uiboucle2, uiboucle3;
	CMatrices<MType> MATretour(MATLireNbLignes(), MATmult.MATLireNbColonnes());
	MType MTPsomme;

	for (uiboucle1 = 0; uiboucle1 < MATretour.MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2; uiboucle2 < MATretour.MATLireNbColonnes(); uiboucle2++) {
			MTPsomme = MType();
			for (uiboucle3 = 0; uiboucle3 < MATLireNbColonnes(); uiboucle3++) {
				MTPsomme += MATLireElement(uiboucle1, uiboucle3) * MATmult.MATLireElement(uiboucle3, uiboucle2);
			}
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MTPsomme);
		}
	}
	return MATretour;
}

template<class MType>
inline CMatrices<MType> CMatrices<MType>::operator*(double dComposante) const
{
	if (MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
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

template<class MType>
inline CMatrices<MType> CMatrices<MType>::MATTransposer(CMatrices<MType> MATMatrice)
{
	CMatrices<MType> MATretour(MATMatrice.MATLireNbColonnes(), MATMatrice.MATLireNbLignes());
	unsigned int uiBoucle1, uiBoucle2;
	for (uiBoucle1 = 0; uiBoucle1 < MATretour.MATLireNbLignes(); uiBoucle1++) {
		for (uiBoucle2 = 0; uiBoucle2 < MATretour.MATLireNbColonnes(); uiBoucle2++) {
			MATretour.MATModifierCase(uiBoucle1, uiBoucle2, MATMatrice.MATLireElement(uiBoucle2, uiBoucle1));
		}
	}


	return MATretour;
}


#endif
