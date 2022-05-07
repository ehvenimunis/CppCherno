#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> v;
int i, n, x, m, a, b;
int main() {
    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cin >> x;
    v.erase(v.begin() + x - 1);

    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    m = v.size();
    cout << m << endl;
    cout << v.at(0); // Returns a reference to the element at position n in the vector.
    for (i = 1; i < m; i++)
        cout << ' ' << v.at(i);
    cout << endl;

    return 0;
}


/*

Sample Input

6
1 4 6 2 8 9
2
2 4

Sample Output

3
1 8 9


*/