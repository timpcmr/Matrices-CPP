#ifndef OPE
#define OPE
#include "CMatrices.h"
#include <iostream>

template <class MType>
class Coperations {
public:
	static CMatrices<MType> OPEMultiplication(const double dComposante, CMatrices<MType> MATparam);
	static CMatrices<MType> OPEMultiplication(CMatrices<MType> MATparam, const double dComposante);
	static CMatrices<MType> OPEDivision(const double dComposante, CMatrices<MType> MATparam);
	static CMatrices<MType> OPEDivision(CMatrices<MType> MATparam, const double dComposante);
};



#endif
