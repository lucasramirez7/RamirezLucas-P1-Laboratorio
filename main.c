#include <stdio.h>
#include <stdlib.h>
#include "buses.h"
#include "kind.h"
#include "company.h"
#include "destiny.h"
#include "travel.h"
#include "date.h"
#include "driver.h"
#include "dataWarehouse.h"
#define SIZE 50
#define KIND_SIZE 4
#define COMPANY_SIZE 4
#define DESTINY_SIZE 4
#define TRAVEL_SIZE 50
#define DRIVER_SIZE 7
#define FALSE 0
#define TRUE 1
int main(){

    sBus buses[SIZE];
    sTravel travels[TRAVEL_SIZE];
    char follow = 's';
    int nextId = 100;
    int nextIdTravel = 20000;
    int flag = FALSE;


    if (!setUpBus(buses,SIZE)){
        puts("Problemas al inicializar los micros! \n");
    }

    if (!setUpTravel(travels,TRAVEL_SIZE)){
        puts("Problemas al inicializar los viajes! \n");
    }


    sCompany companies[COMPANY_SIZE] = {{1000,"Plusmar"},{1001,"Flecha Bus"},{1002,"Tas"},{1003,"El Rapido"}};
    sKind types[KIND_SIZE] = {{5000,"Comun"},{5001,"Coche Cama"},{5002,"Doble"},{5003,"Vip"}};
    sDestiny destinies[DESTINY_SIZE] = {{20000,"calafate",22250},{20001,"Bariloche",103000},{20002,"Iguazu",84400},{20003,"Mendoza",95600}};
    sDriver drivers[DRIVER_SIZE] = {{50000,"Lucas Gonzalez",'m'},{50001,"Veronica Rondo",'f'},{50002,"Camila Parra",'f'},{50003,"Gonzalo Palma",'m'},{50004,"Camilo Szymborsky",'m'},{50005,"Natasha Cali",'f'},{50006,"Ivan Rodriguez",'m'}};
    busesHardcore(buses,SIZE,9,&nextId);
    travelHardcore(travels,SIZE,9,&nextIdTravel);

    do{
    switch (menu()){

    case 'a':
    system("cls");
       if(!registerBus(buses,SIZE, &nextId,types,KIND_SIZE,companies,COMPANY_SIZE,drivers,DRIVER_SIZE)){
                    printf("\nNo se pudo realizar el alta.\n");
                }
                else
                {
                    printf("\nAlta exitosa!!\n");
                    flag = TRUE;
                }
                break;
    case 'b':
    system("cls");
      if(!modifyBus(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE,drivers,DRIVER_SIZE)){

                    printf("\nNo se pudo realizar la modificacion.\n");
                }
                else
                {
                    printf("Modificación exitosa!!\n");
                    flag = TRUE;
                }

                break;

    case 'c':
    system("cls");
      if(!removeBuses(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE,drivers,DRIVER_SIZE)){

                    printf("\nNo se pudo realizar la baja.\n");
                }
                else
                {
                    printf("Baja exitosa!!\n");
                    flag = TRUE;
                }
    break;

    case 'd':
    system("cls");
    orderTravellerAndCompany(buses,SIZE,companies,COMPANY_SIZE);
    showBuses(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE,drivers,DRIVER_SIZE);
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
    if(flag == FALSE){
                printf("\nNo se puede dar de alta un viaje sin un micro \n");
                }
                else
                {
                    if(!registerTravel(travels,TRAVEL_SIZE,&nextIdTravel,buses,SIZE,destinies,DESTINY_SIZE)){
                        printf("\nNo se pudo realizar la baja.\n");
                    }
                    else{
                        printf("Baja exitosa!!\n");
                    }
                }
    break;

    case 'i':
    system("cls");
    showTravels(travels,TRAVEL_SIZE,destinies,DESTINY_SIZE,buses,SIZE);
    break;

    case 'j':
    system("cls");
    showDriver(drivers,DRIVER_SIZE);
    break;

    case 'k':
    system("cls");
    switch (subMenuReports())
    {
    case 1:
       ShowBusesCompanies(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE,drivers,DRIVER_SIZE);
    break; //Mostrar micros de la empresa seleccionada por el usuario.
    case 2:
        ShowBusesTypes(buses,SIZE,types,KIND_SIZE,companies,COMPANY_SIZE,drivers,DRIVER_SIZE);
        break;// Mostrar micros de un tipo seleccionado.
    case 3:
        showpercentageBusesVip(buses,SIZE,companies,COMPANY_SIZE,types,KIND_SIZE);
    break; //Informar Promedio de micros de tipo Vip sobre el total de micros de una empresa
    case 4:
        ShowBusesForCompany(buses,SIZE,companies,COMPANY_SIZE,types,KIND_SIZE,drivers,DRIVER_SIZE);
    break;//Mostrar un listado de los micros separados por empresa.

    }
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

