#ifndef CLIENTS_H
#define CLIENTS_H

typedef struct {
    int numero_client;       
    char nom[20];
    char prenom[20];
    char adresse[50];
    int age;
    char mail[50];
    char tel[20];
} Client;

void saisirClient(Client *c);
void sauvegardeClient(Client *c);
void afficherClients();
void ajouterClient(Client *c);

#endif // CLIENTS_H
