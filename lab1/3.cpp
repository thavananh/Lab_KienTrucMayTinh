#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int binaryToInt(string binary) {
    int value = 0;
    int index = 0;
    for (auto it = binary.rbegin(); it != binary.rend(); ++it, ++index) {
        if (*it == '1') {
            value += (1 << index);
        }
    }
    return value;
}

string intToBinary(int value) {
    string binary = "";
    while (value > 0) {
        binary += (value % 2) ? '1' : '0';
        value /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary == "" ? "0" : binary;
}

string binaryMultiplication(string binary1, string binary2) {
    int num1 = binaryToInt(binary1);
    int num2 = binaryToInt(binary2);
    int product = num1 * num2;
    return intToBinary(product);
}

pair<string, string> binaryDivision(const string& dividend, const string& divisor) {
    int numDividend = binaryToInt(dividend);
    int numDivisor = binaryToInt(divisor);

    if (numDivisor == 0) {
        throw invalid_argument("Divisor cannot be zero.");
    }

    int quotient = numDividend / numDivisor;
    int remainder = numDividend % numDivisor;

    return {intToBinary(quotient), intToBinary(remainder)};
}

string binarySum(string a, string b) {
    string result = ""; // Khởi tạo chuỗi kết quả
    int i = a.length() - 1, j = b.length() - 1, carry = 0;

    // Lặp cho đến khi xử lý hết cả hai chuỗi
    while (i >= 0 || j >= 0 || carry == 1) {
        carry += i >= 0 ? a[i--] - '0' : 0; // Thêm giá trị bit từ a (nếu còn)
        carry += j >= 0 ? b[j--] - '0' : 0; // Thêm giá trị bit từ b (nếu còn)

        result = char(carry % 2 + '0') + result; // Thêm bit kết quả vào chuỗi kết quả
        carry /= 2; // Tính giá trị nhớ cho bước tiếp theo
    }

    return result;
}

string reverseString(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}

// Hàm cộng hai số nhị phân
string binaryAddition(string a, string b) {
    string result = "";
    int carry = 0;

    while (a.length() < b.length())
        a = "0" + a;
    while (b.length() < a.length())
        b = "0" + b;

    for (int i = a.length() - 1; i >= 0; i--) {
        int bit1 = a[i] - '0';
        int bit2 = b[i] - '0';
        int sum = (bit1 ^ bit2 ^ carry) + '0';
        result = (char)sum + result;
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);
    }

    if (carry) result = "1" + result;

    return result;
}

// Hàm tìm bù 2 của một số nhị phân
string findTwosComplement(string str) {
    int n = str.length();

    // Tìm bù 1 của str
    for (int i = 0; i < n; i++)
        str[i] = (str[i] == '0') ? '1' : '0';

    // Cộng 1 vào để tìm bù 2
    str = binaryAddition(str, "1");

    return str;
}

// Hàm trừ hai số nhị phân
string binarySubtraction(string a, string b) {
    // Tìm bù 2 của b
    string twosComplement = findTwosComplement(b);
    // Thực hiện phép cộng a với bù 2 của b
    string result = binaryAddition(a, twosComplement);

    // Nếu kết quả dài hơn a, loại bỏ bit cao nhất
    if (result.length() > a.length()) {
        result = result.substr(1);
    }

    return result;
}

int main() {
    string binary1, binary2;

    cout << "Day nhi phan 1: ";
    cin >> binary1;
    cout << "Day nhi phan 2: ";
    cin >> binary2;
    cout << "ket qua: " << binaryMultiplication(binary1, binary2) << endl;
    system("pause");
    return 0;
}
