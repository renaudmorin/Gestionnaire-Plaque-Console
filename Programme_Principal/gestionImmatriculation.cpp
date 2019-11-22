/**
 * \file gestionImmatriculation.cpp
 * \brief Fichier principal du programme qui demande a lutilisateur dentrer une plaque dautomobile
 * \date 2019-10-15
 * \author Renaud Morin
 */
#include <iostream>
#include "../source/Camion.h"
#include "../source/Vehicule.h"
#include "../source/VehiculePromenade.h"
#include "../source/validationFormat.h"
#include "../source/Proprietaire.h"
#include "../source/Date.h"
#include <string>
#include <sstream>
using namespace std;

int main(){

	cout << "=====================================================" << endl;
	cout << "|Bienvenue a l'outil d;ajout de gestion de vehicules|" << endl;
	cout << "=====================================================" << endl;

	cout << "-----------------------------------------------------" << endl;
	cout << "|          Ajoutez un vehicule de promenade          |" << endl;
	cout << "-----------------------------------------------------" << endl;

	saaq::Proprietaire p1("Renaud", "Morin");
	util::Date date;


	cout<< "Veuillez entrer un NIV valide pour l'automobile de promenade: "<<endl;
	string nivPromenade;
	char buffer[256];
	cin.getline(buffer, 255);
	nivPromenade = buffer;
	while(util::validerNiv(nivPromenade) == false){
		cout<<"Niv invalide!"<<endl;
		cout<<"Veuillez entrer un NIV valide pour l'automobile de promenade: "<<endl;;
		cin.getline(buffer, 255);
		nivPromenade = buffer;
	}

	cout<<endl;
	cout<< "Veuillez entrer une plaque valide pour l'automobile de promenade: "<<endl;
	string plaquePromenade;
	cin.getline(buffer, 255);
	plaquePromenade = buffer;
	while(util::validerImmatriculationPromenade(plaquePromenade) == false){
		cout<<"Plaque invalide!"<<endl;
		cout<<"Veuillez entrer une plaque valide pour l'automobile de promenade: "<<endl;;
		cin.getline(buffer, 255);
		plaquePromenade = buffer;
	}
	cout<< "Veuillez entrer le nombre de place(>0): "<<endl;
	int nb_place_promenade;
	cin>>nb_place_promenade;
    cin.clear();
    cin.ignore(132, '\n');
	while(nb_place_promenade <= 0){
		cout<<"Nombre de place: invalide!"<<endl;
		cout<<"Veuillez entrer le nombre de place(>0): "<<endl;;
        cin.clear();
        cin.ignore(132, '\n');
    	cin>>nb_place_promenade;
	}
	cout << "-----------------------------------------------------" << endl;
	cout << "|                  Ajoutez un Camion                 |" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout<< "Veuillez entrer un NIV valide pour le camion: "<<endl;
	string nivCamion;
	cin.getline(buffer, 255);
	nivCamion = buffer;
	while(util::validerNiv(nivCamion) == false){
		cout<<"Niv invalide!"<<endl;
		cout<<"Veuillez entrer un NIV valide pour le camion: "<<endl;
		cin.getline(buffer, 255);
		nivCamion = buffer;
		}

	cout<<endl;
	cout<< "Veuillez entrer une plaque valide pour pour le camion: "<<endl;
	string plaqueCamion;
	cin.getline(buffer, 255);
	plaqueCamion = buffer;
	while(util::validerImmatriculationCamion(plaqueCamion) == false){
		cout<<"Plaque invalide!"<<endl;
		cout<<"Veuillez entrer une plaque valide pour pour le camion: "<<endl;;
		cin.getline(buffer, 255);
		plaqueCamion = buffer;
		}
	cout<< "Veuillez entrer le poid du camion (>3000): "<<endl;
	int poid_camion;
	cin>>poid_camion;
    cin.clear();
    cin.ignore(132, '\n');
	while(poid_camion <= 0){
		cout<<"Poid invalide!"<<endl;
		cout<<"Veuillez entrer le le poid du camion(>3000): "<<endl;;
		cin.clear();
		cin.ignore(132, '\n');
		cin>>poid_camion;
		}

	cout<< "Veuillez entrer le nombre d'essieux (>=2): "<<endl;
	int nb_essieux_camion;
	cin>>nb_essieux_camion;
    cin.clear();
    cin.ignore(132, '\n');
	while(nb_essieux_camion <= 0){
		cout<<"Nombre d'essieux invalide!"<<endl;
		cout<<"Veuillez entrer le nombre d'essieux (>=2): "<<endl;;
		cin.clear();
		cin.ignore(132, '\n');
		cin>>nb_essieux_camion;
		}
	saaq::VehiculePromenade vProm(nb_place_promenade, nivPromenade, plaquePromenade, date);
	saaq::Camion vCam(poid_camion, nb_essieux_camion, nivCamion, plaqueCamion, date);
	p1.ajouterVehicule(vProm);
	p1.ajouterVehicule(vCam);
	cout<<p1.reqProprietaireFormate();


	cout<<endl;
	cout<<"============================================="<<endl;
	cout<<"Enregistrement fait avec succes!"<<endl;
	cout<<"Fermeture du programme!"<<endl;
	cout<<"============================================="<<endl;
	cout<<endl;




	return 0;
}



