#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define max 6
#define min 0

int i, val, sum1=0, sum2=0, sum3=0, sum4=0, total, turn;
char player1[30], player2[30], player3[30], player4[30];
time_t t;

void single_player()
{
    int count=0;

    while(1)
    {
        printf("Enter Player name: ");
        scanf("%s", player1);

        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            if(sum1>=total && sum1>sum2)
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);
                printf("COMPUTER's score = %d. So, COMPUTER gain last position\n\n\n", sum2);

                sum1=0, sum2=0;
                break;
            }
            else if(sum1 == sum2)
            {
                printf("COMPUTER's score = %d & %s's score = %d. So, the game is tie\n", sum2, player1, sum1);
                sum1=0, sum2=0;
                break;
            }
            else
            {
                printf("COMPUTER's score = %d. So, COMPUTER gain first position\n", sum2);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                sum1=0, sum2=0;
                break;
            }
        }

        if(count%2==0)
        {
            printf("\n%s's turn now\n", player1);
            printf("Press 5 to show your score or\nPress 1 for your turn\n");
            scanf("%d", &turn);

            if(turn ==1)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\n\tYour point: %d\n", val);

                count++;

                if(val == 0)
                {
                    sum1--;
                }

                if(val == 6)
                {
                    sum1 = sum1 + val;
                    count--;

                    if(sum1<total)
                    {
                        printf("\tYou got a bonus turn!\n");
                    }
                }
                else
                {
                    sum1 = sum1 + val;
                }
            }

            else if(turn == 5)
            {
                printf("\n\t%s's scoreboard: %d\n", player1, sum1);
            }

            else
            {
                continue;
            }
        }

        else if(count%2!=0)
        {
            printf("\nCOMPUTER's turn now");
            count++;

            srand((unsigned) time(&t));
            val = (rand() % (max - min)) + min;
            printf("\n\tCOMPUTER's point: %d\n", val);

            if(val == 0)
            {
                sum2--;
            }
            else if(val == 6)
            {
                sum2 = sum2 + val;
                count++;

                if(sum2<total)
                {
                    printf("\tCOMPUTER got a bonus turn!\n");
                }
            }
            else
            {
                sum2 = sum2 + val;
            }
        }
    }
}

void double_palyer()
{
    int count=0;

    while(1)
    {
        printf("Enter Player1 name: ");
        scanf("%s", player1);

        printf("Enter Player2 name: ");
        scanf("%s", player2);

        if(strcmp(player1, player2)==0)
        {
            printf("\nEvery players should be a different name.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            if(sum1>=total && sum1>sum2)
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);

                sum1=0, sum2=0;
                break;
            }
            else if (sum1 == sum2)
            {
                printf("%s's score = %d & %s's score = %d. So, the game is tied!\n", player1, sum1, player2, sum2);

                sum1=0, sum2=0;
                break;
            }
            else
            {
                printf("%s's score = %d. So, %s gain first position\n", player2, sum2, player2);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                sum1=0, sum2=0;
                break;
            }
        }

        if(count%2==0)
        {
            printf("\n%s's turn now\n", player1);
            printf("Press 5 to show your score or\nPress 1 for your turn\n");
            scanf("%d", &turn);

            if(turn ==1)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\n\tYour point: %d\n", val);

                count++;

                if(val == 0)
                {
                    sum1--;
                }
                if(val == 6)
                {
                    sum1 = sum1 + val;
                    count--;

                    if(sum1<total)
                    {
                        printf("\tYou got a bonus turn!\n");
                    }
                }
                else
                {
                    sum1 = sum1 + val;
                }
            }
            else if(turn == 5)
            {
                printf("\n\t%s's scoreboard: %d\n", player1, sum1);
            }
        }
        else
        {
            printf("\n%s's turn now\n", player2);
            printf("Press 5 to show your score or\nPress 2 for your turn\n");
            scanf("%d", &turn);

            if(turn ==2)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\n\tYour point: %d\n", val);

                count++;

                if(val == 0)
                {
                    sum2--;
                }
                if(val == 6)
                {
                    sum2 = sum2 + val;
                    count--;

                    if(sum2<total)
                    {
                        printf("\tYou got a bonus turn!\n");
                    }
                }
                else
                {
                    sum2 = sum2 + val;
                }
            }
            else if(turn == 5)
            {
                printf("\n\t%s's scoreboard: %d\n", player2, sum2);
            }
        }
    }
}

