/**
  *@file biblio.h
  *@author J.Hamshigaa
*/

#ifndef BIBLIO_H
#define BIBLIO_H

//Inclusion des bibliothèques nécessaires
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>



//Struture de l'AVL pour les usines
typedef struct avl {
 char identifiant[64]; //identifiant unique de l'usine
 unsigned long capacité; //volume maximal de quantité d'eau de traitement
 unsigned long volume_capte; //somme des volumes captés
 unsigned long volume_traite; //somme pondéres des volumes captés (volume réellement traité)
 int equilibre; //facteur d'équilibre AVL
 struct avl* fg; //fils gauche
 struct avl* fd; //fils droit
 int hauteur; //hauteur AVL
 // Pour le calcul des fuites (peut pointer vers le nœud de l'arbre de distribution)
 void *distribution_node; // Pointeur vers le nœud racine de la distribution de cette usine
// Pointeur vers le premier nœud de distribution en aval (Stockages)
 struct NoeudDistribution *racine_distribution;
Trancon* sorties; //liste des trançons sortants
}AVL;


typedef struct troncon {
    char aval[64]; // identifiant du nœud aval
    double volume; // volume d'eau
    double fuite; // pourcentage de fuite
    struct Troncon* suivant; // liste chaînée
}Troncon;

    
int hauteur(Noeud *n);
void maj(Noeud *n);
Noeud* rotationGauche(Noeud *x);
Noeud* rotationDroite(Noeud *y);
Noeud* insererNoeud(Noeud *racine, Noeud *n);
Noeud* rechercherNoeud(Noeud *racine, const char *id);
void afficherArbre(Noeud *racine);

// Fonctions tronçon
void ajouterTroncon(Noeud *n, const char *aval, double volume, double fuite);
// distribution.h

typedef struct NoeudDistribution {
    char *id;               // Identifiant de l'acteur (clé pour le second AVL de recherche rapide)
    
    // Pointeur vers la tête de la liste chaînée des tronçons sortants (ses enfants)
    struct Troncon *troncons_sortants; 
    
    // Champs pour le second AVL (pour retrouver les parents/nœuds rapidement pendant la lecture du CSV)
    struct NoeudDistribution *avl_gauche;
    struct NoeudDistribution *avl_droite;
    int avl_hauteur;
    
    // Autres données si nécessaires (ex: identifiant de l'usine si non géré par le tronçon amont)
} NoeudDistribution;

//Prototype des fonctions
AVL* creationArbre(const char* identifiant); //Création de noeud pour l'arbre AVL
AVL* insertionAVL(AVL* a, const char* identifiant); //Insertion de l'arbre AVL
AVL* recherche(AVL* a, const char* identifiant);
void freeAVL(Arbre* a); //Libère la mémoire de l'arbre AVL
//Parcours d'AVL
void infixe(Arbre* a, FILE* fichier_resultat); //Parcours en ordre croissant (infixe = parcours en ordre) et écriture dans le fichier de sortie
//Fonctions utiles
int hauteur(AVL* a); //Calcul de l'hauteur de l'arbre AVL
int facteur_equilibre(AVL* r); //Calcul du facteur d'équilibre
AVL* rotationGauche(Arbre *pivot); //Rotation gauche pour réequilibrer l'arbre
AVL* rotationDroite(Arbre *a); //Rotation droite pour réequilibrer l'arbre
Arbre *doubleRotationGauche(Arbre* a); //Double Rotation Gauche
Arbre *doubleRotationDroite(Arbre* a); //Double Rotation Droite
void traiterFichier(const char* nomFichier, const char* nomFichierTmp); // traite les fichiers en AVL

#endif
