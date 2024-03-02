// Kontr_8-Cpp-ITMO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

# include <windows.h>
#include <iomanip>
#include <iostream>

using namespace std;

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

    // Для прибовления или вычитания времени к или от другому времени
    int To_Time_Other() {
        int a2b2c2 = 0;
        a2b2c2 = CheckingTime(hours, minutes, seconds);
        int hours1 = a2b2c2 / 10000;
        int minutes1 = (a2b2c2 % 10000) / 100;
        int seconds1 = a2b2c2 % 100;
      
        return hours1 * 10000 + minutes1 * 100 + seconds1 * 1;

    }

    Time Result(int resultTime) {

        int hours11 = resultTime / 10000;
        int minutes11 = (resultTime % 10000) / 100;
        int seconds11 = resultTime % 100;
        int a2b2c2 = 0;
        a2b2c2 = CheckingTime(hours11, minutes11, seconds11);
        int hours22 = a2b2c2 / 10000;
        int minutes22 = (a2b2c2 % 10000) / 100;
        int seconds22 = a2b2c2 % 100;
        return Time(hours22, minutes22, seconds22);
    }

    // Прибавление времени
    Time Add(Time& other) {
        Result(other.To_Time_Other() + To_Time_Other());   
        return Result(other.To_Time_Other() + To_Time_Other());
    }

    // Вычитание времени
    Time Sub(Time& other) {
        Result(To_Time_Other() - other.To_Time_Other());
        return Result(To_Time_Other() - other.To_Time_Other());
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
        label:
    if (c1 < 0) {
            b1 = b1 - 1;
            c1 = 60 - abs(c1);
            marker7 = true;
        }
        else {
            marker7 = false;
        }

        if (b1 < 0) {
            a1 = a1 - 1;
            b1 = 60 - abs(b1);
            marker6 = true;
        }
        else {
            marker6 = false;
        }

        if (a1 < 0) {
            a1 = 24 - abs(a1);
            marker5 = true;
        }
        else {
            marker5 = false;
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

        if (a1 >= 24 || b1 >= 60 || c1 >= 60 || a1 < 0 || b1 < 0 || c1 < 0) {
            goto label;
        }

        if (marker2 == true || marker3 == true || marker4 == true || marker5 == true || marker6 == true || marker7 == true) {
            wcout << L"\n-не корректное отображение времени, перерасчитанное время = ";
            printf("%02d", a1);
            cout << "::";
            printf("%02d", b1);
            cout << "::";
            printf("%02d", c1);
            marker1 == false;
            int a1b1c1 = a1 * 10000 + b1 * 100 + c1 * 1;

            marker0 = false;
            marker1 = false;
            marker2 = false;
            marker3 = false;
            marker4 = false;
            marker5 = false;
            marker6 = false;
            marker7 = false;


            return a1b1c1;
        }
        else {
            int a1b1c1 = a1 * 10000 + b1 * 100 + c1 * 1;
            return a1b1c1;
        }

    };

// [out] time-Время, в которое будет считана информация
    friend istream& operator>>(istream& in, Time& time) {
        in >> time.hours;
        in.get();
        in >> time.minutes;
        in.get();
        in >> time.seconds;
        int a3b3c3 = 0;
        a3b3c3 = time.hours * 10000 + time.minutes * 100 + time.seconds * 1;
        time.Result(a3b3c3);

        return in;
    }

// time-Время, которое нужно вывести в поток
    friend ostream& operator<<(ostream& out, const Time& time) {
        out << setw(2) << setfill('0') << time.hours;
        out << ':';
        out << setw(2) << setfill('0') << time.minutes;
        out << ':';
        out << setw(2) << setfill('0') << time.seconds;
        return out;
    }

private:
    Time(int hours, int minutes, int seconds, bool validate) : hours(hours), minutes(minutes), seconds(seconds) {
    }

};

int main() {

    setlocale(LC_CTYPE, "rus");

    wcout << L"Введите первое время \"HH:MM:SS\" через пробел или поочереди: " << endl;
    Time t1_time;
    wcout << L" - \"HH:MM:SS\:";
    cin >> t1_time;
    wcout << L"\n\nВведите второе время \"HH:MM:SS\" через пробел или поочереди: " << endl;

    Time t2_time;
    wcout << L" - \"HH:MM:SS\:";
    cin >> t2_time;

    Time time_result = t1_time.Add(t2_time);

    wcout << L"\n- первое время + второе время = ";
    cout << time_result << endl;
    cout << "--------------" << endl;

    time_result = t1_time.Sub(t2_time);
    wcout << L"\n- первое время - второе время = ";
    cout << time_result << endl;
    cout << "--------------" << endl;

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


//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
