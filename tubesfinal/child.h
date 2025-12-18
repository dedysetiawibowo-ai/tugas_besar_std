#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>

using namespace std;

#define nullptr NULL

struct Pemain {
    string nama;
    string id;
};

typedef struct elemenPemain *adrPemain;

struct elemenPemain {
    Pemain info;
    adrPemain next;
    adrPemain prev;
};

struct ListPemain {
    adrPemain first;
    adrPemain last;
};

void createListPemain(ListPemain &L);
adrPemain createElemenPemain(string nama, string id);
void addPemain(ListPemain &L, adrPemain p);
adrPemain searchPemain(ListPemain L, string id);


#endif // CHILD_H_INCLUDED
