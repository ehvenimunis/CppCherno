#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int N, i = 0;
    std::cin >> N;
    int* A = new int[N];
    while (std::cin >> A[i++]);
    while (std::cout << A[--N] << ' ' && N);
    delete[] A;
    return 0;

    /*
    int size, a, b, c, d;
    cin >> size >> a >> b >> c >> d;
    size -= 1;
    int ary[size] = {a,b,c,d};
    for (int i = size; i>=0; i--){
        cout << ary[i] << " ";
    }
    */

    return 0;
}

/*

Output Format

Print the

integers of the array in the reverse order, space-separated on a single line.

Sample Input

4
1 4 3 2

Sample Output

2 3 4 1


*/
