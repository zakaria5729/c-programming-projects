#include<stdio.h>

int main()
{
    int b_day, b_month, b_year, p_day, p_month, p_year, c_day, c_month, c_year, res, choice;
    char ch[10];
    puts("\t\t\tAge Calculator\n\t\t\t--------------\n");

    while(1)
    {
        printf("\t1. Age calculation\n\t0. Exit\nEnter your choice\n");
        scanf("%d", &choice);

        if(choice==1)
        {
            printf("Enter your birth Day : Month : Year\n");
            scanf("%d%d%d", &b_day, &b_month, &b_year);

            printf("Enter present Day : Month : Year\n");
            scanf("%d%d%d", &p_day, &p_month, &p_year);

            c_day = p_day - b_day;
            c_month = p_month - b_month;
            c_year = p_year - b_year;

            if(b_day>31 || p_day>31 || b_month>12 || p_month>12 || (b_year > p_year))
            {
                if(b_day>31)
                {
                    printf("\nInvalid birth day input! Birth day is not more than 31");
                }
                else if(p_day>31)
                {
                    printf("\nInvalid present day input! Present day is not more than 31");
                }
                else if(b_month>12)
                {
                    printf("\nInvalid birth month input! Birth month is not more than 12");
                }
                else if(p_month>12)
                {
                    printf("\nInvalid present month input! Present month is not more than 12");
                }
                else if(b_day>31 && b_month>12)
                {
                    printf("\nInvalid birth day & month input! Birth day & month is not more than 31");
                }
                else if(p_day>31 && p_month>12)
                {
                    printf("\nInvalid present day & month input! Present day & month is not more than 31");
                }
                else if(b_day>31 && p_day>31)
                {
                    printf("\nInvalid birth & present day input! Birth & present day is not more than 31");
                }
                else if(b_month>12 && p_month>12)
                {
                    printf("\nInvalid birth & present month input! Birth & present month is not more than 12");
                }
                else if(b_day>31 && p_month>12)
                {
                    printf("\nInvalid birth day & present month input! Birth day & present month is not more than 31 & 12");
                }
                else if(b_day>31 && p_month>12)
                {
                    printf("\nInvalid birth day & present month input! Birth day & present month is not more than 31 & 12");
                }
                else if(b_month>31 && p_day>31)
                {
                    printf("\nInvalid birth month & present day input! Birth month & present day is not more than 12 & 31");
                }

                if(b_year > p_year)
                {
                    printf("\nInvalid birth year input! Birth year is not greater than Present year");
                }

                printf("\n\n");
                continue;
            }

            else
            {
                printf("\nYour age is\n");

                if((b_month==1 || b_month==3 || b_month==5 || b_month==7 || b_month==8 || b_month==10 || b_month==12) && (p_month==1 || p_month==3 || p_month==5 || p_month==7 || p_month==8 || p_month==10 || p_month==12))
                {
                    if((c_day>=0 && c_day<=31) && (c_month>=0 && c_month<=12))
                    {
                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day<0) && (c_month>=0 && c_month<=12))
                    {
                        res = (c_month*31) + c_day;
                        c_month = res / 31;
                        c_day = res % 31;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day>=0 && c_day<=31) && (c_month<0))
                    {
                        res = (c_year*12) + c_month;
                        c_year = res / 12;
                        c_month = res % 12;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day<0) && (c_month<0))
                    {
                        res = (c_year*12) + c_month;
                        c_year = res / 12;
                        c_month = res % 12;

                        res = (c_month*31) + c_day;
                        c_month = res / 31;
                        c_day = res % 31;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                }

                else if((b_month==4 || b_month==6 || b_month==9 || b_month==11) && (p_month==4 || p_month==6 || p_month==9 || p_month==11))
                {
                    if((c_day>=0 && c_day<=30) && (c_month>=0 && c_month<=12))
                    {
                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day<0) && (c_month>=0 && c_month<=12))
                    {
                        res = (c_month*30) + c_day;
                        c_month = res / 30;
                        c_day = res % 30;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day>=0 && c_day<=30) && (c_month<0))
                    {
                        res = (c_year*12) + c_month;
                        c_year = res / 12;
                        c_month = res % 12;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day<0) && (c_month<0))
                    {
                        res = (c_year*12) + c_month;
                        c_year = res / 12;
                        c_month = res % 12;

                        res = (c_month*30) + c_day;
                        c_month = res / 30;
                        c_day = res % 30;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                }

                //p=31 b=30
                else if((p_month==1 || p_month==3 || p_month==5 || p_month==7 || p_month==8 || p_month==10 || p_month==12) && (b_month==4 || b_month==6 || b_month==9 || b_month==11))
                {
                    if(c_day>=0 && (c_month>=0 && c_month<=12))
                    {
                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if(c_day<0 && (c_month>=0 && c_month<=12))
                    {
                        if(c_month==1 || c_month==3 || c_month==5 || c_month==7 || c_month==8 || c_month==10 || c_month==12)
                        {
                            res = (c_month*31) + c_day;
                            c_month = res / 31;
                            c_day = res % 31;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if(c_month==4 || c_month==6 || c_month==9 || c_month==11)
                        {
                            res = (c_month*30) + c_day;
                            c_month = res / 30;
                            c_day = res % 30;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                    }
                    else if(c_day>=0 && c_month<0)
                    {
                        res = (c_year*12) + c_month;
                        c_year = res / 12;
                        c_month = res % 12;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day<0) && (c_month<0))
                    {
                        if(c_month == -1 || c_month == -3 || c_month == -5 || c_month == -7 || c_month == -8 || c_month == -10 || c_month == -12)
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            res = (c_month*31) + c_day;
                            c_month = res / 31;
                            c_day = res % 31;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if(c_month == -4 || c_month == -6 || c_month == -9 || c_month == -11)
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            res = (c_month*30) + c_day;
                            c_month = res / 30;
                            c_day = res % 30;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                    }
                }

                //p=30 b=31
                else if((b_month==1 || b_month==3 || b_month==5 || b_month==7 || b_month==8 || b_month==10 || b_month==12) && (p_month==4 || p_month==6 || p_month==9 || p_month==11))
                {
                    if(c_day>=0 && (c_month>=0 && c_month<=12))
                    {
                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if(c_day<0 && (c_month>=0 && c_month<=12))
                    {
                        if(c_month==1 || c_month==3 || c_month==5 || c_month==7 || c_month==8 || c_month==10 || c_month==12)
                        {
                            res = (c_month*31) + c_day;
                            c_month = res / 31;
                            c_day = res % 31;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if(c_month==4 || c_month==6 || c_month==9 || c_month==11)
                        {
                            res = (c_month*30) + c_day;
                            c_month = res / 30;
                            c_day = res % 30;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                    }
                    else if(c_day>=0 && c_month<0)
                    {
                        res = (c_year*12) + c_month;
                        c_year = res / 12;
                        c_month = res % 12;

                        printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                    }
                    else if((c_day<0) && (c_month<0))
                    {
                        if(c_month == -1 || c_month == -3 || c_month == -5 || c_month == -7 || c_month == -8 || c_month == -10 || c_month == -12)
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            res = (c_month*31) + c_day;
                            c_month = res / 31;
                            c_day = res % 31;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if(c_month == -4 || c_month == -6 || c_month == -9 || c_month == -11)
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            res = (c_month*30) + c_day;
                            c_month = res / 30;
                            c_day = res % 30;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                    }
                }

                else if(b_month==2 || p_month==2)
                {
                    if(((b_year%4==0) && (b_year%100!=0 || b_year%400==0)) || ((p_year%4==0) && (p_year%100!=0 || p_year%400==0)))
                    {
                        if((c_day>=0 && c_day<=29) && (c_month>=0 && c_month<=12))
                        {
                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if((c_day<0) && (c_month>=0 && c_month<=12))
                        {
                            res = (c_month*29) + c_day;
                            c_month = res / 29;
                            c_day = res % 29;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if((c_day>=0 && c_day<=29) && (c_month<0))
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if((c_day<0) && (c_month<0))
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            res = (c_month*29) + c_day;
                            c_month = res / 29;
                            c_day = res % 29;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                    }

                    else
                    {
                        if((c_day>=0 && c_day<=28) && (c_month>=0 && c_month<=12))
                        {
                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if((c_day<0) && (c_month>=0 && c_month<=12))
                        {
                            res = (c_month*28) + c_day;
                            c_month = res / 28;
                            c_day = res % 28;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if((c_day>=0 && c_day<=28) && (c_month<0))
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                        else if((c_day<0) && (c_month<0))
                        {
                            res = (c_year*12) + c_month;
                            c_year = res / 12;
                            c_month = res % 12;

                            res = (c_month*28) + c_day;
                            c_month = res / 28;
                            c_day = res % 28;

                            printf("%d day : %d month : %d year\n\n", c_day, c_month, c_year);
                        }
                    }
                }
            }
        }

        else if(choice==0)
        {
            printf("Do you want to exit now (y/n)?\n");
            scanf("%s", ch);

            if(strcmp(ch, "n")==0)
            {
                continue;
            }
            else if(strcmp(ch, "y")==0)
            {
                break;
            }
        }

        else
        {
            printf("Invalid option selected! Try again..\n\n");
        }
    }

    return 0;
}

