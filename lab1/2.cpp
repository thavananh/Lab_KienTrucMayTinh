#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int soNhiPhanSangSoNguyen(string s)
{
    bool negative = false;
    int rs = 0;
    if (s[0] == '1')
    {
        negative = true;
        int pos = -1;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
                pos = i;
                break;
            }
        }
        if (pos != -1)
        {
            for (int i = pos+1; i < s.length(); i++)
            {
                s[i] = '1';
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
            }
            else
            {
                s[i] = '0';
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        int numb = (s[i] == '0') ? 0 : 1;
        if (numb)
        {
            rs += pow(2, s.length() - 1 - i);
        }
    }
    if (negative)
    {
        return -rs;
    }
    return rs;
}

int main()
{
    int i = 5;
    while (i--)
    {
        string s; cin >> s;
        cout << soNhiPhanSangSoNguyen(s) << endl;
    }
    system("pause");
}