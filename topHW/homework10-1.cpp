#include <iostream>

using namespace std;

// task 1 function
int Exponentiation(int a, int b);

//task 2 function
int SummBetween(int a, int b);

//task 3 function
bool isPerfect(int number);

//task 4 Function
template <typename T>
void showCard(T card);

//task 5 Function
bool isLucky(int number);

int main()
{
    //1
    cout << Exponentiation(3,9) << endl;
    //2
    cout << SummBetween(1,11) << endl;
    //3
    isPerfect(6);
    isPerfect(495);
    isPerfect(496);
    //4
    showCard(6);
    showCard('A');
    showCard('J');
    //5
    isLucky(333333);
    isLucky(123321);
    isLucky(345987);
    isLucky(5437899);
    return  0;
}

// task 1 function
int Exponentiation(int a, int b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b > 1) return a * Exponentiation(a, --b);
}

//task 2 function
int SummBetween(int a, int b)
{
    a++;
    if(a>b) return 0;
    if(a==b) return 0;
    while(a <= b)
    {
        return a + SummBetween(a, b);
    }
}

//task 3 function
bool isPerfect(int number)
{
    int summ = 0;
    for(int i = number-1; i > 0; i--)
    {
        if(number % i == 0) summ += i;
    }
    if(summ == number)
    {
        std::cout << "The number " << number << " is perfect!\n";
        return true;
    }
    else
    {
        std::cout << "The number " << number << " is not perfect!\n";
        return false;
    }
}

//task 4 Function
template <typename T>
void showCard(T card)
{
    T temp = card;
    //верхняя граница карты
    for(int i = 0; i < 10; i++)
    {
        cout << "=";
    }
    cout << endl;
    //боковые границы карты
    for(int i = 0; i < 10; i++)
    {
        if(i == 0){ cout << "|" << temp << "       |" << endl;}
        else if(i == 5){ cout << "|   " << temp << "    |" << endl;}
        else if(i == 9) {cout << "|       " << temp << "|" << endl;}
        else{
        cout << "|        |" << endl;
        }
    }
    //нижняя граница карты
    for(int i = 0; i < 10; i++)
    {
        cout << "=";
    }
    cout << endl;
}

//task 5 Function
bool isLucky(int number)
{
    int summ1 = 0, summ2 = 0, temp = number;
    int isSix  = 0;
    while(temp != 0)
    {
        temp = temp / 10;
        isSix++;
    }
    if(isSix == 6)
    {
        for(int i = 0; i < 6; i++)
        {
            if(i <= 2)
            {
                summ1 += number % 10;
                number = number / 10; 
            }else{
                summ2 += number % 10;
                number = number / 10;
            }
        }
            if(summ1 == summ2)
            {
                cout << "Lucky number!\n";
                return true;
            }else{
                cout << "Not lucky number!\n";
                return false;
            }
        }
    else{
        cout << "not 6 digit" << endl;
        return false;
    }
}