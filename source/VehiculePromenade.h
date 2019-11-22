/**
 * \file VehiculePromenade.h
 * \brief Fichier déclaration de la classe VehiculePromenade
 * \date 2019-11-15
 * \author Renaud Morin
 */

#ifndef VEHICULEPROMENADE_H_
#define VEHICULEPROMENADE_H_

#include <iostream>
#include "Vehicule.h"
#include <string>
#include "ContratException.h"


namespace saaq{
/**
 * \class VehiculePromenade
 * \brief Classe VehiculePromenade qui contient les informations sur un Vehicule de Promenade
 *        Contient la plaque d'immatriculation, la date d'enregistrement, le nombre de place et le NIV du vehicule.
 *        Des méthode qui permettent de nous donner chaques valeurs.
 *        Une méthode qui permet d'assigner une nouvelle plaque de Vehicule de Promenade.
 *        Une méthode qui permet d'afficher le tout dans un format console.
 *
 */
class VehiculePromenade: public Vehicule {
public:
	VehiculePromenade(const int p_nbPlaces, const std::string& p_niv, const std::string p_immatriculation, util::Date& p_dateEnregistrement);
	const int req_nbPlaces() const;
	void asgImmatriculation(const std::string& p_immatriculation);
	double tarificationAnnuelle() const;
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;

private:
	int m_nbPlaces;
	void verifieInvariant() const;


};
}/* namespace saaq */
#endif /* VEHICULEPROMENADE_H_ */
