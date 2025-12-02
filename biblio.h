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
char identifiant;
unsigned long capacité;
unsigned long volume_capté;
unsigned long volume_traite;
}Usine;

//Structure de l'AVL
typedef struct{
    char id[64];            // Identifiant de la station
    double valeur1;         // Première valeur
    double valeur2;         // Deuxième valeur
    double valeur3;         // Troisième valeur
    int hauteur;            // Hauteur du nœud
    struct Avl *fg;         // Fils gauche
    struct Avl *fd;         // Fils droit
} AVL;

Traitement : usine de traiteent
Stockage : 
Distribution : principale (jonctions), secondaire (raccordements), branchement (relier le réseaux avec le compteur d'eau de l'usager)
Usagers : plus de vingaine de million

Seuls les trançons de raccordement utilises  par notre programme
Trançons (captage, stockage, distribution principale, secondaire, branchement) 
Les infos de chaque usine de traitement (caacité maximale annuelle de traitement de l'eau)
