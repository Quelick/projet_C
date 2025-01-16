#include "vols.h"
#include "clients.h"
#include "reservations.h"
#include <stdio.h>

void afficherMenuPrincipal() {
    printf("\nMenu Principal:\n");
    printf("1. Afficher les informations\n");
    printf("2. Ajout d'informations\n");
    printf("3. Rechercher une information\n");
    printf("4. Gestion des fichiers\n");
    printf("0. Quitter\n");
    printf("Votre choix: ");
}

void afficherSousMenuAfficher() {
    printf("\nSous-Menu Afficher:\n");
    printf("1. Afficher les Vols\n");
    printf("2. Afficher les Réservations\n");
    printf("3. Afficher les Clients\n");
    printf("4. Afficher les entetes des fichiers\n");
    printf("0. Retour au menu principal\n");
    printf("Votre choix: ");
}

void afficherSousMenuAjouter() {
    printf("\nSous-Menu Ajouter:\n");
    printf("1. Ajouter un Vol\n");
    printf("2. Ajouter une Réservation\n");
    printf("0. Retour au menu principal\n");
    printf("Votre choix: ");
}

void afficherSousMenuRechercher() {
    printf("\nSous-Menu Rechercher:\n");
    printf("1. Rechercher un client par nom\n");
    printf("2. Rechercher une réservation par numéro de client\n");
    printf("3. Rechercher un vol par numéro de vol\n");
    printf("4. Rechercher une réservation par numéro de vol\n");
    printf("5. Rechercher un vol par destination\n");
    printf("6. Rechercher un vol par date de départ\n");
    printf("7. Rechercher un vol par date d'arrivé\n");
    printf("0. Retour au menu principal\n");
    printf("Votre choix: ");
}

void afficherSousMenuFichiers() {
    printf("\nSous-Menu Fichiers:\n");
    printf("1. Initialiser le fichier des Vols\n");
    printf("2. Initialiser le fichier des Réservations\n");
    printf("3. Initialiser le fichier des Clients\n");
    printf("4. Lire l'entête du fichier des Vols\n");
    printf("5. Lire l'entête du fichier des Réservations\n");
    printf("6. Lire l'entête du fichier des Clients\n");
    printf("0. Retour au menu principal\n");
    printf("Votre choix: ");
}



