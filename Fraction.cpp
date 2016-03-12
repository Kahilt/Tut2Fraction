#include<iostream>
#include<iomanip>

using namespace std;
class Fraction
{
public:
	Fraction();       //default constructor
	Fraction(int n, int d);
	void readFrac();
	void displayFrac();
	int get_num();
	int get_den();
	Fraction multiply(Fraction); //multiplies two fractions to give a fraction

	Fraction operator+(Fraction &);  // allows f1+f2
	Fraction operator-(Fraction &); // allows f1-f2
	friend istream& operator>>(istream& input, Fraction& frac);
	friend ostream& operator<<(ostream& output, Fraction& frac);
private:
	int num;
	int den;              // the numerator and denominator
};

Fraction::Fraction() // constructor without parameters
{
	num = 0;
	den = 0; // initialises zero
}
Fraction::Fraction(int n, int d)  //constructor
{

	num = n;
	den = d;
}
int Fraction::get_num()
{
	return num;
}
int Fraction::get_den()
{
	return den;
}
void Fraction::readFrac() //gets inputted fraction
{
	char s;
	cout << "Enter a fraction in the form x/y):  ";
	cin >> num >> s >> den;
}
void Fraction::displayFrac() //simplifies fraction
{
	int temp;
	int n = num;
	int d = den;

	while (d != 0)
	{
		temp = d;
		d = n%d;
		n = temp;
	}

	cout << num / n << "/" << den / n;
}


Fraction Fraction::multiply(Fraction f)
{
	Fraction temp(num*f.num, den*f.den);
	return temp;
}
//overloading an operator

Fraction Fraction::operator+(Fraction &f)
{
	Fraction temp(num*f.den + den*f.num, den*f.den);
	return temp;

}
//overloading an operator

Fraction Fraction::operator-(Fraction &f)
{
	Fraction temp(num*f.den - den*f.num, den*f.den);
	return temp;

}
//overloading an operator

int main()
{

	Fraction f1, f2; //f1 and f2 are objects: instance of the class Fraction
	Fraction f3;     //f3 stores the answer of f1*f2
	Fraction f4;     //f4 stores the answer of f1-f2
	cout << "Enter the first fraction:  " << endl;
	f1.readFrac();
	cout << "Enter the second fraction:  " << endl;
	f2.readFrac();

	f1.displayFrac();
	cout << "*";
	f2.displayFrac();
	cout << "=";
	f3 = f1.multiply(f2);
	f3.displayFrac();
	cout << endl;

	f1.displayFrac();
	cout << "+";
	f2.displayFrac();
	cout << "=";
	f3 = f1 + f2;
	f3.displayFrac();


	cout << endl;


	f1.displayFrac();
	cout << "-";
	f2.displayFrac();
	cout << "=";
	f4 = f1 - f2;
	f4.displayFrac();
	cout << endl;

	return 0;
}