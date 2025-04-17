//pseudo code to reverse an array using pointers
/*
input an array and its size to func
left pointer points to left most element
right pointer points to right most element

create a temp variable

dereference the left pointer and assign to temp
dereference the right pointer and assign to dereferenced left pointer
assign temp to dereferenced right pointer
increment left by 1
decrement right by 1

do this process as long as leftPointer < rightPointer
*/

//pseudo code to reverse an array by passing it as reference
/*
not using pointers
attention to how to pass the arguments and define the formal parameters - not to confuse between
passing "array of references" and "reference to an array"
logic remains same to swap numbers of left most to right most, increment left, decrement right
*/

//pseudo code to reverse an array using recursion
/*
pass the left and right most index of the array
swap the left and right most numbers
recursively call the function with new arguments as "arr, left + 1 , right - 1"
*/

#include <iostream>

void reverseArray(int arr[], int size)
{
    int temp = 0;
    int* leftPointer = &arr[0];
    int* rightPointer = &arr[size - 1];
    
    while(leftPointer < rightPointer)
    {
        temp = *leftPointer;
        *leftPointer = *rightPointer;
        *rightPointer = temp;

        leftPointer++;
        rightPointer--;
    }
}

void reverseArrayByReference(int (&arr)[5], int size)
{
    int temp = 0;
    int left= arr[0];
    int right = arr[size - 1];
    
    while(left < right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

void reverseArrayUsingRecursion(int arr[], int left, int right)
{
    int temp {0};
    if(left >= right)
        return;
    
    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    
    reverseArrayUsingRecursion(arr, left+1, right-1);
}

void printArr(int arr[], int size)
{
    for (int i = 0 ; i < size ; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int arr[5] {1,2,3,4,5};
    printArr(arr,5);

    reverseArray(arr,5);
    printArr(arr,5);
    
    int (&arr1)[5] = arr;

    reverseArrayByReference(arr1, 5);
    printArr(arr,5);
    
    reverseArrayUsingRecursion(arr, 0, 4);
    printArr(arr,5);
}