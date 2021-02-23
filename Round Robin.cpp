#include<bits/stdc++.h>

using namespace std;
int main()
{
     int n,pos,temp,tt=0,m,d,w,i,j,k,t,c,wt,st,et;
     float atat=0,awt=0,stat=0,swt=0;

     cout<<"Enter no of process:  ";
     cin>>n;
     int p[n],a[n],b[n],wtt[n],e[n],tat[50],flag[n], ub[n];

     for(i=0;i<n;i++)
     {
           cout<<"Enter Burst time: ";
           cin>>b[i];
           ub[i]= b[i];
           p[i]=i+1;
           wtt[i]=0;
           e[i]=0;
     }
     cout<<"Enter Time Slice:";
     cin>>d;
     t=0;
     k=0;
     c=0;
     wtt[k]=0;
     tat[k]=0;
     j=1;
     while(1){
        if(ub[k]>=d){

            t=t+d;

        ub[k]=ub[k]-d;
        tat[j]=t;
         j++;

        if(ub[k]==0)
        {
            c++;
        }
        if(ub[k]!=0)
        {
            e[k]=t;
        }

        }
        else{
        t=t+(d-ub[k]);

        tat[j]=t;
           j++;
        ub[k]=ub[k]-(d-ub[k]);
          if(ub[k]==0)
        {
            c++;
        }
        if(ub[k]!=0)
        {
            e[k]=t;
        }
        }
        i=k;
        m=0;
        while(1){
               i++;
               m++;
                if(i==n)
            {
                i=0;
            }
            if((ub[i])>0)
            {
                k=i;
                wtt[k]=wtt[k]+(t-e[k]);
                break;
            }

             if(m==n)
            {
                c=n;
                break;
            }
        }

       if(c==(n))
       {
           break;
       }

     }
     for(int i=0;i<j;i++)
     {
         stat=stat+(float)tat[i];


     }
      for(int i=1;i<n;i++)
     {

         swt=swt+ (float)wtt[i];

     }
    atat=stat/n;
     awt=swt/n;
     cout<<"Process  Burst-time(s)  Waiting-time(s))\n";

   for(i=0;i<n;i++)
   {
   cout<<"P"<<p[i]<<"                  "<<b[i]<<"                  "<<wtt[i]<<endl;
   }
   cout<<endl;
   cout<<"Grand Chart:"<<endl;
    for(int i=0;i<j;i++){
           cout<<tat[i]<<"     ";

        }
 cout<<endl;
   cout<<"Average Waiting time="<<awt<<"   Average Turn around time="<<atat;
    cout<<endl;
        return 0;
}

