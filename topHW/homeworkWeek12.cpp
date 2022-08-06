#include <iostream>

using namespace std;

const int SIZE = 10;

//task 1

bool isLeap(int year);
int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2);

//task 2

double averageOfArray(int arr[], int size);

//task 3

void arrayInfo(int arr[], int size);

int main()
{
    //task 1
    cout << dateDifference(1, 7, 2020, 22, 7, 2020) << endl;
    cout << dateDifference(1, 3, 2020, 3, 6, 2021) << endl;
    cout << dateDifference(3, 3, 2020, 9, 9, 2023) << endl;    

    //task 2
    int arr[10] = {1,21,13,30, 5,6,7,210,9,10};
    cout << averageOfArray(arr, SIZE) << endl;

    //task 3
    int arr2[10] = {1, -2, 3, -4, 5, 0, 0, -8, 9, 10};
    arrayInfo(arr2, SIZE);
    return 0;
}

//task 1

bool isLeap(int year)
{
    if (year % 4 == 0) 
    {
        if (year % 100 == 0) 
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
}

int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2)
{
    int daysBetween = 0; // result
    int daysInLeapYear[12] = {31,29,31,30,31,30,31,31,30,31,30,31}; //for leap year
    int daysInNotLeapYear[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //for not leap year
    int local_month1 = month1-1; 
    int local_month2 = month2-1;
    if(year1 == year2) //if year are equal
    {
        if(isLeap(year1) == false)
        {
            for(int i = local_month1+1; i < local_month2; i++)
            {
                daysBetween += daysInNotLeapYear[i];
            }
            daysBetween += day2;
            if(local_month1 != local_month2)
            {
                daysBetween += daysInNotLeapYear[local_month1] - day1;
            }
            return daysBetween;
        }
        else if(isLeap(year1) == true)
        {
           for(int i = local_month1+1; i < local_month2; i++)
            {
                daysBetween += daysInLeapYear[i];
            }
            daysBetween += day2;
            if(local_month1!=local_month2)
            {
                daysBetween += daysInLeapYear[local_month1] - day1;
            }
            return daysBetween; 
        }
    }
    // neighboring years
    else if(year1 < year2 && year2 - year1 == 1)
    {
        if(isLeap(year1) == false)
        {
            daysBetween += 365 - dateDifference(1,1,year1, day1, month1, year1);
        }else
        {
            daysBetween += 366 - dateDifference(1,1,year1, day1, month1, year1);
        }
        daysBetween += dateDifference(1,1,year2, day2, month2, year2);
        return daysBetween;
    }
    // for distant years
    else if(year1 < year2 && year2-year1 > 1)
    {
        if(isLeap(year1) == false)
        {
            daysBetween += 365 - dateDifference(1,1,year1, day1, month1, year1);
        }else
        {
            daysBetween += 366 - dateDifference(1,1,year1, day1, month1, year1);
        }
        year1++;
        while(year1<year2)
        {
            if(isLeap(year1) == false)
            {
                daysBetween += 365;
            }else{
                daysBetween += 366;
            }
            year1++;
        }
        daysBetween += dateDifference(1,1,year2, day2, month2, year2);
        return daysBetween;
    }
}

// task 2
double averageOfArray(int arr[], int size)
{
    double average = 0;
    double summ=0;
    for(int i = 0; i < size; i++)
    {
        summ += arr[i]; 
    }
    average = (double)summ / size;
    return average;
}

//task 3

void arrayInfo(int arr[], int size)
{
    int positives = 0;
    int negatives = 0;
    int zeros = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 0)
        {
            zeros++;
        }else if(arr[i] > 0)
        {
            positives++;
        }else
        {
            negatives++;
        }
    }
    cout << "In this array number of positives ->\t" << positives << "\n"
         << " number of negatives ->\t" << negatives << "\n"
         << " number of zeros ->\t" << zeros << "\n";
}

