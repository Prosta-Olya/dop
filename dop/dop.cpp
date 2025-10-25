// dop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

struct EventSystem {
    void (*handlers[100])(const std::string&);
    int count = 0;
};
void registerHandler(EventSystem& system, void(*handler)(const std::string&)) {
    if (system.count < 100) {
        system.handlers[system.count] = handler;
        system.count++;
        std::cout << "Обработчик добавлен. Кол-во обработчиков: " << system.count << "\n";
    }
    else {
        std::cout << "Нельзя добавить больше 100 обработчиков";
    }
};
void triggerEvent(const EventSystem& system, const std::string& message) {
    for (int i = 0; i < system.count; i++) {
        system.handlers[i](message);
    }
};

void onUserLogin(const std::string& message) {
    std::cout << "Пользователь вошел в систему " << message << "\n";
};

void onUserLogout(const std::string& message) {
    std::cout << "Пользователь вышел из системы " << message << "\n";
};

void onError(const std::string& message) {
    std::cout << "Произошла ошибка! " << message << "\n";
};

int main()
{
    setlocale(0, "rus");
    EventSystem system;
    std::cout << "Меню для работы с фиксированным массивом:\n1 - добавить обработчик входа\n2 - добавить обработчик выхода\n3 - добавить обработчик ошибки\n4 - Вызвать все зарегистрированные события\n5 - Выход\n";
    int menu1;
    std::cin >> menu1;
    std::string str1="";
    do {
        switch (menu1) {
        case 1:
            registerHandler(system, onUserLogin);
            std::cin >> menu1;
            break;
        case 2:
            registerHandler(system, onUserLogout);
            std::cin >> menu1;
            break;
        case 3:
            registerHandler(system, onError);
            std::cin >> menu1;
            break;
        case 4:
            std::cout << "Введите сообщение message:\n";
            std::cin >> str1;
            triggerEvent(system, str1);
            std::cin >> menu1;
            break;
        case 5:
            std::cout << "Выход\n";
            break;
        default:
            std::cout << "Ошибка\n";
            break;
        }
    } while (menu1 != 5);
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
