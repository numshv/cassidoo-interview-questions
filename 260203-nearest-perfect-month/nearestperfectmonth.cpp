#include <bits/stdc++.h>
using namespace std;

// ASSUMPTIONS
// 
// - I use the definition of perfect month that's on its wikipedia which states that
//   it's gotta be in Feb, in non leap year, and the 1st feb starts on either sunday or monday
//   depends on each person's first day on their own calendar
// 
// - I made an assumption that the date input from user will always be the first of january of that year
//   which means, if a user put 2026 as the input, I'll assume it's the 1st January of 2026
//   making the next perfect month will be 02-2026 and the prev one will be 2015-02 (if we use sunday)

int firstDayOfCalendar = 0; // default = sunday

// sakamoto algo's to find the day of the week of a certain date
int getDayOfTheWeek(int y, int m, int d){

    int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

    if(m < 3){
        y -= 1;
    }

    // sunday: 0 ; monday: 1 ; and so on ...
    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);

}

bool isLeapYear(int year){
    return(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

void nearestPerfectMonth(int year){
    int prev = -1;
    int next = -1;
    bool foundPrev = false;
    bool foundNext = false;
    int i = 0;

    while(!(foundPrev && foundNext)){

        if(!foundPrev && !isLeapYear(year - i -1) && getDayOfTheWeek((year - i -1), 2, 1) == firstDayOfCalendar){
            prev = year - i -1;
            foundPrev =true;
        }

        if(!foundNext && !isLeapYear(year + i) && getDayOfTheWeek((year + i), 2, 1) == firstDayOfCalendar){
            next = year + i;
            foundNext = true;
        }

        i++;
    }

    cout << "> { prev: \"" << prev << "-02\", next: \"" << next << "-02\" }";

}

int main(){
    int year;
    string firstDay;
    cout << "Enter the first day on your calendar (monday/sunday): ";
    cin >> firstDay;
    transform(firstDay.begin(), firstDay.end(), firstDay.begin(), ::tolower);
    if(firstDay == "monday"){
        firstDayOfCalendar = 1;
    }
    else if(firstDay == "sunday"){
        firstDayOfCalendar = 0;
    }
    else{
        cerr << "invalid first day of calendar, defaulted into sunday\n";
    }

    cout << "Enter the year: ";
    cin >> year;
    nearestPerfectMonth(year);

    return 0;
}