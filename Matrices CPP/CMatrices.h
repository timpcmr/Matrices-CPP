#ifndef MAT
#define MAT
#include <iostream>
#include <cstdio>
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
	
	//Surcharges d'op�rateurs
	CMatrices<MType> operator+(CMatrices<MType> MATadd)const;
	CMatrices<MType> operator-(CMatrices<MType> MATdiff)const;
	CMatrices<MType> operator*(CMatrices<MType> MATmult)const;
	CMatrices<MType> operator=(CMatrices<MType> MATegal)const;

	//M�thodes Universelles (ne d�pendent pas du type)
	CMatrices<MType> MATTransposer(CMatrices<MType> MATMatrice);

};

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
inline CMatrices<MType>::CMatrices()
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
**** N�cessite : Un objet CMatrices � recopier								     ****
**** Sorties : CMatrices														 ****
**** Entra�ne : La construction d'un objet CMatrices copi� de MATparam  		 ****
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
	/*if (MATLireNbLignes() > 0 && MATLireNbColonnes() > 0) {
		cout << "Type des �l�ments : " << typeid(MATLireElement(0, 0)) << endl;
	}*/

	cout << "Nombre de lignes : " << MATLireNbLignes() << endl;
	cout << "Nombre de Colonnes : " << MATLireNbColonnes() << endl;

	for (uiboucle1 = 0; uiboucle1 < uiMATNbLignes; uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < uiMATNbColonnes; uiboucle2++) {
			cout << pMTPMATContenu[uiboucle1][uiboucle2] << ' ';
		}
		cout << endl;
	}
}

template<class MType>
void CMatrices<MType>::MATModifierCase(unsigned int uiLigne, unsigned int uiColonne, MType MATParam)
{
	pMTPMATContenu[uiLigne][uiColonne] = MATParam;
}



template<class MType>
inline CMatrices<MType> CMatrices<MType>::MATTransposer(CMatrices<MType> MATMatrice)
{
	CMatrices<MType> retour(MATMatrice.MATLireNbColonnes(), MATMatrice.MATLireNbLignes());
	unsigned int uiBoucle1, uiBoucle2;
	for (uiBoucle1 = 0; uiBoucle1 < retour.MATLireNbLignes(); uiBoucle1++) {
		for (uiBoucle2 = 0; uiBoucle2 < retour.MATLireNbColonnes(); uiBoucle2++) {
			retour.MATModifierCase(uiBoucle1, uiBoucle2, MATMatrice.MATLireElement(uiBoucle2, uiBoucle1));
		}
	}


	return retour;
}


#endif
