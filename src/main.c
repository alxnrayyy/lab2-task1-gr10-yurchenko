#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxFromDigits(int num) {
		int digits[10] = {0};
		int temp = num;

		while (temp > 0) {
				int digit = temp % 10;
				digits[digit]++;
				temp /= 10;
		}

		int result = 0;
		for (int digit = 9; digit >= 0; digit--) {
				for (int count = 0; count < digits[digit]; count++) {
						result = result * 10 + digit;
				}
		}

		return result;
}

int main(int argc, char *argv[]) {
		if (argc != 2) {
				printf("Использование: %s <размер массива>\n", argv[0]);
				return 1;
		}

		int n = atoi(argv[1]);

		if (n <= 0) {
				printf("Ошибка: размер массива должен быть положительным числом\n");
				return 1;
		}

		srand(time(NULL));

		int arr[n];

		printf("Сгенерированный массив:\n");
		for (int i = 0; i < n; i++) {
				arr[i] = rand() % 999 + 1; 
				printf("%d ", arr[i]);
		}
		printf("\n");

		printf("\nИсходные числа и результаты:\n");
		printf("----------------------------\n");
		for (int i = 0; i < n; i++) {
				int maxNum = maxFromDigits(arr[i]);
				printf("%d -> %d\n", arr[i], maxNum);
		}

		return 0;
}