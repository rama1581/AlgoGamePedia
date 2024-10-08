#include "AlgoGamePedia.h"
int main(){
    //kamus
    game data;
    pemain dataP;
    ListG LG;
    adr_Game P;
    adr_Pemain pm;
    ListP LP;
    string z;
    char kembali = 'y';
    int x;

    //algoritma
    CreateListGame(LG);
    CreateListPemain(LP);
    while (kembali == 'y'){
        cout << "=============================== Menu ================================" << endl;
        cout << "| Aulia Azzahra (1301220010) - Muhammad Zidan Ramadhan (1301223314) |" << endl;
        cout << "=====================================================================" << endl;
        cout << "| 1. Masukkan Game                                                  |" << endl;
        cout << "| 2. Masukkan Pemain Game                                           |" << endl;
        cout << "| 3. Cari Nama Game                                                 |" << endl;
        cout << "| 4. Cari Nama Pemain                                               |" << endl;
        cout << "| 5. Cari Pemain berdasarkan game yang dimainkan                    |" << endl;
        cout << "| 6. Hapus Game                                                     |" << endl;
        cout << "| 7. Hapus Pemain                                                   |" << endl;
        cout << "| 8. Jumlah Pemain yang memainkan suatu game                        |" << endl;
        cout << "| 9. Tampilkan List Game                                            |" << endl;
        cout << "| 10.Tampilkan List Pemain                                          |" << endl;
        cout << "| 11.Tambahkan Pemain ke Game                                       |" << endl;
        cout << "| 12.Tampilkan semua data                                           |" << endl;
        cout << "| 0. keluar                                                         |" << endl;
        cout << "--------------------------------------------------------------------"  << endl;
        cout << "Masukkan menu (dalam angka) : ";
        cin >> x;
        if (x==1){
            string inputG;
            int n;
            cout << "Input data di (awal/akhir)? : ";
            cin >> inputG;
            if (inputG=="awal"){
                cout << "============================ Input =============================" << endl;
                cout << "Masukkan jumlah game yang ingin ditambahkan : ";
                cin >> n;
                for (int i = 0; i<n; i++){

                    cout << "Masukkan nama game : ";
                    getline(cin>>ws,data.NamaGame);
                    cout << "Masukkan ID game : ";
                    cin >> data.idGame;
                    cout << "Masukkan platform yang tersedia : ";
                    cin >> data.platform;
                    cout << "Masukkan genre : ";
                    cin >> data.genre;
                    cout << "Masukkan harga game : ";
                    cin >> data.harga;
                    P = AlokasiGame(data);
                    insertFirstGame(LG,P);
                    cout << endl;
                }
            }else if (inputG == "akhir"){
                cout << "============================ Input =============================" << endl;
                cout << "Masukkan jumlah game yang ingin ditambahkan : ";
                cin >> n;
                for (int i = 0; i<n; i++){
                    cout << "Masukkan nama game : ";
                    getline(cin>>ws,data.NamaGame);
                    cout << "Masukkan ID game : ";
                    cin >> data.idGame;
                    cout << "Masukkan platform yang tersedia : ";
                    cin >> data.platform;
                    cout << "Masukkan genre : ";
                    cin >> data.genre;
                    cout << "Masukkan harga game : ";
                    cin >> data.harga;
                    P = AlokasiGame(data);
                    insertLastGame(LG,P);
                    cout << endl;
                }
            } else {
                cout << "Input Tidak Valid" << endl;
            }

        }else if (x==2){
            string inputP;
            int m;
            cout << "Input data di (awal/akhir)? : ";
            cin >> inputP;
            if (inputP=="awal"){
                cout << "============================ Input =============================" << endl;
                cout << "Masukkan jumlah pemain yang ingin ditambahkan : ";
                cin >> m;
                for (int j = 0; j < m; j++){
                    cout << "Masukkan Nama Pemain : ";
                    getline(cin>>ws, dataP.NamaPemain);
                    cout << "Masukkan ID pemain : ";
                    cin >> dataP.idPemain;
                    cout << "Masukkan umur : ";
                    cin >> dataP.umur;
                    cout << "Masukkan kode negara pemain : ";
                    cin >> dataP.kodeNegara;
                    pm = AlokasiPemain(dataP);
                    insertFirstPemain(LP,pm);
                    cout << endl;
                }
            } else if (inputP == "akhir"){
                cout << "============================ Input =============================" << endl;
                cout << "Masukkan jumlah pemain yang ingin ditambahkan : ";
                cin >> m;
                for (int j = 0; j < m; j++){
                    cout << "Masukkan Nama Pemain : ";
                    getline(cin>>ws, dataP.NamaPemain);
                    cout << "Masukkan ID pemain : ";
                    cin >> dataP.idPemain;
                    cout << "Masukkan umur : ";
                    cin >> dataP.umur;
                    cout << "Masukkan kode negara pemain : ";
                    cin >> dataP.kodeNegara;
                    pm = AlokasiPemain(dataP);
                    insertLastPemain(LP,pm);
                    cout << endl;
                }
            } else {
                cout << "Input Tidak Valid" << endl;
            }
        }else if (x==3){
            cout << "============================== Search ==============================" << endl;
            cout << "Masukkan nama game yang ingin dicari : ";
            getline(cin>>ws, z);
            searchGame(LG,z);
        }else if (x==4){
            cout << "============================== Search ==============================" << endl;
            cout << "Masukkan nama pemain yang ingin dicari : ";
            getline(cin>>ws, z);
            searchPemain(LP,z);
        }else if (x==5){
            string namaP, namaG;
            cout << "============================== Search ==============================" << endl;
            cout << "Masukkan nama pemain yang ingin dicari : ";
            getline(cin>>ws, namaP);
            cout << "Masukkan game yang dimainkannya : ";
            getline(cin>>ws, namaG);
            searchPemainBdsGame(LG,LP,namaG,namaP);
        }else if (x==6){
            adr_Game F;
            string inputG;
            cout << "============================== Delete ======   ========================" << endl;
            cout << "Delete data awal : ";
            cin >> inputG;
            if (inputG == "awal"){
                deleteFirstGame(LG,F);
            }else{
                cout << "Input tidak valid." << endl;
            }

        }else if (x==7){
            adr_Pemain Z;
            string inputD;
            cout << "============================== Delete ==============================" << endl;
            cout << "Delete data di (awal/akhir/tengah)? : ";
            cin >> inputD;
            if (inputD == "awal"){
                deleteFirstPemain(LG,LP,Z);
            }else if (inputD == "akhir"){
                deleteLastPemain(LG,LP,Z);
            }else if (inputD == "tengah"){
                string cariPemain;
                adr_Pemain Prec;
                cout << "Masukkan nama pemain yang ingin dihapus : ";
                cin >> cariPemain;
                Z = findElemenPemain(LP,cariPemain);
                deleteAfterPemainAda(LG,LP,Prec,Z);
            }else{
                cout << "Input tidak valid." << endl;
            }

        }else if (x==8){
            adr_Game gameToCount;
            cout << "Masukkan nama game yang ingin dihitung pemainnya: ";
            getline(cin >> ws, z);
            gameToCount = findElemenGame(LG, z);
            if (gameToCount != NULL) {
                adr_Memainkan players = play(gameToCount);
                int playerCount = countChildFromGame(LG, players);
                cout << "Jumlah pemain yang memainkan game " << z << " adalah: " << playerCount << endl;
            } else {
                cout << "Game tidak ditemukan." << endl;
            }
        }else if (x==9){
            showGame(LG);
        }else if (x==10){
            showPemain(LP);
        }else if (x==11){
            ConnectPemaintoGame(LG,LP);
        }else if (x==12){
            showAllData(LG,LP);
        }else if (x==0){
            kembali = 'n';
            cout << "\nAnda Telah Keluar Dari Program" << endl;
        }else{
            cout << "Pilihan tidak valid" << endl;
        }

        if (kembali != 'n'){
            cout << "\nKembali ke menu utama? (y/n) : ";
            cin >> kembali;
            system("PAUSE");
            system("CLS");
        }

    }
}
