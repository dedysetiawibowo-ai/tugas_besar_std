#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define nullptr NULL

struct Turnamen {
    string nama;
    int tahun;
};

typedef struct elemenTurnamen *adrTurnamen;

struct elemenTurnamen {
    Turnamen info;
    adrTurnamen next;
    struct elemenRelasi *firstRelasi;
};

struct ListTurnamen {
    adrTurnamen first;
};

void createListTurnamen(ListTurnamen &L);
adrTurnamen createElemenTurnamen(string nama, int tahun);
void addTurnamen(ListTurnamen &L, adrTurnamen p);
adrTurnamen searchTurnamen(ListTurnamen L, string nama);


#endif // PARENT_H_INCLUDED
