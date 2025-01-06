#include<stdio.h>

#include<stdlib.h>





typedef struct{

        int numero_client;       

        char nom[20];

        char prenom[20];

        char adresse[50];

        int age;

        char mail[50];

        char tel[20];

}Client;



typedef struct{

        int numero_client;  

        int numero_siege;

        char classe[20];

        int prix;

        char statut[20];

        int numero_vol;

}reservation;



typedef struct{

	char compagnie[20];

	char lieu_depart[20];

	char lieu_arrive[20]:

	char date_depart[20];

	char date_arrive[20];

	int duree;

	int nb_siege_eco;

	int nb_siege_aff;

	int nb_siege_class;

	int numero_vol;

	int prix_eco;

	int prix_aff;

	int prix_class;

}vols;



void saisirVol(vols *v);

void saisirReservation(reservation *r);

void saisirClient(client *c);



void sauvegardeVol(vols *v);

void sauvegardeReservation(reservation *r);

void sauvegardeClient(Client *c);



void ajouterVol(Vol *v);

void ajouterReservation(Reservation *r);

void ajouterClient(Client *c);



	

	

	

	

	

	

	