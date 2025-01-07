#include "reservations.h"
#include <stdio.h>
#include <stdlib.h>

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

void sauvegardeReservation(Reservation *r) {
    FILE *file = fopen("./Reservation.dat", "ab+");
    if (file == NULL) {
        perror("Erreur d'ouverture de Reservation.dat");
        exit(EXIT_FAILURE);
    }
    fwrite(r, sizeof(Reservation), 1, file);
    fclose(file);
}

void afficherReservations() {
    FILE *file = fopen("./Reservation.dat", "rb");
    Reservation r;
    while (fread(&r, sizeof(Reservation), 1, file)) {
        printf("Client: %d | Siège: %d\n", r.numero_client, r.numero_siege);
    }
    fclose(file);
}

void ajouterReservation(Reservation *r) {
    saisirReservation(r);
    sauvegardeReservation(r);
}
