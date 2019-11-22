/**
 * \file Proprietaire.h
 * \brief Fichier declaration de la classe Proprietaire
 * \date 2019-10-15
 * \author Renaud Morin
 */
#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_

#include <string>
#include "Camion.h"
#include "VehiculePromenade.h"
#include "ContratException.h"
#include <vector>

namespace saaq{
/**
 * \class Proprietaire
 * \brief Classe Proprietaire qui contient les Camions et Vehicule de promenade
 * 			-Accesseurs pour tous ses attributs
 * 	        -Assigner une nouvelle plaque automobile
 * 	        -Une methode qui retourne le tout de facon formate
 */
class Proprietaire {
public:
	Proprietaire(const std::string& p_nom, const std::string& p_prenom);
	~Proprietaire();
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	std::string reqProprietaireFormate()const;
	void ajouterVehicule(const Vehicule& p_nouveauVehicule);




private:
	std::string m_nom;
	std::string m_prenom;
	std::vector<Vehicule*> m_vVehicules;
	//constructeur copie
	Proprietaire(const Proprietaire& copy);
	//constructeur assignation
	Proprietaire& operator=(const Proprietaire&);
	void verifieInvariant() const;




};
} /* namespace saaq */
#endif /* PROPRIETAIRE_H_ */
