#include<iostream>
using namespace std;


int main()
{
	int arr[]={1,2,3,4,5};
	int *ptr;
	ptr=arr;
	for(int i=0;i<5;i++)
	{
		cout<<ptr<<"\t";                     
		cout<<*(ptr)<<endl;
		ptr++;	                            //(ptr+1*4) address case
	}	
	return 0;
}

