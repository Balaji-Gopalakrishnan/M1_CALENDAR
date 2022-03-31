#include"calendar.h"

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
