#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale> // Подключаем библиотеку для работы с setlocale

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

bool is_power_of_two(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

int main() {
    // Устанавливаем setlocale для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    int N;
    std::cout << "Введите количество чисел N: ";
    std::cin >> N;

    int sum_numbers = 0;
    int count_multiples_of_5 = 0;
    int count_powers_of_two = 0;
    int count_greater_than_sum = 0;

    int prev1 = -1, prev2 = -1; // Предыдущие два числа
    int max_num = INT_MIN, min_num = INT_MAX;

    for (int i = 0; i < N; ++i) {
        int number;
        std::cin >> number;

        // Проверка на простое число
        if (is_prime(number)) {
            std::cout << number << std::endl;
        }

        // Увеличиваем сумму чисел
        sum_numbers += number;

        // Обновляем максимум и минимум
        if (number > max_num) max_num = number;
        if (number < min_num) min_num = number;

        // Проверка на кратность 5
        if (number % 5 == 0) {
            count_multiples_of_5++;
        }

        // Проверка на степень двойки
        if (is_power_of_two(number)) {
            count_powers_of_two++;
        }

        // Проверка на превышение суммы двух предыдущих членов
        if (prev1 != -1 && prev2 != -1) {
            if (number > (prev1 + prev2)) {
                count_greater_than_sum++;
            }
        }

        // Обновляем предыдущие числа
        prev2 = prev1;
        prev1 = number;
    }

    // Вычисление среднего арифметического
    double average = static_cast<double>(sum_numbers) / N;

    // Вывод результатов
    std::cout << std::fixed << std::setprecision(2) << average << std::endl; // Среднее арифметическое
    std::cout << (max_num - min_num) << std::endl; // Разница между максимумом и минимумом
    std::cout << count_multiples_of_5 << std::endl; // Количество чисел кратных 5
    std::cout << count_powers_of_two << std::endl; // Количество чисел, являющихся степенью двойки
    std::cout << count_greater_than_sum << std::endl; // Количество чисел, превышающих сумму двух предшествующих членов

    return 0;
}
