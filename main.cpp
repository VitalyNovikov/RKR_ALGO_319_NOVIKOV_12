#include <iostream>
#include <string>
#include <sstream>   // Для stringstream — розбиття рядка
#include <algorithm> // Для reverse()
using namespace std;

// Функція для переведення десяткового числа в 9-річну систему з алфавітом (0–7, F)
string DecTo_N_(int D) {
    if (D == 0) return "0"; // Якщо число 0 — повертаємо "0"

    string result; // Рядок, у який будемо записувати результат

    while (D > 0) {
        int remainder = D % 9; // Знаходимо остачу від ділення на 9

        // Якщо остача 8 — додаємо 'F', інакше — звичайне число як символ
        if (remainder == 8)
            result += "F";
        else
            result += to_string(remainder);

        D /= 9; // Переходимо до наступної "цифри" у 9-річній системі
    }

    // Реверсуємо рядок, бо цифри додаються у зворотному порядку
    reverse(result.begin(), result.end());

    return result; // Повертаємо отриманий рядок
}

int main() {
    string line; // Змінна для зчитування рядка з кількома числами

    // Запит до користувача
    cout << "Введіть десяткові числа через пробіл: ";
    getline(cin, line); // Зчитуємо весь рядок (може містити багато чисел)

    stringstream ss(line); // Створюємо потік для розбиття рядка на числа
    int number; // Змінна для кожного окремого числа

    // Обробка всіх чисел у рядку
    while (ss >> number) {
        // Перетворюємо число у 9-річну систему
        string converted = DecTo_N_(number);

        // Виводимо результат
        cout << number << " -> " << converted << endl;
    }

    return 0; // Завершення програми
}
