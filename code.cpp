
// Arda Mavi - ardamavi.com

#include <iostream>

using namespace std;

char bölge[10] = {'0','1','2','3','4','5','6','7','8','9'};

// Yapay zeka oynama sayısı :
int yzsira = 1;

// Zorluk -> Kolay : 0 || Orta : 1 || Zor : 2
int zorluk = 1;

// Oyunu Bitiren olupp olmadığını kontrol eder :

bool bitirenvar = false;

void zeminçiz(){

    cout << endl << bölge[1] << " | " << bölge[2] << " | " << bölge[3] << endl
                 << "- | - | -" << endl
                 << bölge[4] << " | " << bölge[5] << " | " << bölge[6] << endl
                 << "- | - | -" << endl
                 << bölge[7] << " | " << bölge[8] << " | " << bölge[9] << endl << endl ;

}

bool kontrol(int yer){

    return ((bölge[yer] != 'X' && bölge[yer] != 'O' ? true : false));

}

int rndsayi(int sayi = 9){

    return (rand() % sayi + 1);

}

int rndkontrol(int rnd, int sayi = 9){

    if(kontrol(rnd)){

        return rnd;

    }else{

        return (rndkontrol(rndsayi(sayi)));

    }

}

int çaprazolasılık(int bölge1, int bölge2, int yer){

    if(((bölge[bölge1] == 'X' && bölge[bölge2] == 'X') || (bölge[bölge1] == 'O' && bölge[bölge2] == 'O')) && (bölge[yer] != 'X' && bölge[yer] != 'O'))
        return yer;

    // Uygun yer bulunamadıysa :
    return 0;
}

int zeka(){

    // Olasılıklar:

    // Dikey Olasılıklar :

    // 1,2,3 ve 4,5,6 aynı cins doluysa 7,8,9'a koy.
    for(int a = 1,b = 4, c = 7; a <= 3;a++,b++,c++){
        if(((bölge[a] == 'X' && bölge[b] == 'X') || (bölge[a] == 'O' && bölge[b] == 'O')) && (bölge[c] != 'X' && bölge[c] != 'O'))
            return c;
    }

    // 7,8,9 ve 4,5,6 aynı cins doluysa 1,2,3'a koy.
    for(int a = 7,b = 4, c = 1; a <= 9;a++,b++,c++){
        if(((bölge[a] == 'X' && bölge[b] == 'X') || (bölge[a] == 'O' && bölge[b] == 'O')) && (bölge[c] != 'X' && bölge[c] != 'O'))
            return c;
    }

    // 1,2,3 ve 7,8,9 aynı cins doluysa 4,5,6'a koy.
    for(int a = 1,b = 7, c = 4; a <= 3;a++,b++,c++){
        if(((bölge[a] == 'X' && bölge[b] == 'X') || (bölge[a] == 'O' && bölge[b] == 'O')) && (bölge[c] != 'X' && bölge[c] != 'O'))
            return c;
    }


    // Yatay Olasılıklar :


    // 1,4,7 ve 2,4,8 aynı cins doluysa 3,6,9'a koy.

    for(int a = 1; a <= 7; a += 3){
        if(((bölge[a] == 'X' && bölge[a+1] == 'X') || (bölge[a] == 'O' && bölge[a+1] == 'O')) && (bölge[a+2] != 'X' && bölge[a+2] != 'O'))
            return (a+2);
    }

    // 2,5,8 ve 3,6,9 aynı cins doluysa 1,4,7'a koy.

    for(int a = 2; a <= 8; a += 3){
        if(((bölge[a] == 'X' && bölge[a+1] == 'X') || (bölge[a] == 'O' && bölge[a+1] == 'O')) && (bölge[a-1] != 'X' && bölge[a-1] != 'O'))
            return (a-1);
    }

    // 1,4,7 ve 3,6,9 aynı cins doluysa 2,5,8'a koy.

    for(int a = 1; a <= 7; a += 3){
        if(((bölge[a] == 'X' && bölge[a+2] == 'X') || (bölge[a] == 'O' && bölge[a+2] == 'O')) && (bölge[a+1] != 'X' && bölge[a+1] != 'O'))
            return (a+1);
    }


    // Çapraz Olasılıklar :

    // 1 - 5 -> 9
    if(çaprazolasılık(1,5,9) != 0)
        return çaprazolasılık(1,5,9);

    // 3 - 5 -> 7
    if(çaprazolasılık(3,5,7) != 0)
        return çaprazolasılık(3,5,7);

    // 5 - 9 -> 1
    if(çaprazolasılık(5,9,1) != 0)
        return çaprazolasılık(5,9,1);

    // 7 - 5 -> 3
    if(çaprazolasılık(7,5,3) != 0)
        return çaprazolasılık(7,5,3);

    // 1 - 9 -> 5
    if(çaprazolasılık(1,9,5) != 0)
        return çaprazolasılık(1,9,5);

    // 3 - 7 -> 5
    if(çaprazolasılık(3,7,5) != 0)
        return çaprazolasılık(3,7,5);


    // Eğer zor seçiliyse ve bir olasılık yoksa köşeye oyna :

    int rnd = rndkontrol(rndsayi(4));

    switch(rnd){

        case 1:
            return 1;
            break;
        case 2:
            return 3;
            break;
        case 3:
            return 7;
            break;
        case 4:
            return 9;
            break;
        default:
            cout << "Bir Hata Oluştu : Eğer zor seçiliyse ve bir olasılık yoksa köşeye oyna." << endl;
            break;

    }

    // Hiçbir olasılık yoksa rastgele seç :
    return rndkontrol(rndsayi());;

}

