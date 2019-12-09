#include <stdlib.h>
#include <stdio.h>

typedef struct Number {
	int val;
	int movement;
} Number;

int get_number_digit(Number n, int idx) {
	int g = n.val;
	int h;
	for(int i = 0; i<idx+1; i++) {
		h = (g % 10);
		g /= 10;
	}
	return h;
}

void copy(Number* from, Number* dest) {
	(*dest).val = (*from).val;
	(*dest).movement = (*from).movement;
}

void swap(Number* a, Number* b) {
	Number temp;
	copy(a, &temp);
	copy(b, a);
	copy(&temp, b);
}

void insertion_sort(Number arr[], int from, int to, int idx) {
    for (int i = from; i < to; i++) {
        for (int j = i + 1; j > from && get_number_digit(arr[j], idx) < get_number_digit(arr[j - 1], idx); j--) {
            swap(&arr[j - 1], &arr[j]);
            arr[j].movement -= 1;
			arr[j - 1].movement += 1;
        }
    }
}

int partitionM(Number arr[], int left, int right) {
	int pivot = arr[right].movement;
	int i = left - 1;
	int j = i + 1;
	for(; j<right; j++) {
		if(arr[j].movement <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	i++;
	swap(&arr[i], &arr[right]);
	return i;
}

void quicksortM(Number arr[], int left, int right) {
	if(left < right) {
		int q = partitionM(arr, left, right);
		quicksortM(arr, left, q-1);
		quicksortM(arr, q+1, right);
	}
}

void radixSort(Number arr[], int left, int right) {
	for(int i = 0; i<4;i++) {
		printf("For %d index\n", i);
		insertion_sort(arr, 0, right, i);
		for(int i = 0; i<right + 1; i++) {
			printf("Num: %d, Movement: %d\n", arr[i].val, arr[i].movement);
		}
	}
	printf("---sdfsdfsdf\n");
}

int main() {
	int d;
	scanf("%d", &d);
	Number arr[d];
	for(int i = 0; i<d; i++) {
		int g;
		scanf("%d", &g);
		arr[i].val = g;
		arr[i].movement = 0;
	}
	radixSort(arr, 0, d-1);
	for(int i = 0; i<d; i++) {
		printf("Num: %d, Movement: %d\n", arr[i].val, arr[i].movement);
	}
	printf("\n");
	printf("------------------------------------\n");
	printf("\n");
	quicksortM(arr, 0, d-1);
	for(int i = 0; i<d; i++) {
		printf("Num: %d, Movement: %d\n", arr[i].val, arr[i].movement);
	}
}