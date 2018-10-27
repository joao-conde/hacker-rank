#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> marks;
    int queries;
    cin >> queries;

    for(int i = 0; i < queries; i++){
        int type; 
        string student;
        cin >> type >> student;
        
        if(type == 1){
            int mark;
            cin >> mark;
            
            auto it = marks.find(student);
            if(it != marks.end())
                marks[student] += mark;
            else
                marks.insert({student, mark});
        }
        else if(type == 2) marks.erase(student);
        else if(type == 3) cout << marks[student] << endl;
    }
}