void three_palyer()
{
    int count=0;

    while(1)
    {
        printf("Enter Player1 name: ");
        scanf("%s", player1);

        printf("Enter Player2 name: ");
        scanf("%s", player2);

        printf("Enter Player3 name: ");
        scanf("%s", player3);

        if((strcmp(player1, player2)==0) || (strcmp(player2, player3)==0) || (strcmp(player3, player1)==0))
        {
            printf("\nEvery players should be a different name.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total || sum3>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            if(sum1>=total && (sum1>sum2 && sum1>sum3))
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);

                if(sum2>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else if(sum2 == sum3)
                {
                    printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);

                    sum1=0, sum2=0, sum3=0;
                }
                break;
            }

            else if(sum2 >= total && (sum2>sum1 && sum2>sum3))
            {
                printf("%s's score = %d. So, %s gain first position\n", player2, sum2, player2);

                if(sum1>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else if(sum1 == sum3)
                {
                    printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player3, sum3, player1, player3);

                    sum1=0, sum2=0, sum3=0;
                }
                else
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                    sum1=0, sum2=0, sum3=0;
                }

                break;
            }

            else if(sum3 >= total && (sum3>sum1 && sum3>sum2))
            {
                printf("%s's score = %d. So, %s gain first position\n", player3, sum3, player3);

                if(sum1>sum2)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);

                    sum1=0, sum2=0, sum3=0;
                }
                else if(sum1 == sum2)
                {
                    printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player2, sum2, player1, player2);

                    sum1=0, sum2=0, sum3=0;
                }
                else
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                    printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                    sum1=0, sum2=0, sum3=0;
                }
                break;
            }

            else if((sum1==sum2) && (sum1==sum3) && (sum2==sum3))
            {
                printf("%s's score = %d & %s's score = %d & %s's score = %d. So, The game is tied\n\n\n", player1, sum1, player2, sum2, player3, sum3);
                sum1=0, sum2=0, sum3=0;
                break;
            }
        }

        while(1)
        {
            if(count%2==0)
            {
                printf("\n%s's turn now\n", player1);
                printf("Press 5 to show your score or\nPress 1 for your turn\n");
                scanf("%d", &turn);

                if(turn ==1)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    count++;

                    if(val == 0)
                    {
                        sum1--;
                    }
                    if(val == 6)
                    {
                        sum1 = sum1 + val;
                        count--;

                        if(sum1<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum1 = sum1 + val;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player1, sum1);
                }
            }
            else if(count%2!=0)
            {
                printf("\n%s's turn now\n", player2);
                printf("Press 5 to show your score or\nPress 2 for your turn\n");
                scanf("%d", &turn);

                if(turn ==2)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum2--;
                    }
                    if(val == 6)
                    {
                        sum2 = sum2 + val;

                        if(sum2<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum2 = sum2 + val;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player2, sum2);
                }
            }
        }

        while(1)
        {
            if(count%2!=0)
            {
                printf("\n%s's turn now\n", player3);
                printf("Press 5 to show your score or\nPress 3 for your turn\n");
                scanf("%d", &turn);

                if(turn == 3)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum3--;
                    }
                    if(val == 6)
                    {
                        sum3 = sum3 + val;

                        if(sum3<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum3 = sum3 + val;
                        count++;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player3, sum3);
                }
            }
        }
    }
}

