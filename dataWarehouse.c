#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataWarehouse.h"
#include "buses.h"
#include "travel.h"

int types[10] = {5000,5000,5001,5002,5000,5003,5002,5001,5003,5002};

int companies[10] = {1001,1002,1003,1001,1000,1002,1000,1001,1003,1002};

int traveller[10] = {17,45,30,24,43,12,17,19,36,10};

int idBus[10]={100,105,108,103,104,102,103,102,109,109};

int idDestinies[10]={20002,20001,20002,20003,20003,20001,20000,20002,20003,20003};

sDate dates[10]=  {
                   {26,06,2022},
                   {22,02,2022},
                   {30,11,2022},
                   {03,12,2021},
                   {31,05,2012},
                   {12,10,2012},
                   {01,01,2003},
                   {10,01,2001},
                   {07,01,2020},
                   {13,01,2006},
                   };

int travelHardcore(sTravel travels[], int size, int amount, int* pId){
    int cont = -1;
    if (travels != NULL && size > 0 && amount >= 0 && amount <= size && pId != NULL){
        cont = 0;
        for (int i = 0; i < amount;  i++){
            travels[i].id = *pId;
            (*pId)++;
            travels[i].idBus = idBus[i];
            travels[i].date = dates[i];
            travels[i].idDestiny = idDestinies[i];
            travels[i].isEmpty = 0;
            cont++;
        }
    }
    return cont;
}
int busesHardcore(sBus buses[], int size, int amount, int* pId){
    int cont = -1;
    if (buses != NULL && size > 0 && amount >= 0 && amount <= size && pId != NULL){
        cont = 0;
        for (int i = 0; i < amount;  i++){
            buses[i].id = *pId;
            (*pId)++;
            buses[i].traveller = traveller[i];
            buses[i].idCompany = companies[i];
            buses[i].idKind = types[i];
            buses[i].isEmpty = 0;
            cont++;
        }
    }
    return cont;
}

