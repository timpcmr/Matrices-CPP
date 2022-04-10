#include "CException.h"

/***************************************************************************
**** Entrées :                                  	                    ****
**** Nécessite :                                                        ****
**** Sorties : iEXCValeur : int                                         ****
**** Entraîne : Renvoie la valeur de l'exception                        ****
****************************************************************************/
int CException::EXCLireErreur()
{
	return iEXCValeur;
}

/***************************************************************************
**** Entrées :  iParam : int                                	        ****
**** Nécessite :                                                        ****
**** Sorties :	                                         	            ****
**** Entraîne : Modifie la valeur de l'exception                        ****
****************************************************************************/
void CException::EXCSetValue(int iParam)
{
	iEXCValeur = iParam;
}
