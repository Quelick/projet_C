#ifndef VOL_H
#define VOL_H

#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char destination[50];
    char date[20];
    float prix;
    int places_disponibles;
} Vol;

extern Vol vols[100];
extern int vol_count;

void ajouterVol(Vol v);
void afficherVols();
Vol* rechercherVol(int id);
void enregistrerVols();
void chargerVols();
void trierVolsParPrix();
void rechercherVolParDate(char* date);
void afficherVolsComplets();
int verifierPlacesDisponibles(int vol_id);

#endif

