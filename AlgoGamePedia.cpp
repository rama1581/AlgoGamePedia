#include "AlgoGamePedia.h"
#include "stdio.h"

//CREATE
void CreateListGame(ListG &LG){
    first(LG) = NULL;
    last(LG) = NULL;
}
void CreateListPemain(ListP &LP){
    first(LP) = NULL;
}
void CreatePointerMemainkan(adr_Memainkan K){
    next(K) = NULL;
    nextPlay(K) = NULL;
}
adr_Game AlokasiGame(game x){
    adr_Game P = new ElmListGame;
    info(P).NamaGame = x.NamaGame;
    info(P).idGame = x.idGame;
    info(P).platform = x.platform;
    info(P).genre = x.genre;
    info(P).harga = x.harga;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}
adr_Pemain AlokasiPemain(pemain x){
    adr_Pemain P = new ElmListPemain;
    info(P).NamaPemain = x.NamaPemain;
    info(P).idPemain = x.idPemain;
    info(P).umur = x.umur;
    info(P).kodeNegara = x.kodeNegara;
    next(P) = NULL;
    return P;
}

//INSERT GAME
void insertFirstGame(ListG &LG, adr_Game P){
    if (first(LG) == NULL){
        first(LG) = P;
        last(LG) = P;
    } else {
        next(P) = first(LG);
        first(LG) = P;
    }
}
void insertLastGame(ListG &LG, adr_Game P){
    if (first(LG) == NULL){
        first(LG) = P;
        last(LG) = P;
    } else {
        next(last(LG)) = P;
        prev(P) = last(LG);
        last(LG) = P;
    }
}

//FIND
adr_Game findElemenGame(ListG LG, string x){
    adr_Game P = first(LG);
    while (P != NULL && info(P).NamaGame!= x){
        P = next(P);
    }

    return P;
}
adr_Pemain findElemenPemain(ListP LP, string x){
    adr_Pemain P = first(LP);
    while (P != NULL && info(P).NamaPemain!= x){
        P = next(P);
    }
    return P;
}
adr_Memainkan findPemainInGame(ListG LG, ListP LP, string Pemain, string Game){
    adr_Game G = findElemenGame(LG,Game);
    adr_Pemain P = findElemenPemain(LP,Pemain);
    if (G!=NULL && P!=NULL){
        adr_Memainkan K = play(G);
        while (K!= NULL && next(K)!=P){
            K = nextPlay(K);
        }
        return K;
    }else if (G==NULL && P==NULL){
        cout << "Game dan Pemain tidak ada di kedua list." << endl;
        return NULL;
    }else if (G==NULL){
        cout << "Game tidak ada di dalam list." << endl;
        return NULL;
    }else {
        cout << "Pemain tidak ada di dalam list." << endl;
        return NULL;
    }
}
int findPemainInAllGame(ListG LG, ListP LP, adr_Pemain P){
    adr_Game G = first(LG);
    adr_Memainkan K;
    int count = 0;
    string pemain = info(P).NamaPemain;
    while (G!=NULL){
        string game = info(G).NamaGame;
        K = findPemainInGame(LG,LP,pemain,game);
        if (K!=NULL){
            count++;
        }
        G = next(G);
    }
    return count;
}

