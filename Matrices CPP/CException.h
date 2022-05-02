#pragma once
#ifndef EXCEPTION
#define EXCEPTION

#define EXCNonSpecifiee 0

class CException
{
private:
	//Attribut
	int iEXCValeur;
public:

	//Constructeur

	/***************************************************************************
	**** Entr�es :                           							    ****
	**** N�cessite :                                                        ****
	**** Sorties :				                                            ****
	**** Entra�ne : Construit un objet exception avec une valeur 0	        ****
	****************************************************************************/
	CException();

	/***************************************************************************
	**** Entr�es : iVal : int                          	                    ****
	**** N�cessite :                                                        ****
	**** Sorties :				                                            ****
	**** Entra�ne : Construit un objet exception avec une valeur iVal       ****
	****************************************************************************/
	CException(const int iVal);

	//Accesseur

	/***************************************************************************
	**** Entr�es :                                  	                    ****
	**** N�cessite :                                                        ****
	**** Sorties : iEXCValeur : int                                         ****
	**** Entra�ne : Renvoie la valeur de l'exception                        ****
	****************************************************************************/
	int EXCLireErreur(void);

	//Modifieur

	/***************************************************************************
	**** Entr�es :  iParam : int                                	        ****
	**** N�cessite :                                                        ****
	**** Sorties :	                                         	            ****
	**** Entra�ne : Modifie la valeur de l'exception                        ****
	****************************************************************************/
	void EXCChangerValeur(const int iparam);

};
#endif