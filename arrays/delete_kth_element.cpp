//input is an integer array
//shall be able to spot all the repeating occurances of target element if any and ask for which instance of that element needs to be deleted.
//should be able to delete multiple instances of the same element
//returns whether the target element is present or not in the input array and its position(output param)
//returns modified size after the deletion(output param)

#include <iostream>

bool deleteKthElement(int arr[], int* size, int k, int* position)
{
    for(int i = 0; i < *size ; ++i)
    {
        if(arr[i] == k)
        {
            arr[i] = arr[i+1];
            *size -= 1;
            *position = i+1;
            return true;
        }
    }
    return false;
}

void PrintArray(int arr[],int size)
{
    for(int i = 0 ; i < size ; ++i)
    {
        std::cout << arr[i]<< " ";
    }
    std::cout << "\n";
}

int main()
{
    int size{0};
    int k{0};
    std::cout << "Enter size of array: ";
    std::cin >> size;
    
    int arr[size];
    std::cout << "Enter the elements of array: ";
    
    for(int i = 0 ; i < size ; ++i)
    {
        std::cin >> arr[i];
    }
    
    std::cout << "elements of the array are: ";
    PrintArray(arr, size);
    
    std::cout << "Which element you want to delete: ?";
    std::cin >> k;
    
    int position = 0;
    bool modified = deleteKthElement(arr, &size, k, &position);
    if(modified)
        std::cout << k << " found at position: " << position << "\nModified array is: ";
    else
        std::cout << k << " cannot be found\nprinting original array: ";
    PrintArray(arr, size);
}
