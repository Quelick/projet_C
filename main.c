#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "vol.h"
#include "reservation.h"

int main() {
    chargerClients();
    chargerVols();
    chargerReservations();
    
    int choice;
    do {
        printf("\nGestion des Vols et Réservations\n");
        printf("1. Ajouter un client\n");
        printf("2. Ajouter un vol\n");
        printf("3. Ajouter une réservation\n");
        printf("4. Afficher les clients\n");
        printf("5. Afficher les vols\n");
        printf("6. Afficher les réservations\n");
        printf("7. Modifier un client\n");
        printf("8. Trier les clients par ID\n");
        printf("9. Trier les vols par prix\n");
        printf("10. Rechercher un vol par date\n");
        printf("11. Afficher les vols complets\n");
        printf("12. Annuler une réservation\n");
        printf("13. Modifier une réservation\n");
        printf("14. Afficher les statistiques des clients\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choice);
        getchar(); // Pour consommer le retour à la ligne

        switch (choice) {
            case 1: {
                Client c;
                printf("|----------1.Ajouter un client----------|\n");
                printf("a-Entrez l'ID du client:\n ");
                scanf("%d", &c.id);
                getchar();
                printf("b-Entrez le nom du client: \n");
                fgets(c.nom, sizeof(c.nom), stdin);
                printf("c-Entrez le prénom du client: \n");
                fgets(c.prenom, sizeof(c.prenom), stdin);
                printf("d-Entrez l'email du client: \n");
                fgets(c.email, sizeof(c.email), stdin);
                c.reservation_count = 0;
                ajouterClient(c);
                break;
            }
            case 2: {
                Vol v;
                printf("|----------2.Ajouter un vol----------|\n");
                printf("a-Entrez l'ID du vol: \n");
                scanf("%d", &v.id);
                getchar();
                printf("a-Entrez la destination du vol: \n");
                fgets(v.destination, sizeof(v.destination), stdin);
                printf("b-Entrez la date du vol (format JJ/MM/AAAA): \n");
                fgets(v.date, sizeof(v.date), stdin);
                printf("c-Entrez le prix du vol: \n");
                scanf("%f", &v.prix);
                printf("d-Entrez le nombre de places disponibles: \n");
                scanf("%d", &v.places_disponibles);
                ajouterVol(v);
                break;
            }
            case 3: {
                Reservation r;
                printf("|----------3.Ajouter une réservation----------|\n");
                printf("a-Entrez l'ID du client:\n ");
                scanf("%d", &r.client_id);
                printf("b-Entrez l'ID du vol: \n");
                scanf("%d", &r.vol_id);
                printf("c-Entrez le montant payé pour la réservation: \n");
                scanf("%f", &r.montant);
                ajouterReservation(r);
                break;
            }
            case 4:
                afficherClients();
                break;
            case 5:
                afficherVols();
                break;
            case 6:
                afficherReservations();
                break;
            case 7: {
                int id;
                printf("---Entrez l'ID du client à modifier: \n");
                scanf("%d", &id);
                modifierClient(id);
                break;
            }
            case 8:
                trierClientsParId();
                break;
            case 9:
                trierVolsParPrix();
                break;
            case 10: {
                char date[20];
                printf("---Entrez la date à rechercher (format JJ/MM/AAAA):\n ");
                fgets(date, sizeof(date), stdin);
                rechercherVolParDate(date);
                break;
            }
            case 11:
                afficherVolsComplets();
                break;
            case 12: {
                int client_id, vol_id;
                printf("---Entrez l'ID du client:\n ");
                scanf("%d", &client_id);
                printf("---Entrez l'ID du vol à annuler:\n ");
                scanf("%d", &vol_id);
                annulerReservation(client_id, vol_id);
                break;
            }
            case 13: {
                int client_id, vol_id;
                printf("---Entrez l'ID du client: \n");
                scanf("%d", &client_id);
                printf("---Entrez l'ID du vol à modifier:\n ");
                scanf("%d", &vol_id);
                modifierReservation(client_id, vol_id);
                break;
            }
            case 14:
                afficherStatsClients();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

