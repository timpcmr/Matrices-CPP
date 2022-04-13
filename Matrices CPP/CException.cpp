#include "CException.h"

CException::CException()
{
	iEXCValeur = EXCNonSpecifiee;
}

CException::CException(int iVal)
{
	iEXCValeur = iVal;
}


/***************************************************************************
**** Entr�es :                                  	                    ****
**** N�cessite :                                                        ****
**** Sorties : iEXCValeur : int                                         ****
**** Entra�ne : Renvoie la valeur de l'exception                        ****
****************************************************************************/
int CException::EXCLireErreur()
{
	return iEXCValeur;
}

/***************************************************************************
**** Entr�es :  iParam : int                                	        ****
**** N�cessite :                                                        ****
**** Sorties :	                                         	            ****
**** Entra�ne : Modifie la valeur de l'exception                        ****
****************************************************************************/
void CException::EXCSetValue(int iParam)
{
	iEXCValeur = iParam;
}
