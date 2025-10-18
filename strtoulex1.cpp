//C++ program to illustrate the
// strtoul() function
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{

    // initializing the string
    char str[256] = "10001 Geeks For Geeks";

    // reference pointer
    char* end;
    long result;

    // finding the unsigned long 
    // integer with base 2
    result = strtoul(str, &end, 2);

    // printing the unsigned number
    cout << "The unsigned long integer is : "
         << result << endl;
    cout << "String in str is : " << end;

    return 0;
}