//INSERT PEMAIN
void insertFirstPemain(ListP &LP, adr_Pemain P){
    if (first(LP) == NULL){
        first(LP) = P;
    } else {
        next(P) = first(LP);
        first(LP) = P;
    }
}
void insertLastPemain(ListP &LP, adr_Pemain P){
    if (first(LP) == NULL) {
        first(LP) = P;
    } else {
        adr_Pemain Q = first(LP);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

//DELETE GAME
void deleteFirstGame(ListG &LG, adr_Game &P){
    P = first(LG);
    if (P!=NULL){
        adr_Memainkan J;
        adr_Memainkan K = play(P);
        while (K!=NULL){
            J = K;
            K = nextPlay(K);
            deleteFirstMemainkan(J,P);
        }
        if (next(P)==NULL) {
            first(LG) = NULL;
            last(LG) = NULL;
            prev(P) = NULL;
        }else {
            first(LG) = next(P);
            prev(first(LG)) = NULL;
            next(P) = NULL;
        }

    }else{
        cout << "List game kosong." << endl;
    }
}
void deleteLastGame(ListG &LG, adr_Game P){
    P = last(LG);
    if (P!=NULL){
        adr_Memainkan J;
        adr_Memainkan K = play(P);
        while (K!=NULL){
            J = K;
            K = nextPlay(K);
            deleteFirstMemainkan(J,P);
        }
        last(LG) = prev(P);
        next(last(LG)) = NULL;
        prev(P) = NULL;
    }else{
        cout << "List game kosong." << endl;
    }
}

//DELETE MEMAINKAN
void deleteFirstMemainkan(adr_Memainkan K, adr_Game G){
    K = play(G);
    if (K!=NULL){
        if (nextPlay(K)==NULL){
            next(K) = NULL;
            play(G) = NULL;
        }else{
            next(K) = NULL;
            play(G) = nextPlay(K);
            nextPlay(K) = NULL;
        }
    }else{
        cout << "tidak ada";
    }
}
void deleteLastMemainkan(adr_Memainkan K, adr_Game G){
    adr_Memainkan P = play(G);
    K = play(G);
    while (nextPlay(K)!=NULL){
        P = K;
        K = nextPlay(K);
    }
    next(K) = NULL;
    nextPlay(P) = NULL;
}
void deleteAMemainkan(ListG &LG, adr_Memainkan K, adr_Game G){
    // K nya udah ada posisinya
    if (play(G)== K){
        deleteFirstMemainkan(K,G);
    }else if (nextPlay(K)==NULL){
        deleteLastMemainkan(K,G);
    }else{
        adr_Memainkan q = play(G);
        while (nextPlay(q)!= K){
            q = nextPlay(q);
        }
        next(K) = NULL;
        nextPlay(q) = nextPlay(K);
        nextPlay(K) = NULL;
    }
}

//DELETE PEMAIN
void deleteFirstPemain(ListG &LG, ListP &LP, adr_Pemain P){
    P = first(LP);
    if (P==NULL){
        cout << "List pemain kosong." << endl;
    }else{
        adr_Game G = first(LG);
        if (G==NULL){
            cout << "List Game kosong." << endl;
        }else{
            while (G!=NULL){
                adr_Memainkan K = play(G);
                while (K!=NULL){
                    if (next(K) == P){
                        deleteAMemainkan(LG,K,G);
                    }
                    K = nextPlay(K);
                }
                G = next(G);
            }
        }
        first(LP) = next(P);
        next(P) = NULL;
    }

}
void deleteLastPemain(ListG &LG, ListP &LP, adr_Pemain P){
    P = first(LP);
    if (P!=NULL){
        adr_Pemain K = first(LP);
        while (next(P)!=NULL){
            K = P;
            P = next(P);
        }
        adr_Game G = first(LG);
        if (G==NULL){
            cout << "List Game kosong." << endl;
        }else{
            while (G!=NULL){
                adr_Memainkan K = play(G);
                while (K!=NULL){
                    if (next(K) == P){
                        deleteAMemainkan(LG,K,G);
                    }
                    K = nextPlay(K);
                }
                G = next(G);
            }
            next(K) = NULL;
        }

    }else{
        cout << "List pemain kosong." << endl;
    }
}
void deleteAfterPemainAda(ListG &LG, ListP &LP, adr_Pemain Prec, adr_Pemain P){
     // P adalah yang ingin dihapus
    if (Prec != NULL) {
        while (next(Prec) != P && Prec != NULL) {
            Prec = next(Prec);
        }

        if (Prec != NULL) {
            adr_Game G = LG.first;
            if (G == NULL) {
                cout << "List Game kosong." << endl;
            } else {
                while (G != NULL) {
                    adr_Memainkan K = play(G);
                    while (K != NULL) {
                        if (next(K) == P) {
                            deleteAMemainkan(LG, K, G);
                        }
                        K = nextPlay(K);
                    }
                    G = next(G);
                }

                if (next(Prec) != NULL) {
                    adr_Pemain temp = next(Prec);
                    next(Prec) = next(temp);
                    next(temp) = NULL;
                    delete temp;
                } else {
                    cout << "Pemain setelah Prec tidak ditemukan." << endl;
                }
            }
        } else {
            cout << "P tidak ditemukan pada List Pemain." << endl;
        }
    } else {
        cout << "List Pemain kosong." << endl;
    }
}


//SEARCH : find sekalian input juga info di dalam pointernya
void searchGame(ListG LG, string x){
    adr_Game P = findElemenGame(LG,x);
    if (first(LG)==NULL){
        cout << "List game kosong." << endl;
    }else{
        if (P!= NULL){
        cout << "============================== Result ==============================" << endl;
        cout << "Nama game : " << info(P).NamaGame << endl;
        cout << "ID game : " << info(P).idGame << endl;
        cout << "Platform tersedia : " << info(P).platform << endl;
        cout << "Genre game : " << info(P).genre << endl;
        cout << "Harga game : " << info(P).harga << endl;
        }else{
            cout << "Game tidak ditemukan." << endl;
        }
    }

}
void searchPemain(ListP LP, string x){
    adr_Pemain P = findElemenPemain(LP,x);
    if (first(LP)==NULL){
        cout << "List pemain kosong." << endl;
    }else{
        if (P!=NULL){
            cout << "============================== Result ==============================" << endl;
            cout << "Nama Pemain : " << info(P).NamaPemain << endl;
            cout << "ID Pemain : " << info(P).idPemain << endl;
            cout << "Umur : " << info(P).umur << endl;
            cout << "Kode Negara : " << info(P).kodeNegara << endl;
        }else{
            cout << "Pemain tidak ditemukan." << endl;
        }
    }

}
void searchPemainBdsGame(ListG LG, ListP LP, string game, string pemain){
    adr_Game G = findElemenGame(LG,game);
    adr_Pemain P = findElemenPemain(LP,pemain);
    adr_Memainkan K = findPemainInGame(LG,LP,pemain,game);
    if (K!=NULL && P!= NULL){
        cout << "============================== Result ==============================" << endl;
        cout << "Nama Pemain : " << info(P).NamaPemain << endl;
        cout << "ID Pemain : " << info(P).idPemain << endl;
        cout << "Umur : " << info(P).umur << endl;
        cout << "Kode Negara : " << info(P).kodeNegara << endl;
    }else if(K==NULL && P!=NULL && G!=NULL){
        cout << "Data pemain " << pemain << " tidak ada di dalam game "<<game << endl;
    }else{

    }

}

void ConnectPemaintoGame(ListG &LG, ListP &LP) {
    string namaGame, namaPemain;
    // Minta input nama game
    cout << "Masukkan nama game yang dimainkan: ";
    getline(cin >> ws, namaGame);
    // Cari game dengan nama tertentu
    adr_Game game = findElemenGame(LG, namaGame);
    // Jika game ditemukan
    if (game != NULL) {
        // Minta input nama pemain
        cout << "Masukkan nama pemain yang memainkan game: ";
        getline(cin >> ws, namaPemain);
        // Cari pemain dengan nama tertentu
        adr_Pemain pemain = findElemenPemain(LP, namaPemain);
        // Jika pemain ditemukan
        if (pemain != NULL) {
            // Alokasi pointer memainkan
            adr_Memainkan memainkan = new ElmListMemainkan;
            CreatePointerMemainkan(memainkan);

            // Hubungkan pointer memainkan dengan pemain
            next(memainkan) = pemain;

            // Hubungkan pointer memainkan dengan game
            if (play(game) == NULL) {
                play(game) = memainkan;
            } else {
                adr_Memainkan Q = play(game);
                while (nextPlay(Q) != NULL) {
                    Q = nextPlay(Q);
                }
                nextPlay(Q) = memainkan;
            }
            cout << "Pemain " << namaPemain << " berhasil ditambahkan ke dalam game " << namaGame << "." << endl;
        } else {
            cout << "Pemain tidak ditemukan." << endl;
        }
    } else {
        cout << "Game tidak ditemukan." << endl;
    }
}

int countChildFromGame(ListG LG, adr_Memainkan P){
    int count = 0;

    // Loop untuk menghitung jumlah pemain yang memainkan game
    while (P != NULL) {
        count++;
        P = nextPlay(P);
    }

    return count;
}

//SHOW
void showGame(ListG LG){
    adr_Game P = first(LG);
    int x = 1;
    cout << "=========================================================================================" << endl;
    cout << "| " << setw(3) << "No." << " |" << setw(22) << "Nama Game" <<"  |  " << setw(11) << "ID Game" <<" |" << setw(13) << "Platform" << " |" << setw(9) << "Genre" << " |" << setw(14) << "Harga" << " |" << endl;
    cout << "=========================================================================================" << endl;
    while (P != NULL){
        cout << "| " << setw(3) << x << " | " << setw(22) << info(P).NamaGame << " | " << setw(12) << info(P).idGame
        << " | " << setw(12) << info(P).platform << " | " << setw(8) << info(P).genre << " | " << setw(13) << info(P).harga << " |" << endl;
        x++;
        P = next(P);
    }
    cout << "=========================================================================================" << endl;
    cout << endl;
}
void showPemain(ListP LP){
    adr_Pemain P = first(LP);
    int x = 1;
    cout << "====================================================================" << endl;
    cout << "| " << setw(3) << "No." << " |" << setw(13) << "ID Pemain" <<"  |  " << setw(16) << "Nama Pemain" <<" |" << setw(9) << "Umur" << " |" << setw(12) << "Kode Negara" << " |" << endl;
    cout << "====================================================================" << endl;
    while (P != NULL){
        cout << "| " << setw(3) << x << " | " << setw(13) << info(P).idPemain << " | " << setw(17) << info(P).NamaPemain << " | "
        << setw(8) << info(P).umur << " | " << setw(11) << info(P).kodeNegara << " |" << endl;
        x++;
        P = next(P);
    }
    cout << "====================================================================" << endl;
    cout << endl;
}

void showAllData(ListG LG, ListP LP) {
    adr_Game G = first(LG);
    adr_Pemain P;

    cout << "============================================================================================================================================================================" << endl;
    cout << "| " << setw(22) << "Nama Game" << "  |  " << setw(12) << "ID Game" << " |" << setw(13) << "Platform" << " |" << setw(9) << "Genre" << " |" << setw(15) << "Harga" << " |" << setw(23) << "Nama Pemain" << " |" << setw(15) << "ID Pemain" << " |" << setw(20) << "Umur" << " |" << setw(20) << "Kode" << " |" << endl;
    cout << "============================================================================================================================================================================" << endl;

    while (G != NULL) {
        adr_Memainkan M = play(G);
        while (M != NULL) {
            P = next(M);
            cout << "| " << setw(23) << info(G).NamaGame << " | " << setw(13) << info(G).idGame << " | " << setw(12) << info(G).platform << " | " << setw(8) << info(G).genre << " | " << setw(14) << info(G).harga << " | "
                 << setw(22) << info(P).NamaPemain << " | " << setw(14) << info(P).idPemain << " | " << setw(19) << info(P).umur << " | " << setw(19) << info(P).kodeNegara << " |" << endl;
            M = nextPlay(M);
        }
        G = next(G);
    }
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

