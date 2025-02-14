#include<iostream>
#include<string>
using namespace std;

//Example of class
class Teacher {
    public:
        string name;
        string dept;
        int salary;
    void ChangeSalary(int s){
        salary = s;
    }
    private:
        long long AccountNo = 1293001700200143;

};

//Constructor
class Student {
public:
    Student(){
        cout<<"This is default constructor";
    }

    Student(string name, double cgpa){
        cout<<"Name : " << name <<endl;
        cout<<"cgpa : " << cgpa << endl;
    }
    void fun(){
        cout<< "This is my fun" << endl;
    }
};

//Distructor
class A {
public:
    ~A(){
        cout<<"Hi, I am Distructor" <<endl;
    }
};

//Single level inheritance
class B {
public:     
    void fun(){
        cout<<"This is B class" << endl;
    }
};

class C : public B {
public:
    void fun1(){
        cout<<"This is C class" << endl;
    }
};

//Multi level inheritance
class D {
public:
    void fun2(){
        cout<< "This is D class" << endl;
    }
};

class E : public D {
public:
    void fun3(){
        cout<< "This is E class" <<endl;
    }
};

class F : public E{
public:
    void fun4(){
        cout<< "This is F class" << endl;
    }
};

//Multiple inheritance
class G {
public:
    void fun5(){
        cout<< "This is G class" << endl;
    }
};

class H {
public:
    void fun6(){
        cout<< "This is H class" << endl;
    }
};

class I : public G, public H {
public:
    void fun7(){
        cout<<"This is I class" << endl;
    }
};

//Hierarchical Inheritance
class J {
public:
    void fun8(){
        cout<< "This is J class" << endl;
    }
};

class K : public J {
public:
    void fun9(){
        cout<< "This is K class" << endl;
    }
};

class L : public J {
public:
    void fun10(){
        cout<<"This is L class" << endl;
    }
};

//Constructor overloading : is a type of compile time pollymorphism
class Show {
public:
    string name;

    Show(){
        cout<<"This is non-Parameterized constructor" <<endl;
    }
    Show(string name){
        this->name = name;
        cout<<"HI, my name is :" << name << endl;
    }
};

//Function Overloading : is also type of compile time pollymorphism
class Print {
public:
    
    void fun(int x){
        cout<<"The value of x : " << x << endl;
    }

    void fun(char ch){
        cout<<"The value of ch : " << ch <<endl;
    }
};

//Function Overriding : is a type of run time pollymorphism
class Parent{
public:
    void fun(){
        cout<<"This is Parent Class" << endl;
    }
};
class Child : public Parent{
public:
    void fun(){
        cout<<"This is Child class" << endl;
    }
};

//Virtual Function : is also type of run time pollymorphism
class Parent1 {
    virtual void Hello(){
        cout<<"Hi, i am virtual fun from parent class" <<endl;
    }
};
class Child1 :public Parent1{
public:
    void Hello(){
        cout<<"Hi, i am virtual fun from child class" <<endl;
    }
};

//Abstraction class
class Shape{
public:
    virtual void draw() = 0; //Pure virtual function
};
class Circle : public Shape{
public:
    void draw(){
        cout<<"This is a drawing of circle" <<endl;
    }
};

//Static varibale

void fun(){
    static int x = 0;
    cout<< "Value of x : " <<x <<endl;
    x++;
}
int main() {
    fun();
    fun();
    fun();
}