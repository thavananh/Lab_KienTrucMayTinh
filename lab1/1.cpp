#include <iostream>
#include <string>
using namespace std;

string soNhiPhan(int n)
{
    string rs = "";
    int n_tmp = n;
    while (abs(n_tmp))
    {
        rs = to_string(abs(n_tmp%2)) + rs;
        n_tmp = n_tmp/2;
    }
    string tmp = "";
    for (int i = 0; i < 10-rs.length(); i++)
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
    int i = 5;
    while (i--)
    {
        int n; cin >> n;
        cout << soNhiPhan(n) << endl;
    }
    system("pause");
}