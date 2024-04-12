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
            rs = "0" + rs;
            for (int j = 1; j < rs.length() - count; j++)
            {
                rs[j] = '1';
            }
        }
        else
        {
            rs = b1[0] + rs;
            for (int k = 1; k < rs.length() - count; k++)
            {
                if (rs[k] == '0' && b1[k] == '1')
                {
                    rs[k] = '1';
                }
                else if (rs[k] == '1' && b1[k] == '1')
                {
                    rs[k] = '0';
                }
                else if (rs[k] == '0' && b1[k] == '0')
                {
                    rs[k] = '1';
                }
                else if (rs[k] == '1' && b1[k] == '0')
                {
                    rs[k] = '1';
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