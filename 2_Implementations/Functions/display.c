#include"calendar.h"

void display(int n_yr,int n_month,int t_days,int days[])
{
    int i,j,pos;
    SetColor(12); 
    gotoxy(56,6);printf("%s %d",m_onth[n_month-1],n_yr); 
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
