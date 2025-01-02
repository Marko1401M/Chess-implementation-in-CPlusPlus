#include "tabla.h"

using namespace std;

int Tabla :: odigranoPoteza = 0;

Tabla :: Tabla(){
    inicijalizujTablu();
}

Tabla :: ~Tabla(){
    for(auto fig : pojedeneBeli) delete fig;
    for(auto fig : pojedeneCrni) delete fig;
}

void Tabla :: inicijalizujTablu(){
    naPotezu = 'B';
    odigranoPoteza = 0;
    potezi.clear();
    pojedeneBeli.clear();
    pojedeneCrni.clear();
    polja = new Polje**[8];
    for(int i = 0 ; i < 8; i++){
        polja[i] = new Polje*[8];
        for(int j = 0; j < 8; j++){
            polja[i][j] = new Polje(i,j);
        }
    }
    for(int i = 0; i < 8; i++){
        polja[1][i] = new Polje(1,i,new Pijun('C'));
    }
    for(int i = 0; i < 8 ;i ++){
        polja[6][i] = new Polje(6,i,new Pijun('B'));
    }
    polja[0][0] = new Polje(0,0,new Top('C'));
    polja[0][7] = new Polje(0,7,new Top('C'));

    polja[7][0] = new Polje(7,0,new Top('B'));
    polja[7][7] = new Polje(7,7,new Top('B'));

    polja[0][2] = new Polje(0,2,new Lovac('C'));
    polja[0][5] = new Polje(0,5,new Lovac('C'));

    polja[7][2] = new Polje(7,2,new Lovac('B'));
    polja[7][5] = new Polje(7,5,new Lovac('B'));

    polja[0][4] = new Polje(0,4,new Kraljica('C'));
    polja[0][3] = new Polje(0,3,new Kralj('C'));

    polja[7][3] = new Polje(7,3,new Kraljica('B'));
    polja[7][4] = new Polje(7,4,new Kralj('B'));

    polja[0][1] = new Polje(0,1,new Skakac('C'));
    polja[0][6] = new Polje(0,6,new Skakac('C'));

    polja[7][1] = new Polje(7,1,new Skakac('B'));
    polja[7][6] = new Polje(7,6,new Skakac('B'));

    cout << "### predstavlja crno polje, prazan prostor predstavlja belo polje\n";
    stampajTablu();
    ucitajPotez();
}

bool Tabla :: proveriPolje(const char boja, const int x, const int y) const{
    if( polja[x][y]->getFigura() == nullptr || polja[x][y]->getFigura()->getBoja() != boja) return true;
    return false;
}

Figura* Tabla :: getPolje(const int x, const int y){
    return polja[x][y]->getFigura();
}

bool Tabla :: odigrajPotez(const int startX,const int startY, const int endX, const int endY) {
    if (startX < 0 || startX >= 8 || startY < 0 || startY >= 8 || endX < 0 || endX >= 8 || endY < 0 || endY >= 8) {
        throw PotezIzvanTableException();
    }
    if(polja[startX][startY]->getFigura() == nullptr) {
        throw PraznoPoljeException();
    }
    if (polja[startX][startY]->getFigura()->getBoja() != naPotezu) {
        throw IgracNijeNaPotezuException();
    }
        
    if (!polja[startX][startY]->getFigura()->proveriPotez(startX, startY, endX, endY, this)) {
        throw NevalidanPotezException();
    }
    //cout << "Tabla" << endl;
    if(polja[endX][endY]->getFigura() != nullptr){
        if(polja[endX][endY]->getFigura()->getBoja() == 'C') pojedeneBeli.push_back(polja[endX][endY]->getFigura());
        else pojedeneCrni.push_back(polja[endX][endY]->getFigura());
    }
    polja[endX][endY]->setFigura(polja[startX][startY]->getFigura());
    polja[startX][startY]->setFigura(nullptr);
    return true;
}

