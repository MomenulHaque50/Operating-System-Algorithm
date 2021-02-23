#include<bits/stdc++.h>

using namespace std;
int main()
{
     int n,pos,temp,tt=0,m,d,i,j,k,wt;
     float atat=0,awt=0,stat=0,swt=0;

    // All Inputs
     cout<<"Enter number of process: ";
     cin>>n;
     int p[n],a[n],b[n],e[n],tat[n+1];

     for(i=0;i<n;i++)
     {
           cout<<"Enter Arrival time: ";
           cin>>a[i];
           p[i]=i+1;

     }
     for(i=0;i<n;i++)
     {
           cout<<"Enter Burst time: ";
           cin>>b[i];
     }

     //Sort all processes according to the arrival time
      for(i=0;i<n;i++)
   {
       pos=i;
       for(j=i+1;j<n;j++)
       {
           if(a[j]<a[pos])
               pos=j;
       }

       temp=a[i];
       a[i]=a[pos];
       a[pos]=temp;

       temp=p[i];
       p[i]=p[pos];
       p[pos]=temp;

        temp=b[i];
       b[i]=b[pos];
       b[pos]=temp;
   }


     tat[0]=a[0];
     tat[1]=b[0];

     for(i=1;i<n;i++)
     {

         if(tat[i]>= a[i])
        {
          m= i;
          for(j=m+1;j<n; j++)
          {
              if(b[i]>b[j] && tat[i]>=a[j])
              {
                   temp=a[m];
       a[m]=a[j];
       a[j]=temp;

       temp=p[m];
       p[m]=p[j];
       p[j]=temp;

        temp=b[m];
       b[m]=b[j];
       b[j]=temp;
              }
          }

          tat[i+1]=tat[i] + b[i];

        }

        }
       e[0]= a[0];

       // Calculate all turnaround time
        for(int i=1;i<n+1;i++)
     {
         stat=stat+(float)tat[i];


     }
      // Calculate all waiting time
      for(int i=1;i<n;i++)
     {
          e[i]= tat[i]-a[i];
         swt=swt+ (float)e[i];

     }


    atat=stat/n;
     awt=swt/n;
     cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s)\n";

   for(i=0;i<n;i++)
   {
   cout<<"P"<<p[i]<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<e[i]<<"               "<<tat[i+1]<<endl;
   }

cout<<"\n\nGrand Chart:\n";
	for(i=0;i<n;i++)
    {
       cout<<"   P"<<i+1<<"     ";
    }
    cout<<endl;
	for(i=0;i<n+1;i++)
    {
        cout<<tat[i]<<"        ";
    }
    cout<<endl;
   cout<<"\n\nAverage Waiting Time ="<<awt<<"    Average Turnaround Time="<<atat<<endl;

   return 0;
}

