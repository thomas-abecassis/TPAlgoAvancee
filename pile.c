#include <stdlib.h>
#include "abr.h"
#include "pile.h"

ppile_t creer_pile ()
{
  ppile_t pil;
  pil->sommet=0;
  
  return pil ;
}

int detruire_pile (ppile_t p)
{
  p=NULL;

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
  if(p->sommet==MAX_PILE_SIZE){
    return 1;
  }

  return 0 ;
} 

pnoeud_t depiler (ppile_t p)
{
  if(pile_vide(p)==0){
    p->sommet--;
    return p->Tab[p->sommet];
  }

  return NULL ;

}

int empiler (ppile_t p, pnoeud_t pn)
  {
  if(p->sommet<MAX_PILE_SIZE){
    p->Tab[p->sommet]=pn;
    p->sommet++;

  }

  return 0 ;

}
