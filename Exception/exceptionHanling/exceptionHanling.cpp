// exceptionHanling.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
using namespace std;

int main()
{
	int x = -1;

	// Some code
	cout << "Before try \n";
	try {
		cout << "Inside try \n";
		if (x < 0)
		{
			throw x;
			cout << "After throw (Never executed) \n";
		}
	}
	catch (int x) { //special catch block 
		cout << "Exception Caught \n";
	}
	catch (char* excp) { // special catch block 
		cout << "Caught " << excp;
	}
	catch (...) { // catch al
		cout << "Default Exception\n";
	}


	cout << "After catch (Will be executed) \n";

	return 0;
}
