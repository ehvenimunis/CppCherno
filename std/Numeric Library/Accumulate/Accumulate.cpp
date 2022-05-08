#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

/*
* This function returns the sum of all the values lying in a range between [first, last) with the variable sum. We usually find out the sum of elements in a particular range or a complete array using a linear operation which requires adding all the elements in the range one by one and storing it into some variable after each iteration.
*/

// User defined function
int myfun(int x, int y)
{
    // for this example we have taken product
    // of adjacent numbers
    return x * y;
}

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int sum = std::accumulate(v.begin(), v.end(), 0); // (start, end, initialize value for sum)

    // Using accumulate function with pre-defined function
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>()); // tüm elemanlara çarpma işlemi yapar

    // Using accumulate function with pre-defined function
    int productMyFun = std::accumulate(v.begin(), v.end()-7, 1, myfun); // istediğimiz elemana kadar çarpma işlemi yapar

    auto dash_fold = [](std::string a, int b) {
        return std::move(a) + '-' + std::to_string(b);
    };

    std::string s = std::accumulate(std::next(v.begin()), v.end(),
        std::to_string(v[0]), // start with first element
        dash_fold);

    // Right fold using reverse iterators
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
        std::to_string(v.back()), // start with last element
        dash_fold);

    std::cout << "sum: " << sum << '\n'
        << "product: " << product << '\n'
        << "dash-separated string: " << s << '\n'
        << "dash-separated string (right-folded): " << rs << '\n'
        << "myFun function result: " << productMyFun << '\n';


    // Using accumulate function with pre-defined function
    std::cout << "Result using accumulate with pre-defined function: ";
    std::cout << accumulate(v.begin(), v.end(), 1, std::minus<int>()) << std::endl;

}

/*

sum: 55
product: 3628800
dash-separated string: 1-2-3-4-5-6-7-8-9-10
dash-separated string (right-folded): 10-9-8-7-6-5-4-3-2-1


*/
