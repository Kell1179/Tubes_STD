#include <iostream>
#include "MLL_elektronik.h"

using namespace std;

int menu(){
    cout << "==========  MF CELL  ==========" << endl;
    cout << "| 1. Input data merk          |" << endl; //done
    cout << "| 2. Hapus data suatu merk    |" << endl; //done
    cout << "| 3. Cari data merk           |" << endl; //done
    cout << "| 4. Update data merk         |" << endl; //done
    cout << "| 5. Show data merk           |" << endl; //done
    cout << "|-----------------------------|" << endl;
    cout << "| 6. Input data seri          |" << endl; //done
    cout << "| 7. Hapus data seri          |" << endl; //done
    cout << "| 8. Update data seri         |" << endl; //last
    cout << "| 9. Cari data seri           |" << endl; //done
    cout << "| 10. Hitung jumlah seri      |" << endl; //done
    cout << "|-----------------------------|" << endl;
    cout << "| 11. Show All Data           |" << endl; //done
    cout << "===============================" << endl;

    cout << "Pilih opsi: ";

    int input = 0;
    cin >> input;
    return input;
};

//Prosedur dan Fungsi Parent (Merk)
void createListMerk(listMerk &LM){
    first(LM) = NULL;
    last(LM) = NULL;
}

adr_merk createElmMerk(infotypemerk x){ //alokasi
    adr_merk P = new elm_Merk;
    info(P) = x;
    next(P) = NULL;
    firstS(P) = NULL;
    return P;
}

void insertMerk(listMerk &LM, adr_merk P){
    string pilihan;
    cout << "Masukkan pilihan input (awal/akhir) : ";
    cin >> pilihan;
    while(pilihan != "awal" && pilihan != "akhir"){
        cout << "Masukkan inputan yang valid!" << endl;
        cout << "Masukkan pilihan input (awal/akhir) : ";
        cin >> pilihan;
    }
    if(pilihan == "awal"){
        if(first(LM) == NULL){
            first(LM) = P;
            last(LM) = P;
        } else {
            next(P) = first(LM);
            first(LM) = P;
        }
    } else if(pilihan == "akhir"){
        if(first(LM) == NULL){
            first(LM) = P;
            last(LM) = P;
        } else {
            next(last(LM)) = P;
            last(LM) = P;
        }
    } else {
        cout << "Input tidak valid" << endl;
    }
}

void showAllMerk(listMerk LM){
    adr_merk P = first(LM);
    if (P == NULL){
        cout << "List Kosong" << endl;
    } else {
        cout << "Berikut adalah data dari setiap Merk :" << endl;
        cout << endl;
        while(P != NULL) {
        cout << "Merk : " << info(P).merk << endl;
        cout << "Total barang dengan merk tersebut : " << info(P).stokMerk << endl;
        cout << endl;
        P = next(P);
        }
    }
}

void deleteMerk(listMerk &LM, adr_merk &P, string merkDihapus){
    P = searchMerk(LM, merkDihapus);
    if (P != NULL) {
        // Hapus elemen pertama
        if (P == first(LM)) {
            first(LM) = next(P);
            if (first(LM) == NULL) { // Jika hanya ada satu elemen
                last(LM) = NULL;
            }
            next(P) = NULL;
        }
        // Hapus elemen terakhir
        else if (P == last(LM)) {
            adr_merk Q = first(LM);
            while (next(Q) != last(LM)) {
                Q = next(Q);
            }
            last(LM) = Q;
            next(Q) = NULL;
        }
        // Hapus elemen di tengah
        else {
            adr_merk prec = first(LM);
            while (next(prec) != P) {
                prec = next(prec);
            }
            next(prec) = next(P);
            next(P) = NULL;
        }

        cout << "Data berhasil dihapus!" << endl;
    } else {
        // Jika merk tidak ditemukan
        cout << "Data tidak ditemukan!" << endl;
    }
}

