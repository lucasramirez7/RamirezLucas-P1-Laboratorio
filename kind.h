#ifndef KIND_H_INCLUDED
#define KIND_H_INCLUDED

typedef struct{
    int id;
    char description[20];
}sKind;

#endif // KIND_H_INCLUDED

int loadKindDescription(sKind types[], int size, int kindId, char description[]);
int showKind(sKind types[], int size);
int validateKindId(sKind types[], int id, int size);


