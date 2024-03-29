
/**
 * \file Camion.cpp
 * \brief Fichier d'implémentation de la classe Camion
 * \date 2019-10-15
 * \author Renaud Morin
 */
#include "Camion.h"
#include "Vehicule.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace saaq {
/**
 * \brief Constructeur d'un nouvel objet de la classe Camion
 * \param[in] p_poids poid du camion
 * \param[in] p_nbEssieux nombre d'essieux
 * \param[in] p_niv NIV du vehicule
 * \param[in] p_immatriculation immatriculation du vehicule
 * \param[in] p_dateEnregistrement date d'enregistrement
 * \pre p_immatriculation est une plaque de camion
 * \pre p_poids est valide (plus grand que 3000)
 * \pre p_nbEssieux est valide (plus que 2 essieux)
 * \post m_poids prend la valeur de p_poids
 * \post m_nbEssieux prend la valeur de p_nbEssieux
 */
Camion::Camion(const int p_poids, const int p_nbEssieux, const std::string& p_niv,
		const std::string p_immatriculation, util::Date& p_dateEnregistrement) :
		Vehicule(p_niv, p_immatriculation, p_dateEnregistrement), m_poids(p_poids), m_nbEssieux(p_nbEssieux)
	{
		PRECONDITION(util::validerNiv(p_niv));
		PRECONDITION(util::validerImmatriculationCamion(p_immatriculation));
		PRECONDITION(util::Date::validerDate(p_dateEnregistrement.reqJour(), p_dateEnregistrement.reqMois(), p_dateEnregistrement.reqAnnee()));

		POSTCONDITION(m_poids == p_poids);
		POSTCONDITION(m_nbEssieux == p_nbEssieux);

		INVARIANTS();


	}
	/**
	 * \brief Retourne le poid  du camion
	 * \return poid du camion
	*/
	const int Camion::reqPoids() const
	{
		return m_poids;
	}
	/**
	 * \brief Retourne le nombre d'essieux  du camion
	 * \return le nombre d'essieux
	*/
	const int Camion::req_NbEssieux() const
	{
		return m_nbEssieux;
	}
	/**
	 * \brief Retourne la tarification annuelle du camion
	 * \return tarification annuelle du camion
	*/
	double Camion::tarificationAnnuelle() const
	{
		if (m_nbEssieux == 2 && m_poids >= 3001 && m_poids <= 4000)
		{
			return 570.28;
		}
		else if (m_nbEssieux == 2 && m_poids >= 4001)
		{
			return 905.28;
		}
		else if (m_nbEssieux == 3)
		{
			return 1566.19;
		}
		else if (m_nbEssieux == 4)
		{
			return 2206.19;
		}
		else if (m_nbEssieux == 5)
		{
			return 2821.76;
		}
		else if (m_nbEssieux >= 6)
		{
			return 3729.76;
		}
		else
		{
			return 0;
		}
	}

	/**
	 * \brief Assigne une nouvelle plaque automobile au camion
	 * \param[in] p_immatriculation est la nouvelle plaque du camion qui est valide
	 * \pre p_immatriculation correspond a une plaque automobile valide
	 * \post la nouvelle plaque a été assigné correctement
	 */
	void Camion::asgImmatriculation(const std::string& p_immatriculation)
	{
		const string& p_immatriculation_test = p_immatriculation;
		PRECONDITION(util::validerImmatriculationCamion(p_immatriculation));
		Vehicule::asgImmatriculation(p_immatriculation);
		POSTCONDITION(p_immatriculation_test != p_immatriculation);
		INVARIANTS();
	}

	/**
	 * \brief Retourne un clone de l'objet du camion
	 * \return une copie du camion
	 */
	Vehicule* Camion::clone() const
	{
		return new Camion(*this);  // Appel du constructeur copie
	}


	/**
	 * \brief Retourne une string contenant les informations du camion de maniere formate
	 * \return informations du camion de maniere formate
	 */
	std::string Camion::reqVehiculeFormate() const
	{
		ostringstream os;
		os << Vehicule::reqVehiculeFormate();
		os << "Nombre d'essieux : "<<Camion::req_NbEssieux() << endl;
		os << "Poids : "<< Camion::reqPoids() <<" kg" << endl;
		os << "Tarif : "<<Camion::tarificationAnnuelle() << "$"<< endl;
		return os.str();
	}
	void Camion::verifieInvariant() const
	{
		INVARIANT(m_poids > 3000);
		INVARIANT(m_nbEssieux >= 2);
	}


}/* namespace saaq */

