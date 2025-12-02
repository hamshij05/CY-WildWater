#include "biblio.h"

//Fonction pour calculer le facteur équilibre
int facteur_equilibre(Arbre* r){
  return (hauteur(r->fd) - hauteur(r->fg)); 
}

//Rotation gauche pour rééquilibrer l'arbre
Arbre *rotationGauche(Arbre *pivot){
  Arbre *a = pivot->fd; //a devient le fils droit de pivot
  Arbre *tmp = a->fg; 

  a->fg = pivot;
  pivot->fd = tmp;

  //Mise à jour des hauteurs des noeuds
  pivot->hauteur = max(hauteur(pivot->fg),hauteur(pivot->fd))+1;
  a->hauteur = max(hauteur(a->fg),hauteur(pivot->fd))+1;   
  return a; //a devient la nouvelle racine
}


//Rotation droite pour rééquilibrer l'arbre
Arbre *rotationDroite(Arbre *a){
  Arbre* pivot = a->fg; //le fils gauche devient le pivot
  Arbre* tmp = pivot->fd; //le fils droit de pivot

  pivot->fd = a; //a devient le fils droit de pivot
  a->fg = tmp; 

  //Mise à jour des hauteurs des noeuds
  a->hauteur = max(hauteur(a->fg),(hauteur(a->fd)))+ 1;
  pivot->hauteur = max(hauteur(pivot->fg),hauteur(pivot->fd))+ 1;
  return pivot; //le pivot devient la nouvelle racine
}


//Double rotation gauche
Arbre* doubleRotationGauche(Arbre* a){
  a->fd=rotationDroite(a->fd);
  return rotationGauche(a);
}


//Double rotation droite
Arbre* doubleRotationDroite(Arbre* a){
  a->fg=rotationGauche(a->fg);
  return rotationDroite(a);
}


//Création de nouveau noeud pour l'arbre AVL (à compléter)

//Insertion de l'arbre AVL

//Fonction pour calculer l'hauteur d'arbre AVL


//Fonction d'équilibre AVL
