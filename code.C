#include <stdio.h>

#include <stdlib.h>

#include <string.h>



// === Déclarations des structures ===



typedef struct {

    int numero_client;       

    char nom[20];

    char prenom[20];

    char adresse[50];

    int age;

    char mail[50];

    char tel[20];

} Client;



typedef struct {

    int numero_client;  

    int numero_siege;

    char classe[20];

    int prix;

    char statut[20];

    int numero_vol;

} Reservation;



typedef struct {

    char compagnie[20];

    char lieu_depart[20];

    char lieu_arrive[20];

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

} Vols;



// === Fonctions de saisie ===



void saisirVol(Vols *v) {

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



void saisirReservation(Reservation *r) {

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



// === Fonctions de sauvegarde ===



void sauvegardeVol(Vols *v) {

    FILE *F_Vol = fopen("./Vols.dat", "ab+");

    if (F_Vol == NULL) {

        fprintf(stderr, "Erreur d'ouverture du fichier Vols.dat\n");

        exit(EXIT_FAILURE);

    }

    fwrite(v, sizeof(Vols), 1, F_Vol);

    fclose(F_Vol);

    printf("Vol sauvegardé avec succès !\n");

}



void sauvegardeReservation(Reservation *r) {

    FILE *F_Res = fopen("./Reservation.dat", "ab+");

    if (F_Res == NULL) {

        fprintf(stderr, "Erreur d'ouverture du fichier Reservation.dat\n");

        exit(EXIT_FAILURE);

    }

    fwrite(r, sizeof(Reservation), 1, F_Res);

    fclose(F_Res);

    printf("Réservation sauvegardée avec succès !\n");

}



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



// === Fonctions d'ajout ===



void ajouterVol(Vols *v) {

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



// === Fonctions d'affichage ===



void afficherVols() {

    FILE *F_Vol = fopen("./Vols.dat", "rb");

    if (F_Vol == NULL) {

        printf("Erreur d'ouverture du fichier Vols.dat\n");

        return;

    }

    Vols v;

    while (fread(&v, sizeof(Vols), 1, F_Vol)) {

        printf("Compagnie: %s | Départ: %s | Arrivée: %s | Numéro: %d\n", 

               v.compagnie, v.lieu_depart, v.lieu_arrive, v.numero_vol);

    }

    fclose(F_Vol);

}



void afficherReservations() {

    FILE *F_Res = fopen("./Reservation.dat", "rb");

    if (F_Res == NULL) {

        printf("Erreur d'ouverture du fichier Reservation.dat\n");

        return;

    }

    Reservation r;

    while (fread(&r, sizeof(Reservation), 1, F_Res)) {

        printf("Client: %d | Siège: %d | Classe: %s | Statut: %s\n",

               r.numero_client, r.numero_siege, r.classe, r.statut);

    }

    fclose(F_Res);

}



void afficherClients() {

    FILE *F_Client = fopen("./Client.dat", "rb");

    if (F_Client == NULL) {

        printf("Erreur d'ouverture du fichier Client.dat\n");

        return;

    }

    Client c;

    while (fread(&c, sizeof(Client), 1, F_Client)) {

        printf("Client: %d | Nom: %s | Prénom: %s | Email: %s\n",

               c.numero_client, c.nom, c.prenom, c.mail);

    }

    fclose(F_Client);

}



// === Fonction principale ===



int main() {

    int choix;

    Vols vol;

    Reservation reservation;

    Client client;



    do {

        printf("\n1. Afficher les Vols\n2. Afficher les Réservations\n3. Afficher les Clients\n4. Ajouter un Vol\n5. Ajouter une Réservation\n6. Ajouter un Client\n0. Quitter\n");

        scanf("%d", &choix);



        switch (choix) {

            case 1: afficherVols(); break;

            case 2: afficherReservations(); break;

            case 3: afficherClients(); break;

            case 4: ajouterVol(&vol); break;

            case 5: ajouterReservation(&reservation); break;

            case 6: ajouterClient(&client); break;

            case 0: printf("Au revoir!\n"); break;

            default: printf("Choix invalide.\n");

        }

    } while (choix != 0);



    return 0;

}

