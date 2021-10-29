#ifndef DESTINY_H_INCLUDED
#define DESTINY_H_INCLUDED

typedef struct {
    int id;
    char description[20];
    float cost;
}sDestiny;

int showDestiny(sDestiny destinies[], int size);
int validateDestinyId(sDestiny destinies[], int size, int id);
int loadDestinyDescription(sDestiny destinies[], int size, int destinyId, char description[]);
int loadDestinyCost(sDestiny destinies[], int size, int destinyId, float* cost);
#endif // DESTINY_H_INCLUDED
