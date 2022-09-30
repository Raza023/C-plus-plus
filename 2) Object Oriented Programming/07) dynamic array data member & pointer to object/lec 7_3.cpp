#include <iostream>
#include<string>
#include<iomanip>
using namespace std;

//class Fraction         we can do it
//{
//	int numerator;
//	int denominator;
//	Fraction()
//	{
//		if(d>0)
//		{
//			deominator=d;
//		}
///		else if(d==0)
//		{
//			cout<<"Denomintor can't be zero."<<endl;
//			denomenator=1;
//		}
//	}
//};

class Rectangle
{
    // data members
private: //marzi ha likh lo
    double width;
    double length;

    // member functions 
public: 
	//constructor: are functions for initializing.
	//1) no return_type.
	//2) function name same as class name.
	//3) compiler is responsible for its calling.
	//4) When we do not write compiler makes its own constructor.
	
	//Rectangle()
	//{
	//	cout<<"Default Constructor called!"<<endl;
	//	length=width=10;
	//}
	
	Rectangle(int a=10,int b=20)  //becomes default with default arguments
	{
		cout<<"Parametrized Constructor called!"<<endl;
		if(a<0)
		{
			a=0;
		}
		length=a;
		if(b<0)
		{
			b=0;
		}
		width=b;
	}
	
	~Rectangle()
	{
		cout<<"Object is destroying"<<endl;
	}
	
    void setLength(double len);     // setters 
    void setWidth(double wid);      // setter
    double getLength();     // getter 
    double getWidth()
    {
        return width;
    }// getter 
    double computeArea();
    void draw();
};

int main()
{
	double len, wid; 
    //Rectangle rect[3];  //array of object
	Rectangle *rectptr;  //pointer to object
	rectptr=new Rectangle;  // not deletion in destructor.
	cout << "Enter length for rectangle: ";
    cin >> len;
    cout << "Enter width for rectangle: ";
    cin >> wid;
	rectptr->setLength(len);
	rectptr->setWidth(wid);
	cout<<"Length: "<<rectptr->getLength()<<endl;
	cout<<"Width: "<<rectptr->getWidth()<<endl;
	cout<<"Area: "<<(*rectptr).computeArea()<<endl;
	rectptr->draw();
    delete rectptr;
	
	/*
	for(int i=0;i<3;i++)
    {
    	cout << "Enter length for rectangle "<<i+1<<": ";
	    cin >> len;
	    cout << "Enter width for rectangle "<<i+1<<": ";
	    cin >> wid;
	    rect[i].setLength(len);
    	rect[i].setWidth(wid);
	}
	
	for(int i=0;i<3;i++)
    {
        cout << endl << "_______________________________" << endl;
	    cout << "Rectangle "<<i+1<<" has following characteristics:- " << endl;
	    cout << "Length: " << rect[i].getLength() << endl;
	    cout << "Width: " << rect[i].getWidth() << endl;
	    cout << "Area: " << rect[i].computeArea() << endl;
	    rect[i].draw();
	}*/
	return 0;
	
}

double Rectangle::computeArea()
{
    return length * width;
}

void Rectangle::draw()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

double Rectangle::getLength()
{
    return length;
}

void Rectangle::setWidth(double wid)
{
    width = wid;
}

void Rectangle::setLength(double len)
{
    length = len;
}
