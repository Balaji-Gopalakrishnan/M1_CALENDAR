#include<stdio.h>
#include<conio.h>
#include<windows.h>

int getkey();
void display(int,int,int,int[]);
void calendar(int,int);

//--- GOTO function definition ---
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//--- CHANGE COLOR ---
void SetColor(int ForgC)
{
     WORD wColor;
                          
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

                           
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                    
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


char *month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
char *week[]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

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


//  === DISPLAYING THE  CALENDAR ===
void display(int n_yr,int n_month,int t_days,int days[])
{
    int i,j,pos;
    SetColor(12); 
    gotoxy(56,6);printf("%s %d",month[n_month-1],n_yr); 
    for(i=0,pos=30;i<7;i++,pos+=10)
    {
         if(i==6)
            SetColor(9); 
         else
            SetColor(10); 
        gotoxy(pos,8);printf("%s",week[i]);
    }

    SetColor(15); 

   t_days++; 
    if(t_days==0 || t_days==7)
        pos=91; 
    if(t_days==1)
        pos=31; 
    if(t_days==2)
        pos=41;
    if(t_days==3)
        pos=51;  
    if(t_days==4)    
        pos=61;  
    if(t_days==5)
        pos=71; 
    if(t_days==6)
        pos=81; 

    for(i=0,j=10,pos;i<days[n_month-1];i++,pos+=10)
    {
        if(pos==91)
            SetColor(8); 
        else
            SetColor(7); 

        gotoxy(pos,j);printf("%d",i+1);
        if(pos==91)
        {
            pos=21; 
            j++; 
        }
    }

    SetColor(5); 

    
    for(i=22;i<102;i++)
    {
        gotoxy(i,4);printf("%c",196);
        gotoxy(i,17);printf("%c",196);
    }

  
    gotoxy(21,4);printf("%c",218);
    gotoxy(102,4);printf("%c",191);
    gotoxy(21,17);printf("%c",192);
    gotoxy(102,17);printf("%c",217);

    
    for(i=5;i<17;i++)
    {
        gotoxy(21,i);printf("%c",179);
        gotoxy(102,i);printf("%c",179);
    }

    SetColor(11); 

    
    gotoxy(24,11);printf("%c",174);
    gotoxy(98,11);printf("%c",175);

}

//===  ARROW KEY ====
int getkey()
{
    int ch;
    ch=getch();
     if(ch==0)
    {
        printf("zero");
        ch=getch();

        return ch;
    }
    return ch;
}

//=== CALCULATING ====
void calendar(int n_yr,int n_month)
{
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int t_days=0,z,m_year;
    system("cls");
    m_year=n_yr-1;
            if(m_year>=1945)
            {
                for(z=1945;z<=m_year;z++)
                {
                    if(z%4==0) 
                        t_days=t_days+366;  
                    else 
                        t_days=t_days+365;  
                }
            }

            if(n_yr%4==0)
                days[1]=29;
            else
                days[1]=28; 

            for(z=0;z<(n_month-1);z++)
            {

                t_days=t_days+days[z];
            }

            t_days=t_days%7; 
            display(n_yr,n_month,t_days,days);
}