void Tabla :: ucitajPotez(){
    char startX,endX; 
    int startY, endY;
    proveriSah();
    cout << "Unesite pocetno i zavrsno polje u formatu [A-H][1-8] [A-H][1-8]: ";
    cin >> startX;
    cin >> startY;
    cin >> endX;
    cin >> endY;
 //   cout << startX - 'A' << ' ' << 8 - startY << ' ' << endX - 'A' << ' ' <<  8 - endY << endl;

    try{
        odigrajPotez(8-startY,startX - 'A',8-endY,endX - 'A');
        cout << '\n';
        cout << '\n';
        cout << '\n';
        //cout << "MOZDA OVDE\n";
        potezi.push_back(Potez(startX, startY, endX, endY,odigranoPoteza/2));
        odigranoPoteza++;
        //cout << "AAAAAA\n";
        naPotezu = naPotezu == 'C'?'B':'C';
        stampajTablu();
        int kraj = proveriKraj();
        if(!kraj) ucitajPotez();
        else if(kraj == 1){
            cout << "Pobednik je beli!\n";
            cout << "Ako zelite novu igru unesite [1]\nAko ne zelite unesite [2]\nAko zelite prikaz svih poteza unesite [3]\n";
            int option;
            cin >> option;
            if(option == 1) inicijalizujTablu();
            else if(option == 3) {
                prikaziPoteze();
                cout << "Ako zelite novu igru pritisnite [1]\nAko ne zelite pritisnite [2]\n";
                cin >> option;
                if(option == 1) inicijalizujTablu();
                else return;
            }
            else return;
        }
        else if(kraj == - 1){
            cout << "Pobednik je crni!\n";
            cout << "Ako zelite novu igru unesite [1]\nAko ne zelite unesite [2]\nAko zelite prikaz svih poteza unesite [3]\n";
            int option;
            cin >> option;
            if(option == 1) inicijalizujTablu();
            else if(option == 3) {
                prikaziPoteze();
                cout << "Ako zelite novu igru pritisnite [1]\nAko ne zelite pritisnite [2]\n";
                cin >> option;
                if(option == 1) inicijalizujTablu();
                else return;
            }
            else return;
        } 
    } catch(const PraznoPoljeException &e){
        cout << e.what() << endl;
        stampajTablu();
        ucitajPotez();
    } catch (const NevalidanPotezException &e) {
        cout << e.what() << endl;
        stampajTablu();
        ucitajPotez();
    } catch (const PotezIzvanTableException &e) {
        cout << e.what() << endl;
        stampajTablu();
        ucitajPotez();
    } catch (const IgracNijeNaPotezuException &e){
        cout << e.what() << endl;
        stampajTablu();
        ucitajPotez();
    } catch (const std::exception &e) {
        cout << e.what() << endl;
        stampajTablu();
        ucitajPotez();
    } catch (...) {
        cout << "Neocekivana greska!" << endl;
        stampajTablu();
        ucitajPotez();
    }
    
    return;
}

void Tabla :: stampajTablu() const{
    stampajPojedene();
    for(int i = 0; i < 8;i++){
        if(!i){
            for(int j = 0; j < 8; j++){
                cout << "| " << (char)(65 + j) << " |";
            }
            cout <<endl;
        }
        for(int j = 0; j < 8 ; j++){
            if(polja[i][j]->getFigura() == nullptr){
                if((i+j)%2 != 0) cout << "|###|";
                else cout << "|   |";
                
            }
            else cout << '|' << polja[i][j]->getFigura() << "|";
        }
        cout << ' ' << 8 - i << endl;
    }
    naPotezu == 'B'?cout<<"Na potezu je BELI\n":cout<<"NA potezu je CRNI\n";
}

int Tabla :: proveriKraj() const{
    bool crniKralj = false, beliKralj = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(polja[i][j]->getFigura() != nullptr && polja[i][j]->getFigura()->getBoja() == 'B' && polja[i][j]->getFigura()->getTip() == 'K') beliKralj = true;
            if(polja[i][j]->getFigura() != nullptr && polja[i][j]->getFigura()->getBoja() == 'C' && polja[i][j]->getFigura()->getTip() == 'K') crniKralj = true;

        }
    }
    if(!beliKralj) return -1;
    if(!crniKralj) return 1;
    return 0;
}

void Tabla :: prikaziPoteze() const{
    cout << "Lista poteza:\n";
    for(Potez potez : potezi){
        cout << potez.getPotez() << endl;
    }
}

void Tabla :: stampajPojedene() const{
    cout << "Pojedene beli: ";
    for(auto fig : pojedeneBeli){
        cout << fig->getTip() << " ";
    }
    cout << endl << "Pojedene crni: ";
    for(auto fig : pojedeneCrni){
        cout << fig->getTip() << " ";
    }
    cout << endl;
}

void Tabla :: proveriSah(){
    int bX, bY;
    int cX, cY;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(polja[i][j]->getFigura() != nullptr && polja[i][j]->getFigura()->getTip() == 'K'){
                if(polja[i][j]->getFigura()->getBoja() == 'B'){
                    bX = i;
                    bY = j;
                }
                else {
                    cX = i;
                    cY = j;
                }
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(polja[i][j]->getFigura() != nullptr && polja[i][j]->getFigura()->proveriPotez(i,j,bX,bY,this) && naPotezu == 'B'){
                cout <<"Beli kralj je pod sahom, Beli igrac mora pomeriti Kralja!!!\n";
            }
            else if(polja[i][j]->getFigura()!= nullptr && polja[i][j]->getFigura()->proveriPotez(i,j,cX,cY,this) && naPotezu == 'C'){
                cout << "Crni kralj je pod sahom, Crni igrac mora pomeriti Kralja!!!\n";

            }
        }
    }
}