void yapayzeka(){

    if(yzsira == 1){

        // Zor seçilmediyse ilk oyunda rastgele yer seç :
        if(zorluk != 2) {

            int rnd = rndsayi();

            if (kontrol(rnd)) {
                bölge[rnd] = 'O';
            } else {
                yapayzeka();
            }

        }else {

            if((bölge[5] != 'X' && bölge[5] != 'O')){
                // Orta Boşsa :
                bölge[5] = 'O';
            }else{
                // Orta Boş Değilse :
                bölge[zeka()] = 'O';}

        }
    }else{

        bölge[zeka()] = 'O';

    }

    // Eğer kolay seçilmişse hep raskele oynar :
    if(zorluk != 0)
    yzsira++;

}

void oyna(char oyuncu){

    if(oyuncu == 'X'){

        int yer;

        cout << "Sıra X'de : ";

            cin >> yer;

        if(kontrol(yer)){

            bölge[yer] = 'X';

        }else{

            cout << "Hatalı Giriş !" << endl;
            oyna('X');

        }

    }else{

        cout << "Sıra O'da ..." << endl ;

        yapayzeka();

    }

}

void kimbitirdi(int yer){

    if(bölge[yer] == 'X') {
        cout << "Kazanan : X\n! Tebrikler Kazandınız !" << endl;
    } else{
        cout << "Kazanan : O\n!Arda'nın yapay zeka'sı kazandı !" << endl;
    }

    bitirenvar = true;

}

bool bittimi(){

    // Yatay Kontrol
    for(int i = 1; i <= 7; i += 3){
        if((bölge[i] == 'X' && bölge[i+1] == 'X' && bölge[i+2] == 'X') || (bölge[i] == 'O' && bölge[i+1] == 'O' && bölge[i+2] == 'O')) {
            kimbitirdi(i+1);
            return true;
        }
    }

    // Dikey Kontrol
    for(int i = 1; i <= 9; i++){
        if((bölge[i] == 'X' && bölge[i+3] == 'X' && bölge[i+6] == 'X') || (bölge[i] == 'O' && bölge[i+3] == 'O' && bölge[i+6] == 'O')){
            kimbitirdi(i+3);
            return true;
        }
    }

    // Çapraz Kontrol :
    if((bölge[1] == 'X' && bölge[5] == 'X' && bölge[9] == 'X') || (bölge[1] == 'O' && bölge[5] == 'O' && bölge[9] == 'O')){
        kimbitirdi(5);
        return true;
    }

    if((bölge[3] == 'X' && bölge[5] == 'X' && bölge[7] == 'X') || (bölge[3] == 'O' && bölge[5] == 'O' && bölge[7] == 'O')){
        kimbitirdi(5);
        return true;
    }

    return false;

}

void zorluksor(){

    cout << endl << "0 - Kolay \n1 - Orta \n2 - Zor" << endl << "Zorluk seçiniz :" ;

    char zorlukseçimi = '3';

    cin >> zorlukseçimi;

    switch(zorlukseçimi){
        case '0':
            zorluk = 0;
            break;
        case '1':
            zorluk = 1;
            break;
        case '2':
            zorluk = 2;
            break;
        default:
            cout << "Hatalı Giriş !" << endl;
            zorluksor();
            break;
    }


}

int main() {

    int tur = 1;

    srand(time(NULL));

    // Mac ve Linux Uyumlu Ekran Temizleme :
    system("clear");

    cout << endl << "Yapay Zeka X-O-X Oyunu - Arda Mavi - ardamavi.com" << endl;

    zorluksor();

    // Oyun :

    cout << endl << "Oyun Başladı !" << endl;

    do{

        zeminçiz();

        oyna(tur%2 != 0 ? 'X' : 'O');

        tur++;

        if(bittimi()){
            break;
        }else{};

    }while(tur <= 9);

    zeminçiz();

    if(!bitirenvar)
        cout << "Güzel oyundu\n! Berabere !\n";

    cout << "Oyun Bitti !" << endl << "Arda Mavi" << endl;

}
