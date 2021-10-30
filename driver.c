#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driver.h"

int loadDriverName(sDriver drivers[], int size, int driverId, char name[]){

    int ok = 0;
    int flag = 1;
    if (drivers != NULL && size > 0 && name != NULL){
        ok = 1;
        for (int i = 0; i < size; i++){
            if (drivers[i].id == driverId){
                strcpy(name, drivers[i].name);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ok = -1;
        }
    }
    return ok;
}
int showDriver(sDriver drivers[], int size){

    int ok = 0;
    if (drivers != NULL && size > 0){

        puts("************* EMPRESAS ************* \n");
        puts("      ID          NOMBRE                 SEXO");
        puts("-------------------------------------------------");

    for (int i=0; i<size; i++){
        printf("     %d          %-20s    %-8c \n",drivers[i].id,drivers[i].name,drivers[i].sex);
            }
        puts("\n \n");
        ok = 1;
        }

    return ok;
}
int validateDriversId(sDriver drivers[], int id, int size){


    int ok = 0;

    if (drivers != NULL && size > 0 ){
        ok = 1;
        for (int i = 0; i < size; i++){
            if(drivers[i].id == id){
                 ok = 1;
                break;
            }
            }
    }
    return ok;
}