adr_merk searchMerk(listMerk LM, string merkDicari){
    adr_merk P = first(LM);
    while(P != NULL){
        if (info(P).merk == merkDicari){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void changeMerk(listMerk &LM, adr_merk &P){
    string MD;
    cout << "Masukkan nama merk : ";
    cin >> MD;
    P = searchMerk(LM, MD);
    if (P != NULL){
        cout << "===============================" << endl;
        cout << "Merk lama               : " << info(P).merk << endl;
        cout << "Masukkan nama Merk baru : ";
        cin >> info(P).merk;
        cout << "Nama merk berhasil diubah !" << endl;

    } else {
        cout << "Merk tidak ditemukan";
    }
}

//Prosedur dan Fungsi Child (Seri)

adr_seri createElmSeri (infotypeseri y){
    adr_seri P = new elm_Seri;
    prev(P) = NULL;
    next(P) = NULL;
    info(P) = y;
    return P;
}

void insertSeri(listMerk &LM, adr_seri S, string merk){
    adr_merk P = searchMerk(LM, merk);
    if(P == NULL){
        cout << "Merk tidak ada" << endl;
    }else{
        if(firstS(P) == NULL){
            firstS(P) = S;
        }else{
            adr_seri Q = firstS(P);
            while(next(Q) != NULL){
                Q = next(Q);
            }
            next(Q) = S;
            prev(S) = Q;
        }
    }
}

void changeSeri(listMerk &LM, adr_seri &P){
    string MD, SD;
    cout << "Masukkan nama merk : ";
    cin >> MD;
    cout << "Masukkan nama seri : ";
    cin >> SD;
    P = searchSeri(LM, MD, SD);
    if (P != NULL){
        cout << "===============================" << endl;
        cout << "Merk                    : " << MD << endl;
        cout << "Nama Seri               : " << SD << endl;
        cout << "Masukkan nama Seri baru : ";
        cin >> info(P).seri;
        cout << "Nama seri berhasil diubah !" << endl;

    } else {
        cout << "Merk tidak ditemukan";
    }
}

adr_seri searchSeri(listMerk LM, string merkDicari,string seriDicari){
    adr_merk P = searchMerk(LM, merkDicari);
    adr_seri S = firstS(P);
    while(S != NULL){
        if (info(S).seri == seriDicari){
            return S;
        }
        S = next(S);
    }
    return NULL;
}

void deleteSeri(listMerk &LM, adr_seri &P, string MD, string SD){
    P = searchSeri(LM, MD, SD);
    adr_merk Q = searchMerk(LM, MD);
    adr_seri R = firstS(Q);
    if (P != NULL) {
        if (P == R){ // Delete first
            R = next(P);
            next(P) = NULL;
            prev(R) = NULL;
            firstS(Q) = R;
        } else if (next(P) == NULL){ // Delete last
            while(next(R) != P){
                R = next(R);
            }
            next(R) = NULL;
            prev(P) = NULL;
        } else {
            while(next(R) != P){
                R = next(R);
            }
            next(R) = next(P);
            prev(next(P)) = R;
            prev(P) = NULL;
            next(P) = NULL;
        }
        info(Q).stokMerk -= info(P).stokSeri;
        cout << "Data berhasil dihapus !" << endl;
    } else {
        cout << "Data tidak ditemukan !" << endl;
    }
}

int countSeri(listMerk LM, string merk){
    int banyak = 0;
    adr_merk P = searchMerk(LM, merk);
    adr_seri S = firstS(P);
    while(S != NULL){
        banyak++;
        S = next(S);
    }
    return banyak;
}

void showAll(listMerk LM){
    adr_merk P = first(LM);
    if (P == NULL) {
        cout << "List Kosong" << endl;
    } else {
        while (P!= NULL){
            cout << "Nama merk     : " << info(P).merk << endl;
            cout << "Jumlah barang : " << info(P).stokMerk << endl;
            cout << endl;
            adr_seri Q = firstS(P);
            while (Q != NULL){
                cout << "Nama seri     : " << info(Q).seri << endl;
                cout << "Jumlah barang : " << info(Q).stokSeri << endl;
                cout << endl;
                Q = next(Q);
            }
            cout << "===============================" << endl;
            P = next(P);
        }
    }
}
