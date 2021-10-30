#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "travel.h"
#include "buses.h"
#include "destiny.h"
#include "company.h"
#include "kind.h"
#define SIZE 50
#define KIND_SIZE 4
#define COMPANY_SIZE 4
#define DESTINY_SIZE 4
#define TRAVEL_SIZE 50

int setUpTravel(sTravel travels[], int size){
    int ok = 0;

    if(travels != NULL && size > 0){
        for(int i=0; i < size; i++)
        {
            travels[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}
int searchFreeTravel(sTravel travels[], int size){

    int index = -1;

    for(int i=0; i<size; i++){
        if(travels[i].isEmpty){
            index = i;
            break;
        }
    }
    return index;
}
int registerTravel(sTravel travels[] ,int size ,int* pId ,sBus buses[] ,int busesSize ,sDestiny destines[],int destinySize){

    int ok = 0;
    int index;
    int cant;



    sTravel auxTravel;


    if(travels != NULL && size > 0 && buses != NULL && busesSize > 0 && destines != NULL && destinySize > 0)
    {

        system("cls");
        puts("**********ALTA VIAJE**********\n\n");
        index = searchFreeTravel(travels, size);


        if(index == -1)
        {
            printf("No hay mas registros \n");
        }
        else
        {
            auxTravel.id = *pId;
            (*pId)++;

            system("cls");
            showDestiny(destines,destinySize);
            puts("ingrese el ID del destino: ");
            scanf("%d", &auxTravel.idDestiny);
            puts("------------------------------------------------- \n");

            while(!validateInt(auxTravel.idDestiny,20000,20003)){
                puts("ID INVALIDO, ingrese el ID del destino: ");
                scanf("%d", &auxTravel.idDestiny);
            }

            puts("ingrese la fecha (dd/mm/aaaa)");
            cant = scanf("%d/%d/%d", &auxTravel.date.day,&auxTravel.date.month,&auxTravel.date.age);
            puts("----------------------------------------------- \n");
            while( !(cant == 3 && (auxTravel.date.day >= 1 && auxTravel.date.day <= 31)&&
                  (auxTravel.date.month >= 1 && auxTravel.date.month <= 12)&&
                  (auxTravel.date.age >= 2000 && auxTravel.date.age <= 2021))){
                   puts("ERROR! Reingrese la fecha correcta (dd/mm/aaaa)");
                   scanf("%d/%d/%d", &auxTravel.date.day,&auxTravel.date.month,&auxTravel.date.age);
                  }

            system("cls");

            puts("Ingrese el ID del micro: ");
            scanf("%d", &auxTravel.idBus);
            puts("----------------------------------------------- \n");

            while(!validateInt(auxTravel.idBus,100,199)){
            puts("ERROR!!! Ingrese el ID del micro: ");
            scanf("%d", &auxTravel.idBus);
            puts("----------------------------------------------- \n");
            }

            auxTravel.isEmpty = 0;

            travels[index] = auxTravel;

        }
        ok = 1;
    }
    return ok;
}
void showTravel(sTravel travels, sBus buses[], int busesSize, sDestiny destinies[], int destinySize){

    float cost;
    char destinyDescription[20];
    loadDestinyDescription(destinies,destinySize,travels.idDestiny,destinyDescription);
    loadDestinyCost(destinies,destinySize,travels.idDestiny,&cost);
     puts("------------------------------------------------------------");
     printf("  %-8d   %-8d   %-15s   $ %6.2f \n",
           travels.id,
           travels.idBus,
           destinyDescription,
           cost);
}
int showTravels(sTravel travels[], int size, sDestiny destinies[], int destinySize,sBus buses[],int busesSize){

    int ok = 0;
    int flag = 1;
    if (travels != NULL && size > 0 && destinies != NULL && destinySize > 0){

        puts("********LISTA DE VIAJES********\n");
        puts("---------------------------------------------------------------");
        puts("   ID    ID MICRO      DESTINO            PRECIO        ");
        puts("----------------------------------------------------------------");

        for(int i=0; i<size; i++){
            if(!travels[i].isEmpty){
                showTravel(travels[i],buses,busesSize,destinies,destinySize);
                flag = 0;
            }
        }
        if(flag)
        {
            puts("-----------------------------------------");
            puts("-******No hay viajes registrados******-");
            puts("-----------------------------------------");

        }
        ok = 1;
    }
    return ok;
}

