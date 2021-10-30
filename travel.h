#include "buses.h"
#include "destiny.h"
#include "date.h"
#include "driver.h"


#ifndef TRAVEL_H_INCLUDED
#define TRAVEL_H_INCLUDED


typedef struct{
 int id; //(autoincremental)
 int idBus; //(debe existir) Validar
 int idDestiny; //(debe existir) Validar
 int isEmpty;
 sDate date;//(Validar día, mes y año)
}sTravel;

int setUpTravel(sTravel travels[], int size);
int searchFreeTravel(sTravel travels[], int size);
int registerTravel(sTravel travels[] ,int size ,int* pId ,sBus buses[] ,int busesSize ,sDestiny destines[],int destinySize);
void showTravel(sTravel travels, sBus buses[], int busesSize, sDestiny destinies[], int destinySize);
int showTravels(sTravel travels[], int size, sDestiny destinies[], int destinySize,sBus buses[],int busesSize);
#endif // TRAVEL_H_INCLUDED
