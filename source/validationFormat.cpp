
/**
 * \file validationFormat.cpp
 * \brief Fichier permettant de valider une plaque automobile et un NIV
 * \date 2019-10-15
 * \author Renaud Morin
 */
#include <iostream>
using namespace std;
namespace util{
/**
 * \brief Fonction qui permet de valider le format dune plaque dimmatriculation
 * \param[in] p_immatriculation numero de plaque a verifier
 * \return valeur booléenne selon la validité de la plaque automobile
 */
bool validerImmatriculation (const std::string& p_immatriculation){
	//iteration de la string
	for (unsigned int i = 0; i <= p_immatriculation.size(); i++){
		//verification plaque 000 ABC
		if (isdigit(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && p_immatriculation[3] == ' ' && isupper(p_immatriculation[4]) && isupper(p_immatriculation[5]) && isupper(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque 000H000
		else if (isdigit(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && isupper(p_immatriculation[3]) && isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque A00 ABC
		else if (isalpha(p_immatriculation[0]) && isupper(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && p_immatriculation[3] == ' ' && isupper(p_immatriculation[4]) && isupper(p_immatriculation[5]) && isupper(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque ABC 000
		else if (isupper(p_immatriculation[0]) && isupper(p_immatriculation[1]) && isupper(p_immatriculation[2]) && p_immatriculation[3] == ' ' && isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque SAAQ
		else if (isupper(p_immatriculation[0]) && isupper(p_immatriculation[1]) && isupper(p_immatriculation[2]) && isupper(p_immatriculation[3]) && p_immatriculation.size() == 4){
			return true;
		}
		//Verification plaque L000000
		else if ((p_immatriculation[0] == 'L') && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && isdigit(p_immatriculation[3]) && isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
	}
	return false;
}

/**
 * \brief Fonction qui permet de valider le format dun NIV
 * \param[in] p_niv numero, NIV a verifier
 * \return valeur booléenne selon la validité du NIV
 */
bool validerNiv(const std::string &p_niv)
{
	//si la taille n'est pas 17, return false
    if (p_niv.size() != 17)
    {
        return false;
    }

    //faire une table du poid de chaque caracteres du NIV
    int weight[] = {8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2};
    int value[] = {};
    int product = 0;

    //iteration de la string p_niv
    for (unsigned int i = 0; i <= p_niv.size() - 1; i++){
    	//ne fait rien pour la cle
    	if(i==8){
    		continue;
    	}
    	else if(isdigit(p_niv[i])){
            value[i] = p_niv[i]- '0';
        }
        else if (isalpha(p_niv[i]) && isupper(p_niv[i])){
             if(p_niv[i] == 'O' || p_niv[i] == 'I' || p_niv[i] == 'Q')
            {
                return false;
            }
             //assigne chaque caracteres a la bonne valeur
            else if(p_niv[i] == 'A' || p_niv[i] == 'J')
            {
                value[i] = 1;
            }
            else if (p_niv[i] == 'B' || p_niv[i] == 'K' || p_niv[i] == 'S')
            {
                value[i] = 2;
            }
            else if (p_niv[i] == 'C' || p_niv[i] == 'L' || p_niv[i] == 'T')
            {
                value[i] = 3;
            }
            else if (p_niv[i] == 'D' || p_niv[i] == 'M' || p_niv[i] == 'U')
            {
                value[i] = 4;
            }
            else if (p_niv[i] == 'E' || p_niv[i] == 'N' || p_niv[i] == 'V')
            {
                value[i] = 5;
            }
            else if (p_niv[i] == 'F' || p_niv[i] == 'W')
            {
                value[i] = 6;
            }
            else if (p_niv[i] == 'G' || p_niv[i] == 'P' || p_niv[i] == 'X')
            {
                value[i] = 7;
            }
            else if (p_niv[i] == 'H' || p_niv[i] == 'Y')
            {
                value[i] = 8;
            }
            else if (p_niv[i] == 'R' || p_niv[i] == 'Z')
            {
                value[i] = 9;
            }
        }
    	//additionne la multiplication du caracteres de la string a son poid approprie
    	product += value[i] * weight[i];
    }

//calculation de la cle du NIV
	if(product % 11 == 10 && p_niv[8] == 'X'){
		return true;
	}if(product % 11 == p_niv[8] - '0'){
		return true;
	}else{
		return false;
	}
}
/**
 * \brief Fonction qui permet de valider le format dune plaque d'immatriculation de camion
 * \param[in] p_immatriculation numero de plaque a verifier
 * \return valeur booléenne selon la validité de la plaque de camion
 */
bool validerImmatriculationCamion (const std::string& p_immatriculation)
{
	for (unsigned int i = 0; i <= p_immatriculation.size(); i++)
	{
		if(p_immatriculation[0] == 'L' && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && isdigit(p_immatriculation[3]) && isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]) && p_immatriculation.size() == 7)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	return false;
}

/**
 * \brief Fonction qui permet de valider le format dune plaque d'immatriculation de promenade
 * \param[in] p_immatriculation numero de plaque a verifier
 * \return valeur booléenne selon la validité de la plaque de vehicule de promenade
 */
bool validerImmatriculationPromenade (const std::string& p_immatriculation)
{
	for (unsigned int i = 0; i <= p_immatriculation.size(); i++){
		//verification plaque 000 ABC
		if (isdigit(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && p_immatriculation[3] == ' ' && isupper(p_immatriculation[4]) && isupper(p_immatriculation[5]) && isupper(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque 000H000
		else if (isdigit(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && isupper(p_immatriculation[3]) && isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque A00 ABC
		else if (isalpha(p_immatriculation[0]) && isupper(p_immatriculation[0]) && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && p_immatriculation[3] == ' ' && isupper(p_immatriculation[4]) && isupper(p_immatriculation[5]) && isupper(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque ABC 000
		else if (isupper(p_immatriculation[0]) && isupper(p_immatriculation[1]) && isupper(p_immatriculation[2]) && p_immatriculation[3] == ' ' && isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		//Verification plaque SAAQ
		else if (isupper(p_immatriculation[0]) && isupper(p_immatriculation[1]) && isupper(p_immatriculation[2]) && isupper(p_immatriculation[3]) && p_immatriculation.size() == 4){
			return true;
		}
		//Verification plaque L000000
		else if ((p_immatriculation[0] == 'L') && isdigit(p_immatriculation[1]) && isdigit(p_immatriculation[2]) && isdigit(p_immatriculation[3]) && isdigit(p_immatriculation[4]) && isdigit(p_immatriculation[5]) && isdigit(p_immatriculation[6]) && p_immatriculation.size() == 7){
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}




















}
