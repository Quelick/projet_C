#ifndef RESERVATION_H
#define RESERVATION_H

#include <stdio.h>
#include <string.h>
#include "client.h"
#include "vol.h"

typedef struct {
    int client_id;
    int vol_id;
    float montant;  // Montant payé pour la réservation
} Reservation;

extern Reservation reservations[100];
extern int reservation_count;

void ajouterReservation(Reservation r);
void afficherReservations();
void annulerReservation(int client_id, int vol_id);
void modifierReservation(int client_id, int vol_id);
void enregistrerReservations();
void chargerReservations();

#endif

