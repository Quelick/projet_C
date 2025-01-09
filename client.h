#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char email[100];
    int reservation_count;  // Nombre de réservations faites par le client
} Client;

extern Client clients[100];
extern int client_count;

void ajouterClient(Client c);
void afficherClients();
Client* rechercherClient(int id);
void enregistrerClients();
void chargerClients();
void modifierClient(int id);
void trierClientsParId();
void afficherStatsClients();

#endif

