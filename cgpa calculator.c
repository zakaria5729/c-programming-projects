#include<stdio.h>

int main()
{
    double gpa, credit, cgpa=0, s_cgpa, s_credit=0;
    int choice;

    printf("\t\tCGPA CALCULATOR\n");
    printf("\t\t---------------\n\n");

    printf("\t1. Subject wise CGPA\n\t2. Semister wise CGPA\n\t3. Grade & credit wise CGPA\nEnter your choice:\n");
    scanf("%d", &choice);

    printf("\n");

    while(1)
    {
        if(choice==3)
        {
            printf("Enter your grade & credit (0 0 for Exit):\n");
            scanf("%lf%lf", &gpa, &credit);

            if(gpa==0 && credit==0)
            {
                break;
            }

            cgpa = cgpa + (gpa*credit);
            s_credit = s_credit + credit;

            s_cgpa = cgpa / s_credit;
        }
        else if(choice==2 || choice==1)
        {
            if(choice==2)
            {
                printf("Enter your Semister's GPA (0 for Exit):\n");
            }
            if(choice==1)
            {
                printf("Enter your Subject's GPA (0 for Exit):\n");
            }
            scanf("%lf", &gpa);

            if(gpa==0)
            {
                break;
            }

            cgpa = cgpa + gpa;
            s_credit++;

            s_cgpa = cgpa / s_credit;
        }
        else
        {
            break;
        }

    }
    if(choice==3)
    {
        printf("\n\tYour CGPA is: %.2lf\n\tAnd total credit: %.0lf\n", s_cgpa, s_credit);
    }
    else if(choice==2 || choice==1)
    {
        printf("\n\tYour CGPA is: %.2lf\n\tAnd total subject: %.0lf\n", s_cgpa, s_credit);
    }
    else
    {
        printf("Invalid choice\n");
    }


    return 0;
}
