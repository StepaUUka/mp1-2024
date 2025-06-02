#pragma once
#include<iostream>
using namespace std;
class Data
{
private:
    const double None = -1000;
    double hours[24] = { None,  None,  None, None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None,  None}; // наблюдения по часам

    int startHour;

public:
    Data() {}
    ~Data() {}

    void set(int hour, double temp)
    {
        hours[hour] = temp;
    }

    double get(int hour)
    {
        return hours[hour];
    }

    double srednee()// 24!!!
    {
        int k = 0;
        double sum = 0;
        for (int i = 0; i < 24; i++)
        {
            if (hours[i] != None)
            {
                sum += hours[i];
                k++;
            }
        }

        return (sum / k);
    }

    double srednee(int hourStart, int hourEnd)
    {
        double sum = 0;
        for (int i = hourStart; i < hourEnd; i++)
        {
            sum += hours[i];
        }

        return (sum / (hourEnd - hourStart));
    }

    void setNabludenie(int hour, double temp)
    {
        hours[hour] = temp;
    }

    double getNabludenie(int hour)
    {
        return hours[hour];
    }
    /*
        friend operator<< (stream)
        {
            for (i = 0; i < 24; i++)
            {
                stream << hours[i];
            }
        }
    */
};