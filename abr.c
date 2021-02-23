#include <stdio.h>
#include <stdlib.h>

#include "abr.h"
#include "pile.h"
#include "file.h"


#define max(a,b) ((a)>(b)?(a):(b))

int min(int a,int b){
  if(a<b){
    return a;
  }
  else{
    return b;
  }
}

int feuille (Arbre_t a)
{
  if (a == NULL)
    return 0 ;
  else
    {
      if ((a->fgauche == NULL) && (a->fdroite == NULL))
	return 1 ;
      else
	return 0 ;
    }
}

Arbre_t ajouter_noeud (Arbre_t a, Arbre_t n)
{
  /* ajouter le noeud n dans l'arbre a */
  
  if (a == NULL)
    return n ;
  else if (n->cle < a->cle)
	a->fgauche = ajouter_noeud (a->fgauche, n) ;
  else
	a->fdroite = ajouter_noeud (a->fdroite, n) ;
  return a ;
  
}  

Arbre_t rechercher_cle_arbre (Arbre_t a, int valeur)
{
  if (a == NULL)
    return NULL ;
  else
    {
      if (a->cle == valeur)
	return a ;
      else
	{
	  if (a->cle < valeur)
	    return rechercher_cle_arbre (a->fdroite, valeur) ;
	  else
	    return rechercher_cle_arbre (a->fgauche, valeur) ;
	}
    }
}

Arbre_t ajouter_cle (Arbre_t a, int cle)
{
  Arbre_t n ;
  Arbre_t ptrouve ;
  
  /* 
     ajout de la clé. Creation du noeud n qu'on insere 
    dans l'arbre a
  */

  ptrouve = rechercher_cle_arbre (a, cle) ;

  if (ptrouve == NULL)
    {
      n = (Arbre_t) malloc (sizeof(noeud_t)) ;
      n->cle = cle;
      n->fgauche = NULL ;
      n->fdroite = NULL ;

      a = ajouter_noeud (a, n) ;
      return a ;
    }
  else
    return a ;
}


Arbre_t lire_arbre (char *nom_fichier)
{
  FILE *f ;
  int cle;
  Arbre_t a = NULL;
  
  f = fopen (nom_fichier, "r") ;

  while (fscanf (f, "%d", &cle) != EOF)
    {
      a = ajouter_cle (a, cle) ;
    }
    
  fclose (f) ;

  return a ;
}

void afficher_arbre (Arbre_t a, int niveau)
{
  /*
    affichage de l'arbre a
    on l'affiche en le penchant sur sa gauche
    la partie droite (haute) se retrouve en l'air
  */
  
  int i ;
  
  if (a != NULL)
      {
	afficher_arbre (a->fdroite,niveau+1) ;
	
	for (i = 0; i < niveau; i++)
	  printf ("\t") ;
	printf (" %d (%d)\n\n", a->cle, niveau) ;

	afficher_arbre (a->fgauche, niveau+1) ;
      }
  return ;
}


int hauteur_arbre_r (Arbre_t a)
{
  if(feuille(a))
    return 0;
  
  int g=0;
  int d=0;
  if(a->fgauche!=NULL)
    g=hauteur_arbre_r(a->fgauche);
  if(a->fdroite!=NULL)
    d=hauteur_arbre_r(a->fdroite);
  return max(g,d) + 1;
}

int hauteur_arbre_nr (Arbre_t a)
{
    if (a == NULL) 
        return 0; 
  
    pfile_t f = creer_file(); 

    enfiler(f,a); 
    int hauteur = -1; 
  
    while (!file_vide(f)) 
    { 
        if (file_vide(f)) 
            return hauteur; 
  
        hauteur++; 
        int taille = f->tete-f->queue;
        if(taille<0)
          taille=-taille;

        while (taille > 0) 
        { 
            Arbre_t arbreCourant = defiler(f); 
            if (arbreCourant->fgauche != NULL) 
                enfiler(f,arbreCourant->fgauche); 
            if (arbreCourant->fdroite != NULL) 
                enfiler(f,arbreCourant->fdroite); 
            taille--; 
        } 
    } 
    return hauteur;
}


void parcourir_arbre_largeur (Arbre_t a)
{
  pfile_t f = creer_file();
  enfiler(f, a);
  Arbre_t arbreCourant;

  printf("\n parcours en largeur : \n");

  while(!file_vide(f)){
    arbreCourant = defiler(f);
    printf("%d ", arbreCourant->cle);
    if(arbreCourant->fgauche!=NULL)
      enfiler(f, arbreCourant->fgauche);
    if(arbreCourant->fdroite!=NULL)
      enfiler(f, arbreCourant->fdroite);
  }
  printf(" \n ");
}

