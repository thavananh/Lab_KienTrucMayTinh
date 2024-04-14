#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;

double nhiPhanSangThapPhan(string binary) {
    if(binary == "0 00000000 00000000000000000000000") {
        return 0.0;
    }

    int signBit = binary[0] - '0';
    string exponentPart = binary.substr(2, 8);
    string mantissaPart = binary.substr(11);

    int exponentValue = bitset<8>(exponentPart).to_ulong() - 127;


    double mantissaValue = 1.0;
    if(exponentValue == -127) { 
        mantissaValue = 0.0;
    }
    
    for (size_t i = 0; i < mantissaPart.length(); ++i) {
        if (mantissaPart[i] == '1') {
            mantissaValue += pow(2, -(static_cast<int>(i) + 1));
        }
    }

    double decimalValue = mantissaValue * pow(2, exponentValue);

    if (signBit == 1) {
        decimalValue = -decimalValue;
    }

    return decimalValue;
}

int main() {
    string binaryRepresentation;
    cout << "Enter the IEEE 754 representation: ";
    getline(cin, binaryRepresentation); 
    double decimalValue = nhiPhanSangThapPhan(binaryRepresentation);
    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}
