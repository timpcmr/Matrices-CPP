#pragma once
#ifndef EXCEPTION
#define EXCEPTION

#define EXCNonSpecifiee 0

class CException
{
private:
	int iEXCValeur;
public:
	CException();
	CException(int iVal);

	int EXCLireErreur(void);
	void EXCChangerValeur(int iparam);

};
#endif