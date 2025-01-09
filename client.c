#include "client.h"

#include <stdio.h>
#include <string.h>


Client clients[100];
int client_count = 0;

void ajouterClient(Client c) {
    clients[client_count] = c;
    client_count++;
    enregistrerClients();
}

void afficherClients() {
    for (int i = 0; i < client_count; i++) {
        printf("ID: %d, Nom: %s, Prénom: %s, Email: %s, Réservations: %d\n", 
            clients[i].id, clients[i].nom, clients[i].prenom, clients[i].email, clients[i].reservation_count);
    }
}

Client* rechercherClient(int id) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].id == id) {
            return &clients[i];
        }
    }
    return NULL;
}

void enregistrerClients() {
    FILE *file = fopen("Client.dat", "wb");
    if (file != NULL) {
        fwrite(clients, sizeof(Client), client_count, file);
        fclose(file);
    }
}

void chargerClients() {
    FILE *file = fopen("Client.dat", "rb");
    if (file != NULL) {
        client_count = fread(clients, sizeof(Client), 100, file);
        fclose(file);
    }
}

void modifierClient(int id) {
    Client* client = rechercherClient(id);
    if (client != NULL) {
        printf("Client trouvé: %s %s\n", client->prenom, client->nom);
        printf("Entrez le nouveau nom du client (laissez vide pour ne pas changer): ");
        char newNom[50];
        fgets(newNom, sizeof(newNom), stdin);
        if (newNom[0] != '\n') {
            strcpy(client->nom, newNom);
        }

        printf("Entrez le nouveau prénom du client (laissez vide pour ne pas changer): ");
        char newPrenom[50];
        fgets(newPrenom, sizeof(newPrenom), stdin);
        if (newPrenom[0] != '\n') {
            strcpy(client->prenom, newPrenom);
        }

        printf("Entrez le nouvel email du client (laissez vide pour ne pas changer): ");
        char newEmail[100];
        fgets(newEmail, sizeof(newEmail), stdin);
        if (newEmail[0] != '\n') {
            strcpy(client->email, newEmail);
        }

        enregistrerClients();
        printf("Informations du client mises à jour avec succès.\n");
    } else {
        printf("Client non trouvé.\n");
    }
}

void trierClientsParId() {
    for (int i = 0; i < client_count - 1; i++) {
        for (int j = i + 1; j < client_count; j++) {
            if (clients[i].id > clients[j].id) {
                Client temp = clients[i];
                clients[i] = clients[j];
                clients[j] = temp;
            }
        }
    }
    printf("Clients triés par ID.\n");
}

void afficherStatsClients() {
    for (int i = 0; i < client_count; i++) {
        printf("Client %s %s a effectué %d réservations.\n", clients[i].prenom, clients[i].nom, clients[i].reservation_count);
    }
}

