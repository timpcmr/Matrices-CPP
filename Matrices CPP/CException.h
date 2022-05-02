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
	**** Entrées :                           							    ****
	**** Nécessite :                                                        ****
	**** Sorties :				                                            ****
	**** Entraîne : Construit un objet exception avec une valeur 0	        ****
	****************************************************************************/
	CException();

	/***************************************************************************
	**** Entrées : iVal : int                          	                    ****
	**** Nécessite :                                                        ****
	**** Sorties :				                                            ****
	**** Entraîne : Construit un objet exception avec une valeur iVal       ****
	****************************************************************************/
	CException(const int iVal);

	//Accesseur

	/***************************************************************************
	**** Entrées :                                  	                    ****
	**** Nécessite :                                                        ****
	**** Sorties : iEXCValeur : int                                         ****
	**** Entraîne : Renvoie la valeur de l'exception                        ****
	****************************************************************************/
	int EXCLireErreur(void);

	//Modifieur

	/***************************************************************************
	**** Entrées :  iParam : int                                	        ****
	**** Nécessite :                                                        ****
	**** Sorties :	                                         	            ****
	**** Entraîne : Modifie la valeur de l'exception                        ****
	****************************************************************************/
	void EXCChangerValeur(const int iparam);

};
#endif