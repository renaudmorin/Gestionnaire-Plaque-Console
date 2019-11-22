/*
 * Proprietaire_Testeur.cpp
 *
 *  Created on: Nov 22, 2019
 *      Author: etudiant
 */
#include <gtest/gtest.h>
#include "Proprietaire.h"
#include "Camion.h"
#include "Date.h"
using namespace std;
using namespace saaq;
util::Date uneDate;
/**
 * \brief Test du Constructeur Proprietaire(string p_nom , string p_prenom)
 *        cas valide: "nom", "prenom"
 *        cas invalides:
 *                    p_nom vide
 *                    p_prenom vide
 */
TEST(Proprietaire, ConstructeurAvecParametres)
{
	Proprietaire testProprietaire("Renaud", "Morin");
	ASSERT_EQ("Renaud", testProprietaire.reqNom());
	ASSERT_EQ("Morin", testProprietaire.reqPrenom());
}

/**
 * \brief Test du Constructeur avec p_nom invalide
 *        cas valide: p_nom non vide
 *        cas invalides:
 *                    p_nom vide
 *
 */
TEST(Proprietaire, ConstructeurP_nomInvalide)
{
	ASSERT_THROW(Proprietaire testProprietaire("", "Morin"), PreconditionException);
}

/**
 * \brief Test du Constructeur avec p_prenom invalide
 *        cas valide: p_prenom non vide
 *        cas invalides:
 *                    p_prenom vide
 *
 */
TEST(Proprietaire, ConstructeurP_prenomInvalide)
{
	ASSERT_THROW(Proprietaire testProprietaire("Renaud", ""), PreconditionException);
}

/**
 * \test Test de la méthode reqProprietaireFormate()
 *
 *     Cas valide: vérifier le retour des informations sur le proprietaire
 *     Cas invalide: pas bon restltat
 */
TEST(Proprietaire, reqProprietaireFormate)
{
	string nom = "nom";
	string prenom = "prenom";
	Proprietaire testProprietaire(nom,prenom);
	ostringstream os;
	os<<"Proprietaire \n"<<"========================\n";
	os<<"Nom    : "<<testProprietaire.reqNom()<<endl;
	os<<"Prenom : "<<testProprietaire.reqPrenom()<<endl;
	os<<"========================\n";

	ASSERT_EQ(os.str(), testProprietaire.reqProprietaireFormate());
}

/**
 * \class ProprietaireValide
 * \brief création d'un objet Proprietaire pour les tests unitaire
 */
class UnProprietaire: public ::testing::Test
{
public:
	UnProprietaire() : t_Proprietaire("Renaud", "Morin")
    {
    };
	Proprietaire t_Proprietaire;
};


/**
 * \test Test de la méthode AjouterVehicule
 * 	Cas valides: Creation d'un objet vehicule avec un des parametres valides
 */
TEST_F(UnProprietaire, AjouterVehicule)
{
	Camion c1(3500, 7, "3VWFE21C04M000001", "L000000", uneDate);
	t_Proprietaire.ajouterVehicule(c1);
	ASSERT_EQ(false, t_Proprietaire.reqProprietaireFormate().empty());
}

/**
 * \test Test de la méthode reqNom
 * 	Cas valides: non est valide et non vide
 */
TEST_F(UnProprietaire, reqNom)
{
	ASSERT_EQ("Renaud", t_Proprietaire.reqNom());
}

/**
 * \test Test de la méthode reqPrenom
 * 	Cas valides: Prenom est valide et non vide
 */
TEST_F(UnProprietaire, reqPrenom)
{
	ASSERT_EQ("Morin", t_Proprietaire.reqPrenom());
}



