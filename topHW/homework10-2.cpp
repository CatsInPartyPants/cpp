#include <iostream>

using namespace std;

//task 1 
void makingArr(int arr[][3], int size, int userElement);
void showarr(int arr[][3], int size);

//task 2
void makingArr2(int arr[][3], int size, int userElement);


int main()
{
    int userElement;
    cout << "Enter first element of the array->";
    cin >> userElement;
    int myArray[3][3];
    int myArray2[3][3];
    makingArr(myArray,3, userElement);
    showarr(myArray,3);
    makingArr2(myArray2, 3, 1);
    showarr(myArray2, 3);
    return 0;
}


//show array function
void showarr(int arr[][3], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j <size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
//task 1 function
void makingArr(int arr[][3], int size, int userElement)
{
    int temp = userElement;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        if(i == 0 && j == 0)
        {
            arr[0][0] = userElement;
            temp *= 2;
        }
        else{
            arr[i][j] = temp;
            temp*=2;
        }
    }
}

//task 2 function
void makingArr2(int arr[][3], int size, int userElement)
{
    int temp = userElement;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        if(i == 0 && j == 0)
        {
            arr[0][0] = temp;
            temp ++;
        }
        else{
            arr[i][j] = temp;
            temp++;
        }
    }
}