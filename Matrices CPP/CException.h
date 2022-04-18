#pragma once
#ifndef EXCEPTION
#define EXCEPTION

#define EXCNonSpecifiee 0
#define EXCCheminNul 1
#define EXCFichierNonOuvert 2
#define EXCErrTypeMat 3
#define EXCDimLigneNeg 4
#define EXCDimColonneNeg 5
#define EXCParserPointeurNul 6
#define EXCTokenNulMinuscule 7
#define EXCTokenNulSuppEspace 8
#define EXCColonneDimSup 9
#define EXCColonneDimInf 10
#define EXCLigneDimSup 11
#define EXCLigneDimInf 12
#define EXCDimLigne 13
#define EXCDimColonne 14
#define EXCDimMatMult 15
#define EXCDivZero 16


class CException
{
private:
	int iEXCValeur;
public:
	CException();
	CException(int iVal);

	int EXCLireErreur(void);
	void EXCSetValue(int iparam);

};
#endif