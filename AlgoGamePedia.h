#ifndef ALGOGAMEPEDIA_H_INCLUDED
#define ALGOGAMEPEDIA_H_INCLUDED
#include <iostream>
#include <string>
#include <iomanip>

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define play(Q) Q->play
#define nextPlay(Q) Q->nextPlay
using namespace std;

struct game {
    string NamaGame;
    string idGame;
    string platform;
    string genre;
    int harga;
};

struct pemain {
    string NamaPemain;
    string idPemain;
    int umur;
    string kodeNegara;
};

typedef struct ElmListPemain *adr_Pemain;

struct ElmListPemain {
    pemain info;
    adr_Pemain next;
};

typedef struct ElmListGame *adr_Game;

typedef struct ElmListMemainkan *adr_Memainkan;

struct ElmListGame {
    game info;
    adr_Game next,prev;
    adr_Memainkan play;
};

struct ElmListMemainkan {
    adr_Pemain next;
    adr_Memainkan nextPlay;
};

struct ListG {
    adr_Game first, last;
};

struct ListP {
    adr_Pemain first;
};

void CreateListGame(ListG &LG);
void CreateListPemain(ListP &LP);
void CreatePointerMemainkan(adr_Memainkan K);
adr_Game AlokasiGame(game x);
adr_Pemain AlokasiPemain(pemain x);
void insertFirstGame(ListG &LG, adr_Game P);
void insertFirstPemain(ListP &LP, adr_Pemain P);
void insertAfterGame(ListG &LG, adr_Game P, string game);
void insertAfterPemain(ListP &LP, adr_Pemain Prec, adr_Pemain P);
void insertLastGame(ListG &LG, adr_Game P);
void insertLastPemain(ListP &LP, adr_Pemain P);

void deleteFirstGame(ListG &LG, adr_Game &P);
void deleteFirstPemain(ListG &LG, ListP &LP, adr_Pemain P);
void deleteAfterGame(ListG &LG, adr_Game Prec, adr_Game P);
void deleteAfterPemainAda(ListG &LG, ListP &LP, adr_Pemain Prec, adr_Pemain P);

void deleteLastGame(ListG &LG, adr_Game P);
void deleteLastPemain(ListG &LG, ListP &LP, adr_Pemain P);

void showGame(ListG LG);
void showPemain(ListP LP);
adr_Game findElemenGame(ListG LG, string x);
adr_Pemain findElemenPemain(ListP LP, string x);
adr_Memainkan findPemainInGame(ListG LG, ListP LP, string Pemain, string Game);
int findPemainInAllGame(ListG LG, ListP LP, adr_Pemain P);

void searchGame(ListG LG, string x);
void searchPemain(ListP LP, string x);
void searchPemainBdsGame(ListG LG, ListP LP, string game, string pemain);

int countChildFromGame(ListG LG, adr_Memainkan P);
void ConnectPemaintoGame(ListG &LG, ListP &LP);
void showAllData(ListG LG, ListP LP);

void deleteAMemainkan(ListG &LG, adr_Memainkan K, adr_Game G);
void deleteFirstMemainkan(adr_Memainkan K, adr_Game G);
void deleteLastMemainkan(adr_Memainkan K, adr_Game G);
#endif // ALGOGAMEPEDIA_H_INCLUDED
