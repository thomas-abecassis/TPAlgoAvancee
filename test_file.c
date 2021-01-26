#include <stdlib.h>
#include <stdio.h>

#include "abr.h"
#include "file.h"

int main(){


    pfile_t file = creer_file();

    pnoeud_t n1 = malloc(sizeof(noeud_t));
    n1->cle=1;


    pnoeud_t n2 = malloc(sizeof(noeud_t));
    n2->cle=2;   

    printf("file vide ? : %d \n", file_vide(file)); // normalement vide

    printf("file vide ? : %d \n", file_vide(file)); // normalement pas vide
    printf("file pleine ? : %d \n", file_pleine(file)); // normalement pas pleine

    for(int i=0; i<30; i++){
        enfiler(file, n2);
    }

    printf("file pleine ? : %d \n", file_pleine(file)); // normalement pleine
    enfiler(file, n2);//test qu'il n'y ai pas d'erreurs

    printf("premier element : %d \n", defiler(file)->cle); //1
    printf("deuxieme element : %d \n", defiler(file)->cle); //2
    printf("troisieme element : %d \n", defiler(file)->cle); //1
    printf("quatrieme element : %d \n", defiler(file)->cle); //2
    printf("cinquieme element : %d \n", defiler(file)->cle); //1
    printf("sixième element : %d \n", defiler(file)->cle); //2
    detruire_file(file);
}
