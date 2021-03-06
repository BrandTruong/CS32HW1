#include "Map.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    Map m1; //test swap
    m1.insert("Fred", 2.956);
    Map m2;
    m2.insert("Ethel", 3.538);
    m2.insert("Lucy", 2.956);
    m1.swap(m2);
    assert(m1.size() == 2 && m1.contains("Ethel") && m1.contains("Lucy") &&
        m2.size() == 1 && m2.contains("Fred"));
    Map m;  // maps strings to doubles
    assert(m.empty()); //test empty
    ValueType v = -1234.5;
    assert(!m.get("abc", v) && v == -1234.5); //test get 2 parameters
    m.insert("xyz", 9876.5); //test insert
    assert(m.size() == 1); //test size
    KeyType k = "hello";
    assert(m.get(0, k, v) && k == "xyz" && v == 9876.5); //test get 3 parameters
    assert(m.update("xyz", 113.2)); //test update
    assert(m.insertOrUpdate("wtf", 144.3)); //test insert part of iou
    assert(m.insertOrUpdate("wtf", 156.3)); //test update part of iou
    assert(m.get(1, k, v) && k == "wtf" && v == 156.3);
    assert(m.erase("wtf")); //test erase
    assert(m.insert("red", 98.2));
    assert(m.get(1, k, v) && k == "red" && v == 98.2 && !m.contains("wtf")); //tests contains
    cout << "Passed all tests POG" << endl;
}
