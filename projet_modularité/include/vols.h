#ifndef VOLS_H
#define VOLS_H

typedef struct {
    char compagnie[20];
    char lieu_depart[20];
    char lieu_arrive[20];
    char date_depart[20];
    char date_arrive[20];
    int duree;
    int nb_siege_eco;
    int nb_siege_aff;
    int nb_siege_class;
    int numero_vol;
    int prix_eco;
    int prix_aff;
    int prix_class;
} Vols;

void saisirVol(Vols *v);
void sauvegardeVol(Vols *v);
void afficherVols();
void ajouterVol(Vols *v);

#endif // VOLS_H
