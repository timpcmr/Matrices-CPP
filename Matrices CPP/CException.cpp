#include "CException.h"


/***************************************************************************
**** Entrées :                           							    ****
**** Nécessite :                                                        ****
**** Sorties :				                                            ****
**** Entraîne : Construit un objet exception avec une valeur 0	        ****
****************************************************************************/
CException::CException()
{
	iEXCValeur = EXCNonSpecifiee;
}

/***************************************************************************
**** Entrées : iVal : int                          	                    ****
**** Nécessite :                                                        ****
**** Sorties :				                                            ****
**** Entraîne : Construit un objet exception avec une valeur iVal       ****
****************************************************************************/
CException::CException(int iVal)
{
	iEXCValeur = iVal;
}


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
void CException::EXCChangerValeur(int iParam)
{
	iEXCValeur = iParam;
}
