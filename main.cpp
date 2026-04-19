#include <iostream>
using namespace std;

// Функция для обработки массива
void processMatrix(double** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        double sum = 0;

        // Считаем сумму элементов строки
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }

        // Проверка на деление на ноль
        if (sum == 0) {
            cout << "Строка " << i << ": сумма равна 0, деление невозможно.\n";
            continue;
        }

        // Делим каждый элемент строки на сумму
        for (int j = 0; j < cols; j++) {
            arr[i][j] /= sum;
        }
    }
}

// Функция для ввода массива
void inputMatrix(double** arr, int rows, int cols) {
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
}

// Функция для вывода массива
void printMatrix(double** arr, int rows, int cols) {
    cout << "Результат:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;

    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;

    // Проверка корректности
    if (rows <= 0 || cols <= 0) {
        cout << "Некорректные размеры массива.\n";
        return 1;
    }

    // Выделение памяти
    double** arr = new double*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[cols];
    }

    inputMatrix(arr, rows, cols);

    processMatrix(arr, rows, cols);

    printMatrix(arr, rows, cols);

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}