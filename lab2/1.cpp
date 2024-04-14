#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string soNhiPhan(int n)
{
    if (n == 0)
    {
        return "0";
    }
    string rs = "";
    while (n > 0)
    {
        rs = to_string(n % 2) + rs;
        n = n / 2;
    }
    return rs;
}

string chuyenDoiSoThapPhanSangNhiPhan(double n)
{
    if(n == 0) {
        return "0 00000000 00000000000000000000000";
    }
    
    int signBit = n < 0 ? 1 : 0;
    n = fabs(n);
    
    int phanNguyen = static_cast<int>(n);
    string binaryPhanNguyen = soNhiPhan(phanNguyen);
    
    double phanThapPhan = n - phanNguyen;
    string binaryPhanThapPhan = "";
    
    while (binaryPhanThapPhan.length() < 23 && phanThapPhan > 0) {
        phanThapPhan *= 2;
        int bitValue = static_cast<int>(phanThapPhan);
        binaryPhanThapPhan += to_string(bitValue);
        if(bitValue == 1) phanThapPhan -= bitValue;
    }
    
    int bias = 127;
    int exponent;
    string mantissa;
    
    if(phanNguyen > 0) { // Normalized
        exponent = bias + binaryPhanNguyen.length() - 1;
        mantissa = binaryPhanNguyen.substr(1) + binaryPhanThapPhan;
    } else { // Denormalized
        size_t pos = binaryPhanThapPhan.find('1');
        exponent = bias - (pos + 1);
        mantissa = binaryPhanThapPhan.substr(pos+1);
    }
    
    mantissa = mantissa.substr(0, 23); // Trim or pad the mantissa
    while(mantissa.length() < 23) {
        mantissa += "0";
    }
    
    string binaryExponent = soNhiPhan(exponent);
    while(binaryExponent.length() < 8) {
        binaryExponent = "0" + binaryExponent;
    }
    
    return to_string(signBit) + " " + binaryExponent + " " + mantissa;
}

int main()
{
    double n; cin >> n;
    cout << chuyenDoiSoThapPhanSangNhiPhan(n) << endl;
    system("pause"); // This is generally not portable, use cin.get() instead if needed.
    return 0;
}
