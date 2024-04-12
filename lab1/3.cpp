#include <iostream>
#include <string>
using namespace std;

string nhanHaiSoNhiPhan(string b1, string b2)
{
    string rs = "";
    string chuoikhong = "";
    for (size_t i = 0; i < b1.length(); i++)
    {
        chuoikhong += "0";
    }
    if (b2[b2.length()-1] == '0')
    {
        rs = chuoikhong;
    }
    else
    {
        rs = b1;
    }
    int count = 1;
    
    for (int i = b2.length() - 2; i >= 0; i--)
    {
        if (b2[i] == '0')
        {
            rs = to_string('0') + rs;
            for (int i = 1; i < rs.length() - count; i++)
            {
                rs[i] = '1';
            }
        }
        else
        {
            rs = b1[i] + rs;
            for (int i = 1; i < rs.length() - count; i++)
            {
                if (rs[i] == '0' && b1[i] == '1')
                {
                    rs[i] = '1';
                }
                else if (rs[i] == '1' && b1[i] == '1')
                {
                    rs[i] = '0';
                }
                else if (rs[i] == '0' && b1[i] == '0')
                {
                    rs[i] = '1';
                }
                else if (rs[i] == '1' && b1[i] == '0')
                {
                    rs[i] = '1';
                }
            } 
        }
        count++;
    }
    return rs;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << nhanHaiSoNhiPhan(s1, s2) << endl;
    system("pause");
}