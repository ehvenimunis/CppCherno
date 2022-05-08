// OverloadingOstreamOperator.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>

using namespace std;

/*
The task is to overload the << operator for Person class in such a way that for p being an instance of class Person the result of:
std::cout << p << " " << <some_string_value> << std::endl;
*/

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
        return first_name_;
    }
    const string& get_last_name() const {
        return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};
// Enter your code here.
ostream& operator<<(ostream& os, const Person& pr)
{
    os << "first_name=" << pr.get_first_name() << ",last_name=" << pr.get_last_name();
    return os;
}

int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}

/*
    Sample Input:

    john doe registered

    Sample Output:

    first_name=john,last_name=doe registered
*/