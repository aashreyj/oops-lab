#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int n,i,j; //initalize variables
	cout<<"Enter the number of lines to print. ";
	cin>>n; //taking user input
	for(i=1;i<=n;i++) //for upper half of diamond
	{
		cout<<setw(n-i+1)<<setfill('*');
		for(j=1;j<=i;j++)
			cout<<right<<j;
		for(j=i-1;j>=1;j--)
			cout<<j;
		if(i!=n)
			cout<<setw(n-i)<<"*";
		cout<<endl;
	}
	for(i=1;i<n;i++) //for lower half of diamond
	{
		cout<<setw(i+1);
		for(j=1;j<=(n-i);j++)
			cout<<j;
		j-=2;
		for(j;j>=1;j--)
			cout<<j;
		cout<<setw(i)<<"*";
		cout<<endl;
	}
	return 0;
}

