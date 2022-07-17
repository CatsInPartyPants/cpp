#include <iostream>

using namespace std;

void stepRight(int arr[3][4], int s)
{
    for(int i = 0; i<3;i++) 
    {
        int temp = arr[i][3];
        for(int j = 3;j>=0;j--)
        {
            arr[i][j] = arr[i][j-1];            
        }
        arr[i][0] = temp;
    }
    if(s >= 0)
    {
        stepRight(arr, --s);
    }
}

void show(int arr[3][4])
{
    for(int  i =0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void stepLeft(int arr[3][4], int s)
{
    for(int i = 0; i<3; i++)
    {
        int temp = arr[i][0];
        for(int j = 1; j< 4; j++)
        {
            arr[i][j-1] = arr[i][j];
        }
        arr[i][3] = temp;
    }
    if(s>1)
        stepLeft(arr,--s);
}

void stepUp(int arr[3][4], int s)
{
    for(int j = 0; j<4; j++)
    {
        int temp = arr[0][j];
        for(int i = 0; i <= 2; i++)
        {
            arr[i][j] = arr[i+1][j];
        }
        arr[2][j] = temp;
    }
    if(s>1)
    {
        stepUp(arr, --s);
    }
}

void farr(int* arr)
{
    for(int i = 0; i<5; i ++)
    {
        cout << *arr;
        arr++;
    }
}


int main()
{
    //int arr[3][4]={{4, 5, 6, 7}, {1,2,4,1}, {4,5,6,9} };
    //stepRight(arr, 1);
    //stepLeft(arr,2);
    //stepUp(arr, 1);
    //show(arr);

    // POINTERS
    int x = 10;
    int y = 5;
    int *px;
    int *py;
    //записываем адрес переменной х к указатель пх
    px = &x;
    py = &y;

    //отображаем адрес х через указатель и операцию 
    //cout << px << " " << &x << endl;
    // отобразим значение переменной х через указатель
    //cout << *px << " " << x << endl;
    //изменяем значение х используя операцию разыменовывания
    //*px = 99;
    //cout << x << " " << *px << endl;
    //cout << ++px << endl;
    //int arr[5] = {3,4,5,6,7};
    //string s = "Hello world!";
    //const char* c = "Hello world";
    //farr(arr);
    const int size = 5;
    int arr[size] = {33,44,7,8,9};
    // записываем адрес нулевого элемента массива в указатель
    int *ptr = &arr[0];
    //показываем значение нулевого элемента массива через указатель
    cout << *ptr << endl;
    //показываем значение второго элемента массива через разыменовывание указателя
    cout << *(ptr+1) << endl;
    //выполним смещение на один элемент вперед и записываем новый адрес в указатель ptr
    //ptr++;
    cout << *ptr << endl;
    for(int i = 0; i < size; i++){
        cout << *(ptr+i) << " ";
    }
    cout << endl;
    //изменим значение второго элемента массива
    *(ptr+1) = 55;
    *(ptr+2) = 77;
    for(int i = 0; i < size; i++){
        cout << *(ptr+i) << " ";
    }
    cout << endl;

    return 0;
}