#include "biblio.h"
#include "fonction.c"
#define MAX_LINE 1024




//Parse une ligne du CSV
int pars_csv(char* ligne, CSVLigne *resultat){
char *token;
int col=0;
//Initialiser
strcpy(resultat->col1, "-");
strcpy(resultat->col2, "-");
strcpy(resultat->col3, "-");
resultat->volume = -1;
resultat->fuite= -1.0;

token= strtok(line, ";");


//Structure pour

int main(int argc, char* argv[]) {
    const char *input_file = argv[1];
    const char *fichier_resultat = argv[2];
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