void afficher_nombre_noeuds_par_niveau (Arbre_t a)
{
  /*
    a completer
  */

  return ;
}


int nombre_cles_arbre_r (Arbre_t a)
{
  if(feuille(a))
    return 1;
  
  int g=0;
  int d=0;

  if(a->fgauche!=NULL)
    g=hauteur_arbre_r(a->fgauche);
  if(a->fdroite!=NULL)
    d=hauteur_arbre_r(a->fdroite);
  return g + d + 1;
}

int nombre_cles_arbre_nr (Arbre_t a)
{
  pfile_t f = creer_file();
  enfiler(f, a);
  Arbre_t arbreCourant;
  int compteur = 0;
  while(!file_vide(f)){
    compteur++;
    arbreCourant = defiler(f);
    if(arbreCourant->fgauche!=NULL)
      enfiler(f, arbreCourant->fgauche);
    if(arbreCourant->fdroite!=NULL)
      enfiler(f, arbreCourant->fdroite);
  }

  return compteur;
}

int trouver_cle_min (Arbre_t a)
{
  /*
    a completer
  */

  return 0 ; 
}

 

void imprimer_liste_cle_triee_r (Arbre_t a)
{   
  if(a->fgauche!=NULL)
    imprimer_liste_cle_triee_r(a->fgauche);

  printf("%d \n", a->cle);

  if(a->fdroite!=NULL)
    imprimer_liste_cle_triee_r(a->fdroite);
}

void imprimer_liste_cle_triee_nr (Arbre_t a)
{
  ppile_t pile = creer_pile();
  int fin = 0;
  Arbre_t arbreCourant = a;

  while(!fin)
  {
      while (arbreCourant != NULL)
      {
          empiler(pile, arbreCourant);
          arbreCourant = arbreCourant->fgauche;
      }

      if (pile_vide(pile))
      {
          fin = 1;
      }
      else
      {
          arbreCourant = depiler(pile);
          printf("%d ", arbreCourant->cle);
          arbreCourant = arbreCourant->fdroite;
      }
  }
  printf("\n");
}


int arbre_plein (Arbre_t a)
{
  if(a->fdroite==NULL){
    if(a->fgauche==NULL){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    if(a->fgauche==NULL){
      return 0;
    }
    return min(arbre_plein( a->fgauche),arbre_plein(a->fdroite));

  }
}
void element_abr(Arbre_t a,ppile_t p){
  if(a->fdroite!=NULL){
    empiler(p,a->fdroite);
    element_abr(a->fdroite,p);
  }
  if(a->fgauche!=NULL){
    empiler(p,a->fgauche);
    element_abr(a->fgauche,p);
  }

}
int puissance(int a, int b){
  int r=1;
  for(int i=0;i<b;i++){
    r=r*a;
  }
  return r;
}

int arbre_parfait (Arbre_t a)
{
  int h=hauteur_arbre_r(a);
  ppile_t p=creer_pile();
  element_abr( a, p);
  int nb=0;
  while(pile_vide(p)!=1){
    nb++;
    //pnoeud_t azerty=depiler(p);
    depiler(p);
  }
  if(nb==puissance(2,h)){
    return 1;
  }
  
  return 0 ;
}




Arbre_t rechercher_cle_sup_arbre (Arbre_t a, int valeur)
{

  Arbre_t g = NULL;

  if(a->fgauche!=NULL)
    g = rechercher_cle_sup_arbre (a->fgauche, valeur);

  if(g!=NULL)
    return g;

  if(a->cle > valeur)
    return a;

  if(a->fdroite!=NULL)
    return rechercher_cle_sup_arbre (a->fdroite, valeur);

  return NULL;
  
}

Arbre_t rechercher_cle_inf_arbre (Arbre_t a, int valeur)
{
  Arbre_t d = NULL;

  if(a->fdroite!=NULL)
    d = rechercher_cle_inf_arbre (a->fdroite, valeur);

  if(d!=NULL)
    return d;

  if(a->cle < valeur)
    return a;

  if(a->fgauche!=NULL)
    return  rechercher_cle_inf_arbre (a->fgauche, valeur);

  return NULL;

}


Arbre_t detruire_cle_arbre (Arbre_t a, int cle)
{
  /*
    a completer
  */

  return NULL ;
}



Arbre_t intersection_deux_arbres (Arbre_t a1, Arbre_t a2)
{
  /*
    a completer
  */

  return NULL ;
  
}

Arbre_t union_deux_arbres (Arbre_t a1, Arbre_t a2)
{
  /*
    a completer
  */

  return NULL ;
}

