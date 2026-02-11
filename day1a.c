#include <stdio.h>

int main() {
    int n, pos, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n + 1];   // extra space for insertion

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &x);

    // Convert 1-based to 0-based
    int index = pos - 1;

    // Shift elements to right
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[index] = x;

    printf("Updated array:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
