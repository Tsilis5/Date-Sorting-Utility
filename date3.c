#include <stdio.h>
#define MAX_SIZE 30           /* Define the Max size of dates that the user can enter*/

/* I Copied the code from part 2 to part 3 But the pieces that i didn't use i erased them.*/

struct date {                   /*I create a struct with 3 variables*/
    int day_s;
    int month_s;
    int year_s;
};
typedef struct date DateT;    /*In order not to write the struct all the time i called the typedef so i can call my struct by writing DateT*/


void Print_Array(DateT CLASSIFICATION_DATES[], int num_Dates) 
{
    int i;

    for (i = 0; i < num_Dates; i++) 
    {
        printf("%d/%d/%d\n", CLASSIFICATION_DATES[i].day_s, CLASSIFICATION_DATES[i].month_s, CLASSIFICATION_DATES[i].year_s);
    }
}


void SelectionSort(DateT CLASSIFICATION_DATES[], int num_Dates)               /*The sorting of the dates*/
{
    int k;
    DateT temp;
    int i = 0, j = 0;

    for (i = 0; i < num_Dates; i++)
    {
        k = i;
        for (j = i + 1; j < num_Dates; j++)
            if (CLASSIFICATION_DATES[j].day_s < CLASSIFICATION_DATES[k].day_s)             /*I do the sorting 3 times so it can be more correct*/
            {
                k = j;
                temp.day_s = CLASSIFICATION_DATES[i].day_s;
                temp.month_s = CLASSIFICATION_DATES[i].month_s;
                temp.year_s = CLASSIFICATION_DATES[i].year_s;

                CLASSIFICATION_DATES[i].day_s = CLASSIFICATION_DATES[k].day_s;
                CLASSIFICATION_DATES[i].month_s = CLASSIFICATION_DATES[k].month_s;
                CLASSIFICATION_DATES[i].year_s = CLASSIFICATION_DATES[k].year_s;

                CLASSIFICATION_DATES[k].day_s = temp.day_s;
                CLASSIFICATION_DATES[k].month_s = temp.month_s;
                CLASSIFICATION_DATES[k].year_s = temp.year_s;
            }

    }

    for (i = 0; i < num_Dates; i++)
    {
        k = i;
        for (j = i + 1; j < num_Dates; j++)
            if (CLASSIFICATION_DATES[j].month_s < CLASSIFICATION_DATES[k].month_s)
            {
                k = j;
                temp.day_s = CLASSIFICATION_DATES[i].day_s;
                temp.month_s = CLASSIFICATION_DATES[i].month_s;
                temp.year_s = CLASSIFICATION_DATES[i].year_s;

                CLASSIFICATION_DATES[i].day_s = CLASSIFICATION_DATES[k].day_s;
                CLASSIFICATION_DATES[i].month_s = CLASSIFICATION_DATES[k].month_s;
                CLASSIFICATION_DATES[i].year_s = CLASSIFICATION_DATES[k].year_s;

                CLASSIFICATION_DATES[k].day_s = temp.day_s;
                CLASSIFICATION_DATES[k].month_s = temp.month_s;
                CLASSIFICATION_DATES[k].year_s = temp.year_s;
            }


    }

    for (i = 0; i < num_Dates; i++)
    {
        k = i;
        for (j = i + 1; j < num_Dates; j++)
            if (CLASSIFICATION_DATES[j].year_s < CLASSIFICATION_DATES[k].year_s )
            {
                k = j;
                temp.day_s = CLASSIFICATION_DATES[i].day_s;
                temp.month_s = CLASSIFICATION_DATES[i].month_s;
                temp.year_s = CLASSIFICATION_DATES[i].year_s;

                CLASSIFICATION_DATES[i].day_s = CLASSIFICATION_DATES[k].day_s;
                CLASSIFICATION_DATES[i].month_s = CLASSIFICATION_DATES[k].month_s;
                CLASSIFICATION_DATES[i].year_s = CLASSIFICATION_DATES[k].year_s;

                CLASSIFICATION_DATES[k].day_s = temp.day_s;
                CLASSIFICATION_DATES[k].month_s = temp.month_s;
                CLASSIFICATION_DATES[k].year_s = temp.year_s;
            }


    }
    Print_Array(CLASSIFICATION_DATES, num_Dates);
}


void date1(int num_Dates)                                         /*I use the function form part 1 , 2 in order to receive the values*/
{

    int day = 0, month = 0, year = 0;
    char a, b;
    int flag = 0;
    DateT CLASSIFICATION_DATES[MAX_SIZE];


    while (flag <= num_Dates - 1)
    {


        while (1)
        {
            day = 0, month = 0, year = 0;


            scanf("%d%c%d%c%d", &day, &a, &month, &b, &year);

            if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1 && year <= 10000)
            {
                if (month == 2 && day <= 28)
                {
                    break;
                }
                else if (month == 4 || month == 6 || month == 9 || month == 11)
                {
                    if (day <= 30)
                    {
                        break;
                    }
                }
                else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    break;
                }
            }
        }

        CLASSIFICATION_DATES[flag].day_s = day;
        CLASSIFICATION_DATES[flag].month_s = month;
        CLASSIFICATION_DATES[flag].year_s = year;

        flag++;
    }




    SelectionSort(CLASSIFICATION_DATES, num_Dates);         /*I pass the values to the Selection sort function*/


}
int main()
{

    int num_Dates = 0;          /*I make it 0 so that the variable can't trash value that we dont won't. And it is safer, meaning that it wont cause troubles to the programm*/

    scanf("%d", &num_Dates); /*Give the dates that the user will enter*/

    date1(num_Dates);

    return(0);

}
