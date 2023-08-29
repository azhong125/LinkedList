#include "List.h"
#include <iostream>
using namespace std;
// Use this file to test your List class!
// This file won't be graded - do whatever you want.

int main() {
    List list;

 /*   list.insert("a");
    list.insert("b");
    list.insert("b");
   // list.insert("e");
   // list.insert("f");
    list.insert("g");
    list.insert("b");
    //list.insert("d");

/*
    list.insert("BOTTOM");
    list.insert("CHARM");
    list.insert("DOWN");
    list.insert("STRANGE");
    list.insert("UP");
    list.insert("TOP");
*/

    list.insert("A");
    list.insert("B");
    list.insert("AA");

    //list.insert("pla");
    cout << "count: " << list.count() << endl;
   // cout << list.remove(4) << endl;
    list.print(0);

    //list.print(1);


    //cout << list.lookup(0);
    //list.~List();
    return 0;
}
