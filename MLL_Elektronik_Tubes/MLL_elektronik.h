#ifndef MLL_ELEKTRONIK_H_INCLUDED
#define MLL_ELEKTRONIK_H_INCLUDED
#include <iostream>

#define prev(P) P -> prev
#define next(P) P -> next
#define info(P) P -> info
#define firstS(P) P -> firstS
#define first(L) L.first
#define last(L) L.last

using namespace std;

struct merkElektronik {
    string merk;
    int stokMerk;
};

struct seriElektronik {
    string seri;
    int stokSeri;
};

typedef seriElektronik infotypeseri;
typedef merkElektronik infotypemerk;
typedef struct elm_Merk *adr_merk;
typedef struct elm_Seri *adr_seri;

struct elm_Seri{
    infotypeseri info;
    adr_seri next;
    adr_seri prev;
};

struct elm_Merk{
    infotypemerk info;
    adr_merk next;
    adr_seri firstS;
};

struct listMerk {
    adr_merk first;
    adr_merk last;
};

int menu();

//Prosedur dan Fungsi Parent (Merk)
void createListMerk(listMerk &LM);

adr_merk createElmMerk(infotypemerk x);
void insertMerk(listMerk &LM, adr_merk P);
void showAllMerk(listMerk LM);
void deleteMerk(listMerk &LM, adr_merk &P, string merkDihapus);
adr_merk searchMerk(listMerk LM, string merkDicari);
void changeMerk(listMerk &LM, adr_merk &P);

//Prosedur dan Fungsi Child (Seri)
adr_seri createElmSeri (infotypeseri y);
void insertSeri(listMerk &LM, adr_seri S,string merk);

void changeSeri(listMerk &LM, adr_seri &P);
adr_seri searchSeri(listMerk LM, string merkDicari,string seriDicari);
void deleteSeri(listMerk &LM, adr_seri &P, string MD, string SD);
int countSeri(listMerk LM, string merk);
void showAll(listMerk LM);

#endif // MLL_ELEKTRONIK_H_INCLUDED
