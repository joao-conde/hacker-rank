#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    public:
        string name;
        int age, cur_id;
        
        virtual void getdata(){}
        virtual void putdata(){}
};

class Professor : public Person{
    static int PROF_ID;

    int publications;

    public:

        Professor(){
            cur_id = PROF_ID;
            PROF_ID++;
        }

        void getdata(){
            cin >> name >> age >> publications;
        }

        void putdata(){
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
};

class Student : public Person{
    static int STUDENT_ID;

    int marks[6];

    public:

        Student(){
            cur_id = STUDENT_ID;
            STUDENT_ID++;
        }

        void getdata(){
            cin >> name >> age;
            for(int i = 0; i < 6; i++) cin >> marks[i];
        }

        void putdata(){
            int sum = 0; 
            for(int i = 0; i < 6; i++) sum += marks[i];
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }

};

int Student::STUDENT_ID = 1;
int Professor::PROF_ID = 1;
int main(){
    int n, val;
    cin >> n;
    Person *per[n];

    for(int i = 0; i < n; i++){
        cin >> val;
        if(val == 1)
            per[i] = new Professor; 
        else 
            per[i] = new Student;

        per[i]->getdata();
    }

    for(int i = 0; i < n; i++)
        per[i]->putdata();
}
