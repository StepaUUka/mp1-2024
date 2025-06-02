#pragma once
#include "Data.h"
#include<iostream>
using namespace std;
class Month
{
private:
    Data days[31];
    unsigned maxDays;

    unsigned startDay;

public:
    Month() {}

    ~Month() {}

    void setMaxDays(int days)
    {
        maxDays = days;
    }

    void setStartDay(int day)
    {
        startDay = day - 1;
    }

    int getStartDay(int day)
    {
        return startDay + 1;
    }

    int getMaxDays() const
    {
        return maxDays;
    }

    double srednee(int day)
    {
        return days[day - 1].srednee();
    }
    double srednee(int day, int starthour, int hourend)
    {
        return days[day - 1].srednee(starthour,hourend);
    }
    void setNabludenie(int day, int hour, double temp)
    {
            days[day - 1].setNabludenie(hour, temp);
    }

    double getNabludenie(int day, int hour)
    {
        return days[day - 1].getNabludenie(hour);
    }
    /*
    friend operator<< (stream)
    {
        for (i = 0; i < maxDays; i++)
        {
            stream << days[i];
        }
    }
       */

};