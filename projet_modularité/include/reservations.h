#ifndef RESERVATIONS_H
#define RESERVATIONS_H

typedef struct {
    int numero_client;  
    int numero_siege;
    char classe[20];
    int prix;
    char statut[20];
    int numero_vol;
} Reservation;

void saisirReservation(Reservation *r);
void sauvegardeReservation(Reservation *r);
void afficherReservations();
void ajouterReservation(Reservation *r);

#endif // RESERVATIONS_H
