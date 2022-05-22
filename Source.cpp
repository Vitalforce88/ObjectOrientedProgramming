#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*1 Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для всех классов создать
конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). Во всех остальных классах переопределить
эту функцию, исходя из геометрических формул нахождения площади.*/
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

/*2 Создать класс Car (автомобиль) с полями company (компания) и model (модель). Классы-наследники: PassengerCar (легковой автомобиль)
и Bus (автобус). От этих классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из классов, чтобы они выводили
данные о классах. Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
Обратить внимание на проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.
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
/*3 Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:

    * математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
    * унарный оператор (-)
    * логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 
Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
Продемонстрировать использование перегруженных операторов.*/
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
/*4 Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты
и положение карты (вверх лицом или рубашкой). Сделать поля масть и значение карты типом перечисления (enum). 
Положение карты - тип bool. Также в этом классе должно быть два метода:
* метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
* метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/
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
		//карта лицом вниз - value = 0:
		int value = 0;
		if (m_IsFaceUp)
		{
			//value - это число указанное на карте:
			value = static_cast<int>(m_Rank);
			// value = 10 для JACK QUEEN и KING
			if (value > 10)
			{
				value = 10;
			}
			return value;
		}
	};// Возвращает значение карты
	Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {};
	

	void Flip()
	{
		m_IsFaceUp = !(m_IsFaceUp);
	};// перворачивает карту

private:
	//friend ostream& operator <<(ostream& os, const Card& aCard);
	rank m_Rank;//rank - enum (все 13 значений карт)

	suit m_Suit;// suit - enum (содержит 4 возможные масти)

	bool m_IsFaceUp;//Карта вверх лицом или рубашкой?(влияет на её отображение)

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