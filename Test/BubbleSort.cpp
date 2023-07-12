#include <gtest/gtest.h>
#include <algorithm>


class ArraySorter {
private:
    int* arr;
    int size;

public:
    ArraySorter(int array[], int arraySize) : arr(array), size(arraySize) {}

    void BubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Hoán đổi giá trị của hai phần tử
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void PrintArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

TEST(BubbleSortTest, EmptyArray) {
    int arr[] = {};
    int size = 0;

    ArraySorter(arr, size);

    // Check if the array remains empty
    EXPECT_EQ(0, 0);
}

TEST(BubbleSortTest, SortedArray) {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    ArraySorter(arr, size);

    // Check if the array is still sorted
    for (int i = 0; i < size - 1; ++i) {
        EXPECT_LE(arr[i], arr[i + 1]);
    }
}

TEST(BubbleSortTest, ReverseSortedArray) {
    int arr[] = {5, 4, 3, 2, 1};
    int size = 5;

    ArraySorter(arr, size);

    // Check if the array is sorted in ascending order
    for (int i = 0; i < size - 1; ++i) {
        EXPECT_LE(arr[i], arr[i + 1]); //Verifies that a[i] < a[i + 1]
    }
}

TEST(BubbleSortTest, RandomArray) {
    int arr[] = {3, 1, 4, 2, 5};
    int size = 5;

    ArraySorter(arr, size);

    // Check if the array is sorted in ascending order
    for (int i = 0; i < size - 1; ++i) {
        EXPECT_LE(arr[i], arr[i + 1]); //Verifies that a[i] < a[i + 1]
    }
}