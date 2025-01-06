#include "base_don_proj.h"





void saisirVol(Vols *v) {                 // Fonction de saisie pour les vols

    printf("=== Saisie d'un vol ===\n");

    printf("Compagnie : ");

    scanf("%19s", v->compagnie);

    printf("Lieu de départ : ");

    scanf("%19s", v->lieu_depart);

    printf("Lieu d'arrivée : ");

    scanf("%19s", v->lieu_arrive);

    printf("Date de départ : ");

    scanf("%19s", v->date_depart);

    printf("Date d'arrivée : ");

    scanf("%19s", v->date_arrive);

    printf("Durée (en heures) : ");

    scanf("%d", &v->duree);

    printf("Nombre de sièges économiques : ");

    scanf("%d", &v->nb_siege_eco);

    printf("Nombre de sièges affaires : ");

    scanf("%d", &v->nb_siege_aff);

    printf("Nombre de sièges première classe : ");

    scanf("%d", &v->nb_siege_class);

    printf("Numéro du vol : ");

    scanf("%d", &v->numero_vol);

    printf("Prix siège économique : ");

    scanf("%d", &v->prix_eco);

    printf("Prix siège affaires : ");

    scanf("%d", &v->prix_aff);

    printf("Prix siège première classe : ");

    scanf("%d", &v->prix_class);

}





void saisirReservation(Reservation *r) {                // Fonction de saisie pour une réservation

    printf("\n=== Saisie d'une réservation ===\n");

    printf("Numéro du client : ");

    scanf("%d", &r->numero_client);

    printf("Numéro du siège : ");

    scanf("%d", &r->numero_siege);

    printf("Classe (eco/aff/class) : ");

    scanf("%19s", r->classe);

    printf("Prix : ");

    scanf("%d", &r->prix);

    printf("Statut (confirmé/en attente) : ");

    scanf("%19s", r->statut);

    printf("Numéro du vol : ");

    scanf("%d", &r->numero_vol);

}





void saisirClient(Client *c) {                              // Fonction de saisie pour un client

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



// Fonction de sauvegarde pour les vols

void sauvegardeVol(Vols *v) {

    FILE *F_Vol = fopen("./Vols.dat", "ab+");

    if (F_Vol == NULL) {

        fprintf(stderr, "Erreur d'ouverture du fichier Vols.dat\n");

        exit(EXIT_FAILURE);

    }

    fwrite(v, sizeof(vols), 1, F_Vol);

    fclose(F_Vol);

    printf("Vol sauvegardé avec succès !\n");

}



// Fonction de sauvegarde pour les réservations

void sauvegardeReservation(Reservation *r) {

    FILE *F_Res = fopen("./Reservation.dat", "ab+");

    if (F_Res == NULL) {

        fprintf(stderr, "Erreur d'ouverture du fichier Reservation.dat\n");

        exit(EXIT_FAILURE);

    }

    fwrite(r, sizeof(reservation), 1, F_Res);

    fclose(F_Res);

    printf("Réservation sauvegardée avec succès !\n");

}



// Fonction de sauvegarde pour les clients

void sauvegardeClient(Client *c) {

    FILE *F_Client = fopen("./Client.dat", "ab+");

    if (F_Client == NULL) {

        fprintf(stderr, "Erreur d'ouverture du fichier Client.dat\n");

        exit(EXIT_FAILURE);

    }

    fwrite(c, sizeof(Client), 1, F_Client);

    fclose(F_Client);

    printf("Client sauvegardé avec succès !\n");

}



void ajouterVol(Vol *v) {

    saisirVol(v);

    sauvegardeVol(v);

}



void ajouterReservation(Reservation *r) {

    saisirReservation(r);

    sauvegardeReservation(r);

}



void ajouterClient(Client *c) {

    saisirClient(c);

    sauvegardeClient(c);

}

