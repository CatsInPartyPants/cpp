#include <iostream>

using namespace std;

int& rf(int index);
int& rmax(int n, int d[]);
int a[10][2];

// + or -
string znak(int* a)
{
    return *a > 0 ? "positive" : "negative";
}

void change(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int primcalc(int* a, int *b, char* z)
{
    if(*z == '+')
    {
        return *a + *b;
    }else if(*z == '-')
    {
        return *a - *b;
    }else if(*z == '*')
    {
        return *a * *b;
    }else if(*z == '/')
    {
        return *a / *b;
    }else{
        cout << "error\n";
        return -1;
    }
}

int main()
{
    /*
    int b;
    cout << "Fill array\n";
    for(int i = 0; i<10; i++)
    {
        cout << i+1 << " element: ";
        cin >> b;
        a[i][0] = b;
        rf(i) = b;
    }  
    cout << "\nShow array\n";
    for(int i = 0; i<10; i++)
    {
        cout << a[i][0] << "\t" << rf(i) << endl;
    }

    //нахождение максимального элемента в массиве и замена его на 0
    int x[] = {10,20,30,14};
    int n = 4;
    cout << "rmax(n, x) = " << rmax(n,x) << endl;
    rmax(n,x) = 0;
    for(int i = 0; i < n; i++)
    {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
    */
   /*
   int* ip = new int;
   int a; cin >> a;
   cout << znak(&a);
    return 0;
    */
    int a = 5, b = 10;
    //change(&a, &b);
    //cout << a << " " << b << endl;
    char z = '*';
    cout << primcalc(&a, &b, &z);
}

int& rf(int index) // возвращает ссылку на элемент массива
{
    return a[index][1];
}

int& rmax(int n, int d[])
{
    int im = 0;
    for(int i = 0; i<n; i++)
    {
        im = d[im] > d[i] ? im : i;
    }
    return d[im];
}