void four_player()
{
    int count=0;

    while(1)
    {
        printf("Enter Player1 name: ");
        scanf("%s", player1);

        printf("Enter Player2 name: ");
        scanf("%s", player2);

        printf("Enter Player3 name: ");
        scanf("%s", player3);

        printf("Enter Player4 name: ");
        scanf("%s", player4);

        if((strcmp(player1, player2)==0) || (strcmp(player1, player3)==0) || (strcmp(player1, player4)==0) || (strcmp(player2, player3)==0)|| (strcmp(player2, player4)==0)|| (strcmp(player3, player4)==0))
        {
            printf("\nEvery players should be a different name.\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total <= 0)
        {
            printf("\n\tTotal number cann't be less than or equal to Zero (0).\n");
            continue;
        }
        else
        {
            break;
        }
    }

    while(1)
    {
        if(sum1>=total || sum2>=total || sum3>=total || sum4>=total)
        {
            printf("\n\n\t\tGame over!!\n\t\t-----------\n");

            //for sum1 greater
            if(sum1 >= total && (sum1>sum2 && sum1>sum3 && sum1>sum4))
            {
                printf("%s's score = %d. So, %s gain first position\n", player1, sum1, player1);

                if(sum2>sum3 && sum2>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);

                    if(sum3>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum3>sum2 && sum3>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);

                    if(sum2>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum4>sum2 && sum4>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);

                    if(sum3>sum2)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }

                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2==sum3 && sum2==sum4 && sum3==sum4)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player2, sum2, player3, sum3, player4, sum4, player2, player3, player4);
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2==sum3 || sum2==sum4 || sum3==sum4)
                {
                    if(sum2==sum3)
                    {
                        if(sum4>sum2 && sum4>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player3, sum3, player2, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                        }
                    }
                    else if(sum3==sum4)
                    {
                        if(sum2>sum3 && sum2>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player3, sum3, player4, sum4, player3, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player3, sum3, player4, sum4, player3, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum2==sum4)
                    {
                        if(sum3>sum2 && sum3>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player4, sum4, player2, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player4, sum4, player2, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            //2nd
            else if(sum2 >= total && (sum2>sum1 && sum2>sum3 && sum2>sum4))
            {
                printf("%s's score = %d. So, %s gain first position\n", player2, sum2, player2);

                if(sum1>sum3 && sum1>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);

                    if(sum3>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum3>sum1 && sum3>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);

                    if(sum1>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum4>sum1 && sum4>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);

                    if(sum3>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }

                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum3 && sum1==sum4 && sum3==sum4)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player1, sum1, player3, sum3, player4, sum4, player1, player3, player4);
                }

                else if(sum1==sum3 || sum1==sum4 || sum3==sum4)
                {
                    if(sum1==sum3)
                    {
                        if(sum4>sum1 && sum4>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player3, sum3, player1, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                        }
                    }
                    else if(sum3==sum4)
                    {
                        if(sum2>sum3 && sum2>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player3, sum3, player4, sum4, player3, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player3, sum3, player4, sum4, player3, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum1==sum4)
                    {
                        if(sum3>sum1 && sum3>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player4, sum4, player1, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player4, sum4, player1, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            //3rd
            else if(sum3 >= total && (sum3>sum1 && sum3>sum2 && sum3>sum4))
            {
                printf("%s's score = %d. So, %s gain first position\n", player3, sum3, player3);

                if(sum1>sum2 && sum1>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);

                    if(sum2>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2>sum1 && sum2>sum4)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);

                    if(sum1>sum4)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player4, sum4, player4);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum4>sum1 && sum4>sum2)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);

                    if(sum2>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 && sum1==sum4 && sum2==sum4)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player4, sum4, player1, player2, player4);
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 || sum1==sum4 || sum2==sum4)
                {
                    if(sum1==sum2)
                    {
                        if(sum4>sum1 && sum4>sum2)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player4, sum4, player4);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player1, player2);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player2, sum2, player1, player2);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player4, sum4, player4);
                        }
                    }
                    else if(sum1==sum4)
                    {
                        if(sum2>sum1 && sum2>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player4, sum4, player1, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player4, sum4, player1, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum2==sum4)
                    {
                        if(sum1>sum2 && sum1>sum4)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player4, sum4, player2, player4);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player4, sum4, player2, player4);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            //4th
            else if(sum4 >= total && (sum4>sum1 && sum4>sum2 && sum4>sum3))
            {
                printf("%s's score = %d. So, %s gain first position\n", player4, sum4, player4);

                if(sum1>sum3 && sum1>sum2)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);

                    if(sum2>sum3)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum2>sum1 && sum2>sum3)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);

                    if(sum3>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player3, sum3, player3);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum3>sum2 && sum3>sum1)
                {
                    printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);

                    if(sum2>sum1)
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player2, sum2, player2);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                    }
                    else
                    {
                        printf("%s's score = %d. So, %s gain third position\n", player1, sum1, player1);
                        printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 && sum1==sum3 && sum2==sum3)
                {
                    printf("%s's score = %d, %s's score = %d & %s's score = %d. So, %s, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player3, sum3, player1, player2, player3);
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }

                else if(sum1==sum2 || sum1==sum3 || sum2==sum3)
                {
                    if(sum1==sum2)
                    {
                        if(sum3>sum1 && sum3>sum2)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player3, sum3, player3);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player2, sum2, player1, player2);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player2, sum2, player1, player2);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player3, sum3, player3);
                        }
                    }
                    else if(sum1==sum3)
                    {
                        if(sum2>sum1 && sum2>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player2, sum2, player2);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player1, sum1, player3, sum3, player1, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player1, sum1, player3, sum3, player1, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player2, sum2, player2);
                        }
                    }
                    else if(sum2==sum3)
                    {
                        if(sum1>sum2 && sum1>sum3)
                        {
                            printf("%s's score = %d. So, %s gain second position\n", player1, sum1, player1);
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n\n\n", player2, sum2, player3, sum3, player2, player3);
                        }
                        else
                        {
                            printf("%s's score = %d && %s's score = %d. So, %s & %s are tied!\n", player2, sum2, player3, sum3, player2, player3);
                            printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);
                        }
                    }
                    sum1=0, sum2=0, sum3=0, sum4=0;
                }
                break;
            }

            else if(sum1==sum2 && sum1==sum3 && sum1==sum4 && sum2==sum3 && sum3==sum4 && sum2==sum4)
            {
                printf("%s's score = %d & %s's score = %d & %s's score = %d & %s's score = %d. So, The game is tied\n\n\n", player1, sum1, player2, sum2, player3, sum3, player4, sum4);

                sum1=0, sum2=0, sum3=0, sum4=0;
                break;
            }
        }

        while(1)
        {
            if(count%2==0)
            {
                printf("\n%s's turn now\n", player1);
                printf("Press 5 to show your score or\nPress 1 for your turn\n");
                scanf("%d", &turn);

                if(turn ==1)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    count++;

                    if(val == 0)
                    {
                        sum1--;
                    }
                    if(val == 6)
                    {
                        sum1 = sum1 + val;

                        if(sum1<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                        count--;
                    }
                    else
                    {
                        sum1 = sum1 + val;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player1, sum1);
                }
            }
            else if(count%2!=0)
            {
                printf("\n%s's turn now\n", player2);
                printf("Press 5 to show your score or\nPress 2 for your turn\n");
                scanf("%d", &turn);

                if(turn ==2)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum2--;
                    }
                    if(val == 6)
                    {
                        sum2 = sum2 + val;

                        if(sum2<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum2 = sum2 + val;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player2, sum2);
                }
            }
        }

        while(1)
        {
            if(count%2!=0)
            {
                printf("\n%s's turn now\n", player3);
                printf("Press 5 to show your score or\nPress 3 for your turn\n");
                scanf("%d", &turn);

                if(turn == 3)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    count++;

                    if(val == 0)
                    {
                        sum3--;
                    }
                    if(val == 6)
                    {
                        sum3 = sum3 + val;

                        if(sum3<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                        count--;
                    }
                    else
                    {
                        sum3 = sum3 + val;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player3, sum3);
                }
            }
            else if(count%2==0)
            {
                printf("\n%s's turn now\n", player4);
                printf("Press 5 to show your score or\nPress 4 for your turn\n");
                scanf("%d", &turn);

                if(turn == 4)
                {
                    srand((unsigned) time(&t));
                    val = (rand() % (max + 1 - min)) + min;
                    printf("\n\tYour point: %d\n", val);

                    if(val == 0)
                    {
                        sum4--;
                    }
                    if(val == 6)
                    {
                        sum4 = sum4 + val;

                        if(sum4<total)
                        {
                            printf("\tYou got a bonus turn!\n");
                        }
                    }
                    else
                    {
                        sum4 = sum4 + val;
                        break;
                    }
                }
                else if(turn == 5)
                {
                    printf("\n\t%s's scoreboard: %d\n", player4, sum4);
                }
            }
        }
    }
}

