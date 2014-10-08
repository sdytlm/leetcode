#include<iostream>

using namespace std;
const int len=8;
int A[len];

void Insert_Sort()
{
	int j;
	for(j=1;j<len;j++)
	{
		int key=A[j];
		int i=j-1;
		while((i>=0) && (A[i]>key))
		{
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=key; 
	}
}

int main()
{
	int length=0;
	int i;
    	cout << "Num of Slices:";
	cin >> length;
	for(i=0;i<length;i++)
		cin>>A[i];
        Insert_Sort();
        
        for(i=0;i<length;i++)
	   	cout<<A[i]<<" ";
	return 0;
}
