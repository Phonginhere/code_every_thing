#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int day, month, year, ndays, leapdays;
    bool leapyear;
    int main () {
        day = 31;
        month = 12;
        year = 2010;
        ndays = day + 1;
        leapyear = false;
        printf ("Enter a date in the form day month year: %d %d %d \n", day, month, year);
        if (year % 4 == 0) {
            leapyear = true;
        }
        if (year % 100 == 0) {
            leapyear = false;
        }
        if (year % 400 == 0) {
            leapyear = true;
        }
        if ((leapyear) && (month == 12 || month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 )) {
            leapdays = 31;
        }
        if ((leapyear) && (month == 4 || month == 6 || month == 9 || month == 11 )) {
            leapdays = 30;
        }
        if ((leapyear) && (month == 2 )) {
            leapdays = 29;
        } else if (leapyear == false) {
            leapdays = 28;
        }
        if ((leapdays == 31) && (day == 31)) {
            ndays = 1;
            month = month + 1;
        }else if ((leapdays == 30) && (day == 30)) {
                    ndays = 1;
                    month = month + 1;

        }else if ((leapdays == 29) && (day == 29)) {
                        ndays = 1;
                     month = month + 1;
        }else if ((leapdays == 28) && (day == 28)) {
                    ndays = 1;
                    month = month + 1;
        }else if ((month == 12) && (day == 31)) {
                   ndays = 1;
                    month = 1;
                   year = year + 1;
        }


        printf ("The date of the next day is: %d/%d/%d", ndays, month, year);
    }
	return 0;
}
