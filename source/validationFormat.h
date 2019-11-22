/**
 * \file validationFormat.h
 * \brief Fichier permettant de valider une plaque automobile et un NIV
 * \date 2019-10-15
 * \author Renaud Morin
 */
#include <iostream>
#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
namespace util {
	bool validerImmatriculation (const std::string& p_immatriculation);
	bool validerImmatriculationPromenade (const std::string& p_immatriculation);
	bool validerImmatriculationCamion (const std::string& p_immatriculation);
	bool validerNiv(const std::string &p_niv);
}




#endif /* VALIDATIONFORMAT_H_ */
