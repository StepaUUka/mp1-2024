#pragma once
#include "Month.h"
#include<iostream>
using namespace std;

int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31 ,31 ,30 ,31 ,30 ,31 };

class Year
{
private:
    Month months[12];
    int startMonth;

public:
    Year()
    {
        startMonth = 0;
        for (int i = 0; i < 12; i++)
        {
            months[i].setMaxDays(daysInMonth[i]);
        }
    }

    ~Year() {}

    void setStartMonth(int month)
    {
        startMonth = month - 1;
    }

    unsigned getStartMonth()
    {
        return startMonth + 1;
    }

    double srednee(int month, int day)
    {
        return months[month - 1].srednee(day);
    }
    double srednee(int month, int day, int starthour, int hourend)
    {
        return months[month - 1].srednee(day, starthour, hourend);
    }
    void setNabludenie(int month, int day, int hour, double temp)
    {
        months[month - 1].setNabludenie(day, hour, temp);
    }

    double getNabludenie(int month, int day, int hour)
    {
        return months[month - 1].getNabludenie(day, hour);
    }
    int getMaxDays(int month)
    {
        return(months[month - 1].getMaxDays());
    }
    /*
    friend operator<< (stream)
    {
        for (i = 0; i < 12; i++)
        {
            stream << months[i];
        }
    }
    */
};