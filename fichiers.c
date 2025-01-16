#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fichiers.h"

FILE *ouvrirFichier(const char *nomFichier, const char *mode) {
    FILE *fichier = fopen(nomFichier, mode);
    if (!fichier) {
        perror("Erreur lors de l'ouverture du fichier");
    }
    return fichier;
}

// Fonction pour initialiser un fichier avec une entête
void initialiserFichierAvecEntete(const char *nomFichier, int tailleEnregistrement) {
    FILE *fichier = ouvrirFichier(nomFichier, "wb");
    if (!fichier) return;

    EnteteFichier entete;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    entete.annee = tm.tm_year + 1900;
    entete.mois = tm.tm_mon + 1;
    entete.jour = tm.tm_mday;
    entete.nbEnregistrements = 0;
    entete.tailleEntete = sizeof(EnteteFichier);
    entete.tailleEnregistrement = tailleEnregistrement;

    fwrite(&entete, sizeof(EnteteFichier), 1, fichier);

    fclose(fichier);
    printf("Fichier '%s' initialisé avec succès.\n", nomFichier);
}

// Fonction pour mettre à jour l'entête d'un fichier
void mettreAJourEnteteFichier(const char *nomFichier, int increment) {
    FILE *fichier = ouvrirFichier(nomFichier, "rb+"); // Utilisation de ouvrirFichier
    if (!fichier) return;

    EnteteFichier entete;

    fread(&entete, sizeof(EnteteFichier), 1, fichier);

    entete.nbEnregistrements += increment;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    entete.annee = tm.tm_year + 1900;
    entete.mois = tm.tm_mon + 1;
    entete.jour = tm.tm_mday;

    fseek(fichier, 0, SEEK_SET);
    fwrite(&entete, sizeof(EnteteFichier), 1, fichier);

    fclose(fichier);
}

// Fonction pour lire et afficher l'entête d'un fichier
void lireEnteteFichier(const char *nomFichier) {
    FILE *fichier = ouvrirFichier(nomFichier, "rb"); // Utilisation de ouvrirFichier
    if (!fichier) return;

    EnteteFichier entete;

    fread(&entete, sizeof(EnteteFichier), 1, fichier);

    printf("Date de dernière mise à jour : %d-%02d-%02d\n", entete.annee, entete.mois, entete.jour);
    printf("Nombre total d'enregistrements : %d\n", entete.nbEnregistrements);
    printf("Taille de l'entête : %d octets\n", entete.tailleEntete);
    printf("Taille des enregistrements : %d octets\n", entete.tailleEnregistrement);

    fclose(fichier);
}

