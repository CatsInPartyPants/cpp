#include <iostream>

using namespace std;

//task 1 
void makingArr(int arr[][3], int size, int userElement);
void showarr(int arr[][3], int size);

//task 2
void makingArr2(int arr[][3], int size, int userElement);

//task 3
void moveArray(int arr[2][10], int howMuchMove, char whichWay);

int main()
{
    
    int userElement;
    cout << "Enter first element of the array->";
    cin >> userElement;
    int myArray[3][3];
    int myArray2[3][3];
    //1
    makingArr(myArray,3, userElement);
    showarr(myArray,3);
    //2
    makingArr2(myArray2, 3, userElement);
    showarr(myArray2, 3);
    //3 
    int arrayForConvert[2][10] ={
                                {1,2,3,4,5,6,7,8,9,10},
                                {9,8,7,6,5,4,3,2,1,0}
                                };
    
    moveArray(arrayForConvert, 20, 'r');
    moveArray(arrayForConvert, 111, 'l');
   //show array
   for(int i = 0; i<2; i++)
   {
       for(int j = 0; j<10; j++)
       {
           cout << arrayForConvert[i][j] << " ";
       }
       cout << endl;
   }
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
            temp++;
        }
        else{
            arr[i][j] = temp;
            temp++;
        }
    }
}

//task 3 Function
//only moving to right or left working
void moveArray(int arr[2][10], int howMuchMove, char whichWay)
{
    if(whichWay == 'r')
    {
        for(int i =0; i < 2; i++)
        {
            for(int k = 0; k < howMuchMove; k++)
            {
                int temp = arr[i][10-1];
                for(int d =10-2; d>=0; d--)
                {   
                    arr[i][d+1] = arr[i][d];
                }
                arr[i][0] = temp;
            }
        }
    }

    if(whichWay == 'l')
    {
        for(int i =0; i < 2; i++)
        {
            for(int k = 0; k < howMuchMove; k++)
            {
                int temp = arr[i][0];
                for(int d =0; d<=9; d++)
                {   
                    arr[i][d] = arr[i][d+1];
                }
                arr[i][9] = temp;
            }
        }
    }
}