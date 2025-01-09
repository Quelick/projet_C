#include "reservation.h"

Reservation reservations[100];
int reservation_count = 0;

void ajouterReservation(Reservation r) {
    if (verifierPlacesDisponibles(r.vol_id) > 0) {
        reservations[reservation_count] = r;
        reservation_count++;
        // Décrémenter le nombre de places disponibles du vol
        Vol* vol = rechercherVol(r.vol_id);
        if (vol != NULL) {
            vol->places_disponibles--;
        }
        enregistrerReservations();
        printf("Réservation ajoutée avec succès.\n");
    } else {
        printf("Aucune place disponible pour ce vol.\n");
    }
}

void afficherReservations() {
    for (int i = 0; i < reservation_count; i++) {
        printf("Client ID: %d, Vol ID: %d, Montant payé: %.2f\n", 
               reservations[i].client_id, reservations[i].vol_id, reservations[i].montant);
    }
}

void annulerReservation(int client_id, int vol_id) {
    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].client_id == client_id && reservations[i].vol_id == vol_id) {
            // Supprimer la réservation
            for (int j = i; j < reservation_count - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            reservation_count--;
            // Réincrémenter le nombre de places disponibles du vol
            Vol* vol = rechercherVol(vol_id);
            if (vol != NULL) {
                vol->places_disponibles++;
            }
            enregistrerReservations();
            printf("Réservation annulée avec succès.\n");
            return;
        }
    }
    printf("Réservation non trouvée.\n");
}

void modifierReservation(int client_id, int vol_id) {
    for (int i = 0; i < reservation_count; i++) {
        if (reservations[i].client_id == client_id && reservations[i].vol_id == vol_id) {
            printf("Réservation trouvée.\n");
            printf("Entrez le nouveau montant de la réservation: ");
            scanf("%f", &reservations[i].montant);
            enregistrerReservations();
            printf("Réservation mise à jour avec succès.\n");
            return;
        }
    }
    printf("Réservation non trouvée.\n");
}

void enregistrerReservations() {
    FILE *file = fopen("Reservation.dat", "wb");
    if (file != NULL) {
        fwrite(reservations, sizeof(Reservation), reservation_count, file);
        fclose(file);
    }
}

void chargerReservations() {
    FILE *file = fopen("Reservation.dat", "rb");
    if (file != NULL) {
        reservation_count = fread(reservations, sizeof(Reservation), 100, file);
        fclose(file);
    }
}

