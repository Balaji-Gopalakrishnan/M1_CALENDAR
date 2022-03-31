#include"calendar.h"

int main()
{
    int n_month,n_yr,ch;
    enteryear:
    while(1)
    {
        printf("Enter year and month(number):" );
        scanf("%d%d",&n_yr,&n_month);
        if(n_yr<1945)
        {
            
            printf("\n\t Please enter year above 1945\n");
            continue;
        }
        else
        {
            
            calendar(n_yr,n_month);
        }
        while(1)
        {
        gotoxy(20,20);printf("(*) Use LEFT, RIGHT, UP and DOWN arrow.");
        gotoxy(20,22);printf("(*) Press P to go to particular year and month.");
        gotoxy(20,24);printf("(*) Press ESC to Exit.");
        ch=getkey();
        switch(ch)
        {
        case 80: 
                if(n_month==12)
                {
                    
                     n_month=1;
                     n_yr++;
                }
                else
                {
                    n_month++;
                }
                calendar(n_yr,n_month);
                break;
        case 77:
            
                n_yr++;
                calendar(n_yr,n_month);
                break;
        case 72: 
                if(n_month==1)
                {
                    
                    n_yr--;
                    n_month=12;
                }
                else
                    n_month--;
                calendar(n_yr,n_month);
                break;
        case 75: 
            
                if(n_yr==1945)
                {
                    
                  gotoxy(15,2);printf("Year below 1945 not available");
                }
                else
                {
                    n_yr--;
                    calendar(n_yr,n_month);
                }

                break;
        case 27: 
           
                system("cls");
                gotoxy(50,14);printf("Exiting program.\n\n\n\n\n");
                exit(0);
        case 112:
            
                system("cls");
                goto enteryear;
        }
        }
        break;

    }
    getch();
    return 0;
}
