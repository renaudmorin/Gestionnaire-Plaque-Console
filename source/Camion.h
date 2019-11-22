/**
 * \file Camion.h
 * \brief Fichier déclaration de la classe Camion
 * \date 2019-10-15
 * \author Renaud Morin
 */


#ifndef CAMION_H_
#define CAMION_H_

#include <string>
#include "Vehicule.h"
#include <iostream>
#include "ContratException.h"


namespace saaq{
/**
 * \class Camion
 * \brief Classe Camion qui contient les informations sur un Camion
 *        Contient la plaque d'immatriculation, la date d'enregistrement, le poid, le nombre d'essieu et le NIV du camion.
 *        Des méthode qui permettent de nous donner chaques valeurs.
 *        Une méthode qui permet d'assigner une nouvelle plaque de camion.
 *        Une méthode qui permet d'afficher le tout dans un format console.
 *
 */
class Camion: public Vehicule {
public:
	Camion(const int p_poids, const int p_nbEssieux, const std::string& p_niv, const std::string p_immatriculation, util::Date& p_dateEnregistrement);
	const int reqPoids() const;
	const int req_NbEssieux() const;
	double tarificationAnnuelle() const;
	void asgImmatriculation(const std::string& p_immatriculation);
	virtual Vehicule* clone() const;
	virtual std::string reqVehiculeFormate() const;

private:
	int m_poids;
	int m_nbEssieux;
	void verifieInvariant() const;



};
}/* namespace saaq */

#endif /* CAMION_H_ */