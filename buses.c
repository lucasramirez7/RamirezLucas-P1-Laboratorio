#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "buses.h"
#include "kind.h"
#include "company.h"
#include "driver.h"

char menu(){

    char opcion;

    system("cls");
    printf("********** GESTIONAR EMPRESA DE VIAJES ********** \n \n");
    puts("A- Alta Micro");
    puts("B- Modificar Micro");
    puts("C- Baja Micro");
    puts("D- Listar Micros");
    puts("E- Listar Empresas");
    puts("F- Listar Tipos");
    puts("G- Listar Destinos");
    puts("H- Alta viaje");
    puts("I- listar viajes");
    puts("J- listar Choferes");
    puts("K- INFORMES");
    puts("X- Salir \n");
    printf("INGRESE OPCION: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);
    return opcion;
}
int setUpBus(sBus buses[], int size){

    int ok = 0;

    if(buses != NULL && size > 0){
        for(int i=0; i < size; i++)
        {
            buses[i].isEmpty = 1;
        }
        ok = 1;
    }
    return ok;
}
int searchFreeBus(sBus buses[], int size){

    int index = -1;

    for(int i=0; i<size; i++){
        if(buses[i].isEmpty){
            index = i;
            break;
        }

    }
    return index;
}
int registerBus(sBus buses[] ,int size ,int* pId ,sKind types[] ,int kindSize ,sCompany companies[],int companySize, sDriver drivers[],int driverSize){

    int ok = 0;
    int index;

    sBus auxBus;

   if(buses != NULL && size > 0 && types != NULL && kindSize > 0 && companies != NULL && companySize > 0){

        system("cls");
        puts("**********ALTA MICRO**********\n\n");
        index = searchFreeBus(buses, size);


        if(index == -1)
        {
            printf("No hay mas registros \n");
        }
        else
        {
            auxBus.id = *pId;
            (*pId)++;

            showCompany(companies,companySize);

            puts("ingrese ID de empresa que desee viajar: ");
            scanf("%d", &auxBus.idCompany);
            puts("----------------------------------------------- \n");

            while(!validateInt(auxBus.idCompany,1000,1003)){
                puts("ID INVALIDO, ingrese ID de empresa que desee viajar: ");
                scanf("%d", &auxBus.idCompany);
            }

            system("cls");
            showKind(types,kindSize);
            puts("ingrese ID del tipo de micro que desee viajar: ");
            scanf("%d", &auxBus.idKind);
            puts("------------------------------------------------- \n");

            while(!validateInt(auxBus.idKind,5000,5003)){
                puts("ID INVALIDO, ingrese ID del tipo de micro que desee viajar: ");
                scanf("%d", &auxBus.idKind);
            }

            system("cls");
            puts("Ingrese los pasajeros que van a viajar (MAX 50): ");
            scanf("%d", &auxBus.traveller);
            puts("----------------------------------------------- \n");

            while(!validateInt(auxBus.traveller,0,50)){
            puts("ERROR!!! Ingrese los pasajeros que van a viajar (MAX 50): ");
            scanf("%d", &auxBus.traveller);
            puts("----------------------------------------------- \n");
            }
            system("cls");
            showDriver(drivers,driverSize);
            puts("ingrese ID chofer que desee viajar: ");
            scanf("%d", &auxBus.idDriver);
            puts("------------------------------------------------- \n");

            while(!validateInt(auxBus.idDriver,50000,50006)){
                puts("ID INVALIDO, ingrese ID chofer que desee viajar: ");
                scanf("%d", &auxBus.idDriver);
            }

            auxBus.isEmpty = 0;

            buses[index] = auxBus;

        }
        ok = 1;
    }
    return ok;
}
void showBus(sBus bus, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driverSize){

    char kindDescription[20];
    char companyDescription[20];
    char driverName[20];


    loadKindDescription(types,kindSize,bus.idKind,kindDescription);
    loadCompanyDescription(companies,companySize,bus.idCompany,companyDescription);
    loadDriverName(drivers,driverSize,bus.idDriver,driverName);


     puts("--------------------------------------------------------------------------");
     printf("  %-8d   %-8d  %-15s   %-10s    %-10s    \n",
           bus.id,
           bus.traveller,
           companyDescription,
           kindDescription,
           driverName
           );
}
int showBuses(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driverSize){

    int ok = 0;
    int flag = 1;
    if (buses != NULL && size > 0 && types != NULL && kindSize > 0 && companies != NULL && companySize > 0 && drivers != NULL && driverSize > 0){

        puts("********LISTA DE MICROS********\n");
        puts("--------------------------------------------------------------------------");
        puts("   ID    PASAJEROS      EMPRESA          TIPO           CHOFER      ");
        puts("--------------------------------------------------------------------------");

        for(int i=0; i<size; i++){
            if(!buses[i].isEmpty){
                showBus(buses[i],types,kindSize,companies,companySize,drivers,driverSize);
                flag = 0;
            }
        }
        if(flag)
        {
            puts("-----------------------------------------");
            puts("-******No hay micros registradas******-");
            puts("-----------------------------------------");

        }
        ok = 1;
    }
    return ok;
}
int searchBusId(sBus buses[], int size,int id){

    int index = -1;

    for(int i=0; i<size; i++){
        if(buses[i].id == id && buses[i].isEmpty == 0){

                index = i;
                break;
            }
    }

 return index;
}
int modifyMenu(){

    int option;

    system("cls");
    puts("********** SELECCIONA EL DATO A MODIFICAR ********** \n \n");
    printf("1- Empresa\n");
    printf("2- Tipo \n");
    printf("3- Cantidad pasajeros\n");
    printf("4- Chofer");
    printf("10- Salir\n \n");
    printf("INGRESE OPCION: ");
    scanf("%d", &option);

    return option;
}
int modifyBus(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[],int driverSize){

    int ok = 0;
    int index;
    int id;
    char confirm;



    if(buses != NULL && size > 0 && types != NULL && kindSize > 0 && companies != NULL && companySize > 0 && drivers != NULL && driverSize > 0){
        system("cls");
        puts(" -----------------MODIFICAR MICRO-----------------\n");
        showBuses(buses,size,types,kindSize,companies,companySize,drivers,driverSize);
        printf("\n \n Ingrese ID: ");
        scanf("%d", &id);

        index = searchBusId(buses,size,id);

        if(index == -1){
            printf("ERROR!! El ID: %d no corresponde a un micro\n", id);
        }
        else{

            do{
            system("cls");
            showBus(buses[index],types,kindSize,companies,companySize,drivers,driverSize);
            printf("------------------------------------------------------------\n");
            printf("Confirma Modificacion?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirm);
            confirm  = tolower(confirm);
            }while(!validateChar(confirm,'s','n'));

            if(confirm != 's'){
                puts("Modificación cancelada");
            }
            else{
                    switch(modifyMenu()){
                    case 1:
                    system("cls");
                    puts("Ingrese la nueva empresa a la cual desea cambiar");
                    showCompany(companies,companySize);
                    printf("Ingrese id: ");
                    scanf("%d", &buses[index].idCompany);
                    ok = 1;
                break;

                case 2:
                    system("cls");
                    puts("Ingrese el nuevo tipo de micro a la cual desea cambiar");
                    showKind(types,kindSize);
                    printf("Ingrese id: ");
                    scanf("%d", &buses[index].idKind);
                    ok = 1;
                break;

                case 3:
                    system("cls");
                    printf("La cantidad es: %d \n", buses[index].traveller);
                    fflush(stdin);
                    puts("Ingrese el nuevo sexo para modificar: ");
                    scanf("%d",&buses[index].traveller);
                    ok = 1;
                break;

                case 4:
                    system("cls");
                    puts("Ingrese el nuevo chofer al cual desea cambiar");
                    showDriver(drivers,driverSize);
                    printf("Ingrese id: ");
                    scanf("%d", &buses[index].idDriver);
                    ok = 1;
                break;

                case 10:
                    ok = 1;
                break;
                default:
                    puts("Opcion invalida");
                break;

               }
               }
            }
    }
    return ok;
}
int removeBuses(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driverSize){

    int ok = 0;
    int id;
    int index;


    char confirm;
    if(buses != NULL && size > 0 && types != NULL && kindSize > 0 && companies != NULL && companySize > 0 && drivers != NULL && driverSize > 0){
        system("cls");
        puts("------------------------BAJA MICROS------------------------\n\n");
        showBuses(buses,size,types,kindSize,companies,companySize,drivers,driverSize);
        puts("\n");
        printf("Ingrese ID: ");
        scanf("%d", &id);

        index = searchBusId(buses,size,id);
        if(index == -1){
            printf("ERROR!! El ID: %d no corresponde a un micro\n", id);
        }
        else{
            do{
            system("cls");
            showBus(buses[index],types,kindSize,companies,companySize,drivers,driverSize);
            printf("------------------------------------------------------------\n");
            printf("Confirma baja?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirm);
            confirm = tolower(confirm);
            }while(!validateChar(confirm,'s','n'));
            if(confirm == 's'){
            buses[index].isEmpty = 1;
            printf("*****Baja exitosa!****** \n");
            }
            else{
                printf("*****Baja cancelada!****** \n");
            }
        }

    }
    return ok;
}
int orderTravellerAndCompany(sBus buses[], int size , sCompany companies[], int companySize){
    int ok=0;
    char companyDescriptionI[21];
    char companyDescriptionJ[21];
    sBus auxBuses;

    if(buses != NULL && size > 0 && companies != NULL && companySize >0){
        for(int i = 0; i<size-1; i++)
        {
            for(int j = i + 1; j<size; j++)
            {
                loadCompanyDescription(companies, companySize,buses[i].idCompany, companyDescriptionI);
                loadCompanyDescription(companies, companySize,buses[j].idCompany, companyDescriptionJ);
                if((buses[i].traveller > buses[j].traveller)||
                    (buses[i].traveller == buses[j].traveller &&
                    strcmp(companyDescriptionI, companyDescriptionJ) > 0))
                {
                    auxBuses = buses[i];
                    buses[i] = buses[j];
                    buses[j] = auxBuses;
                }
            }
        }
        ok=1;
    }

    return ok;
}
int subMenuReports(){

    int option;

    system("cls");
    puts("********** SELECCIONA EL INFORME ********** \n \n");
    printf("1- Mostrar micros de la empresa seleccionada por el usuario.\n");
    printf("2- Mostrar micros de un tipo seleccionado. \n");
    printf("3- Informar Promedio de micros de tipo Vip sobre el total de micros de una empresa\n");
    printf("4- Mostrar un listado de los micros separados por empresa. \n");
    printf("5- Informar la o las empresas que pueden transportar más pasajeros (mayor acumulador de capacidades de sus micros) \n");
    printf("6- Mostrar la empresa con menor cantidad de micros\n");
    printf("10- Salir\n \n");
    printf("INGRESE OPCION: ");
    scanf("%d", &option);

    return option;

}
int showBusIdCompany(int companyId, sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driversSize){

    int ok = 0;
    int flag = 1;


    if (buses != NULL && size > 0 && companies !=NULL && companySize > 0)
    {


        while ( !validateCompanyId(companies,companyId,companySize)){
            printf("Error, ingrese id de la Empresa: ");
            scanf("%d", &companyId);
        }


        printf("------------------------------------------------------------\n");
        printf(" ID       Empresa       Tipo    Pasajeros      Chofer\n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < size; i++){
            if (!buses[i].isEmpty && buses[i].idCompany == companyId)
            {
                showBus(buses[i],types,kindSize,companies,companySize,drivers,driversSize);
                flag = 0;
            }
        }
        if (flag)
        {
            puts("No hay micros en esa empresa");

        }
        ok = 1;
    }
    return ok;
}
int ShowBusesCompanies(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize,
                         sDriver drivers[], int driverSize){
    int ok = 0;
    int companyId;

    if (buses != NULL && size > 0 && companies != NULL && companySize > 0 && types != NULL && kindSize > 0 && drivers != NULL && driverSize > 0){

        system("cls");
        puts("      ***Informes empresa de micros  ***");
        showCompany(companies,companySize);
        printf("Ingrese id de la empresa del micro: ");
        scanf("%d", &companyId);

        while(!validateCompanyId(companies,companyId,companySize)){
            printf("Error, ingrese id de Empresa de micro valido: ");
            scanf("%d", &companyId);
        }
        showBusIdCompany(companyId,buses,size,types,kindSize,companies,companySize,drivers,driverSize);

        ok = 1;
    }
    return ok;

}
int showBusIdKind(int kindId, sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driversSize){

    int ok = 0;
    int flag = 1;


    if (buses != NULL && size > 0 && types !=NULL && companySize > 0)
    {


        while ( !validateKindId(types,kindId,kindSize)){
            printf("Error, ingrese id del tipo de micro: ");
            scanf("%d", &kindId);
        }


        printf("------------------------------------------------------------\n");
        printf(" ID       Empresa       Tipo    Pasajeros      Chofer\n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < size; i++){
            if (!buses[i].isEmpty && buses[i].idKind == kindId)
            {
                showBus(buses[i],types,kindSize,companies,companySize,drivers,driversSize);
                flag = 0;
            }
        }
        if (flag)
        {
            puts("No hay micros de este tipo");
        }
        ok = 1;
    }
    return ok;
}
int ShowBusesTypes(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize,
                         sDriver drivers[], int driverSize){
    int ok = 0;
    int kindId;

    if (buses != NULL && size > 0 && companies != NULL && companySize > 0 && types != NULL && kindSize > 0 && drivers != NULL && driverSize > 0){

        system("cls");
        puts("     ***Informes empresa de micros  ***");
        showKind(types,kindSize);
        printf("Ingrese id del tipo de micro: ");
        scanf("%d", &kindId);

        while(!validateKindId(types,kindId,kindSize)){
            printf("Error, Ingrese id del tipo de micro: ");
            scanf("%d", &kindId);
        }
        showBusIdKind(kindId,buses,size,types,kindSize,companies,companySize,drivers,driverSize);

        ok = 1;
    }
    return ok;

}
int showpercentageBusesVip(sBus buses[], int size, sCompany companies[], int companySize, sKind types[], int kindSize){

    int ok = 0;
    int companyId;
    char companyDescription[20];
    int flag = 1;
    int allCont = 0;
    int vipCont = 0;
    float vipPorc = 0;

    if (buses != NULL && size > 0 && companies != NULL && companySize > 0 && types != NULL && kindSize > 0 ){
        system("cls");
        puts("               INFORME MICROS VIP ");
        puts("------------------------------------------------------------");

        showCompany(companies, companySize);

        puts("Ingrese id de la empresa del micro: ");
        scanf("%d", &companyId);

        while(!validateCompanyId(companies,companyId,companySize)){
            puts("Error, Ingrese id de la empresa del micro: ");
            scanf("%d", &companyId);
        }

        loadCompanyDescription(companies,companySize,companyId,companyDescription);

        for (int i=0; i < size; i++)
        {
            if (!buses[i].isEmpty && buses[i].idCompany == companyId){
                allCont++;
                if ( buses[i].idKind == 5003){
                    vipCont++;
                }
                flag = 0;
            }
        }
        if (flag)
        {
            puts("No hay micros VIP!.\n");

        }
        else
        {

            printf("En la empresa %s hay %d micros tipo VIP.\n", companyDescription, vipCont);
            vipPorc = (float) vipCont / allCont * 100;
            printf("el porcentaje de VIP sobre todos los tipos de micros es: %.2f \n", vipPorc);
            puts("\n");
        }
        ok = 1;
    }
    return ok;
}
int ShowBusesForCompany(sBus buses[], int size, sCompany companies[], int companySize, sKind types[], int kindSize, sDriver drivers[], int driverSize){

    int ok = 0;

    if (buses != NULL && size > 0 && companies != NULL && companySize > 0 && types != NULL && kindSize > 0){
        system("cls");
        puts("               ***  INFORMES DE MICROS POR EMPRESA  ***");
        puts("------------------------------------------------------------");

        for (int i=0; i < companySize; i++){

            printf("Empresa: %s\n", companies[i].description);
            showBusIdCompany(buses[i].idCompany,buses,size,types,kindSize,companies,companySize,drivers,driverSize);
            puts("------------------------------------------------------------\n");
        }

        ok = 1;
    }
    return ok;
}
char validateChar(char value, char a, char b){
      return (value == a || value == b);
}
int validateInt(int value, int lBot, int lTop){
    return (value >=lBot && value <= lTop);
}
