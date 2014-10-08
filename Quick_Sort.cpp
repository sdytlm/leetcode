#include<iostream>
#include<vector>
using namespace std;

vector<int> array;

int exchange(int i, int j)
{
	int x;
	x=array[i];
	array[i]=array[j];
	array[j]=x;
}

int partition(int p, int r)
{
	int i=p-1;
	int x=array[r];
	for(int j=p; j<r; j++)
	{
		if(array[j] <= x)
		{
		  i++;
		  exchange(i,j);
		}
	}
	exchange(i+1,r);
	return i+1;
}


void quick_sort(int p, int r)
{
	if (p < r)
	{
		int q = partition(p,r);
		quick_sort(p,q-1);
		quick_sort(q+1,r);
	}
}

int main()
{
	int i;
	while(cin >> i)
	  array.push_back(i);
	
	for(i=0;i<array.size();i++)
		cout << array[i]<<" ";
	cout << endl;

	quick_sort(0,array.size()-1);
	
	for(i=0;i<array.size();i++)
		cout << array[i]<<" ";
	cout << endl;
	return 0;
	
}
