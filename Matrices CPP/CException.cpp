#include "CException.h"


/***************************************************************************
**** Entr�es :                           							    ****
**** N�cessite :                                                        ****
**** Sorties :				                                            ****
**** Entra�ne : Construit un objet exception avec une valeur 0	        ****
****************************************************************************/
CException::CException()
{
	iEXCValeur = EXCNonSpecifiee;
}

/***************************************************************************
**** Entr�es : iVal : int                          	                    ****
**** N�cessite :                                                        ****
**** Sorties :				                                            ****
**** Entra�ne : Construit un objet exception avec une valeur iVal       ****
****************************************************************************/
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
void CException::EXCChangerValeur(int iParam)
{
	iEXCValeur = iParam;
}
