#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "parent.h"
#include "child.h"

typedef struct elemenRelasi *adrRelasi;

struct elemenRelasi {
    adrTurnamen parent;
    adrPemain child;
    adrRelasi next;
};

adrRelasi createElemenRelasi(adrTurnamen p, adrPemain c);
void addRelasi(adrTurnamen p, adrRelasi r);
void deleteRelasi(adrTurnamen p, string idPemain);
void displayRelasi(adrTurnamen p);



#endif // RELASI_H_INCLUDED
