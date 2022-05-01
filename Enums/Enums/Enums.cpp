/*
    Author: Muhammed Salih AYDOGAN
    Date: 01/05/2022
    Version: 1.0
*/

#include <iostream>
using namespace std;

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum seasons { spring = 34, summer = 4, autumn = 9, winter = 32 };
enum suit {
    club = 0,
    diamonds = 10,
    hearts = 20,
    spades = 3
} card;
enum class eyecolor :char {
    blue, green, brown
}eye;


int main()
{

    // Example 1: Enumeration Type
    week today;
    today = Wednesday;
    cout << "Day = " << today + 1;


    // Example2: Changing Default Value of Enums
    seasons s;

    s = summer;
    cout << endl <<  "Summer = " << s << endl;


    // Example3: An enum variable takes only one value out of many possible values. 
    card = club;
    cout << "Size of enum variable " << sizeof(card) << " bytes." << endl;
    cout << "Size of enum class eyecolor variable:" << sizeof(eye) << endl;
    // It's because the size of an integer is 4 bytes.

    cout << endl << endl;

    /*   -------------------------------------------------------------------------------------------------------------------------------   */
    // Rules
    // 1. Two enumerations cannot share the same names
    // 2. No variable can have a name which is already in some enumeration
    /*   -------------------------------------------------------------------------------------------------------------------------------   */

    // Example4 : Enum Class 
    enum class Color {
        Red,
        Green,
        Blue = 99
    };
    enum class Color2 {
        Red,
        Black,
        White
    };
    enum class People {
        Good,
        Bad
    };

    // An enum value can now be used
    // to create variables
    int Green = 10;

    // Instantiating the Enum Class
    Color x = Color::Green;
    Color y = Color::Blue;

    // Comparison now is completely type-safe
    if (x == Color::Red)
        cout << "It's Red\n";
    else
        cout << "It's not Red\n";

    People p = People::Good;

    if (p == People::Bad)
        cout << "Bad people\n";
    else
        cout << "Good people\n";

    // gives an error
    // if(x == p)
    // cout<<"red is equal to good";

    // won't work as there is no
    // implicit conversion to int
    // cout<< x;

    cout << int(x);
    cout << endl << int(y);

    return 0;
}