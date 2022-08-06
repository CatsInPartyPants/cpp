#include <iostream>
#include <cmath>

using namespace std;

const int SIZE = 10;
//task 1
int linearSearch(int arr[], int size, int target);

//task 2
int binarySearch(int arr[], int size, int target);

//task 3
int binToDec(long int binNum);

int main()
{
    //task 1
    int test_array[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target = 4;
    int key_linear = linearSearch(test_array, SIZE, target);
    cout << "linear search:\tElement " << target << " is on position " << key_linear << endl;

    //task 2
    target = 8;
    int key_binary = binarySearch(test_array, SIZE, target);
    cout << "binary search:\tElement " << target << " is on position " << key_binary << endl;

    //task 3
    cout << binToDec(11010010);
    return 0;
}

//task 1
int linearSearch(int arr[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
}

//task 2
int binarySearch(int arr[], int size, int target)
{
    int middle;
    int left = 0;
    int right = size-1;
    while(true)
    {
        middle = (left + right)/2;
        if(target < arr[middle])
        {
            right = middle-1;
        }else if(target > arr[middle])
        {
            left = middle+1;
        }else
        {
            return middle;
        }
        if(left > right)
        {
            return -1;
        }
    }
}

//task 3

int binToDec(long int binNum)
{
    long int temp = binNum;
    int total = 0;
    int decNumber = 0;
    while(temp != 0)
    {
        temp = temp / 10;
        total++;
    }
    for(int i = 0; i <= total; i++)
    {
        decNumber += (binNum%10) * pow(2, i);
        binNum = binNum / 10;
    }
    return decNumber;
}