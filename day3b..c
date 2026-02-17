#include <stdio.h>

int missingNumber(int arr[], int size) {
    int n = size + 1;   // since one number is missing
    long long total_sum = (long long)n * (n + 1) / 2;
    long long arr_sum = 0;

    for(int i = 0; i < size; i++) {
        arr_sum += arr[i];
    }

    return total_sum - arr_sum;
}

int main() {
    int size;

    printf("Enter size of array (n-1): ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d distinct numbers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int result = missingNumber(arr, size);

    printf("Missing number is: %d\n", result);

    return 0;
}
