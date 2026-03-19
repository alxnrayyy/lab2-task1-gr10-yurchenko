#include <stdio.h>
#include <stdlib.h>

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

int main() {
		int n;

		printf("Введите количество чисел: ");
		scanf("%d", &n);

		int arr[n];

		printf("Введите %d натуральных чисел:\n", n);
		for (int i = 0; i < n; i++) {
				scanf("%d", &arr[i]);
		}

		printf("\nИсходные числа и результаты:\n");
		printf("----------------------------\n");
		for (int i = 0; i < n; i++) {
				int maxNum = maxFromDigits(arr[i]);
				printf("%d -> %d\n", arr[i], maxNum);
		}

		return 0;
}