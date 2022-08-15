// Copyright (c) 2022 enikeev_tg. All rights haven't reserve;)
#include <stdio.h>
#include <stdlib.h>

#define LEN_STEP 10

int *input_array(int *plength, int *perror);
void print_array(int *array, int length);

void bubble_sorting(int *array, int length);
void quick_sorting(int* array, int length);

int main() {
	int length, error;
	int *array = input_array(&length, &error);  // Заполнение массива из stdin

#ifdef BUBBLE
	if (error == 0)
		bubble_sorting(array, length);
#endif

#ifdef QUICK
	if (error == 0)
		quick_sorting(array, length);
#endif

	if (error == 0)
		print_array(array, length);  // Вывод отсортированного массива в stdout
	else
		printf("n/a");
	
	free(array);  // Очистка памяти
    return 0;
}

// Ввод целочисленного массива произвольной длины
int *input_array(int *plength, int *perror) {
	unsigned int arr_len = LEN_STEP;
	int *array = (int*) malloc(arr_len * sizeof(int));
	*plength = 0;
	*perror = 0;

	int num;
	char symb;
	do {
		if (scanf("%d%c", &num, &symb) == 2 && (symb == ' ' || symb == '\n')) {
			array[*plength] = num;
			(*plength)++;
			if (*plength == arr_len) {
				arr_len += LEN_STEP;
				array = (int*) realloc(array, arr_len * sizeof(int));
			}
		} else {
			*perror = 1;
		}
	} while (*perror == 0 && symb != '\n');
	array = (int*) realloc(array, *plength * sizeof(int));
	return array;
}

// Распечатка отсортированного массива
void print_array(int *array, int length) {
	for (int i = 0; i < length; ++i)
		printf("%d ", array[i]);
}

// Сортировка пузырьком
void bubble_sorting(int* array, int length) {
	for (int i = 0; i < length - 1; ++i)
		for (int j = 0; j < length - 1 - i; ++j)
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
}

// Быстрая сортировка
void quick_sorting(int* array, int length) {
	
}

/*========================================================
                      Мусорный код
========================================================*/
/* Если нужно заранее ввести длину массива

    // int n;
    // char ch;
    // if (scanf("%d%c", &n, &ch) != 2 || n <= 0 || ch != 10)  // Считывание длины массива
    //     error = 1;

    // int* array = NULL;
    // if (error == 0)  // Выделение памяти под массив
    //     array = malloc(n * sizeof(int));

    // if (error == 0 && array == NULL)
    //     error = 1;

    // for (int i = 0; i < n && error == 0; ++i)  // Пользовательский ввод элементов массива
    //     if (scanf("%d%c", &array[i], &ch) != 2 || (i < n - 1 && ch != 32) || (i == n - 1 && ch != 10))
    //         error = 1;
*/
