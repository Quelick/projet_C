#include "vols.h"
#include <stdio.h>
#include <stdlib.h>

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

void sauvegardeVol(Vols *v) {
    FILE *file = fopen("./Vols.dat", "ab+");
    if (file == NULL) {
        perror("Erreur d'ouverture de Vols.dat");
        exit(EXIT_FAILURE);
    }
    fwrite(v, sizeof(Vols), 1, file);
    fclose(file);
}

void afficherVols() {
    FILE *file = fopen("./Vols.dat", "rb");
    Vols v;
    while (fread(&v, sizeof(Vols), 1, file)) {
        printf("Compagnie: %s | Numéro: %d\n", v.compagnie, v.numero_vol);
    }
    fclose(file);
}

void ajouterVol(Vols *v) {
    saisirVol(v);
    sauvegardeVol(v);
}
