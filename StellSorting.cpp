#include <iostream>
using namespace std;

//1)Пузырьковая сортировка
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//2)Сортировка вставками
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//3)Успеваемость 
void printGrades(int grades[]) {
    cout << "Оценки: ";
    for (int i = 0; i < 10; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

void retakeExam(int grades[]) {
    int index, newGrade;
    cout << "Введите номер оценки (1-10): ";
    cin >> index;
    cout << "Введите новую оценку: ";
    cin >> newGrade;
    grades[index - 1] = newGrade;
}

void checkScholarship(int grades[]) {
    double sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += grades[i];
    }
    double average = sum / 10;
    cout << "Средний балл: " << average << endl;
    if (average >= 10.7) {
        cout << "Стипендия выходит!" << endl;
    }
    else {
        cout << "Стипендия не выходит!" << endl;
    }
}

void studentPerformance() {
    int grades[10];
    cout << "Введите 10 оценок студента: ";
    for (int i = 0; i < 10; i++) {
        cin >> grades[i];
    }

    int choice;
    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Вывод оценок" << endl;
        cout << "2. Пересдача экзамена" << endl;
        cout << "3. Проверить стипендию" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1: printGrades(grades);
            break;
        case 2: retakeExam(grades);
            break;
        case 3: checkScholarship(grades);
            break;
        case 0: cout << "Выход..." << endl;
            break;
        default: 
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}

//4)Быстрая сортировка 
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left, j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

//5)Условная сортировка
void conditionalSort(int arr[], int n) {
    //вычисляем среднее арифметическое
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = sum / n;

    int sortSize;
    if (average > 0) {
        sortSize = (2 * n) / 3;  //первые 2/3
    }
    else {
        sortSize = n / 3;        //первая 1/3
    }

    // сортируем выбранную часть
    for (int i = 0; i < sortSize - 1; i++) {
        for (int j = 0; j < sortSize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    
    for (int i = sortSize; i < n - 1; i++) {
        for (int j = sortSize; j < n - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//ОСНОВНАЯ ПРОГРАММА
int main() {
    setlocale(LC_ALL, "ru");
    cout << "ЗАДАНИЕ 1: Пузырьковая сортировка" << endl;
    int arr1[] = { 5, 2, 8, 1, 9, 3 };
    int n1 = 6;
    bubbleSort(arr1, n1);
    cout << "После пузырьковой сортировки: ";
    for (int i = 0; i < n1; i++) cout << arr1[i] << " ";
    cout << endl;

    cout << "\nЗАДАНИЕ 2: Сортировка вставками" << endl;
    int arr2[] = { 5, 2, 8, 1, 9, 3 };
    int n2 = 6;
    insertionSort(arr2, n2);
    cout << "После сортировки вставками: ";
    for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
    cout << endl;

    cout << "\nзадание 3: Успеваемость " << endl;
    studentPerformance();

    cout << "\nЗАДАНИЕ 4: Быстрая сортировка" << endl;
    int arr4[] = { 5, 2, 8, 1, 9, 3 };
    int n4 = 6;
    quickSort(arr4, 0, n4 - 1);
    cout << "После быстрой сортировки: ";
    for (int i = 0; i < n4; i++) cout << arr4[i] << " ";
    cout << endl;

    cout << "\nзадание 5: Условная сортировка" << endl;
    int arr5[] = { 5, -2, 8, -1, 9, 3, 7, 4, 6 };
    int n5 = 9;
    conditionalSort(arr5, n5);
    cout << "После условной сортировки: ";
    for (int i = 0; i < n5; i++) cout << arr5[i] << " ";
    cout << endl;

    return 0;
}
