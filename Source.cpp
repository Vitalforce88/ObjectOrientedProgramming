#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*1 ������� ����������� ����� Figure (������). ��� ������������ �������� ������ Parallelogram (��������������) � Circle (����).
����� Parallelogram � ������� ��� ������� Rectangle (�������������), Square (�������), Rhombus (����). ��� ���� ������� �������
������������. ��� ������ Figure �������� ����� ����������� ������� area() (�������). �� ���� ��������� ������� ��������������
��� �������, ������ �� �������������� ������ ���������� �������.*/
class Figure
{
public:
	Figure() {};
	virtual void area() = 0;
	virtual ~Figure() {};
};

class Parallelogram : public Figure
{
	int height = 0;
	int side = 0;
public:
	Parallelogram() {};
	Parallelogram(int height,int side) : height(height),side(side) {};
	void area()
	{
		cout << "Parallelogram area : " << (height * side) << endl;
	};
};

class Circle : public Figure
{
	const double pi = 3.14;
	double radius = 0;
public:
	Circle(int radius) : radius(radius) {};
	void area()
	{
		cout << "Circle area : " << ((radius * radius) * pi) << endl;
	};
};

class Rectangle : public Parallelogram
{
	double side = 0;
	double height = 0;
public:
	Rectangle(double side,double height) : side(side),height(height) {};
	void area()
	{
		cout << "Rectangle area : " << ((side/2) * height) << endl;
	};
};

class Square : public Parallelogram
{
	double side = 0;
public:
	Square(double side) : side(side) {};
	void area()
	{
		cout << "Square area : " << (side * side) << endl;
	};

};

class Rombus : public Parallelogram
{
	double side = 0;
	double height = 0;
public:
	Rombus(double side, double height) : side(side),height(height) {};
	void area()
	{
		cout << "Rombus area : " << (height * side) << endl;
	};
};

/*2 ������� ����� Car (����������) � ������ company (��������) � model (������). ������-����������: PassengerCar (�������� ����������)
� Bus (�������). �� ���� ������� ��������� ����� Minivan (�������). ������� ������������ ��� ������� �� �������, ����� ��� ��������
������ � �������. ������� ������� ��� ������� �� ������� � ����������, � ����� ������������������ ����������� ������������.
�������� �������� �� �������� ������ ������.
����������: ���� ������������ ����������� ������� �����, �� ������ ������ "��������" �������� ������ ������� ����� "��������" �����.
*/
 class Car
 {
	string company = "?";
	string model = "?";
 public:
	 Car()
	 {
		 cout << "Car" << endl;
	 };
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar()
	{
		cout << "Passenger car" << endl;
	};
};

class Bus : virtual public Car
{
public:
	Bus()
	{
		cout << "Bus" << endl;
	};
};
class Minivan : public PassengerCar, public Bus
{
public:
	Minivan() : Car(), PassengerCar(), Bus()
	{
		cout << "Minivan" << endl;
	}
};
/*3 ������� �����: Fraction (�����). ����� ����� ��������� � ����������� (��������, 3/7 ��� 9/2). �������������, ����� ����������� �� ��� ����� 0. �����������:

    * �������������� �������� ��������� (+, -, *, /) ��� ���������� �������� � �������
    * ������� �������� (-)
    * ���������� ��������� ��������� ���� ������ (==, !=, <, >, <=, >=). 
����������: ��������� ��������� < � >=, > � <= � ��� ���������� �����������������, ���������� ����������� ���� ����� ������.
������������������ ������������� ������������� ����������.*/
class Fraction
{
	int Numerator = 0;
	int Denominator = 1;
	friend void NoD( Fraction& f1, Fraction& f2);
	friend Fraction operator+(const Fraction& f1, const Fraction& f2);
	friend Fraction operator-(const Fraction& f1, const Fraction& f2);
	friend Fraction operator*(const Fraction& f1, const Fraction& f2);
	friend Fraction operator/(const Fraction& f1, const Fraction& f2);
	friend bool operator==(const Fraction& f1, const Fraction& f2);
	friend bool operator!=(const Fraction& f1, const Fraction& f2);
	friend bool operator<(const Fraction& f1, const Fraction& f2);
	friend bool operator>(const Fraction& f1, const Fraction& f2);
	friend bool operator<=(const Fraction& f1, const Fraction& f2);
	friend bool operator>=(const Fraction& f1, const Fraction& f2);
	
public:
	Fraction(int num, int den) : Numerator(num), Denominator(den)
	{
		while (den == 0)
		{
			cout << "denominator(>0): ";
			std::cin >> den;
			Denominator = den;
			if (Denominator > 0) cout << "New value of fraction: " << Numerator << "/" << Denominator << endl;
		};
		
		
	}


	void getFraction_Value()const
	{
		if (Numerator == 0)
		{
			cout << Numerator << endl;
		}
		else if (Numerator < 0 || Denominator < 0)
		{
			cout << '-' << Numerator * (-1) << '/' << Denominator * (-1) << endl;
		}
		else
		{
			cout << Numerator << "/" << Denominator << endl;
		}
		
	}
	Fraction operator-()const
	{
		return Fraction(-Numerator, -Denominator);
	}
};

