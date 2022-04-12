#pragma once
#ifndef EXCEPTION
#define EXCEPTION

#define ExcNonSpecifiee 0


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