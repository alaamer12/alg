#include <iostream>
using namespace std;

class MyAlg {
public:
    // Function to perform insertion sort
    int* insertion_sort(int unsorted_arr[], int length, bool order) {
        int* arr = new int[length];
        for (int i = 0; i < length; ++i) {
            arr[i] = unsorted_arr[i];
        }

        // Perform insertion sort
        for (int i = 1; i < length; ++i) {
            int key = arr[i];
            int j = i - 1;
            bool condition = order ? (key < arr[j]) : (key > arr[j]);
            while (j >= 0 && condition) {
                arr[j + 1] = arr[j];
                j--;
                if (j >= 0)
                    condition = order ? (key < arr[j]) : (key > arr[j]);
            }
            arr[j + 1] = key;
        }

        return arr;
    }

    // Function to perform merge sort
    void merge_sort(int arr[], int length, bool order = 0) {
        if (length <= 1) return;

        int mid = length / 2;
        int* left = new int[mid];
        int* right = new int[length - mid];

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < length; i++) {
            right[i - mid] = arr[i];
        }

        merge_sort(left, mid, order);
        merge_sort(right, length - mid, order);

        merge(arr, left, right, mid, length - mid, order);

        delete[] left;
        delete[] right;
    }

private:
    // Function to merge two subarrays
    void merge(int arr[], int left[], int right[], int sizeLeft, int sizeRight, bool order) {
        int i = 0, j = 0, k = 0;
        bool condition;
        while (i < sizeLeft && j < sizeRight) {
			condition = order ? (left[i] < right[j]) : (left[i] > right[j]);
            if (condition) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }

        while (i < sizeLeft) {
            arr[k++] = left[i++];
        }

        while (j < sizeRight) {
            arr[k++] = right[j++];
        }
    }
};

class CollegeAlg {
public:
    // Function to perform insertion sort
    void insertionSort(int arr[], int size, bool order) {
        int i, key, j;
        for (i = 1; i < size; i++) {
            key = arr[i];
            j = i - 1;
            bool condition = order ? (key < arr[j]) : (key > arr[j]);
            while (j >= 0 && condition) {
                arr[j + 1] = arr[j];
                j--;
                if (j >= 0)
                    condition = order ? (key < arr[j]) : (key > arr[j]); // Update condition
            }
            arr[j + 1] = key;
        }
    }

    // Function to display array elements
    void display(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

private:
    // Function to merge two subarrays
    void merge(int arr[], int s, int m, int e, bool order) {
        int i, j, k;
        int n1 = m - s + 1;
        int n2 = e - m;
        int* Left_list = new int[n1];
        int* Right_list = new int[n2];

        for (i = 0; i < n1; i++) {
            Left_list[i] = arr[s + i];
        }

        for (j = 0; j < n2; j++) {
            Right_list[j] = arr[m + 1 + j];
        }

        i = j = 0;
        k = s;

        while (i < n1 && j < n2) {
            if (order ? (Left_list[i] < Right_list[j]) : (Left_list[i] > Right_list[j])) {
                arr[k] = Left_list[i];
                i++;
            }
            else {
                arr[k] = Right_list[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = Left_list[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = Right_list[j];
            j++;
            k++;
        }

        delete[] Left_list;
        delete[] Right_list;
    }
public:
    // Function to perform merge sort
    void mergeSort(int a[], int start, int end, bool order = false) {
        int mid = 0;
        if (start < end) {
            mid = (start + end) / 2;
            mergeSort(a, start, mid, order);
            mergeSort(a, mid + 1, end, order);
            merge(a, start, mid, end, order);
        }
    }
};


int main() {
    MyAlg myalg;
    int unsorted_arr[] = { 100, 19, 32, 46, 15, 4, 33, 20, 10 };
    int length = sizeof(unsorted_arr) / sizeof(unsorted_arr[0]);
    cout << "Array before sorting: ";
    for (int i = 0; i < length; i++) {
        cout << unsorted_arr[i] << " ";
    }
    cout << endl;

    myalg.merge_sort(unsorted_arr, length, 0);

    cout << "Array after myalg merge sort (descending): ";
    for (int i = 0; i < length; i++) {
        cout << unsorted_arr[i] << " ";
    }
    cout << endl;

    myalg.merge_sort(unsorted_arr, length, 1);

    cout << "Array after myalg merge sort (ascending): ";
    for (int i = 0; i < length; i++) {
        cout << unsorted_arr[i] << " ";
    }

    int* sorted_arr = myalg.insertion_sort(unsorted_arr, length, false);
    cout << "\nArray after insertion sort (descending): ";
    for (int i = 0; i < length; ++i) {
        cout << sorted_arr[i] << " ";
    }

    int* sorted_arr2 = myalg.insertion_sort(unsorted_arr, length, true);
    cout << "\nArray after insertion sort (ascending): ";
    for (int i = 0; i < length; ++i) {
        cout << sorted_arr2[i] << " ";
    }

    cout << endl;

    delete[] sorted_arr; // Free allocated memory

    CollegeAlg collegeAlg;

    int arr[8] = { 9,2,7,5,1,4,3,6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    collegeAlg.insertionSort(arr, n, false);
    cout << "\nArray after insertion sort (descending): ";
    collegeAlg.display(arr, n);

    collegeAlg.insertionSort(arr, n, true);
    cout << "Array after insertion sort (ascending): ";
    collegeAlg.display(arr, n);

    int arr2[] = { 99,6,76,15,58,35,86 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    collegeAlg.mergeSort(arr2, 0, n2 - 1, 0);
    cout << "Array after merge sort: (descending) ";
    collegeAlg.display(arr2, n2);

    collegeAlg.mergeSort(arr2, 0, n2 - 1, 1);
    cout << "Array after merge sort: (ascending) ";
    collegeAlg.display(arr2, n2);

    return 0;
}
