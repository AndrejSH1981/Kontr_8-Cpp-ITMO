// Kontr_8-Cpp-ITMO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <cmath>
# include <windows.h>
#include <iomanip>
#include <iostream>
#include <format>
#include <stdexcept>
#include <string>
#include <sstream>



using namespace std;

//// Количество секунд в минуте
//int SecondsInMinute = 60;
//
//// Количество минут в часе
//int MinutesInHour = 60;
//
//// Количество секунд в часе
//int SecondsInHour = SecondsInMinute * MinutesInHour;
//
//// Количество часов в дне
//int HoursInDay = 24;
//
//// Количество секунд в дне
//int SecondsInDay = SecondsInHour * HoursInDay;



// Время в формате часы, минуты, секунды
class Time {
public:

    int hours;
 
    int minutes;

    int seconds;

    Time() : Time(0, 0, 0, false) {}

    Time(int hours, int minutes, int seconds) : Time(hours, minutes, seconds, true) {
        CheckingTime(hours, minutes, seconds);
    }

    // Для преобразование или вычитания времени к или от другому времени
    int const To_Time_Other() {
        int a2b2c2 = 0;
        a2b2c2 = CheckingTime(hours, minutes, seconds);
        int hours1 = a2b2c2 / 10000;
        int minutes1 = (a2b2c2 % 10000) / 100;
        int seconds1 = a2b2c2 % 100;
        return hours1 * 10000 + minutes1 * 100 + seconds1 * 1;
    }


    // Прибавление времени
    int Add( Time& other) {
        int(other.To_Time_Other() + To_Time_Other());
        int aa = int(other.To_Time_Other() + To_Time_Other());
        int hours11 = aa / 10000;
        int minutes11 = (aa % 10000) / 100;
        int seconds11 = aa % 100;     
       int result = 0;
       result = CheckingTime(hours11, minutes11, seconds11);
        return result;        
    }

    // Вычитание времени
    int Sub(Time& other) {
        int(To_Time_Other() - other.To_Time_Other());
        int aa = int(To_Time_Other() - other.To_Time_Other());
        int hours11 = aa / 10000;
        int minutes11 = (aa % 10000) / 100;
        int seconds11 = aa % 100;
        int result = 0;
        result = CheckingTime(hours11, minutes11, seconds11);
        return result;
    }


    // Перерасчёт времени если больше напечатано
    int  CheckingTime(int a, int b, int c) {
        int a1 = a;
        int b1 = b;
        int c1 = c;
        bool marker0 = false;
        bool marker1 = false;
        bool marker2 = false;
        bool marker3 = false;
        bool marker4 = false;
        bool marker5 = false;
        bool marker6 = false;
        bool marker7 = false;

        if (a1 == 0 && b1 == 0 && c1 == 0) {
            a1 = a;
            b1 = b;
            c1 = c;
            marker1 = true;
        }
        if (a1 < 0) {
            a1 = 24 - a1;
            marker5 = true;
        }
        else {
            marker5 = false;
        }
        if (b1 < 0) {
            a1 = a1 - 1;
            b1 = 60 + b1;
            marker6 = true;
        }
        else {
            marker6 = false;
        }
        if (c1 < 0) {
            b1 = b1 - 1;
            c1 = 60 + c1;
            marker7 = true;
        }
        else {
            marker7 = false;
        }
        if (c1 >= 60) {
            b1 = b1 + 1;
            c1 = c1 - 60;
            marker4 = true;
        }
        else {
            marker4 = false;
        }     
        if (b1 >= 60) {
            a1 = a1 + 1;
            b1 = b1 - 60;
            marker3 = true;
        }
        else {
            marker3 = false;
        }     
        if (a1 >= 24) {
            a1 = a1 - 24;
            marker2 = true;
        }
        else {
            marker2 = false;
        }
        if (marker2 == true || marker3 == true || marker4 == true || marker5 == true || marker6 == true || marker7 == true) {
            wcout << L"\n-не корректное отображение времени, перерасчитанное время = ";
            printf("%02d", a1);
            cout << ":";
            printf("%02d", b1);
            cout << ":";
            printf("%02d", c1);
            cout << " " << endl;
            marker1 == false;
            int a1b1c1 = a1 * 10000 + b1 * 100 + c1 * 1;
            return a1b1c1;
        }
        else {
            int a1b1c1 = a1 * 10000 + b1 * 100 + c1 * 1;
            return a1b1c1;
        }
    };

private:
    Time(int hours, int minutes, int seconds, bool validate) : hours(hours), minutes(minutes), seconds(seconds) {
    }

};

int main() {

    setlocale(LC_CTYPE, "rus");

    wcout << L"Введите первое время \"HH:MM:SS\" поочереди: " << endl;
    int t1_hours = 0;
    int t1_minutes = 0;
    int t1_seconds = 0;

    wcout << L" - часы \"HH\":";
    cin >> t1_hours;
    wcout << L" - минуты \"MM\":";
    cin >> t1_minutes;
    wcout << L" - секунды \"SS\":";
    cin >> t1_seconds;
    Time t1 = Time(t1_hours, t1_minutes, t1_seconds);
   
    cout << "Введите второе время \"HH:MM:SS\" поочереди: : " << endl;

    int t2_hours = 0;
    int t2_minutes = 0;
    int t2_seconds = 0;
    wcout << L" - часы \"HH\":";
    cin >> t2_hours;
    wcout << L" - минуты \"MM\":";
    cin >> t2_minutes;
    wcout << L" - секунды \"SS\":";
    cin >> t2_seconds;
    Time t2 = Time(t2_hours, t2_minutes, t2_seconds);

    int int_result = int(t1.Add(t2));
    int hours_result = int_result / 10000;
    int minutes_result = (int_result % 10000) / 100;
    int seconds_result = int_result % 100;

    wcout << L"- первое время + второе время = ";
    printf("%02d", hours_result);
    cout << ":";
    printf("%02d", minutes_result);
    cout << ":";
    printf("%02d", seconds_result);
    cout << " " << endl;

    int_result = int(t1.Sub(t2));
    hours_result = int_result / 10000;
    minutes_result = (int_result % 10000) / 100;
    seconds_result = int_result % 100;

    wcout << L"- первое время - второе время = ";
    printf("%02d", hours_result);
    cout << ":";
    printf("%02d", minutes_result);
    cout << ":";
    printf("%02d", seconds_result);
    cout << " " << endl;
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


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
