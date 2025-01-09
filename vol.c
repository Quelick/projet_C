#include "vol.h"

#include <stdio.h>
#include <string.h>

Vol vols[100];
int vol_count = 0;

void ajouterVol(Vol v) {
    vols[vol_count] = v;
    vol_count++;
    enregistrerVols();
}

void afficherVols() {
    for (int i = 0; i < vol_count; i++) {
        printf("ID: %d, Destination: %s, Date: %s, Prix: %.2f, Places disponibles: %d\n", 
            vols[i].id, vols[i].destination, vols[i].date, vols[i].prix, vols[i].places_disponibles);
    }
}

Vol* rechercherVol(int id) {
    for (int i = 0; i < vol_count; i++) {
        if (vols[i].id == id) {
            return &vols[i];
        }
    }
    return NULL;
}

void enregistrerVols() {
    FILE *file = fopen("Vols.dat", "wb");
    if (file != NULL) {
        fwrite(vols, sizeof(Vol), vol_count, file);
        fclose(file);
    }
}

void chargerVols() {
    FILE *file = fopen("Vols.dat", "rb");
    if (file != NULL) {
        vol_count = fread(vols, sizeof(Vol), 100, file);
        fclose(file);
    }
}

void trierVolsParPrix() {
    for (int i = 0; i < vol_count - 1; i++) {
        for (int j = i + 1; j < vol_count; j++) {
            if (vols[i].prix > vols[j].prix) {
                Vol temp = vols[i];
                vols[i] = vols[j];
                vols[j] = temp;
            }
        }
    }
    printf("Vols triés par prix.\n");
}

void rechercherVolParDate(char* date) {
    int found = 0;
    for (int i = 0; i < vol_count; i++) {
        if (strcmp(vols[i].date, date) == 0) {
            printf("ID: %d, Destination: %s, Date: %s, Prix: %.2f, Places disponibles: %d\n",
                   vols[i].id, vols[i].destination, vols[i].date, vols[i].prix, vols[i].places_disponibles);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun vol trouvé pour la date %s.\n", date);
    }
}

void afficherVolsComplets() {
    int found = 0;
    for (int i = 0; i < vol_count; i++) {
        if (vols[i].places_disponibles == 0) {
            printf("Vol ID: %d, Destination: %s, Date: %s est complet.\n", 
                   vols[i].id, vols[i].destination, vols[i].date);
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun vol complet.\n");
    }
}

int verifierPlacesDisponibles(int vol_id) {
    for (int i = 0; i < vol_count; i++) {
        if (vols[i].id == vol_id) {
            return vols[i].places_disponibles;
        }
    }
    return -1;  // Vol non trouvé
}

