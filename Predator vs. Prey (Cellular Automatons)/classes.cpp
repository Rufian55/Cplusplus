#include <iostream>

using namespace std;

class Critter {
    protected:
        int life;
        int location_x;
        int location_y;
    public:
        virtual void move(void){
            return;
        }
        virtual void print(void){
            return;
        }
        
};
class Ant: public Critter {
    public:
        Ant(){
            location_x = 0;
            location_y = 0;
            life = 0;
        }
        void move(){
            location_x += 1;
            location_y += 2;
        }
        void print(){
            cout << "[" << location_x << "][" << location_y << "]" << endl;
        }
        Ant* clone(){
            return new Ant(*this);
        }
};

class Dbug: public Critter {
    public:
        Dbug(){
            location_x = -1;
            location_y = -1;
            life = -1;
        }
        void move(){
            cout << "moving..." << endl;
        }
        void print() {
            cout << "printing..." << endl;
        }
};

class Gnat: public Critter {
    public:
        Gnat() {
            location_x = -99;
            location_y = -99;
            life = 0;
        }
        void move(){}
        void print(){cout << "Gnat!" << endl;}
};

void init_critters(Critter ***critters,int size){
    int i,j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            
            critters[i][j] = new Gnat();
        }
    }

}
void default_critters(Critter ***critters,int size, int ants, int doodlebugs){
    int i,j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            //here you could put in ants, doodlebugs, and fill the rest with gnats
        }
    }

}

void swap_critters(Critter** a, Critter** b){
    Critter *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int i,j;
    int size = 20; //20x20
    Critter* swap; 
    
    Critter** c;
    c = new Critter*[size];
    for (i = 0; i < size; i++){
        c[i] = new Gnat();
    }
    delete c[5];
    c[5] = new Ant(); 
    c[5]->print();
    c[5]->move();
    c[5]->print();
    //swap = c[4];
    //c[4] = c[5];
    //c[5] = swap;
    swap_critters(&c[4],&c[5]);
    c[4]->print();
    c[4]->move();
    c[4]->print();
    c[5]->print();
    
    cout << endl;
    
    Critter*** d;
    d = new Critter**[size];
    for (i = 0; i < size; i++){
        d[i] = new Critter*[size];
    }
    init_critters(d,size);
    d[5][5]->print();
    delete d[5][5];
    d[5][5] = new Ant();
    d[5][5]->print();
    d[5][5]->move();
    d[5][5]->print();
    //swap = d[7][7];
    //d[7][7] = d[5][5];
    //d[5][5] = swap;
    swap_critters(&d[7][7],&d[5][5]);
    d[7][7]->print();
    d[7][7]->move();
    d[7][7]->print();
    d[5][5]->print(); 
    return 0;
}
