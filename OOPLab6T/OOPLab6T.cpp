#include <iostream>
#include <string>

using namespace std;

// Код 1
void executeCode1() {
    // базовий клас
    class Circle {
    protected:
        float radius;

    public:
        // конструктор 
        Circle(float r) : radius(r) {}

        // віртуальна функція 
        virtual void printInfo() const {
            std::cout << "Circle with radius: " << radius << std::endl;
        }
    };

    // клас-похідник з віртуальним успадкуванням 
    class CircleDerivedVirtual : public virtual Circle {
    protected:
        float additionalData;

    public:
        // конструктор 
        CircleDerivedVirtual(float r, float ad) : Circle(r), additionalData(ad) {}

        // перевизначена функція 
        virtual void printInfo() const override {
            std::cout << "Derived Circle with radius: " << radius << " and additional data: " << additionalData << std::endl;
        }
    };

    // клас-похідник без віртуального успадкування 
    class CircleDerived : public Circle {
    protected:
        float additionalData;

    public:
        // конструктор 
        CircleDerived(float r, float ad) : Circle(r), additionalData(ad) {}

        // не перевизначаємо функцію базового класу 
    };

    Circle circle(5.0);
    CircleDerivedVirtual derivedVirtual(10.0, 20.0);
    CircleDerived derived(15.0, 30.0);

    std::cout << "Size of base Circle object: " << sizeof(circle) << " bytes" << std::endl;
    std::cout << "Size of derived Circle object with virtual inheritance: " << sizeof(derivedVirtual) << " bytes" << std::endl;
    std::cout << "Size of derived Circle object without virtual inheritance: " << sizeof(derived) << " bytes" << std::endl;
}

// Код 2
void executeCode2() {
    // абстрактний клас "Фігура"
    class Figure {
    public:
        // віртуальна функція для обчислення периметру
        virtual double perimeter() const = 0;
    };

    // клас "Прямокутник", що успадковує клас "Фігура"
    class Rectangle : public Figure {
    private:
        double length;
        double width;
    public:
        Rectangle(double l, double w) : length(l), width(w) {}

        // реалізація віртуальної функції для обчислення периметру
        double perimeter() const override {
            return 2 * (length + width);
        }
    };

    // клас "Коло", що успадковує клас "Фігура"
    class Circle : public Figure {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}

        // реалізація віртуальної функції для обчислення периметру
        double perimeter() const override {
            return 2 * 3.14159 * radius;
        }
    };

    // клас "Прямокутний трикутник", що успадковує клас "Фігура"
    class RightTriangle : public Figure {
    private:
        double a, b, c;
    public:
        RightTriangle(double side1, double side2, double hypotenuse) : a(side1), b(side2), c(hypotenuse) {}

        // реалізація віртуальної функції для обчислення периметру
        double perimeter() const override {
            return a + b + c;
        }
    };

    // клас "Трапеція", що успадковує клас "Фігура"
    class Trapezoid : public Figure {
    private:
        double a, b, c, d;
    public:
        Trapezoid(double side1, double side2, double side3, double side4) : a(side1), b(side2), c(side3), d(side4) {}

        // ралізація віртуальної функції для обчислення периметру
        double perimeter() const override {
            return a + b + c + d;
        }
    };

    Rectangle rect(4, 5);
    Circle circle(3);
    RightTriangle triangle(3, 4, 5);
    Trapezoid trapezoid(2, 3, 4, 5);

    cout << "Perimeter of Rectangle: " << rect.perimeter() << endl;
    cout << "Perimeter of Circle: " << circle.perimeter() << endl;
    cout << "Perimeter of Right Triangle: " << triangle.perimeter() << endl;
    cout << "Perimeter of Trapezoid: " << trapezoid.perimeter() << endl;
}

// Код 3
void executeCode3() {
    // базовий клас "Особа"
    class Person {
    protected:
        string name;
        int age;
    public:
        Person(const string& n, int a) : name(n), age(a) {}

        void display() const {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
    };

    // похідний клас "Жінка", що успадковує клас "Особа"
    class Woman : virtual public Person {
    public:
        Woman(const string& n, int a) : Person(n, a) {}

        void display() const {
            cout << "Woman - ";
            Person::display();
        }
    };

    // похідний клас "Працівник", що успадковує клас "Особа"
    class Employee : virtual public Person {
    protected:
        double salary;
    public:
        Employee(const string& n, int a, double s) : Person(n, a), salary(s) {}

        void display() const {
            cout << "Employee - ";
            Person::display();
            cout << "Salary: " << salary << endl;
        }
    };

    // похідний клас "Працівник-Жінка", що успадковує класи "Працівник" та "Жінка"
    class FemaleEmployee : public Employee, public Woman {
    public:
        FemaleEmployee(const string& n, int a, double s) : Person(n, a), Employee(n, a, s), Woman(n, a) {}

        void display() const {
            cout << "Female Employee - ";
            Person::display(); // виклик методу display() з класу Person
            cout << "Salary: " << salary << endl;
        }
    };

    Woman woman("Anna", 30);
    Employee employee("John", 35, 50000);
    FemaleEmployee femaleEmployee("Emily", 25, 60000);

    cout << "Woman: ";
    woman.display();

    cout << "\nEmployee: ";
    employee.display();

    cout << "\nFemale Employee: ";
    femaleEmployee.display();
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    int choice;

    cout << "Виберіть код для виконання (1, 2, чи 3): ";
    cin >> choice;

    switch (choice) {
    case 1: {
        executeCode1();
        break;
    }
    case 2: {
        executeCode2();
        break;
    }
    case 3: {
        executeCode3();
        break;
    }
    default: {
        cout << "Неправильний вибір. Будь ласка, виберіть 1, 2, чи 3." << endl;
        break;
    }
    }

    return 0;
}