void game_rules()
{
    printf("\t\t\t\t Rules of LUDU game\n\t\t\t\t--------------------\n#Rule :If a player point becomes 1/2/3/4/5 so, this point will be added to that particular player's scoreboard.\n#Rule : If your point becomes 6 then this 6 point be added to your scoreboard and also will get a bonus chance/turn.\n#Rule : If your point becomes 0 then your score decrease by one(that means -1) from your total score.\n#Rule : If any particular player score is greater than total number of score (that players were set at the begining) and all the players turn is finished then the game will automatic exit and automatic show the score and result of this game.\n#Rule: If two or more players score is equal then this two or more players result is tied when the game will be exit\n\n\n");
}

int main()
{
    int choice;
    puts("\t\t\tWelcome to LUDU game\n\t\t\t____________________\n");

    while(1)
    {
        puts("\t1. Single Player\n\t2. Double Player\n\t3. Three Player\n\t4. Four Player\n\t5. Game rules\n\t0. Exit\nSelect Your Option");
        scanf("%d", &choice);

        if(choice==1)
        {
            single_player();
        }
        else if(choice==2)
        {
            double_palyer();
        }
        else if(choice==3)
        {
            three_palyer();
        }
        else if(choice==4)
        {
            four_player();
        }
        else if(choice==5)
        {
            game_rules();
        }
        else if(choice==0)
        {
            char ch[10];
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
