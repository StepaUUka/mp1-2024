#include "Year.h"
#include "Month.h"
#include "Data.h"
using namespace std;
int getMonth()
{
    int mo = 0;
    do 
    {
        cout << "Enter month" << endl;
        cin >> mo;
    } while (mo > 12 || mo < 1);
    return mo;
}
int getDay( int month)
{
    int d = 0;
    do
    {
        cout << "Enter day" << endl;
        cin >> d;
    } while (d < 1 || d > daysInMonth[month - 1]);
    return d;
}
int getHour()
{   int h;
    do
    {
        cout << "Enter hour" << endl;
        cin >> h;
    } while (h < 0 || h > 23);
    return h;

}

int main()
{
    Year year;
    int ok = -1;

    while(ok!=0)
    {
        cout << "1. Start month" << endl;
        cout << "2. setNabludenie" << endl;
        cout << "3. getNabludenie" << endl;
        cout << "4. year.srednee" << endl;
        cout << "5. year.srednee.period" << endl;
        cout << "6. getStartMonth" << endl;
        cout << "0. exit" << endl;
        cin >> ok;
        while (ok < 0 || ok >6)
        {
            cout << "" << endl;
            cin >> ok;
        }
        switch (ok)
        {
        case 1:
        {
            int m = getMonth();
            year.setStartMonth(m);
            break;
        }
        case 2:
        {
            int mo = getMonth();
            int d = getDay(mo);
            int h = getHour();
            cout << "Enter temperature" << endl;
            double t;
            cin >> t;
            year.setNabludenie(mo, d, h, t);
            break;
        }
        case 3:
        {
            int mo = getMonth();
            int d = getDay(mo);
            int h = getHour();
            double t = year.getNabludenie(mo, d, h);
            if (t == -1000)
            {
                cout << "No nabludenie" << endl;
                break;
            }
            cout << t << endl;
            break;
            }
        case 4:
        {
            double sum;
            int mo = getMonth();
            int d = getDay(mo);
            sum = year.srednee(mo, d);
            cout << sum<<endl;
            break;
        }
        case 5:
        {
            int mo = getMonth();
            int d = getDay(mo);
            cout << "Enter start hour" << endl;
            int h1 = getHour();
            cout << "Enter end hour" << endl;
            int h2 = getHour();
            double t = year.srednee( mo,  d,  h1,  h2);
            if (t == -1000)
            {
                cout << "No nabludenie" << endl;
                break;
            }
            cout << t << endl;
            break;
        }
        case 6:
        {
            cout<<year.getStartMonth()<<endl;
            break;
        }
        };
        //cout << year.getMaxDays(3)<<endl;
    }
    /*
    year.setStartMonth(2);
    year.setNabludenie(2, 24, 2, 37.7);
    year.setNabludenie(2, 24, 3, 38);
    year.setNabludenie(2, 24, 12, -10);
    double sum = year.srednee(2, 24);
    int m = year.getStartMonth();
    cout << sum<<endl;
    cout << m<<endl;
    double t = year.getNabludenie(2, 24, 2);
    cout << t;
    /*std::fostream file(name);
    file << year;

    std::fistream file(name);
    file >> year;
    */
}

