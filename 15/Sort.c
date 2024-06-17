//Insertion_Sort
#include<stdio.h>
void insert(int a[], int n) {
    int i, j, key;
    for (i=1;i<n;i++) {
        key = a[i];
        j=i-1;
        while (j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements: ", n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }
    insert(a, n);
    printf("Sorted array: ");
    for (int i=0;i<n;i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
output:
Enter the number of elements: 5
Enter 5 elements: 12 11 13 5 6
Sorted array: 5 6 11 12 13
//merge sort
  #include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_arr[n1], right_arr[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];
    i = 0,j = 0,k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the %d elements: ",size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: \n");
    print_array(arr, size);
    merge_sort(arr, 0, size - 1);
    printf("Sorted array: \n");
    print_array(arr, size);
    return 0;
}
output:
Enter the number of elements: 5
Enter 5 elements: 12 11 13 5 6
Sorted array: 5 6 11 12 13
//quick sort
#include <stdio.h>
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int partition_index = i + 1;
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the %d elements: ",size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: \n");
    print_array(arr, size);
    quick_sort(arr, 0, size - 1);
    printf("Sorted array: \n");
    print_array(arr, size);
    return 0;
}
output:
Enter the number of elements: 5
Enter 5 elements: 12 11 13 5 6
Sorted array: 5 6 11 12 13
