#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	cout<<"Enter total number of processes:";
	cin>>n;
	cout<<"\nEnter Process Burst Time:\n";
	for (i=0;i<n;i++) {
		cout<<"P["<<i+1<<"]:";
		cin>>bt[i];
	}
	wt[0]=0;

	for (i=1;i<n;i++) {
		wt[i]=0;
		for (j=0;j<i;j++)
		            wt[i]+=bt[j];
	}
	tat[0]=0;
	cout<<"\nProcess Burst Time Waiting Time Turnaround Time\n";
	for (i=0;i<n;i++) {
		tat[i+1]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i+1];
		cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"  "<<wt[i]<<"  "<<tat[i+1];
	}

	cout<<"\n\nGrand Chart:\n";
	for(i=0;i<n;i++)
    {
       cout<<"   P"<<i+1<<"     ";
    }
    cout<<endl;
	for(i=0;i<n+1;i++)
    {
        cout<<tat[i]<<"       ";
    }
    cout<<endl;
	avwt/=i;
	avtat/=i;
	cout<<"\nAverage Waiting Time:"<<avwt;
	cout<<"\nAverage Turnaround Time:"<<avtat<<endl;
	return 0;
}

