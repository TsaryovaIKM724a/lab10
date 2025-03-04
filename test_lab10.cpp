#include <iostream>

using namespace std;

struct User {
    string surname;
    int birthYear;
    int booksCount;
};

int main() {
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

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (users[j].booksCount < users[j + 1].booksCount) {
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }

    cout << "\nТоп-5 користувачів за кількістю книг: \n";
    for (int i = 0; i < min(5, n); i++) {
        cout << users[i].surname << " - " << users[i].booksCount << " книг\n";
    }
}
