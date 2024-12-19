#include <iostream>
#include "MLL_elektronik.h"

using namespace std;

int main()
{
    listMerk LM;
    infotypemerk dataMerk;
    infotypeseri dataSeri;
    adr_merk M;
    adr_merk P;
    adr_seri S;
    adr_seri Q;
    string merkDicari, seriDicari, dihapus;
    int jumlah;
    char choice;

    createListMerk(LM);

    int mainmenu = menu();
    while(mainmenu != 0){
        switch (mainmenu){
        case 1 : // Input data merk
            cout << "Masukkan jumlah merk yang akan diinput : ";
            cin >> jumlah;
            while(jumlah > 0){
                cout << "Nama Merk : ";
                cin >> dataMerk.merk;
                dataMerk.stokMerk = 0;
                M = createElmMerk(dataMerk);
                insertMerk(LM, M);
                jumlah--;
            }
            break;
        case 2 : // Hapus Merk
            if(first(LM) == NULL){

            } else {
                cout << "Masukkan nama merk : ";
                cin >> dihapus;
                deleteMerk(LM, M, dihapus);
            }
            break;
        case 3 : // Mencari Merk
            if(first(LM) == NULL){
                cout << "List masih kosong" << endl;
            } else {
                cout << "Masukkan nama merk : ";
                cin >> merkDicari;
                cout << endl;
                P = searchMerk(LM, merkDicari);
                if(P != NULL){
                    cout << "Merk ditemukan!" << endl;
                    cout << "Merk : " << info(P).merk << endl;
                    cout << "Total barang dengan merk tersebut : " << info(P).stokMerk << endl;
                    cout << endl;
                } else {
                    cout << "Merk tidak ditemukan" << endl;
                }
            }
            break;
        case 4 : // Update Merk
            changeMerk(LM, M);
            break;
        case 5 : // Menampilkan semua data merk
            showAllMerk(LM);
            break;
        case 6 : // Input data seri
            cout << "Masukkan merk : ";
            cin >> merkDicari;
            P = searchMerk(LM, merkDicari);
            if (P == NULL){
                cout << "Merk tidak ditemukan" << endl;
            } else {
                cout << "Masukkan jumlah seri yang akan diinput : ";
                cin >> jumlah;
                while(jumlah > 0){
                    cout << "Masukkan nama seri : " ;
                    cin >> dataSeri.seri;
                    cout << "Masukkan banyak barang : " ;
                    cin >> dataSeri.stokSeri;
                    Q = searchSeri(LM, merkDicari,dataSeri.seri);
                    if (Q == NULL){
                        S = createElmSeri(dataSeri);
                        insertSeri(LM, S, merkDicari);
                    } else {
                        cout << "Seri sudah ada, jumlah barang ditambahkan" << endl;
                        info(Q).stokSeri += dataSeri.stokSeri;
                    }
                    info(P).stokMerk += dataSeri.stokSeri;
                    jumlah--;
                }
            }
            break;
        case 7 : // Menghapus data suatu seri pada merk tertentu
            cout << "Masukkan merk : ";
            cin >> merkDicari;
            cout << "Masukkan seri : ";
            cin >> seriDicari;
            deleteSeri(LM, S, merkDicari, seriDicari);

            break;
        case 8 :
            changeSeri(LM, S);
            break;
        case 9 : // Mencari seri pada merk tertentu
            cout << "Masukkan merk : ";
            cin >> merkDicari;
            cout << "Masukkan seri : ";
            cin >> seriDicari;
            Q = searchSeri(LM, merkDicari, seriDicari);
            if (Q == NULL){
                cout << "Seri tidak ditemukan" << endl;
            } else {
                cout << "===============================" << endl;
                cout << "Seri ditemukan!" << endl;
                cout << "Merk      : " << merkDicari << endl;
                cout << "Nama Seri : " << info(Q).seri << endl;
                cout << "Jumlah    : " << info(Q).stokSeri << endl;
                cout << endl;
            }
            break;
        case 10 : // Menampilkan banyaknya seri pada suatu merk
            cout << "Masukkan nama merk : ";
            cin >> merkDicari;
            P = searchMerk(LM, merkDicari);
            if(P == NULL){
                cout << "Merk tidak ada" << endl;
            } else {
                cout << "===============================" << endl;
                cout << "Nama merk   :" << merkDicari << endl;
                cout << "Jumlah seri :" << countSeri(LM, merkDicari) << endl;
            }
            break;
        case 11 : // Menampilkan setiap merk beserta setiap seri pada merk tersebut
            showAll(LM);
            break;
        }

        cout << "Kembali ke menu utama?(Y/N): ";
        cin >> choice;

        if(choice == 'Y'){
            mainmenu = menu();
        } else {
            mainmenu = 0;
        }
    }
}
