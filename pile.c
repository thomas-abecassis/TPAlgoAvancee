#include <stdlib.h>
#include "abr.h"
#include "pile.h"

ppile_t creer_pile ()
{
  ppile_t pil = malloc(sizeof(pile_t));
  pil->sommet=0;
  
  return pil ;
}

int detruire_pile (ppile_t p)
{
  p=NULL;
  free(p);
  return 0 ;
}  

int pile_vide (ppile_t p)
{
  if(p->sommet==0){
    return 1;
  }

  return 0 ;
}

int pile_pleine (ppile_t p)
 {
  if(p->sommet==MAX_PILE_SIZE-1){
    return 1;
  }

  return 0 ;
} 

pnoeud_t depiler (ppile_t p)
{
  if(!pile_vide(p)){
    p->sommet--;
    return p->Tab[p->sommet+1];
  }

  return NULL ;

}

int empiler (ppile_t p, pnoeud_t pn)
  {
  if(!pile_pleine(p)){
    p->sommet++;
    p->Tab[p->sommet]=pn;
    return 0;
  }

  return -1;

}
