#include<iostream>
using namespace std;


void printArray(int * ,int);

int main()
{
	int arr[]={1,2,3,4,5};
	int *ptr;
	ptr=arr;
	printArray(arr,5);
	

	return 0;
}

void printArray(int *arr ,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
		//cout<<*(arr+i)<<endl;
	}	
}

