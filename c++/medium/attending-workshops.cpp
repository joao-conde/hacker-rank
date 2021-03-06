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


int CalculateMaxWorkshops(Available_Workshops* ptr){
    int max = 0, end_time = 0;
    vector<Workshop> ws = ptr->ws;
    sort(ws.begin(), ws.end());
      
    for(int i = 0; i < ws.size(); i++){
		if(ws[i].start_time >= end_time){
			max++;
			end_time = ws[i].start_time + ws[i].duration;
		}
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
