#include <iostream>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct User {
    string surname;
    int birthYear;
    int booksCount;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість користувачів: ";
    cin >> n;

    User users[100];

    for (int i = 0; i < n; i++) {
        cout << "Введіть прізвище, рік народження та кількість книг користувача " << i + 1 << ": ";
        cin >> users[i].surname >> users[i].birthYear >> users[i].booksCount;
    }

    cout << "\nСписок користувачів бібліотеки:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Прізвище: " << users[i].surname << ", Рік народження: " << users[i].birthYear << ", Кількість книг: " << users[i].booksCount << endl;
    }

    sort(users, users + n, [](const User& a, const User& b) {
        return a.booksCount > b.booksCount;
        });

    cout << "\nТоп-5 користувачів за кількістю книг:" << endl;
    for (int i = 0; i < min(5, n); i++) {
        cout << users[i].surname << " - " << users[i].booksCount << " книг" << endl;
    }
}
