#include "biblio.h"

//Création de nouveau noeud pour l'arbre AVL
Arbre *creationArbre(int a){
   Arbre *nouveau=malloc(sizeof(Arbre)); 
   if(nouveau==NULL){ //vérification de l'échec d’allocation
      exit(1); //quitter le programme en cas d'échec
   }
   nouveau->elmt=a; //initialisation de la valeur du chaînon
   nouveau->fg=NULL;
   nouveau->fd=NULL;
   nouveau->equilibre=0;
   return nouveau;
}


//Insertion de l'arbre AVL

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
AVL *rotationDroite(Arbre *a){
  AVL* pivot = a->fg; //le fils gauche devient le pivot
  AVL* tmp = pivot->fd; //le fils droit de pivot

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




//Fonction pour calculer l'hauteur d'arbre AVL  
c liee //Fonction facteur d'équilibre AVL

//Fonction suppression
Arbre *suppressionAVL(Arbre *a, int e, int *h) {
	if (a==NULL){
    	*h = 0;
    	return a;
	}
	else if (e > a->elmt){
    	a->fd = suppressionAVL(a->fd, e);
	}
	else if(e < a->elmt){
    	a->fg = suppressionAVL(a->fg, e);
    	*h = -*h;
	}
	else if(existeFilsDroite->a){
    	a->fd=suppMinAVL(a->fd, h, &(a->elmt))
	}
	else{
    	tmp=a;
    	a=a->fg;
    	free(tmp);
    	*h=-1;
    	return(a);
	}
	if(a==NULL){
    	return a;
	}
	if(*h!=0){
    	a->equilibre=a->equilibre+*h;
    	if(a->equilibre==0){
        	*h=-1;
    	}
    	else{
        	*h=0;
    	}
	}
	return a;
}


//Parcours en ordre croissant (infixe = parcours en ordre) et écriture dans le fichier de sortie
void infixe(Arbre* a, FILE* fichier_resultat){ 
  if (a==NULL){
    return; //Si a est NULL, la fonction retourne
  }; 
  infixe(a->fg,fichier_resultat); //parcours du sous-arbre gauche
  Trancon* t=a->sorties;
  fprintf(fichier_resultat, "%s ; %s ; %.2f ; %.2f\n", a->identifiant, t->aval, t->volume, t->fuite);
  infixe(a->fd,fichier_resultat); //parcours du sous-arbre droit
}
   

//Fonction pour calculer le facteur équilibre
int facteur_equilibre(Arbre* r){
  return (hauteur(r->fd) - hauteur(r->fg)); 
}
