#pragma once
#ifndef EXCEPTION
#define EXCEPTION

#define FichierIntrouvable 1
#define DivZero 2
#define SegFault 3
#define Doublon 4


class CException
{
	private:
		int iEXCValeur;
public:
	int EXCLireErreur(void);
	void EXCSetValue(int iparam);

};
#endif