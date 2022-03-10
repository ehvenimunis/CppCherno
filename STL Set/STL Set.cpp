#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    set<long long int> st;
    int n, q;
    long long int x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q >> x;
        if (q == 1)
            st.insert(x);
        else if (q == 2)
            st.erase(x);
        else if (q == 3) {
            set<long long int>::iterator it = st.find(x);
            if (it == st.end())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }

    }
    return 0;
}

/*

Sample Input

8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6

Sample Output

Yes
No
No


*/