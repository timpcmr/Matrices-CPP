#ifndef OPE
#define OPE
#include "CMatrices.h"
#include <iostream>

#define EXCDimLigne 13
#define EXCDimColonne 14
#define EXCDimMatMult 15
#define EXCDivZero 16

template<class MType>
class Coperations
{
public:
	static CMatrices<MType> OPEMultiplication(const double dComposante, CMatrices<MType> MATparam);
	static CMatrices<MType> OPEMultiplication(CMatrices<MType> MATparam, const double dComposante);
	static CMatrices<MType> OPEDivision(const double dComposante, CMatrices<MType> MATparam);
	static CMatrices<MType> OPEDivision(CMatrices<MType> MATparam, const double dComposante);
};


template<class MType>
inline CMatrices<MType> Coperations<MType>::OPEMultiplication(const double dComposante, CMatrices<MType> MATparam)
{
	if (MATparam.MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATparam.MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATparam.MATLireNbLignes(), MATparam.MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATparam.MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATparam.MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATparam.MATLireElement(uiboucle1, uiboucle2) * dComposante);
		}
	}
	return MATretour;
}

template<class MType>
CMatrices<MType> Coperations<MType>::OPEMultiplication(CMatrices<MType> MATparam, const double dComposante)
{
	if (MATparam.MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATparam.MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATparam.MATLireNbLignes(), MATparam.MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATparam.MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATparam.MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATparam.MATLireElement(uiboucle1, uiboucle2) * dComposante);
		}
	}
	return MATretour;
}

template<class MType>
CMatrices<MType> Coperations<MType>::OPEDivision(const double dComposante, CMatrices<MType> MATparam)
{
	if (MATparam.MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATparam.MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
	}
	if (dComposante == 0) {
		throw CException(EXCDivZero);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATparam.MATLireNbLignes(), MATparam.MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATparam.MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATparam.MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATparam.MATLireElement(uiboucle1, uiboucle2) / dComposante);
		}
	}
	return MATretour;
}

template<class MType>
CMatrices<MType> Coperations<MType>::OPEDivision(CMatrices<MType> MATparam, const double dComposante)
{
	if (MATparam.MATLireNbLignes() < 0) {
		throw CException(EXCDimLigneNeg);
	}
	if (MATparam.MATLireNbColonnes < 0) {
		throw CException(EXCDimColonneNeg);
	}
	if (dComposante == 0) {
		throw CException(EXCDivZero);
	}

	unsigned int uiboucle1, uiboucle2;
	CMatrices<MType> MATretour(MATparam.MATLireNbLignes(), MATparam.MATLireNbColonnes());

	for (uiboucle1 = 0; uiboucle1 < MATparam.MATLireNbLignes(); uiboucle1++) {
		for (uiboucle2 = 0; uiboucle2 < MATparam.MATLireNbColonnes(); uiboucle2++) {
			MATretour.MATModifierCase(uiboucle1, uiboucle2, MATparam.MATLireElement(uiboucle1, uiboucle2) / dComposante);
		}
	}
	return MATretour;
}


#endif
