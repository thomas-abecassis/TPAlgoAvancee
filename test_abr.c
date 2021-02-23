#include <stdio.h>
#include <stdlib.h>

#include "abr.h"

int main (int argc, char**argv)
{
  Arbre_t a ;

  if (argc != 2)
    {
      fprintf (stderr, "il manque le parametre nom de fichier\n") ;
      exit (-1) ;
    }

  a = lire_arbre (argv[1]) ;
  
  afficher_arbre (a,0) ;
  //imprimer_liste_cle_triee_nr(a);
  //int test = rechercher_cle_inf_arbre(a,10)->cle;
  //parcourir_arbre_largeur(a);
  printf("Hauteur arbre : %d \n", hauteur_arbre_nr(a));
  printf("Hauteur arbre : %d \n", hauteur_arbre_r(a));

  //printf("inf : %d \n",test);

  /*
     appeler les fonctions que vous
     avez implementees
  */
}
