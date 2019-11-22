/**
 * \file Proprietaire.cpp
 * \brief Fichier d'implémentation de la classe Proprietaire
 * \date 2019-10-15
 * \author Renaud Morin
 */
#include "Proprietaire.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
namespace saaq{

/**
 * \brief Constructeur d'un nouvel objet de la classe Proprietaire
 * \param[in] p_nom nom du proprietaire
 * \param[in] p_prenom prenom du proprietaire
 * \pre p_nom est un nom valide
 * \pre p_prenom est un prenom valide
 * \post m_nom prend la valeur de p_nom
 * \post m_prenom prend la valeur de p_prenom
 */
Proprietaire::Proprietaire(const std::string& p_nom, const std::string& p_prenom):m_nom(p_nom), m_prenom(p_prenom)
	{
		PRECONDITION(!(m_nom.size()==0));
		PRECONDITION(!(m_prenom.size()==0));
		POSTCONDITION(m_nom == p_nom);
		POSTCONDITION(m_prenom == p_prenom);
		INVARIANTS();
	}

	/**
	 * \brief Retourne le nom du proprietaire
	 * \return nom du proprietaire
	*/
	const std::string& Proprietaire::reqNom() const
	{
		return m_nom;
	}

	/**
	 * \brief Retourne le prenom du proprietaire
	 * \return prenom du proprietaire
	*/
	const std::string& Proprietaire::reqPrenom() const
	{
		return m_prenom;
	}

	Proprietaire::~Proprietaire()
	{
		for (size_t i = 0; i < m_vVehicules.size(); ++i)
		{
			delete m_vVehicules[i];
		}
		m_vVehicules.clear();
	}

	/**
	 * \brief Retourne string contenant les informations des vehicules des proprietaire
	 * \return informations des vehicules des proprietaire
	 */
	std::string Proprietaire::reqProprietaireFormate() const
	{
		ostringstream os;
		os<<"Proprietaire \n"<<"========================\n";
		os<<"Nom    : "<<reqNom()<<endl;
		os<<"Prenom : "<<reqPrenom()<<endl;
		for(unsigned int i = 0; i < m_vVehicules.size(); i++)
		{
			os<<"------------------------\n"<<(*m_vVehicules[i]).reqVehiculeFormate();
		}
		os<<"========================\n";
		return os.str();
	}

	/**
	 * \brief Permet l'ajout d'un Vehicule (Camion ou Promenade) au proprietaire
	 * \param[in] p_nouveauVehicule Objet de type Vehicule
	 */
	void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule)
	{
		m_vVehicules.push_back(p_nouveauVehicule.clone());
	}

	void Proprietaire::verifieInvariant() const
	{
		INVARIANT(!(m_nom.size()==0));
		INVARIANT(!(m_prenom.size()==0));
	}

}/* namespace saaq */
