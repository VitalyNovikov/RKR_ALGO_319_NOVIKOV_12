#include <iostream>
#include <string>
#include <sstream>   // Для stringstream
#include <algorithm> // Для reverse()
using namespace std;

// Функція для переведення десяткового числа в 9-річну систему з алфавітом (0,1,2,3,4,5,6,7,F)
string DecTo_N_(int D) {
    if (D == 0) return "0";

    string result;
    while (D > 0) {
        int remainder = D % 9;
        if (remainder == 8)
            result += "F";
        else
            result += to_string(remainder);
        D /= 9;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string line;
    cout << "Введіть десяткові числа через пробіл: ";
    getline(cin, line); // Зчитуємо весь рядок

    stringstream ss(line);
    int number;
    while (ss >> number) {
        string converted = DecTo_N_(number);
        cout << number << " -> " << converted << endl;
    }

    return 0;
}
