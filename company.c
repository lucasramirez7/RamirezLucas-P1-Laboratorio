#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company.h"

int loadCompanyDescription(sCompany companies[], int size, int companyId, char description[]){

    int ok = 0;
    int flag = 1;
    if (companies != NULL && size > 0 && description != NULL){
        ok = 1;
        for (int i = 0; i < size; i++){
            if (companies[i].id == companyId){
                strcpy(description, companies[i].description);
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
int showCompany(sCompany companies[], int size){

     int ok = 0;
    if (companies != NULL && size > 0){

        puts("************* EMPRESAS ************* \n");
        puts("      ID          DESCRIPCION ");
        puts("-------------------------------");

    for (int i=0; i<size; i++){
        printf("     %d          %-10s \n",companies[i].id,companies[i].description);
            }
        puts("\n \n");
        ok = 1;
        }

    return ok;
}
int validateCompanyId(sCompany companies[], int id, int size){


    int ok = 0;

    if (companies != NULL && size > 0 ){
        ok = 1;
        for (int i = 0; i < size; i++){
            if(companies[i].id == id){
                 ok = 1;
                break;
            }
            }
    }
    return ok;
}
