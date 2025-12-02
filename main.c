#include "biblio.h"
#include "fonction.c"

int main(int argc, char* argv[]) {
    const char *input_file = argv[1];
    const char *fichier_resultat = argv[2];


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage : %s fichier.csv\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *f = fopen(filename, "r");

    if (!f) {
        perror("Erreur d’ouverture du fichier");
        return 1;
    }

    Troncon t;

    printf("Lecture du fichier : %s\n", filename);

    int compteur = 0;

    // Boucle principale de lecture
    while (lire_ligne(f, &t)) {
        compteur++;

        // ➤ Pour l'instant : juste afficher (debug)
        printf("%d | usine=%s | amont=%s | aval=%s | vol=%.2f | fuite=%.2f\n",
               compteur, t.usine, t.amont, t.aval, t.volume, t.fuite);

        // Plus tard, on fera ici :
        // accumulate volumes
        // handle stockage
        // calcul des fuites
        // etc.
    }

    fclose(f);

    printf("\nLecture terminée. %d lignes lues.\n", compteur);

    return 0;
}

