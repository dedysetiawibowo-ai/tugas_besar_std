#include "parent.h"
#include "child.h"
#include "relasi.h"

// ini untuk parent
void createListTurnamen(ListTurnamen &L){
    L.first = nullptr;
}

adrTurnamen createElemenTurnamen(string nama, int tahun){
    adrTurnamen p = new elemenTurnamen;
    p->info.nama = nama;
    p->info.tahun = tahun;
    p->next = nullptr;
    p->firstRelasi = nullptr;
    return p;
}

void addTurnamen(ListTurnamen &L, adrTurnamen p){
    p->next = L.first;
    L.first = p;
}

adrTurnamen searchTurnamen(ListTurnamen L, string nama){
    adrTurnamen p = L.first;
    while(p != nullptr){
        if(p->info.nama == nama){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// ini untuk child
void createListPemain(ListPemain &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrPemain createElemenPemain(string nama, string id){
    adrPemain p = new elemenPemain;
    p->info.nama = nama;
    p->info.id = id;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}

void addPemain(ListPemain &L, adrPemain p){
    if(L.first == nullptr){
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}

adrPemain searchPemain(ListPemain L, string id){
    adrPemain p = L.first;
    while(p != nullptr){
        if(p->info.id == id){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

// ini untuk relasi
adrRelasi createElemenRelasi(adrTurnamen p, adrPemain c){
    adrRelasi r = new elemenRelasi;
    r->parent = p;
    r->child = c;
    r->next = nullptr;
    return r;
}

void addRelasi(adrTurnamen p, adrRelasi r){
    r->next = p->firstRelasi;
    p->firstRelasi = r;
}

void deleteRelasi(adrTurnamen p, string idPemain){
    adrRelasi r = p->firstRelasi;
    adrRelasi prev = nullptr;

    while(r != nullptr){
        if(r->child->info.id == idPemain){
            if(prev == nullptr){
                p->firstRelasi = r->next;
            } else {
                prev->next = r->next;
            }
            delete r;
            return;
        }
        prev = r;
        r = r->next;
    }
}

void displayRelasi(adrTurnamen p){
    adrRelasi r = p->firstRelasi;
    while(r != nullptr){
        cout << r->child->info.nama << " ";
        r = r->next;
    }
}
