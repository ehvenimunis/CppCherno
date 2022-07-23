// Flyweight.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

#include<iostream>
using namespace std;

class Object {
public:
    Object(int value_one) {
        m_value_one = value_one;
        cout << "ctor: " << m_value_one << '\n';
    }
    ~Object() {
        cout << m_value_one << ' ';
    }
    void report(int value_two) {
        cout << m_value_one << value_two << ' ';
    }
private:
    int m_value_one;
};

class FlyWeight {
public:
    static int X, Y;
    static Object* get_record(int in) {
        if (!myArray[in])
            myArray[in] = new Object(in);
        return myArray[in];
    }
    static void clean_up() {
        cout << "dtors: ";
        for (int i = 0; i < X; ++i) {
            if (myArray[i]) {
                delete myArray[i];
            }
        }
        cout << '\n';
    }
private:
    static Object* myArray[];
};

int FlyWeight::X = 6, FlyWeight::Y = 10;
Object* FlyWeight::myArray[] = {
  0, 0, 0, 0, 0, 0
};

int main() {
    for (int i = 0; i < FlyWeight::X; ++i) {
        for (int j = 0; j < FlyWeight::Y; ++j)
            FlyWeight::get_record(i)->report(j);
        cout << '\n';
    }
    FlyWeight::clean_up();
}

/*

    ctor: 0
    00 01 02 03 04 05 06 07 08 09
    ctor: 1
    10 11 12 13 14 15 16 17 18 19
    ctor: 2
    20 21 22 23 24 25 26 27 28 29
    ctor: 3
    30 31 32 33 34 35 36 37 38 39
    ctor: 4
    40 41 42 43 44 45 46 47 48 49
    ctor: 5
    50 51 52 53 54 55 56 57 58 59
    dtors: 0 1 2 3 4 5

*/