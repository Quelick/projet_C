#include "clients.h"
#include <stdio.h>
#include <stdlib.h>

void saisirClient(Client *c) {
    printf("\n=== Saisie d'un client ===\n");
    printf("Numéro du client : ");
    scanf("%d", &c->numero_client);
    printf("Nom : ");
    scanf("%19s", c->nom);
    printf("Prénom : ");
    scanf("%19s", c->prenom);
    printf("Adresse : ");
    scanf("%49s", c->adresse);
    printf("Âge : ");
    scanf("%d", &c->age);
    printf("Email : ");
    scanf("%49s", c->mail);
    printf("Téléphone : ");
    scanf("%19s", c->tel);
}

void sauvegardeClient(Client *c) {
    FILE *file = fopen("./Client.dat", "ab+");
    if (file == NULL) {
        perror("Erreur d'ouverture de Client.dat");
        exit(EXIT_FAILURE);
    }
    fwrite(c, sizeof(Client), 1, file);
    fclose(file);
}

void afficherClients() {
    FILE *file = fopen("./Client.dat", "rb");
    Client c;
    while (fread(&c, sizeof(Client), 1, file)) {
        printf("Nom: %s | Email: %s\n", c.nom, c.mail);
    }
    fclose(file);
}

void ajouterClient(Client *c) {
    saisirClient(c);
    sauvegardeClient(c);
}
