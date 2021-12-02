/*
1.
Создать класс Person (человек) с полями:
имя, возраст, пол и вес. 
Определить методы переназначения имени, 
изменения возраста и веса. 
Создать производный класс Student (студент), 
имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. 
Создать счетчик количества созданных студентов. 
В функции main() создать несколько (не больше трёх) студентов. 
Вывести информацию о них.

2.
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
У Fruit есть две переменные-члена: name (имя) и color (цвет). 
Добавить новый класс GrannySmith, который наследует класс Apple.

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
Код, приведенный выше, должен давать следующий результат:

My apple is red.
My banana is yellow.
My Granny Smith apple is green.

3.
Изучить правила игры в Blackjack. 
Подумать, как написать данную игру на С++, 
используя объектно-ориентированное программирование. 
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? 
Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы.

*/
#include <iostream>
#include <string>
#include <vector>
#include <locale>
//#1

class Person {
    std::string name = "unknown";
    int age = -1;
    std::string gender = "unknown";
    double wt = -1.0;
    
public:
   
    Person() {
        std::cout << "An unnamed object of type \"Person\" has been created" << std::endl;
    };
    Person(std::string name, std::string gender, int age, double wt):name(name),gender(gender),age(age),wt(wt){

    }
    std::string getName() const { return name; };
    std::string getgender()const { return gender; };
    int getAge() const{ return age; };
    double getWT()const { return wt; };

    void change_name(std::string sub){
       name = sub;
       std::cout << "Name changed to " << sub << std::endl;
    }
    void change_gender(std::string sub) {
        gender = sub;
        std::cout << "Gender сhanged to " << sub << std::endl;
    }
    void change_age(int sub) {
        age = sub;
        std::cout << "Age changed to " << sub << std::endl;
    }
    void change_wt(int sub) {
        wt = sub;
        std::cout << "Weight changed to " << sub << std::endl;
    }
    void GetPersonData()const {
        std::cout << "\n**********" << std::endl;
        std::cout << "Person Data : " << std::endl;
        std::cout << "NAME: " << name << "\nAGE: " << age << "\nGENDER: " << gender << "\nWEIGHT: " << wt << '\n';
        std::cout << "**********" << std::endl;
    }
   // friend class Student; ??????
    
};

 static int students_count = 0;// При добавлении в деструктор students_count-- почему то всё сбивается, не пойму почему, объясните пожалуйста

//void AddToTheList(Student name) {};    ?????
class Student : public Person {

    unsigned year_of_study = 0;

public:
    
        Student(std::string name, std::string gender, int age, double wt, unsigned year) : Person(name, gender, age, wt), year_of_study(year)
    {
        ++students_count;
        std::cout << "\n***creating object of type \"Student\".....***" << std::endl;
        std::cout << "Object with characteristics:\n" << "name: " << name << "\n" << "gender: " << gender << "\n" << "age: " << age <<
            "\n" << "weught: " << wt << "\nyear of study: " << year_of_study << std::endl;
        std::cout << "***created***" << std::endl;

       // AddToTheList(*this); ????? 
    }

    ~Student() {}

    void GetStudentData()const {
        std::cout << "\n\t\t**********" << std::endl;
        std::cout << "\t\tNAME: " << getName() << "\n\t\tAGE: " << getAge() << "\n\t\tGENDER: " << getgender() <<
            "\n\t\tWEIGHT: " << getWT() << "\n\t\tYEAR_OF_STUDY: "<< year_of_study << '\n';
        std::cout << "\t\t**********" << std::endl;
    }

    void HowManyStudents() {
        std::cout << getName() << " says that we have " << students_count << " students" << std::endl;
    }

    void ChangeYearOfStart(unsigned year) {
        year_of_study = year;
    }
    
    
    };

std::vector<Student> Students;//????
void AddToTheList(Student name) {
    Students.push_back(name);
    std::cout << "\nThe student " << name.getName() << " is added to the list" << std::endl;
};

void List_of_students() {
    std::cout << "\n\t\t\t***STUDENTS LIST***" << std::endl;
    std::cout << "\tTotal students: " << students_count << std::endl;
    std::cout << "\tin list:" << Students.size() << std::endl;
    /*for (int i = 0; i != Students.size(); i++) {
        Students[i].GetStudentData();
    };*/
    for (auto s : Students) {
        s.GetStudentData();
    }
};

class Fruit {
    std::string name = "?";
    std::string color = "?";
public:
      std::string getColor() { return color; };
      std::string getName() { return name; };
};
class Apple : public Fruit {
    std::string name = "apple";
    std::string color = "?";
public:
    Apple() {};
    Apple(std::string c) {
        color = c;
    }
    std::string getColor() { return color; };
    std::string getName() { return name; };
};

class Banana : public Fruit {
    std::string name = "banana";
    std::string color = "yellow";
public:
    std::string getColor() { return color; };
    std::string getName() { return name; };
};

class GrannySmith : public Apple {
    std::string name = "grenny smith apple";
    std::string color = "green";
public:
    std::string getColor() { return color; };
    std::string getName() { return name; };
};


int main() {
    setlocale(LC_ALL, "Russian");
    //Не могу понять как в идеале сделать ДЗ - 
    // 1.как сделать так чтобы при создании объекта он в конструкторе сразку же 
    // добавлял его в вектор Students? - если мы прописываем Вектор в классе то каждый раз новый будет создаваться, если сделать его глобальным(что не очень хорошо наверное), то не создан ещё тип
    // для вектора, я что то не допонимаю...
    // 2.Счётчик студентов обязательно делать глобальным и статическим? подскажите есть более хороший вариант?
    // 3. мне кажется я дублирую и пишу лишний код в классе student - так ли это? Нужно ли "дружить" Student c Person?
    // Подскажите пожалуйста  в целом как это можно реализовать с примером кода и укажите на всё что режет глаз в первом заданиии 
    // и на то что можно сократить, буду очень благодарен за развёрнутую обратную связь.

    //#1
    
    Person Anton;
    Anton.change_name("Anton");
    Person Andrey("Andrey", "male", 33, 75);

    Student Vasya("Vasya", "male", 23, 67, 2019);
    AddToTheList(Vasya);
    Student Anatoly("Anatoly", "male", 25, 75, 2020);
    AddToTheList(Anatoly);
    Student Katya("Katya", "female", 22, 75, 2018);
    AddToTheList(Katya);
    Vasya.HowManyStudents();
    List_of_students();
    
    //#2

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    //#3

/*
В игре думаю необходим класс игрок, колода карт от игрока,
соперник, и клас с тем что находится в руке, производный от игрока и компьютера(2 шт),
функция игры, которая использует данные классы.

*/

}


