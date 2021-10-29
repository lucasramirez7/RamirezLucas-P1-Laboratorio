#include <stdio.h>
#include <stdlib.h>
#include "buses.h"
#include "kind.h"
#include "company.h"
#include "destiny.h"
#include "travel.h"
#include "date.h"
#include "dataWarehouse.h"
#define SIZE 50
#define KIND_SIZE 4
#define COMPANY_SIZE 4
#define DESTINY_SIZE 4
#define TRAVEL_SIZE 50
int main(){

    sBus buses[SIZE];
    sTravel travels[TRAVEL_SIZE];
    char follow = 's';
    int nextId = 100;
    int nextIdTravel = 20000;


    if (!setUpBus(buses,SIZE)){
        puts("Problemas al inicializar los micros! \n");
    }

    if (!setUpTravel(travels,TRAVEL_SIZE)){
        puts("Problemas al inicializar los viajes! \n");
    }


    sCompany companies[COMPANY_SIZE] = {{1000,"Plusmar"},{1001,"Flecha Bus"},{1002,"Tas"},{1003,"El Rapido"}};
    sKind types[KIND_SIZE] = {{5000,"Comun"},{5001,"Coche Cama"},{5002,"Doble"},{5003,"Vip"}};
    sDestiny destinies[DESTINY_SIZE] = {{20000,"calafate",22250},{20001,"Bariloche",103000},{20002,"Iguazu",84400},{20003,"Mendoza",95600}};

    busesHardcore(buses,SIZE,9,&nextId);
    travelHardcore(travels,SIZE,9,&nextIdTravel);

    do{
    switch (menu()){

    case 'a':
    system("cls");
    registerBus(buses,SIZE, &nextId,types,KIND_SIZE,companies,COMPANY_SIZE);
    break;

    case 'b':
    system("cls");
    modifyBus(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE);
    break;

    case 'c':
    system("cls");
    removeBuses(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE);
    break;

    case 'd':
    system("cls");
    orderTravellerAndCompany(buses,SIZE,companies,COMPANY_SIZE);
    showBuses(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE);
    break;

    case 'e':
    system("cls");
    showCompany(companies,COMPANY_SIZE);
    break;

    case 'f':
    system("cls");
    showKind(types,KIND_SIZE);
    break;

    case 'g':
    system("cls");
    showDestiny(destinies,DESTINY_SIZE);
    break;

    case 'h':
    system("cls");
    registerTravel(travels,TRAVEL_SIZE,&nextIdTravel,buses,SIZE,destinies,DESTINY_SIZE);
    break;

    case 'i':
    system("cls");
    showTravels(travels,TRAVEL_SIZE,destinies,DESTINY_SIZE,buses,SIZE);
    break;

    case 'x':
        follow = 'n';
    break;

    default:
        puts("Opcion incorrecta");
        break;
    }
    system("pause");
    }while(follow == 's');

    return 0;
}

