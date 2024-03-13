#include "Map.h"

#include <iostream>
using namespace std;

//ii
void test2() {
    Map map(3, 3);

    map.place(0, 0, VEGETATION);
    cout << map.getLabel(0, 0) << endl; //print 'T'

    map.place(0, 0, HERBIVORE);
    cout << map.getLabel(0, 0) << endl; //shoudl also print 'T'

    cout << endl;
}

//iii
void test3() {
    Map map(7, 10);
    map.display();

    cout << endl;
}

//iv
void test4() {
    //testing edge cases
    Map map(7, 10);
    map.place(0, 0, VEGETATION);
    map.place(1, 1, TERRAIN);
    map.place(0, 0, HERBIVORE); //will not change (0, 0)
    map.place(1, 1, OMNIVORE); //will not change (1, 1)
    cout << map.getXY(0, 0) << " " << map.getXY(1, 1) << endl; //should print "T #"

    cout << endl;
    Map map1(7, 10);

    //placing 15 blocks (#) randomly on the map
    map1.randomPlace(TERRAIN, 15);
    map1.display();

    cout << endl;
    Map map2(7, 10);

    //placing 15 blocks (#) randomly on the map
    map2.randomPlace(TERRAIN, 15);
    map2.display();

    cout << endl;
}

//v
void test5() {

    //1x1
    Map map1(1, 1);
    map1.randomPlace(TERRAIN, 1);
    map1.display();

    //7x10
    cout << endl;
    Map map2(7, 10);
    map2.randomPlace(TERRAIN, 7);
    map2.display();

    //15x20
    cout << endl;
    Map map3(15, 20);
    map3.randomPlace(TERRAIN, 15);
    map3.display();

    cout << endl;
}

int main() {
    test2();
    test3();
    test4();
    test5();
}
