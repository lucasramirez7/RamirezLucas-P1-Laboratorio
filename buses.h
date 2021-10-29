#include "kind.h"
#include "company.h"

#ifndef BUSES_H_INCLUDED
#define BUSES_H_INCLUDED

typedef struct{

    int id;
    int idCompany;
    int idKind;
    int idDestiny;
    int traveller;
    int isEmpty;
}sBus;

char menu();
int setUpBus(sBus buses[], int size);
int searchFreeBus(sBus buses[], int size);
int registerBus(sBus buses[] ,int size ,int* pId ,sKind types[] ,int kindSize ,sCompany companies[],int companySize);
int validateInt(int value, int lBot, int lTop);
void showBus(sBus bus, sKind types[], int kindSize, sCompany companies[], int companySize);
int showBuses(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize);
int searchBusId(sBus buses[], int size,int id);
int modifyMenu();
int modifyBus(sBus buses[], int size, sKind types[], int kindSize, sCompany companies[], int companySize);
int removeBuses(sBus buses[], int size, sKind cities[], int kindSize, sCompany companies[], int companySize);
int orderTravellerAndCompany(sBus buses[], int size , sCompany companies[], int companySize);
char validateChar(char value, char a, char b);

#endif // BUSES_H_INCLUDED
