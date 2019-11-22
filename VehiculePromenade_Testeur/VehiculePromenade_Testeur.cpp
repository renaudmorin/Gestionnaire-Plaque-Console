/*
 * VehiculePromenade_Testeur.cpp
 *
 *  Created on: Nov 22, 2019
 *      Author: etudiant
 */
#include <gtest/gtest.h>
#include "VehiculePromenade.h"
#include "Date.h"
#include "Vehicule.h"

using namespace saaq;
using namespace std;

util::Date uneDate;

/**
 * \brief Test du Constructeur VehiculePromenade(const int p_nbPlaces, const std::string& p_niv, const std::string p_immatriculation, util::Date& p_dateEnregistrement);
 *        cas valide:
 *				      p_nbPlaces > 0
 *				      p_immatriculation valide
 *        cas invalides:
 *        			  p_nbPlaces <= 0
 *                    p_niv invalide
 *                    p_immatriculation invalide
 *                    p_dateEnregistrement invalide
 *
 */
TEST(VehiculePromenade, ConstructeurAvecParametreValide)
{
	VehiculePromenade testPromenade(1, "3VWFE21C04M000001", "IFT 006", uneDate);
	ASSERT_EQ(1,testPromenade.req_nbPlaces());
	ASSERT_EQ("3VWFE21C04M000001",testPromenade.reqNiv());
	ASSERT_EQ("IFT 006",testPromenade.reqImmatriculation());
	ASSERT_EQ(true, util::Date::validerDate(uneDate.reqJour(), uneDate.reqMois(), uneDate.reqAnnee()));
}

/**
 * \brief Test du Siege invalide VehiculePromenade
 *        cas invalides:
 *                    p_nbPlaces <= 0
 */
TEST(VehiculePromenade, ConstructeurAvecSiegeInvalide)
{
	ASSERT_THROW(VehiculePromenade testPromenade(0, "3VWFE21C04M000001", "IFT 006", uneDate), PreconditionException);
}

/** \class unVehiculePromenade
 *  \Fixture unVehiculePromenade pour la création d'un vehicule de promenade pour les tests
 */
class unVehiculePromenade: public ::testing::Test
{
public:
	unVehiculePromenade() : v_vehiculePromenade(2, "3VWFE21C04M000001", "IFT 006", uneDate){};
	VehiculePromenade v_vehiculePromenade;
};


/** \brief Test de la méthode req_nbPlaces
 *   Cas valide : le nbPlaces doit être égal au nbPlaces
 *   Cas invalide : si il est mal assigne
 */
TEST_F(unVehiculePromenade, req_nbPlaces)
{
	ASSERT_EQ(2, v_vehiculePromenade.req_nbPlaces());
}

/** \brief Test de la méthode asgImmatriculation
 *   Cas valide : l'immatriculation assigné doit être égal à l'immatriculation passé en paramètre
 *   Cas invalide : immatriculation invalide ou si elle n'est pas egale a celle passe en parametre
 */
TEST_F(unVehiculePromenade, asgImmatriculation)
{
	v_vehiculePromenade.asgImmatriculation("L032006");
	ASSERT_EQ("L032006", v_vehiculePromenade.reqImmatriculation());
}

/** \brief Test de la méthode tarificationAnnuelle
 *   Cas valide : la tarification doit être égal à 224.04
 *   Cas invalide : la tarification pas égal à 224.04
 */
TEST_F(unVehiculePromenade, tarificationAnnuelle)
{
	ASSERT_EQ(224.04, v_vehiculePromenade.tarificationAnnuelle());
}

/**
 * \brief Test de la méthode virtuelle Vehicule* clone() const
 *        cas valides:
 *                cloneVehicule :vérification que le clone possède les mêmes attributs que vehicule
 *
 *                cloneVehiculePointeur : Vérification que le pointeur du vehicule et son clone n'ont pas la meme adresse
 *
 */
TEST_F(unVehiculePromenade, cloneVehiculePromenade)
{
	Vehicule* clone = v_vehiculePromenade.clone();
	ASSERT_EQ(v_vehiculePromenade.tarificationAnnuelle(), clone->tarificationAnnuelle());
    ASSERT_EQ(v_vehiculePromenade.reqNiv(), clone->reqNiv());
    ASSERT_EQ(v_vehiculePromenade.reqImmatriculation(), clone->reqImmatriculation());
    ASSERT_EQ(v_vehiculePromenade.reqDateEnregistrement(), clone->reqDateEnregistrement());
    ASSERT_EQ(v_vehiculePromenade.reqVehiculeFormate(), clone->reqVehiculeFormate());
}

TEST_F(unVehiculePromenade, clonePointeurVehiculePromenade)
{
    Vehicule* clone = v_vehiculePromenade.clone();
    VehiculePromenade* cloneVehiculePointeur = &v_vehiculePromenade;
    ASSERT_NE(cloneVehiculePointeur, clone);
}

/**
 * \test Test de la méthode std::string reqVehiculeFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objets Vehicule formaté
 *        Cas invalides: aucun
 */

TEST_F(unVehiculePromenade,reqVehiculeFormate)
{
	ostringstream os;
	os << "Numero de serie          : " << v_vehiculePromenade.reqNiv() << endl;
	os << "Numero d’immatriculation : " << v_vehiculePromenade.reqImmatriculation() << endl;
	os << "Date d’enregistrement    : " << v_vehiculePromenade.reqDateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre de places : "<<v_vehiculePromenade.req_nbPlaces() << endl;
	os << "Tarif : "<<v_vehiculePromenade.tarificationAnnuelle() << "$"<< endl;

	ASSERT_EQ(os.str(), v_vehiculePromenade.reqVehiculeFormate());
}






