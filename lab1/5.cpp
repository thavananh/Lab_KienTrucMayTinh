#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    //a
    // int x = 9999999999;
    // cout << x << endl;
    //b
    // long long int y = 9999999999;
    // int x = y;
    // cout << x << endl;
    int p = INT_MAX;
    unsigned int k = UINT32_MAX;
    unsigned char c = sizeof(unsigned char);

    long x = p + k + c;
    cout << x; // 2147483647
    system("pause");
}