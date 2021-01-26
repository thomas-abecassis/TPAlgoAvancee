#include <stdlib.h>

#include "abr.h"
#include "file.h"

pfile_t creer_file ()
{
  pfile_t f = malloc(sizeof(file_t));
  f->tete=0;
  f->queue=0;
  return f;
}

int detruire_file (pfile_t f)
{
  free(f);
  return 0;
}

int file_vide (pfile_t f)
{
  return f->queue==f->tete;
}

int file_pleine (pfile_t f)
  {
    return f->tete == (( f->queue - 1 + MAX_FILE_SIZE) % MAX_FILE_SIZE);
}

pnoeud_t defiler (pfile_t f)
  {
    if(f->queue == f->tete){
      return NULL; // rien à prendre
    }
  pnoeud_t n = f->Tab[f->queue];
  f->queue = (f->queue+1) % MAX_FILE_SIZE;
  return n;
}

int enfiler (pfile_t f, pnoeud_t p)
{

  if(file_pleine(f))
    return -1; // dans ce cas on ne peut pas enfiler
  
  f->Tab[f->tete]=p;
  f->tete = (f->tete + 1) % MAX_FILE_SIZE;
  return 0 ;
}
