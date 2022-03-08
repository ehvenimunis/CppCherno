#include <iostream>
#include <sstream>
#include <map>

using namespace std;

void printFrequency(string st)
{
    // Each word it mapped to
    // it's frequency
    map<string, int>FW;

    // Used for breaking words
    stringstream ss(st);

    // To store individual words
    string Word;

    while (ss >> Word)
        FW[Word]++;

    map<string, int>::iterator m;
    for (m = FW.begin(); m != FW.end(); m++)
        cout << m->first << "-> "
        << m->second << "\n";
}

int countWords(string str)
{
    // Breaking input into word
    // using string stream

    // Used for breaking words
    stringstream s(str);

    // To store individual words
    string word;

    int count = 0;
    while (s >> word) // altı defa buraya girer 
        count++;
    return count;
}

int main() {
    stringstream stream;
    stream << "ahmet" << "  " << 42 << "  " << 1500 << endl;

    string x;
    int y;
    int z;
    stream >> x >> y >> z;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;

    // stringstream nesnesi oluştur
    stringstream stream1;
    // nesnenin içeriğini ayarla
    stream1.str("mehmet 22 3000");

    // içeriği yazdır
    cout << "Fonksiyon ile icerik okuma" << endl;
    cout << stream1.str() << endl;

    cout << "*************************************" << endl;

    //bir önceki yöntem ile içeriği okuma
    cout << "icerigi tek tek okuma" << endl;
    string a;
    int b, c;
    stream1 >> a >> b >> c;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    cout << "*************************************" << endl;

    string s = "Geeks For Geeks Ide";
    printFrequency(s);

    cout << "*************************************" << endl;

    string s1 = "geeks for geeks geeks "
        "contribution placements";
    cout << "Number of words are: " << countWords(s1) << endl << endl;
    

    return 0;
}

/*

    clear()- To clear the stream.
    str()- To get and set string object whose content is present in the stream.
    operator <<- Add a string to the stringstream object.
    operator >>- Read something from the stringstream object.
    
*/