#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

string soNhiPhan(long long n)
{
    string rs = "";
    long long n_tmp = n;
    while (abs(n_tmp))
    {
        rs = to_string(abs(n_tmp%2)) + rs;
        n_tmp = n_tmp/2;
    }
    string tmp = "";
    for (int i = 0; i < rs.length(); i++)
    {
        tmp += "0";
    }
    rs = tmp + rs;
    
    if (n < 0)
    {
        for (int i = 0; i < rs.length(); i++)
        {
            if (rs[i] == '0')
            {
                rs[i] = '1';
            }
            else
            {
                rs[i] = '0';
            }
        }
        for (int i = rs.length() - 1; i >= 0; i--)
        {
            if (rs[i] == '0')
            {
                rs[i] = '1';
                break;
            }
            else
            {
                rs[i] = '0';
            }
        }
    }
    return rs;
}

int main()
{
    cout << soNhiPhan(-32768) << endl; // int 16
    cout << soNhiPhan(32767) << endl; 
    cout << soNhiPhan(INT_MAX) << endl; // int 32
    cout << soNhiPhan(INT_MIN) << endl;
    cout << soNhiPhan(INT64_MIN) << endl; // int 64   
    cout << soNhiPhan(INT64_MAX) << endl;
    system("pause");
}