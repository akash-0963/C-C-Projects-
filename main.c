#include <stdio.h>
#include <stdlib.h>

int weekday_1(int year){

    int day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;

}

int main()
{
    system("Color 3F");
    int Year,month,days,weekdays,startday;
    printf("ENTER THE DESIRED YEAR OF CALENDER: \n");
    scanf("%d",&Year);



    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31};

    startday=weekday_1(Year);

    if(  (Year%4==0  &&  Year%100!=0 ) || Year%400==0 )
        monthday[1]=29;

    for(month=0;month<12;month++){
        printf("\n\n\n-----------------%s-----------------",months[month]);
        printf("\n\n  Sun  Mon   Tue  Wed  Thu  Fri  Sat\n");

        for(weekdays=0;weekdays<startday;weekdays++){
            printf("     ");
        }

        for(days=1; days<=monthday[month];days++){
            printf("%5d",days);



            if(++weekdays>6){
                printf("\n");
                weekdays=0;
            }

            startday=weekdays;

        }
    }
    return 0;
}
