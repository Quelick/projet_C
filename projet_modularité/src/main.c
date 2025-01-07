#include "vols.h"
#include "clients.h"
#include "reservations.h"
#include "menu.h"
#include <stdio.h>

int main() {
    int choix;
    Vols vol;
    Reservation reservation;
    Client client;

    do {
         printf("\n1. Afficher les Vols\n2. Afficher les Réservations\n3. Afficher les Clients\n4. Ajouter un Vol\n5. Ajouter une Réservation\n6. Ajouter un Client\n0. Quitter\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1: afficherVols(); break;
            case 2: afficherReservations(); break;
            case 3: afficherClients(); break;
            case 4: ajouterVol(&vol); break;
            case 5: ajouterReservation(&reservation); break;
            case 6: ajouterClient(&client); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
