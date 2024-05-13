
/*
    Challenge 1 from The Modern C, by Jens Gudstedt
    In this program we are tasked with implementing
    a recursive merge sort and quirk sort algorithm
    on arrays with sort keys such as double or strings.

*/
#include <stdio.h>
void mergeSort(int array[], int left, int right);
void merge(int array[], int left, int middle, int right);
void printArray(int arr[], int size);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{

    int array1[6] = {1, 4, 2, 5, 9, 6};
    int array2[6] = {8, 4, 2, 5, 9, 10};
    int array3[6] = {9, 4, 1, 5, 9, 3};

    // mergeSort(array1, 0,5)
    // mergeSort(array2, 0,5);
    // mergeSort(array3, 0,5);

    // mergeSort(array2, 0, 3);

    // printArray(array2, 6);
    // printf("\n");
    // printArray(array2, 6);
    // printf("\n");
    // printArray(array3, 6);
    // printf("\n");

    quickSort(array2, 0, 5);
    printArray(array2, 6);
    return 0;
}

void merge(int array[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int leftArr[n1];
    int rightArr[n2];

    // Copy into Left array
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = array[left + i];
    }

    // Copy into Right Array
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = array[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            array[k] = leftArr[i];
            i++;
        }
        else
        {
            array[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int array[], const int left, const int right)
{
    // Need to split arrays into a left array and right array
    // By finding middle index; take midpoint of left and right index
    if (left < right)
    {
        int middle = (left + right) / 2;

        // mergeSort left half
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void quickSort(int arr[], int low, int high)
{
    // when low is less than high
    if (low < high)
    {
        // pi is the partition return index of pivot

        int pi = partition(arr, low, high);

        // Recursion Call
        // smaller element than pivot goes left and
        // higher element goes right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    // choose the pivot

    int pivot = arr[high];
    // Index of smaller element and Indicate
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            // Increment index of smaller element
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}