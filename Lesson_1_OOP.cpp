/* 1.   Создать класс Power, который содержит два вещественных числа.Этот класс должен иметь две переменные - члена
        для хранения этих вещественных чисел.Еще создать два метода : один с именем set, который позволит присваивать 
        значения объявленным в классе переменным, второй — calculate, который будет выводить результат возведения первого 
        числа в степень второго числа.Задать значения этих двух чисел по умолчанию.

   2.   Написать класс с именем RGBA, который содержит 4 переменные - члена типа 
        std::uint8_t : m_red, m_green, m_blue и m_alpha(#include cstdint для доступа к этому типу).
        Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha.
        Создать конструктор со списком инициализации членов, который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha.
        Написать функцию print(), которая будет выводить значения переменных - членов.

    3.  Написать класс, который реализует функциональность стека.Класс Stack должен иметь :
                                                        • private - массив целых чисел длиной 10;

                                                        • private целочисленное значение для отслеживания длины стека;

                                                        • public - метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;

                                                        • public - метод с именем push(), который будет добавлять значение в стек.push() должен возвращать значение false, 
                                                          если массив уже заполнен, и true в противном случае;

                                                        • public - метод с именем pop() для вытягивания и возврата значения из стека.
                                                          Если в стеке нет значений, то должно выводиться предупреждение;

                                                        • public - метод с именем print(), который будет выводить все значения стека.

Код main() :


    int main()
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}

Этот код должен выводить :
()
(3 7 5)
(3 7)
()
*/


#include <iostream>
#include <cmath>
#include<cstdint>
class Power {
    double a = 0.0;
    double b = 0.0;
public:
    Power() {};
    void Set(double firstValue, double secondValue) {
        a = firstValue;
        b = secondValue;
        std::cout << "\nValues " << a << " and " << b << " set..." << std::endl;
    }
    void Calculate() {
        std::cout << "Calculating the first value to the power of the second...." << std::endl;
        std::cout << std::pow(a, b) << std::endl;
    }
    ~Power() {};
};

class RGBA {
    std::uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;
public:
    RGBA() {
        std::cout << "Default constructor: ***object created***" << std::endl;
    };// по умолчанию
    RGBA(int R, int G, int B, int A) : m_red(R), m_green(G), m_blue(B), m_alpha(A) {

        std::cout << "Constructor with parameters: " << "RED= " << R << " GEEN= "
                  << G << " BLUE= " << B << " Alpha= " << A << " was created" << std::endl;
    };

    void print() {
        std::cout << "PRINTING THE VALUES.... " << m_red << " " << m_green << " " << m_blue << " " << m_alpha << std::endl;
    }
};
class Stack {
    int count = -1;
    int array[10] = { 0 };
public:
    bool push(int value) {
        if (count == 9) { 
            std::cout << "***Stack overflowed - last value not written***" << std::endl;
            return false;
        }
        else
        {
            count++;
            array[count] = value;
            std::cout << "***The value was written successfully***" << std::endl;
            return true;
        }
    }
    void pop() {
        array[count] = 0;
        count--;
        std::cout << "***Last value removed***" << std::endl;
    }
    void reset() {
        for (auto c : array) {
            array[c] = 0;
        }
        count = -1;
        std::cout << "***All values are cleared, the stack is empty***" << std::endl;
    }
    void print() {
        std::cout << "( ";
        for (int i = 0; i <= count; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << ")" << std::endl;
    }
};


int main()
{   
    //1
    Power values_1;
    values_1.Set(5, 3);
    values_1.Calculate();

    //2
    RGBA Color;
    Color.print();
    RGBA DifferenColor(3, 45, 67, 89);
    DifferenColor.print();
    RGBA Hearts(3, 3, 3, 3);
    Hearts.print();

    //3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    stack.reset();
    stack.print();
    return 0;
}
