#include<bits/stdc++.h>

using namespace std;
int main()
{
     int n,pos,temp,tt=0,m,d,w,i,j,k,t,c,wt,st,et;
     float atat=0,awt=0,stat=0,swt=0;

     cout<<"Enter no of process: ";
     cin>>n;
     int p[n],a[n],pr[n],b[n],wtt[n],e[n],tat[50],flag[n], ub[n];

      for(i=0;i<n;i++)
     {
           cout<<"Enter priority time: ";
           cin>>pr[i];
     }
     for(i=0;i<n;i++)
     {
           cout<<"Enter Arrival time: ";
           cin>>a[i];
           p[i]=i+1;
       flag[i]=0;
       wtt[i]=0;
      e[i]=0;
     }
     for(i=0;i<n;i++)
     {
           cout<<"Enter Burst time: ";
           cin>>b[i];
     }
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

       temp=pr[i];
       pr[i]=pr[pos];
       pr[pos]=temp;
   }

   for(i=0;i<n;i++)
   { ub[i]=b[i];
   }

     tat[0]=a[0];

    t=0;
    k=0;
    c=0;
    j=1;
    for(i=1;i<n;i++)
    {
        if(t>=a[i])
        {
            if(pr[k]>=pr[i])
            {
                if(ub[k]>ub[i])
                {
                    k=i;
                }
            }
        }
    }
     st=0;
     wtt[k]=st;
    flag[k]=3;
       while(1){


        t++;
        m=0;
        w=0;
        if(t==(b[k]+st))
        {
            flag[k]=1;
            c++;
           tat[j]=t;
            j++;

        }

        if( flag[k]==1)
        {
        i=0;
        while(1)
       {

           if(k==(n-1) && flag[k]==1)
           {
               k=0;
           }
        if(flag[k]==0 || flag[k]==2 || flag[k]!=1 )
           {
               break;
           }
           if(i==(n+1))
           {
               break;
           }

           k++;
           i++;
       }
           for(i=0;i<n;i++)
       {
            if(c==(n-1))
               {
                   m=k;
                   break;
               }

           if(t>=a[i])
           {


              if((pr[k]>=pr[i])&& k!=i && (flag[i]==0 || flag [i]==2)){
                    if(pr[k]==pr[i]){
                            if(b[k]>b[i]){
                       m=i;
                       k=i;
                            }
                            else{
                       m=k;
                    }

                    }
                    else{
                       m=i;
                       k=i;
                    }
               }

               else{
                m=k;

               }
             }

         }

       k=m;
          if(flag[k]==0)
               {
                   wtt[k]=wtt[k]+(t-a[k]);
               }
               if(flag[k]==2){
               wtt[k]=wtt[k]+(t-e[k]);
               }
    flag[k]=3;
      st=t;

        }
     else {
       for(i=0;i<n;i++)
       {
            if(c==(n-1))
               {
                   m=k;

                   break;
               }
               if(k!=i){
           if(t>=a[i])
           {
              if((pr[k]>=pr[i])&& (flag[i]==0 || flag[i]==2) && flag[k]!=1){
                     if(pr[k]==pr[i]){
                            if(b[k]>b[i]){
                       m=i;
                      w=1;
                            }
                            else{
                                m=k;
                                w=1;
                            }
                     }
                             else{
                       m=i;
                        w=1;
                    }


               }
           }
               }

       }
     }
       if( w==1){

                  i=m;
                   et=t-st;
               b[k]=b[k]-et;
                if(flag[i]==0)
               {
                   wtt[i]=wtt[i]+(t-a[i]);
               }
               if(flag[i]==2){
               wtt[i]=wtt[i]+(t-e[i]);
               }
               flag[k]=2;
               e[k]=t;

               k=i;
               st=t;

               if(flag[k]!=1){
               flag[k]=3;

               }
                tat[j]=t;
                j++;
           }

         if(c == n)
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
     cout<<"Process  Arrival-time(s)  Burst-time(s)  Waiting-time(s))\n";

   for(i=0;i<n;i++)
   {
   cout<<"P"<<p[i]<<"              "<<a[i]<<"                "<<b[i]<<"                  "<<wtt[i]<<endl;
   }
   cout<<endl;
   cout<<"Grand Chart:"<<endl;
    for(int i=0;i<j;i++){
           cout<<tat[i]<<"     ";

        }
  cout<<endl;
   cout<<"Average Waiting time="<<awt<<"    Average Turn around time="<<atat;
  cout<<endl;
   return 0;
}



