// Copyright (c) 2022 enikeev_tg. All rights reserved.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int error = 0;
    int n;
    char ch;
    if (scanf("%d%c", &n, &ch) != 2 || n <= 0 || ch != 10)  // Считывание длины массива
        error = 1;

    int* array = NULL;
    if (error == 0)  // Выделение памяти под массив
        array = malloc(n * sizeof(int));

    if (error == 0 && array == NULL)
        error = 1;

    for (int i = 0; i < n && error == 0; ++i)  // Пользовательский ввод элементов массива
        if (scanf("%d%c", &array[i], &ch) != 2 || (i < n - 1 && ch != 32) || (i == n - 1 && ch != 10))
            error = 1;

    for (int i = 0; i < n - 1 && error == 0; ++i)  // Сортировка пузырьком
        for (int j = 0; j < n - 1 - i; ++j)
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }

    for (int i = 0; i < n && error == 0; ++i)  // Распечатка отсортированного массива
        printf("%d ", array[i]);

    free(array);  // Очистка памяти
    if (error != 0)  // Если ввод с ошибкой
        printf("n/a");

    return 0;
}