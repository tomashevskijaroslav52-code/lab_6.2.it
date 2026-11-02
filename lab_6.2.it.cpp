#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функція формування масиву за допомогою генератора випадкових чисел
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

// Функція виведення елементів масиву в рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

// Функція пошуку максимального елемента масиву
int FindMax(const int* a, const int size)
{
    int max_val = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max_val)
        {
            max_val = a[i];
        }
    }
    return max_val;
}

// Функція пошуку мінімального елемента масиву
int FindMin(const int* a, const int size)
{
    int min_val = a[0];
    for (int i = 1; i < size; i++)
    {
        if (a[i] < min_val)
        {
            min_val = a[i];
        }
    }
    return min_val;
}

// Функція обчислення суми максимального та мінімального елементів
int SumMaxAndMin(const int* a, const int size)
{
    int max_val = FindMax(a, size);
    int min_val = FindMin(a, size);
    return max_val + min_val;
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand((unsigned)time(NULL));

    const int n = 10; // Кількість елементів масиву
    int a[n];
    int Low = -25;
    int High = 25;

    // Формування та виведення масиву
    Create(a, n, Low, High);
    cout << "Array:" << endl;
    Print(a, n);
    cout << endl;

    // Знаходження максимального, мінімального та їх суми
    int max_val = FindMax(a, n);
    int min_val = FindMin(a, n);
    int resultSum = SumMaxAndMin(a, n);

    // Виведення результатів
    cout << "Max element = " << max_val << endl;
    cout << "Min element = " << min_val << endl;
    cout << "Sum (Max + Min) = " << resultSum << endl;

    return 0;
}
