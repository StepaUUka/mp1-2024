#include "functions.h"

int main() {
    setlocale(LC_ALL, "Russian");

    SinFunction sinFunc;
    CosFunction cosFunc;
    ExpFunction expFunc;
    SinhFunction sinhFunc;
    const Function* functions[] = { &sinFunc, &cosFunc, &expFunc, &sinhFunc };
    int choice;
    double x, eps;
    double a, b, step;

    while (true) {
        printMenu();
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice < 1 || choice > 4) {
            cout << "Неверный выбор!\n";
            continue;
        }

        const Function* selectedFunc = functions[choice - 1];
        Processor processor(selectedFunc);

        cout << "\nВыбрана функция: " << selectedFunc->getName() << endl;

        // Ввод точки для вычисления ряда Тейлора
        cout << "Введите точку x: ";
        cin >> x;
        cout << "Введите точность eps: ";
        cin >> eps;

        // Вычисление и вывод ряда Тейлора
        double taylorValue = processor.Taylor(x, eps);
        double exactValue = selectedFunc->evaluate(x);

        cout << "\nРезультаты:\n";
        cout << "Ряд Тейлора: " << taylorValue << endl;
        cout << "Точное значение: " << exactValue << endl;
        cout << "Разница: " << abs(taylorValue - exactValue) << endl;

        // Ввод параметров для отрезка
        cout << "\nВведите отрезок [a, b] и шаг:\n";
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "step = ";
        cin >> step;

        // Вывод значений на отрезке
        processor.printOnInterval(a, b, step);

        // Вычисление интеграла
        cout << "\nВычисление интеграла на отрезке [" << a << ", " << b << "]:\n";
        double integral = processor.Integral(a, b);
        cout << "Значение интеграла: " << integral << endl;
    }

    return 0;
}
