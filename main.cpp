#include <iostream>
using namespace std;

const int MAXN = 50;

/* ============================================================
   ФУНКЦІЇ ВВЕДЕННЯ ТА ВИВЕДЕННЯ МАСИВУ
   ============================================================ */

// Введення масиву
void inputArray(int a[], int &n) 
{
    cout << "Введіть розмір масиву (2..50): ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }
}

// Виведення масиву
void printArray(const int a[], int n) 
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

/* ============================================================
   ARRAY27
   ============================================================ */

// Перевірка чергування знаків
int checkAlternating(const int a[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        if (a[i] * a[i - 1] > 0)
            return i + 1; // порушення, номер елемента (з 1)
    }
    return 0; // чергуються
}

void taskArray27() 
{
    int a[MAXN], n;

    inputArray(a, n);

    cout << "Початковий масив:\n";
    printArray(a, n);

    int result = checkAlternating(a, n);

    cout << "Результат: " << result << endl;
}

/* ============================================================
   ARRAY101
   ============================================================ */

// Вставка 0 перед елементом K
void insertZero(int a[], int &n, int k) 
{
    for (int i = n; i >= k; i--)
        a[i] = a[i - 1];

    a[k - 1] = 0;
    n++;
}

void taskArray101() 
{
    int a[MAXN + 1], n, k;

    inputArray(a, n);

    cout << "Введіть K (1 <= K <= N): ";
    cin >> k;

    cout << "Початковий масив:\n";
    printArray(a, n);

    insertZero(a, n, k);

    cout << "Змінений масив:\n";
    printArray(a, n);
}

/* ============================================================
   МЕНЮ
   ============================================================ */

int main() 
{
    int choice;

    do 
    {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 – Array27 (чергування знаків)\n";
        cout << "2 – Array101 (вставка 0)\n";
        cout << "0 – Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            taskArray27();
            break;
        case 2:
            taskArray101();
            break;
        case 0:
            cout << "Завершення програми...\n";
            break;
        default:
            cout << "Невірний вибір\n";
        }
    } 
    while (choice != 0);

    return 0;
}
