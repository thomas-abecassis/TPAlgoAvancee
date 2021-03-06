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
  //ne marche pas
  ppile_t p = creer_pile();
  empiler(p, a);
  Arbre_t arbreCourant;

  while(!pile_vide(p)){
    arbreCourant = depiler(p);
    if(arbreCourant->fgauche!=NULL)
      empiler(p, arbreCourant->fgauche);
    if(arbreCourant->fdroite!=NULL)
      empiler(p, arbreCourant->fdroite);
  }

  return 1;
}


void parcourir_arbre_largeur (Arbre_t a)
{
  pfile_t f = creer_file();
  enfiler(f, a);
  Arbre_t arbreCourant;

  while(!file_vide(f)){
    arbreCourant = defiler(f);
    if(arbreCourant->fgauche!=NULL)
      enfiler(f, arbreCourant->fgauche);
    if(arbreCourant->fdroite!=NULL)
      enfiler(f, arbreCourant->fdroite);
  }

  return ;
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
  /*
    a completer
  */

  
  return ;
}

void imprimer_liste_cle_triee_nr (Arbre_t a)
{
  /*
    a completer
  */}

Arbre_t rotation_gauche(Arbre_t a){
    Arbre_t newsom=a->fdroite;
    Arbre_t newfils_a=a->fdroite->fgauche;

    newsom->fgauche=a;
    a->droite=newfils_a;
    return newsom;

}

Arbre_t rotation_droite(Arbre_t a){
    Arbre_t newsom=a->fgauche;
    Arbre_t newfils_a=a->fgauche->fdroite;

    newsom->fdroite=a;
    a->fdroite=newfils_a;
    return newsom;
}

Arbre_t double_rotation_gauche(Arbre_t a){
    a->fdroite=rotation_droite(a->fdroite);
    a=rotation_gauche(a);
    return a;
}

Arbre_t double_rotation_droite(Arbre_t a){
    a->fgauche=rotation_gauche(a->fgauche);
    a=rotation_droite(a);
    return a;
}