void NoD(Fraction& f1, Fraction& f2)
{
	if (f1.Denominator != f2.Denominator)
	{
		f1.Numerator *= f2.Denominator;
		f1.Denominator *= f2.Denominator;
		f2.Numerator *= f1.Denominator;
		f2.Denominator *= f1.Denominator;
	}

};

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
	int nOd = 0;
	Fraction result(1, 1);
	if ((f1.Denominator) != (f2.Denominator))
	{
		nOd = (f1.Denominator) * (f2.Denominator);
		result.Denominator = nOd;
		result.Numerator = (f1.Numerator * f2.Denominator) + (f2.Numerator * f1.Denominator);
		return result;
	}
	else if((f1.Denominator)==(f2.Denominator))
	{
		result.Numerator = f1.Numerator + f2.Numerator;
		result.Denominator = f1.Denominator;
		return result;
	}
};

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
	int nOd = 0;
	Fraction result(1, 1);
	if ((f1.Denominator) != (f2.Denominator))
	{
		nOd = (f1.Denominator) * (f2.Denominator);
		result.Denominator = nOd;
		result.Numerator = (f1.Numerator * f2.Denominator) - (f2.Numerator * f1.Denominator);
		return result;
	}
	else if ((f1.Denominator) == (f2.Denominator))
	{
		result.Numerator = f1.Numerator - f2.Numerator;
		result.Denominator = f1.Denominator;


		return result;
	}
	
};

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
	Fraction result(1, 1);
	result.Numerator = ((f1.Numerator) * (f2.Numerator));
	result.Denominator = ((f1.Denominator) * (f2.Denominator));
	return result;
};

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
	Fraction result(1, 1);
	result.Numerator = ((f1.Numerator) * (f2.Denominator));
	result.Denominator = ((f1.Denominator) * (f2.Numerator));
	return result;
};

bool operator==(const Fraction& f1, const Fraction& f2)
{
	Fraction fr1 = f1;
	Fraction fr2 = f2;
	NoD(fr1,fr2);
	if ((fr1.Numerator) == (fr2.Numerator))
	{
		return true;
	}
	else
	{
		return false;
	}
	
};

bool operator!=(const Fraction& f1, const Fraction& f2)
{
	if (!(f1 == f2)) return true;
	else return false;
};

bool operator<(const Fraction& f1, const Fraction& f2)
{
	Fraction fr1 = f1;
	Fraction fr2 = f2;
	NoD(fr1, fr2);
	if ((fr1.Numerator) < (fr2.Numerator)) return true;
	else return false;
};


bool operator>(const Fraction& f1, const Fraction& f2)
{
	if (!(f1 < f2) && (f1 != f2)) return true;
	else return false;
};

bool operator<=(const Fraction& f1, const Fraction& f2)
{
	if (f1 < f2 || f1 == f2) return true;
	else return false;
};

bool operator>=(const Fraction& f1, const Fraction& f2)
{
	if (f1 > f2 || f1 == f2) return true;
	else return false;
};
/*4 ������� ����� Card, ����������� ����� � ���� ��������. � ����� ������ ������ ���� ��� ����: �����, �������� �����
� ��������� ����� (����� ����� ��� ��������). ������� ���� ����� � �������� ����� ����� ������������ (enum). 
��������� ����� - ��� bool. ����� � ���� ������ ������ ���� ��� ������:
* ����� Flip(), ������� �������������� �����, �.�. ���� ��� ���� �������� �����, �� �� �� ������������ ����� �����, � ��������.
* ����� GetValue(), ������� ���������� �������� �����, ���� ����� �������, ��� ��� = 1.*/
class Card
{
public:
	enum class rank
	{
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGTH, NINE, TEN, JACK = 10, QUEEN = 10, KING = 10
	};
	enum class suit
	{ 
		CLUBS, DIAMONDS, HEARTS, SPADES
	};

	int GetValue()const
	{
		//����� ����� ���� - value = 0:
		int value = 0;
		if (m_IsFaceUp)
		{
			//value - ��� ����� ��������� �� �����:
			value = static_cast<int>(m_Rank);
			// value = 10 ��� JACK QUEEN � KING
			if (value > 10)
			{
				value = 10;
			}
			return value;
		}
	};// ���������� �������� �����
	Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {};
	

	void Flip()
	{
		m_IsFaceUp = !(m_IsFaceUp);
	};// ������������� �����

private:
	//friend ostream& operator <<(ostream& os, const Card& aCard);
	rank m_Rank;//rank - enum (��� 13 �������� ����)

	suit m_Suit;// suit - enum (�������� 4 ��������� �����)

	bool m_IsFaceUp;//����� ����� ����� ��� ��������?(������ �� � �����������)

};

int main()
{
	//1
	Parallelogram par(5, 7);
	Square sq(6.5);
	Rombus rom(7,5);
	Circle cir(7);
	Rectangle rec(5, 8);
	rec.area();
	sq.area();
	par.area();
	cir.area();
	rom.area();
	//2
	cout << endl;
	Car car;
	PassengerCar p_car;
	Bus bus;
	Minivan m_van;
	//3
	Fraction frac(1, 6);
	frac.getFraction_Value();
	Fraction frac2(1, 6);
	Fraction frac3 = frac + frac2;
	Fraction frac4 = frac - frac2;
	frac3.getFraction_Value();
	frac4.getFraction_Value();
	cout << std::boolalpha << (frac == frac2) << endl;
	cout << std::boolalpha << (frac <= frac2) << endl;
	cout << std::boolalpha << (frac >= frac2) << endl;
	cout << std::boolalpha << (frac != frac2) << endl;
	cout << std::boolalpha << (frac < frac2) << endl;
	cout << std::boolalpha << (frac > frac2) << endl;
	Fraction frac5 = -frac;
	frac5.getFraction_Value();
	//4

	return 0;
}