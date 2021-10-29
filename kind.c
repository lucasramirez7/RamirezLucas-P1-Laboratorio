#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kind.h"


int loadKindDescription(sKind types[], int size, int kindId, char description[]){

    int ok = 0;
    int flag = 1;
    if (types != NULL && size > 0 && description != NULL){
        ok = 1;
        for (int i = 0; i < size; i++){
            if (types[i].id == kindId){
                strcpy(description, types[i].description);
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

int showKind(sKind types[], int size){

     int ok = 0;
    if (types != NULL && size > 0){

        puts("************* TIPOS DE MICRO ************* \n");
        puts("      ID          DESCRIPCION ");
        puts("-------------------------------");

    for (int i=0; i<size; i++){
        printf("     %d          %-10s \n",types[i].id,types[i].description);
            }
        puts("\n \n");
        ok = 1;
        }

    return ok;
}
int validateKindId(sKind types[], int id, int size){

    int ok = 0;

    if (types != NULL && size > 0 ){
        ok = 1;
        for (int i = 0; i < size; i++){
            if(types[i].id == id){
                 ok = 1;
                break;
            }
            }
    }
    return ok;
}
