#pragma once
template<class MType> class CMatrices {
private:
	unsigned int uiNbLignes;
	unsigned int uiNbColonnes;
	MType** pMTPContenu;

public:
	CMatrices<MType>();
	CMatrices<MType>(unsigned int uiParam1, unsigned int uiParam2);
	CMatrices<MType>(CMatrices<MType> MATparam);
	~CMatrices<MType>();

	unsigned int MATLireNbLignes();
	unsigned int MATLireNbColonnes();
	MType MATAfficherMatrice();

};