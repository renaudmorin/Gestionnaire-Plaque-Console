/*
 * Vehicule_Testeur.cpp
 *
 *  Created on: Nov 22, 2019
 *      Author: etudiant
 */
#include <gtest/gtest.h>
#include "Vehicule.h"
#include "Date.h"
using namespace saaq;
using namespace std;

util::Date uneDate;

/**
 * \class VehiculeTest
 * \brief classe de test permettant de tester la classe Vehicule
 */

class VehiculeTest: public Vehicule
{
public:
	VehiculeTest(const std::string& p_niv, const std::string& p_immatriculation, util::Date& p_dateEnregistrement):
		Vehicule(p_niv, p_immatriculation, p_dateEnregistrement)
	{

	};
	virtual string reqVehiculeFormate() const
	{
		ostringstream os;
		os << "Numero de serie          : " << Vehicule::reqNiv() << endl;
		os << "Numero d’immatriculation : " << Vehicule::reqImmatriculation() << endl;
		os << "Date d’enregistrement    : " << Vehicule::reqDateEnregistrement().reqDateFormatee() << endl;

		return os.str();;
	}
	virtual double tarificationAnnuelle() const
	{
		return 0;
	}
	virtual Vehicule* clone() const
	{
		return new VehiculeTest(*this);
	}

};

/** \class unVehicule
 *  \Fixture unVehicule pour la création d'un vehicule pour les tests
 */
class unVehicule : public ::testing::Test
{
public:
	unVehicule() : v_vehicule("3VWFE21C04M000001", "IFT 006", uneDate) {};
	VehiculeTest v_vehicule;
};


/**
 * \brief Test du constructeur valide Vehicule(const std::string& p_niv, const std::string& p_immatriculation, util::Date& p_dateEnregistrement)
 *        cas valide: Creation d'un objet Vehicule et que tous ses attributs sont valides
 *        cas invalides:
 *                    p_niv invalide
 *                    p_immatriculation invalide
 *                    p_dateEnregistrement invalide
 */
TEST(Vehicule, ConstructeurAvecParametresValides)
{
	VehiculeTest vehicTest("3VWFE21C04M000001", "IFT 006", uneDate);
	ASSERT_EQ("3VWFE21C04M000001", vehicTest.reqNiv());
	ASSERT_EQ("IFT 006", vehicTest.reqImmatriculation());
	ASSERT_EQ(true, util::Date::validerDate(uneDate.reqJour(), uneDate.reqMois(), uneDate.reqAnnee()));

}

/**
 * \brief Test du niv invalide Vehicule
 *        cas invalides:
 *                    p_niv invalide
 */
TEST(Vehicule, ConstructeurAvecNivInvalides)
{
	ASSERT_THROW(VehiculeTest vehicTest("INVALIDE", "IFT 006", uneDate), ContratException);
}

/**
 * \brief Test de l'immatriculation invalide Vehicule
 *        cas invalides:
 *                    p_immatriculation invalide
 */
TEST(Vehicule, ConstructeurAvecImmatriculationInvalides)
{
	ASSERT_THROW(VehiculeTest vehicTest("3VWFE21C04M000001", "INVALIDE", uneDate), ContratException);
}


/** \brief Test de la méthode reqNiv
 *   Cas valide : le NIV  doit être égal au NIV
 *   Cas invalide : si il est mal assigne
 */
TEST_F(unVehicule, reqNiv)
{
	ASSERT_EQ("3VWFE21C04M000001", v_vehicule.reqNiv());
}

/** \brief Test de la méthode reqImmatriculation
 *   Cas valide : l'immatriculation  doit être égal a l'immatriculation
 *   Cas invalide : si il est mal assigne
 */
TEST_F(unVehicule, reqImmatriculation)
{
	ASSERT_EQ("IFT 006", v_vehicule.reqImmatriculation());
}

/** \brief Test de la méthode TarificationAnnuelle
 *   Cas valide : la tarification doit être égal a 0
 *   Cas invalide : si il n'est pas 0
 */
TEST_F(unVehicule, TarificationAnnuelle)
{
	ASSERT_EQ(0, v_vehicule.tarificationAnnuelle());
}

/**
 * \test Test de la méthode std::string reqVehiculeFormate();
 *
 *        Cas valides: vérifier le retour des information sur l'objets Vehicule formaté
 *        Cas invalides: aucun
 */

TEST_F(unVehicule,reqVehiculeFormate)
{

	ostringstream os;
	os << "Numero de serie          : " << v_vehicule.reqNiv() << endl;
	os << "Numero d’immatriculation : " << v_vehicule.reqImmatriculation() << endl;
	os << "Date d’enregistrement    : " << v_vehicule.reqDateEnregistrement().reqDateFormatee() << endl;

	ASSERT_EQ(os.str(), v_vehicule.reqVehiculeFormate());
}


/**
 * \brief Test de la méthode virtuelle Vehicule* clone() const
 *        cas valides:
 *                cloneVehicule :vérification que le clone possède les mêmes attributs que vehicule
 *
 *                cloneVehiculePointeur : Vérification que le pointeur du vehicule et son clone n'ont pas la meme adresse
 *
 */
TEST_F(unVehicule, cloneVehicule)
{
    Vehicule* clone = v_vehicule.clone();
    ASSERT_EQ(v_vehicule.reqNiv(), clone->reqNiv());
    ASSERT_EQ(v_vehicule.reqImmatriculation(), clone->reqImmatriculation());
    ASSERT_EQ(v_vehicule.reqDateEnregistrement(), clone->reqDateEnregistrement());
    ASSERT_EQ(v_vehicule.reqVehiculeFormate(), clone->reqVehiculeFormate());
}
TEST_F(unVehicule, cloneVehiculePointeur)
{
	Vehicule* clone = v_vehicule.clone();
	Vehicule* cloneVehiculePointeur = &v_vehicule;
    ASSERT_NE(cloneVehiculePointeur, clone);
}
