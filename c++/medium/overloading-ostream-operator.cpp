#include <iostream>

using namespace std;

class Person {
    
    public:
        Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
      
        const string& get_first_name() const {
          return first_name_;
        }
       
        const string& get_last_name() const {
         return last_name_;
        }
    
    private:
        string first_name_;
        string last_name_;
};

//Could be declared inside class as friend, not simply as class function else 'cout << p' would not be possible, only 'p << cout'
ostream& operator<<(ostream& out, Person &p){
    return out << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
}


int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;

    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
}