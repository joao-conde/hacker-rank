#include <bits/stdc++.h>

using namespace std;

struct Workshop{
    int start_time, duration, end_time;
};

bool operator<(const Workshop &w1, const Workshop &w2){
    return (w1.start_time + w1.duration < w2.start_time + w2.duration);
}

struct Available_Workshops{
    int n;
    vector<Workshop> ws;
};

Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops* aws = new Available_Workshops;
    aws->n = n;
    for(int i = 0; i < n; i++){
        Workshop ws;
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = start_time[i] + duration[i];
        aws->ws.push_back(ws);
    }
    return aws;
}

bool intersects(Workshop w1, Workshop w2){
    int end1 = w1.start_time + w1.duration,
        end2 = w2.start_time + w2.duration;
    
    return(!(w1.start_time >= end2 || end1 <= w2.start_time));
}
int CalculateMaxWorkshops(Available_Workshops* ptr){
    int max = 0;
    vector<Workshop> ws = ptr->ws;
    sort(ws.begin(), ws.end());
    while(!ws.empty()){
        Workshop earliest = ws[0];
        ws.erase(ws.begin());
        for(unsigned int i = 0; i < ws.size(); i++){
            if(intersects(earliest, ws[i])){      
                ws.erase(ws.begin() + i);
                i--;
            }
        }
        max++;
    }    
    return max;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
}
