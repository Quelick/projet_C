#ifndef FICHIERS_H
#define FICHIERS_H

#include <stdio.h>
#include <time.h>

typedef struct {
    short annee;        // Année de la dernière mise à jour
    short mois;         // Mois de la dernière mise à jour
    short jour;         // Jour de la dernière mise à jour
    int nbEnregistrements; // Nombre total d'enregistrements
    int tailleEntete;   // Taille de l'entête
    int tailleEnregistrement; // Taille d'un enregistrement
} EnteteFichier;

FILE *ouvrirFichier(const char *nomFichier, const char *mode);
void initialiserFichierAvecEntete(const char *nomFichier, int tailleEnregistrement);
void mettreAJourEnteteFichier(const char *nomFichier, int increment);
void lireEnteteFichier(const char *nomFichier);

#endif // FICHIERS_H
