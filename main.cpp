#include <iostream>
#include <cmath>

void input(std::string& str){
    std::cout << "Введите строку\n";
    std::cin >> str;
}

void braketization_rec_body(std::string& str, int index, unsigned long long original_len, int brackets) {
    if (index >= str.size()) {
        return;
    } else if (index - brackets < std::ceil(static_cast<double>(original_len) / 2)) {
        str.insert(index, "(");
    } else if (original_len % 2 == 0 && index - brackets == original_len / 2) {
        braketization_rec_body(str, ++index, original_len, brackets);
        return;
    } else {
        str.insert(index, ")");
    }
    braketization_rec_body(str, ++++index, original_len, ++brackets);
}

void braketization(std::string& str){
    std::cout << "Перевернутая строка\n";
    braketization_rec_body(str, 1, str.size(), 0);
    std::cout << str << '\n';
}

int main() {
    std::string str;
    int op;
    while (true) {
        std::cout << "Меню\n";
        std::cout << "1. Ввести строку\n";
        std::cout << "2. Вывести перевернутую строку\n";
        std::cout << "3. Завершение работы\n";
        std::cin >> op;
        switch (op) {
            case 1:
                input(str);
                break;
            case 2:
                braketization(str);
                break;
            case 3:
                std::cout << "Выход из программы...";
                exit(1);
            default:
                std::cout << "Возможно, вы ввели неверный код команды. Попробуйте ввести код ещё раз)\n";
        }
    }
}
