#include "vols.h"
#include "clients.h"
#include "fichiers.h"
#include "reservations.h"
#include "menu.h"
#include <stdio.h>

int main() {
    int choixPrincipal, choixSousMenu;
    Vols vol;
    Reservation reservation;

    do {
        afficherMenuPrincipal();
        scanf("%d", &choixPrincipal);

        switch (choixPrincipal) {
            case 1:
                do {
                    afficherSousMenuAfficher();
                    scanf("%d", &choixSousMenu);
                    switch (choixSousMenu) {
                        case 1: afficherVols(); break;
                        case 2: afficherReservations(); break;
                        case 3: afficherClients(); break;
                        case 0: break;
                        default: printf("Choix invalide.\n");
                    }
                } while (choixSousMenu != 0);
                break;

            case 2:
                do {
                    afficherSousMenuAjouter();
                    scanf("%d", &choixSousMenu);
                    switch (choixSousMenu) {
                        case 1: ajouterVol(&vol); break;
                        case 2: ajouterReservation(&reservation); break;
                        case 0: break;
                        default: printf("Choix invalide.\n");
                    }
                } while (choixSousMenu != 0);
                break;

            case 3:
                do {
                    afficherSousMenuRechercher();
                    scanf("%d", &choixSousMenu);
                    switch (choixSousMenu) {
                        case 1: afficheRechercheClients(); break;
                        case 2: afficheRechercheReservation(); break;
                        case 3: afficheRechercheVol(); break;
                        case 4: afficheRechercheReservationVol(); break;
                        case 5:afficheRechercheVolParDestination();break;
            		case 6:afficheRechercheVolParDateDepart();break;
            		case 7:afficheRechercheVolParDateArrivee();break;
                        case 0: break;
                        default: printf("Choix invalide.\n");
                    }
                } while (choixSousMenu != 0);
                break;
                
                case 4:
    do {
        afficherSousMenuFichiers();
        scanf("%d", &choixSousMenu);
        switch (choixSousMenu) {
            case 1: initialiserFichierAvecEntete("./data/Vols.dat", sizeof(Vols)); break;
            case 2: initialiserFichierAvecEntete("./data/Reservation.dat", sizeof(Reservation)); break;
            case 3: initialiserFichierAvecEntete("./data/Clients.dat", sizeof(Client)); break;
            case 4: lireEnteteFichier("./data/Vols.dat"); break;
            case 5: lireEnteteFichier("./data/Reservation.dat"); break;
            case 6: lireEnteteFichier("./data/Clients.dat"); break;
            case 0: break;
            default: printf("Choix invalide.\n");
        }
    } while (choixSousMenu != 0);
    break;


            case 0:
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide.\n");
        }
    } while (choixPrincipal != 0);

    return 0;
}
