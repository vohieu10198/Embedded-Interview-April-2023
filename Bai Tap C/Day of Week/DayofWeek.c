/*
* File Name: DayofWeek.c
* Author: VO MINH HIEU
* Date: 02/06/2023
* Description: This file is used for finding the day of week from given date
*/

#include <stdio.h>

/*
 * function: checkInput
 * Discription: this function is used for checking input day
 * input: 
 *  int - day
 *  int - month
 *  int - year
 * return : 0 - invalid, 1 - valid
 */

int checkInput(int day, int month, int year)
{
    //check year 
    if (year >= 1 && year <= 2999) {
        //check month 
        if (month >= 1 && month <= 12) {
            //check day 
            if (day >= 1 && day <= 31) {
                if ((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
                    return 1; //valid date
                else if ((day >= 1 && day <= 30) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
                    return 1; //valid date
                else if ((day >= 1 && day <= 28) && (month == 2))
                    return 1; //valid date
                else if (day == 29 && month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) // leap year
                    return 1; //valid date
                else
                    return 0; //invalid day
            }
            else {
                return 0; //invalid day
            }
        }
        else {
            return 0; //invalid month
        }
    }
    else {
        return 0; //invalid year
    }
}

/*
 * function: weekDay
 * Discription: This function will return week day number from 0 to 6
 * input: 
 *  int - day
 *  int - month
 *  int - year
 * return : 0 - invalid, 1 - valid
 */

int weekDay(int year, int month, int day)
{
    int weekDay = 0;
    weekDay = (day + ((153 * (month + 12 * ((14 - month) / 12) - 3) + 2) / 5)
               + (365 * (year + 4800 - ((14 - month) / 12)))
               + ((year + 4800 - ((14 - month) / 12)) / 4)
               - ((year + 4800 - ((14 - month) / 12)) / 100)
               + ((year + 4800 - ((14 - month) / 12)) / 400)
               - 32045)
        % 7;  //Julian Day Calculation 
    return weekDay;
}

/*
 * function: findDayOfWeekint
 * Discription: This function will name of the day
 * input: 
 *  int - day
 *  int - month
 *  int - year
 * return :
 *  None
 */

void findDayOfWeekint(int day, int month, int year){
    int weekDayNo = 0;
    char dayNames[][12] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    if (checkInput(day, month, year) == 1) {
        printf("Date is correct [%02d/%02d/%02d].\n", day, month, year);
        //get weekday number
        weekDayNo = weekDay(year, month, day);
        //print weekday according to wDayNo
        printf("week day is: %s\n", dayNames[weekDayNo]);
    }
    else
        printf("Date is in-correct.\n");
}

int main()
{
    int day, month, year;
    
    printf("Input date (DD-MM-YYYY): ");
    scanf("%d-%d-%d", &day, &month, &year);

    findDayOfWeekint(day, month, year);


    return 0;
}
