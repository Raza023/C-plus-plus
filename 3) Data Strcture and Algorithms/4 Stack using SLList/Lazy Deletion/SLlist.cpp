#include "SLlist.h"
#include<iostream>

using namespace std;

template <class T>
SLlist<T>::SLlist()
{
	//check=false;
	top=-1;
	first=NULL;
}

template <class T>
void SLlist<T>::push(T x)
{
	node<T> *temp;
	if(first==NULL)
	{
		first=new node<T>(x);
	}
	else
	{
		node<T> *temp;
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new node<T>(x);
	}
	top++;
	//data[++top] = x;
}

template <class T>
T SLlist<T>::pop()
{
	node<T> *pprev;
	node<T> *prev;
	node<T> *cur;
	pprev=first;
	prev=first;
	cur=first;
	while(cur!=NULL)
	{
		pprev=prev;
		prev=cur;
		cur=cur->next;
	}
	T ch=prev->getX();
	pprev->next=prev->next;
	delete prev;
	top--;
	return ch;
	//return data[top--];
}

template <class T>
int SLlist<T>::empty()
{
	return (top == -1);
}

template <class T>
T SLlist<T>::topValue()
{
	node<T> *pprev;
	node<T> *prev;
	node<T> *cur;
	pprev=first;
	prev=first;
	cur=first;
	while(cur!=NULL)
	{
		pprev=prev;
		prev=cur;
		cur=cur->next;
	}
	T ch=prev->getX();
	return ch;
	//return data[top];
}

template <class T>
void SLlist<T>::append(T var)
{
	if(first==NULL)
	{
		first=new node<T>(var);
	}
	else
	{
		node<T> *temp;
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new node<T>(var);
	}
}

template <class T>
void SLlist<T>::insertDes(T val)
{
	node<T> *temp=new node<T>(val);
	if(first==NULL)
	{
		first=temp;
	}
	else
	{
		node<T> *prev;
		node<T> *cur;
		cur=first;
		prev=first;
		if(val>first->getX())
		{
			temp->next=first;
			first=temp;
		}
		while(cur!=NULL&&cur->getX()>=val)
		{
			prev=cur;
			cur=cur->next;
		}
		temp->next=cur;
		prev->next=temp;
	}
}

template <class T>
void SLlist<T>::deleteFirst(T val)
{
	node<T> *temp=first;
	if(first->getX()==val)
	{
		first=first->next;
		delete temp;
	}
	else
	{
		node<T> *prev;
		node<T> *cur;
		prev=NULL;
		cur=first;
		while(cur!=NULL&&cur->getX()!=val)
		{
			prev=cur;
			cur=cur->next;
		}
		if(cur==NULL)
		{
			cout<<val<<" Not found."<<endl;
		}
		else
		{
			prev->next=cur->next;
			delete cur;
		}
	}
}

template <class T>
void SLlist<T>::lazyDelte(T val)
{
	node<T> *temp=first;
	if(first->getX()==val)
	{
		first=first->next;
		temp->check=true;
	}
	else
	{
		node<T> *prev;
		node<T> *cur;
		prev=NULL;
		cur=first;
		while(cur!=NULL&&cur->getX()!=val)
		{
			prev=cur;
			cur=cur->next;
		}
		if(cur==NULL)
		{
			cout<<val<<" Not found."<<endl;
		}
		else
		{
			prev->next=cur->next;
			cur->check=true;
		}
	}
}

template <class T>
void SLlist<T>::deleteAt(int val)
{
	node<T> *temp;
	temp=first;
	if(val==0)
	{
		first=first->next;
		delete temp;
	}
	else
	{
		node<T> *prev;
		node<T> *cur;
		prev=NULL;
		cur=first;
		for(int i=0;i<val&&cur!=NULL;i++)
		{
			prev=cur;
			cur=cur->next;
		}
		if(cur==NULL)
		{
			cout<<val+1<<"th location Not found."<<endl;
		}
		else
		{
			prev->next=cur->next;
			delete cur;
		}
	}
}

template <class T>
void SLlist<T>::deleteLast(T val)
{
	node<T> *curr, *prev, *fdPrev, *fd;
    prev = NULL;
    curr = first;
	bool flag=false;
    while(curr!=NULL)
	{
        if (curr->getX() == val)
		{
            flag = true;
            fdPrev = prev;
            fd = curr;
        }
        prev = curr;
        curr=curr->next;
    }
    if(!flag)
    {
    	cout<<"Not found\n";
	}   
    else
	{
        fdPrev->next = fd->next;
        delete fd;
    }
}

template <class T>
void SLlist<T>::deleteAll(T val)
{ 
    node<T> *prev, *curr;
    prev=NULL;
    curr=first;
    while (first->getX() == val)
	{
        first=first->next;
        delete curr;
        curr=first;
    }
    node<T> *temp;
    while (curr!=NULL)
	{
        if (curr->getX() == val)
		{
            temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            delete temp;
        }
        else
		{
            prev=curr;
            curr=curr->next;
        }
    }
}

template <class T>
void SLlist<T>::traverse()
{
	node<T> *temp;
	temp=first;
	while(temp!=NULL)
	{
		if(temp->check==true)
		{
			deleteFirst(temp->getX());
		}
		else
		{
			cout<<temp->getX()<<endl;
			temp=temp->next;
		}
	}		
}

template <class T>
void SLlist<T>::getList(int arr[],int size)
{
	node<T> *temp;
	temp=first;
	int i=0;
	while(temp!=NULL)
	{
		arr[i]=temp->getX();
		temp=temp->next;
		i++;
	}
}
template <class T>
SLlist<T>::~SLlist()
{
	node<T> *temp;
	while(first!=NULL)
	{
		temp=first;
		first=first->next;
		delete temp;
	}
	first=NULL;
}
