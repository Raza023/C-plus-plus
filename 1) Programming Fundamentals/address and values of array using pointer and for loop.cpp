#include<iostream>
using namespace std;


int main()
{
	int arr[]={1,2,3,4,5};
	int *ptr;
	ptr=arr;
	for(int i=0;i<5;i++)
	{
		cout<<ptr+i<<"\t";                      //(ptr+i*4)
		cout<<*(ptr+i)<<endl;
	}	
	return 0;
}

