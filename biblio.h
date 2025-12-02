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
 char identifiant[64]; //identifiant de la station
 unsigned long capacité;
 unsigned long volume_capté;
 unsigned long volume_traite;
 struct usine* suivante;
}Usine;




typedef struct troncon {
    char aval[64]; // identifiant du nœud aval
    double volume; // volume d'eau
    double fuite; // pourcentage de fuite
    struct Troncon* suivant; // liste chaînée
}Troncon;

typedef struct Noeud {
    char id[64];             // identifiant du nœud (usine, stockage, jonction)
    Troncon *sorties;        // liste des tronçons sortants
    struct Noeud *fg;        // fils gauche pour AVL
    struct Noeud *fd;        // fils droit pour AVL
    int hauteur;             // hauteur AVL
    int equilibre;           // facteur d'équilibre AVL
} Noeud;

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

#endif



Traitement : usine de traiteent
Stockage : 
Distribution : principale (jonctions), secondaire (raccordements), branchement (relier le réseaux avec le compteur d'eau de l'usager)
Usagers : plus de vingaine de million

Seuls les trançons de raccordement utilises  par notre programme
Trançons (captage, stockage, distribution principale, secondaire, branchement) 
Les infos de chaque usine de traitement (caacité maximale annuelle de traitement de l'eau)
