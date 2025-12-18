#include "parent.h"
#include "child.h"
#include "relasi.h"

int main(){
    ListTurnamen LT;
    ListPemain LP;

    createListTurnamen(LT);
    createListPemain(LP);

    int menu;
    string namaTurnamen, namaPemain, idPemain;
    int tahun;

    do{
        cout << "\n====== MENU MLL TURNAMEN BADMINTON ======\n";
        cout << "1. Tambah Turnamen\n";
        cout << "2. Tambah Pemain\n";
        cout << "3. Hubungkan Pemain ke Turnamen\n";
        cout << "4. Tampilkan Semua Turnamen & Pemain\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;
        cout << endl;

        switch(menu){
        case 1:
            cout << "Nama Turnamen : ";
            cin >> namaTurnamen;
            cout << "Tahun         : ";
            cin >> tahun;

            addTurnamen(
                LT,
                createElemenTurnamen(namaTurnamen, tahun)
            );
            cout << "Turnamen berhasil ditambahkan.\n";
            break;

        case 2:
            cout << "Nama Pemain : ";
            cin >> namaPemain;
            cout << "ID Pemain   : ";
            cin >> idPemain;

            addPemain(
                LP,
                createElemenPemain(namaPemain, idPemain)
            );
            cout << "Pemain berhasil ditambahkan.\n";
            break;

        case 3:
            cout << "Nama Turnamen : ";
            cin >> namaTurnamen;
            cout << "ID Pemain     : ";
            cin >> idPemain;

            {
                adrTurnamen t = searchTurnamen(LT, namaTurnamen);
                adrPemain p = searchPemain(LP, idPemain);

                if(t != nullptr && p != nullptr){
                    addRelasi(
                        t,
                        createElemenRelasi(t, p)
                    );
                    cout << "Relasi berhasil ditambahkan.\n";
                } else {
                    cout << "Turnamen atau Pemain tidak ditemukan!\n";
                }
            }
            break;

        case 4:
            {
                adrTurnamen t = LT.first;
                while(t != nullptr){
                    cout << "\nTurnamen: "
                         << t->info.nama
                         << " (" << t->info.tahun << ")\n";
                    cout << "Pemain: ";
                    displayRelasi(t);
                    cout << endl;
                    t = t->next;
                }
            }
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Menu tidak valid!\n";
        }

    } while(menu != 0);

    return 0;
}

