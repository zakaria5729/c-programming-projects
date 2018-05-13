#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define max 6
#define min 0

int i, val, sum1=0, sum2=0, total, turn, p_One=1, c_One=1, six=0;
char player1[30], player2[30];
time_t t;

void single_player()
{
    int count=0;

    printf("Enter Player name: ");
    scanf("%s", player1);

    while(1)
    {
        printf("Set the total number of score: ");
        scanf("%d", &total);

        if(total < 30)
        {
            printf("\n\t[N.B. Total number of score can not be less than thirty(30).]\n\n");
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

                sum1=0, sum2=0, six=0, p_One=1, c_One=1;
                break;
            }
            else if(sum1 == sum2)
            {
                printf("COMPUTER's score = %d & %s's score = %d. So, the game is tie\n", sum2, player1, sum1);
                sum1=0, sum2=0, six=0, p_One=1, c_One=1;
                break;
            }
            else
            {
                printf("COMPUTER's score = %d. So, COMPUTER gain first position\n", sum2);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                sum1=0, sum2=0, six=0, p_One=1, c_One=1;
                break;
            }
        }

        if(count%2==0)
        {
            printf("\n%s's turn now-->\n", player1);
            printf("Press 1 for your turn\n");
            scanf("%d", &turn);

            if(turn == 1)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\t%s's point: %d\n", player1, val);

                count++;

                if(val==1 && p_One==1)
                {
                    sum1 = sum1 + val;
                    p_One++;
                }

                else if(p_One != 1)
                {
                    if(val == 0)
                    {
                        sum1--;
                        six = 0;
                    }
                    else if(val == 6)
                    {
                        if(six == 3)
                        {
                            sum1 = sum1 - 18;
                            six = 0;
                            break;
                        }
                        else
                        {
                            sum1 = sum1 + val;
                        }
                        six++;
                        count--;

                        if(sum1<total)
                        {
                            printf("\t%s got a bonus turn!\n", player1);
                        }
                    }
                    else
                    {
                        sum1 = sum1 + val;
                        six = 0;
                    }
                }
            }
            else
            {
                continue;
            }
            printf("\t%s's Scoreboard: %d\n", player1, sum1);
        }

        else if(count%2!=0)
        {
            printf("\nCOMPUTER's turn now-->\n");
            count++;

            srand((unsigned) time(&t));
            val = (rand() % (max - min)) + min;
            printf("\tCOMPUTER's point: %d\n", val);

            if(val==1 && c_One==1)
            {
                sum2 += val;
                c_One++;
            }

            else if(c_One != 1)
            {
                if(val == 0)
                {
                    sum2--;
                    six = 0;
                }
                else if(val == 6)
                {
                    if(six == 3)
                    {
                        sum2 = sum2 - 18;
                        six = 0;
                        break;
                    }
                    else
                    {
                        sum2 = sum2 + val;
                    }
                    six++;
                    count++;

                    if(sum2<total)
                    {
                        printf("\tCOMPUTER got a bonus turn!\n");
                    }
                }
                else
                {
                    sum2 = sum2 + val;
                    six = 0;
                }
            }
            printf("\tCOMPUTER's Scoreboard: %d\n", sum2);
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
            printf("\n\t[N.B. Every players should be a different name.]\n\n");
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

        if(total < 30)
        {
            printf("\n\t[N.B. Total number of score can not be less than thirty(30).]\n\n");
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

                sum1=0, sum2=0, six=0, p_One=1, c_One=1;
                break;
            }
            else if (sum1 == sum2)
            {
                printf("%s's score = %d & %s's score = %d. So, the game is tied!\n", player1, sum1, player2, sum2);

                sum1=0, sum2=0, six=0, p_One=1, c_One=1;
                break;
            }
            else
            {
                printf("%s's score = %d. So, %s gain first position\n", player2, sum2, player2);
                printf("%s's score = %d. So, %s gain last position\n\n\n", player1, sum1, player1);

                sum1=0, sum2=0, six=0, p_One=1, c_One=1;
                break;
            }
        }

        if(count%2==0)
        {
            printf("\n%s's turn now-->\n", player1);
            printf("Press 1 for your turn\n");
            scanf("%d", &turn);

            if(turn == 1)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\t%s's point: %d\n", player1, val);

                count++;

                if(val==1 && p_One==1)
                {
                    sum1 = sum1 + val;
                    p_One++;
                }

                else if(p_One != 1)
                {
                    if(val == 0)
                    {
                        sum1--;
                        six = 0;
                    }
                    else if(val == 6)
                    {
                        if(six == 3)
                        {
                            sum1 = sum1 - 18;
                            six = 0;
                            break;
                        }
                        else
                        {
                            sum1 = sum1 + val;
                        }
                        six++;
                        count--;

                        if(sum1<total)
                        {
                            printf("\t%s got a bonus turn!\n", player1);
                        }
                    }
                    else
                    {
                        sum1 = sum1 + val;
                        six = 0;
                    }
                }
            }
            else
            {
                continue;
            }
            printf("\t%s's Scoreboard: %d\n", player1, sum1);
        }
        else
        {
            printf("\n%s's turn now-->\n", player2);
            printf("Press 2 for your turn\n");
            scanf("%d", &turn);

            if(turn == 2)
            {
                srand((unsigned) time(&t));
                val = (rand() % (max + 1 - min)) + min;
                printf("\t%s's point: %d\n", player2, val);

                count++;

                if(val==1 && c_One==1)
                {
                    sum2 = sum2 + val;
                    c_One++;
                }

                else if(c_One != 1)
                {
                    if(val == 0)
                    {
                        sum2--;
                        six = 0;
                    }
                    else if(val == 6)
                    {
                        if(six == 3)
                        {
                            sum2 = sum2 - 18;
                            six = 0;
                            break;
                        }
                        else
                        {
                            sum2 = sum2 + val;
                        }
                        six++;
                        count--;

                        if(sum2<total)
                        {
                            printf("\t%s got a bonus turn!\n", player2);
                        }
                    }
                    else
                    {
                        sum2 = sum2 + val;
                        six = 0;
                    }
                }
            }
            else
            {
                continue;
            }
            printf("\t%s's Scoreboard: %d\n", player2, sum2);
        }
    }
}

void game_rules()
{
    printf("\t\t\t\t Rules of LUDU game\n\t\t\t\t--------------------\n#Rule :If a player point becomes 1/2/3/4/5 so, this point will be added to that particular player's scoreboard.\n#Rule : If your point becomes 6 then this 6 point be added to your scoreboard and also will get a bonus chance/turn.\n#Rule : If your point becomes 0 then your score decrease by one(that means -1) from your total score.\n#Rule : If any particular player score is greater than total number of score (that players were set at the beginning) and all the players turn is finished then the game will automatic exit and automatic show the score and result of this game.\n#Rule: If two or more players score is equal then this two or more players result is tied when the game will be exit\n\n\n");
}

int main()
{
    int choice;
    puts("\t\t\tWelcome to LUDO (Snack-Ladder) game\n\t\t\t___________________________________\n");

    while(1)
    {
        puts("\t1. Single Player\n\t2. Double Player\n\t5. Game rules\n\t0. Exit\nSelect Your Choice");
        scanf("%d", &choice);

        if(choice==1)
        {
            single_player();
        }
        else if(choice==2)
        {
            double_palyer();
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
