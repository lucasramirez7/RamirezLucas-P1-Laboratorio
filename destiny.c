#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destiny.h"



int showDestiny(sDestiny destinies[], int size){

    int ok = 0;
    if (destinies != NULL && size > 0){

        puts("************* TIPOS DE MICRO ************* \n");
        puts("      ID          DESCRIPCION       PRECIO   ");
        puts("---------------------------------------------");

    for (int i=0; i<size; i++){
        printf("     %d          %-10s       $ %6.2f \n",destinies[i].id,destinies[i].description, destinies[i].cost);
            }
        puts("\n \n");
        ok = 1;
        }

    return ok;
}
int validateDestinyId(sDestiny destinies[], int size, int id){

    int ok = 0;

    if (destinies != NULL && size > 0 ){
        ok = 1;
        for (int i = 0; i < size; i++){
            if(destinies[i].id == id){
                 ok = 1;
                break;
            }
            }
    }
    return ok;
}
int loadDestinyDescription(sDestiny destinies[], int size, int destinyId, char description[]){

    int ok = 0;
    int flag = 1;
    if (destinies != NULL && size > 0 && description != NULL){
        ok = 1;
        for (int i = 0; i < size; i++){
            if (destinies[i].id == destinyId){
                strcpy(description, destinies[i].description);
                flag = 0;
                break;
            }
        }
        if (flag){
            ok = -1;
        }
    }
    return ok;
}
int loadDestinyCost(sDestiny destinies[], int size, int destinyId, float* cost){

    int ok = 0;
    int flag = 1;
    if (destinies != NULL && size > 0){
        ok = 1;
        for (int i = 0; i < size; i++){
            if (destinies[i].id == destinyId){
                *cost = destinies[i].cost;
                flag = 0;
                break;
            }
        }
        if (flag){
            ok = -1;
        }
    }
    return ok;
}
