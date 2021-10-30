#include "kind.h"
#include "company.h"
#include "driver.h"

#ifndef BUSES_H_INCLUDED
#define BUSES_H_INCLUDED

typedef struct{

    int id;
    int idCompany;
    int idKind;
    int idDestiny;
    int idDriver;
    int traveller;
    int isEmpty;
}sBus;

char menu();
int setUpBus(sBus buses[], int size);
int searchFreeBus(sBus buses[], int size);
int registerBus(sBus buses[] ,int size ,int* pId ,sKind types[] ,int kindSize ,sCompany companies[],int companySize, sDriver drivers[],int driverSize);
void showBus(sBus bus, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driverSize);
int showBuses(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driverSize);
int searchBusId(sBus buses[], int size,int id);
int modifyMenu();
int modifyBus(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[],int driverSize);
int removeBuses(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driverSize);
int orderTravellerAndCompany(sBus buses[], int size , sCompany companies[], int companySize);
int showBusIdCompany(int companyId, sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driversSize);
int ShowBusesCompanies(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize, sDriver drivers[], int driverSize);
int ShowBusesForCompany(sBus buses[], int size, sCompany companies[], int companySize, sKind types[], int kindSize, sDriver drivers[], int driverSize);
char validateChar(char value, char a, char b);
int validateInt(int value, int lBot, int lTop);
#endif // BUSES_H_INCLUDED
