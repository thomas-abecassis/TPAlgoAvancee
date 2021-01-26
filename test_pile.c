#include <stdlib.h>
#include <stdio.h>

#include "abr.h"
#include "pile.h"

int main(){


    ppile_t pile = creer_pile();

    pnoeud_t n1 = malloc(sizeof(noeud_t));
    n1->cle=1;


    pnoeud_t n2 = malloc(sizeof(noeud_t));
    n2->cle=2;   

    printf("pile vide ? : %d \n", pile_vide(pile)); // normalement vide

    empiler(pile, n1);

    printf("pile vide ? : %d \n", pile_vide(pile)); // normalement pas vide
    printf("pile pleine ? : %d \n", pile_pleine(pile)); // normalement pas pleine

    for(int i=0; i<26; i++){
        empiler(pile, n2);
    }
    
    empiler(pile, n2); 
    empiler(pile, n1);
    empiler(pile, n2); 
    empiler(pile, n1);
    printf("pile pleine ? : %d \n", pile_pleine(pile)); // normalement pleine
    empiler(pile, n2);//test qu'il n'y ai pas d'erreurs

    printf("premier element : %d \n", depiler(pile)->cle); //1
    printf("deuxieme element : %d \n", depiler(pile)->cle); //2
    printf("troisieme element : %d \n", depiler(pile)->cle); //1
    printf("quatrieme element : %d \n", depiler(pile)->cle); //2
    detruire_pile(pile);
}