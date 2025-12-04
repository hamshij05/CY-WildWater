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



//Struture de l'usine
typedef struct usine {
 char identifiant[64]; //identifiant unique de l'usine
 unsigned long capacité; //volume maximal de quantité d'eau de traitement
 unsigned long volume_capte; //somme des volumes captés
 unsigned long volume_traite; //somme pondéres des volumes captés (volume réellement traité)
 struct usine* fg; //fils gauche
 struct usine* fd; //fils droit
 int hauteur; //hauteur AVL
 int equilibre; //facteur d'équilibre AVL
 // Pour le calcul des fuites (peut pointer vers le nœud de l'arbre de distribution)
 void *distribution_node; // Pointeur vers le nœud racine de la distribution de cette usine
// Pointeur vers le premier nœud de distribution en aval (Stockages)
    struct NoeudDistribution *racine_distribution; 
}Usine;

    
  
    
    
} Factory;


typedef struct troncon {
    char aval[64]; // identifiant du nœud aval
    double volume; // volume d'eau
    double fuite; // pourcentage de fuite
    struct Troncon* suivant; // liste chaînée
}Troncon;

typedef struct Noeud {
    char id[64];             // identifiant du nœud (usine, stockage, jonction)
    Troncon *sorties;        // liste des tronçons sortants
// usine.h

typedef struct Usine {
    char *id;               // Identifiant unique de l'usine (clé de l'AVL)
    long max_capacite_k_m3; 
    long volume_capte_total_k_m3; 
    long volume_traite_reel_k_m3; 
    
    
    
    // Champs pour la gestion de l'AVL
    struct Usine *gauche;
    struct Usine *droite;
    int hauteur; 
} Usine;    

typedef struct Troncon {
    struct NoeudDistribution *noeud_aval; // Pointeur vers l'acteur aval (enfant)
    double pourcentage_fuite;            // Pourcentage de fuites dans ce tronçon (colonne 5)
    
    struct Troncon *suivant;             // Pour la liste chaînée des tronçons sortants
} Troncon; 

// Fonctions AVL
Noeud* creerNoeud(const char *id);
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
Arbre *creationArbre(long identifiant, const char* capacite, const char* consommation); //Création de noeud pour l'arbre AVL
Arbre *insertionAVL(Arbre* a, long identifiant, const char* capacite,const char* consommation); //Insertion de l'arbre AVL
long max(long x, long y); //Fonction pour obtenir la valeur maximale
Arbre *rotationGauche(Arbre *pivot); //Rotation gauche pour réequilibrer l'arbre
Arbre *rotationDroite(Arbre *a); //Rotation droite pour réequilibrer l'arbre
Arbre *doubleRotationGauche(Arbre* a); //Double Rotation Gauche
Arbre *doubleRotationDroite(Arbre* a); //Double Rotation Droite
int hauteur(Arbre* a); //Calcul de l'hauteur de l'arbre AVL
int facteur_equilibre(Arbre* r); //Calcul du facteur d'équilibre
void infixe(Arbre* a, FILE* fichier_resultat); //Parcours en ordre croissant (infixe = parcours en ordre) et écriture dans le fichier de sortie
void freeAVL(Arbre* a); //Libère la mémoire de l'arbre AVL
void traiterFichier(const char* nomFichier, const char* nomFichierTmp); // traite les fichiers en AVL

#endif



Traitement : usine de traiteent
Stockage : 
Distribution : principale (jonctions), secondaire (raccordements), branchement (relier le réseaux avec le compteur d'eau de l'usager)
Usagers : plus de vingaine de million

Seuls les trançons de raccordement utilises  par notre programme
Trançons (captage, stockage, distribution principale, secondaire, branchement) 
Les infos de chaque usine de traitement (caacité maximale annuelle de traitement de l'eau)
