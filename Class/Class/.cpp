// Default Constructor

#include <iostream>

using namespace std;

class Myclass {

public:
    Myclass();
}; 

Myclass::Myclass()
{
    cout << "Myclass default constructor" << endl;
}

void func()
{
    Myclass m1, m2; // hem m1 hemde m2 icin cagirilacak ayri ayri
    cout << "************************" << endl;
}

int main()
{
    for (int k = 0; k < 10; k++)
        func();

    return 0;
}