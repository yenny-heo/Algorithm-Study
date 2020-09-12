#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class BTime{
public:
    int hour;
    int minute;
    bool full;
    BTime(){
        hour = 0;
        minute = 0;
        full = false;
    }
    BTime(int h, int m, bool f){
        hour = h;
        minute = m;
        full = f;
    }
};

string intToTime(int h, int m){
    string zero = "0";
    string hour = to_string(h);
    string min = to_string(m);
    if(hour.length() == 1){
        hour = zero + hour;
    }
    if(min.length() == 1){
        min = zero + min;
    }
    string result = hour + ":" + min;
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    BTime* arr = new BTime[11];
    vector<pair<int, int>> tt;
    
    for(int i=0; i<timetable.size(); i++){
        int hour = stoi(timetable[i].substr(0, 2));
        int min = stoi(timetable[i].substr(3, 2));
        tt.push_back({hour, min});
    }
    sort(tt.begin(), tt.end());
    
    int bus = 0;
    int busHour = 9;
    int busMin = 0;
    int passenger = 0;
    bool end = false;
    for(int i=0; i<tt.size(); i++){
        int hour = tt[i].first;
        int min = tt[i].second;
        //버스 시간이 지났거나, 승객이 다 찬 경우: next bus
        while((busHour*60 + busMin) < (hour*60 + min) || passenger >= m){
            //승객이 다 차지 않은 경우
            if(passenger < m){
                BTime t = BTime(busHour, busMin, false);
                arr[bus] = t;
            }
            bus++;
            if(bus >= n){
                end = true;
                break;
            }
            busMin += t;
            passenger = 0;
            if(busMin >= 60){
                busHour++;
                busMin -= 60;
            }
        }
        if(end) break;
        passenger++;
        //승객이 다 찬 경우
        if(passenger >= m){
            BTime t = BTime(hour, min, true);
            arr[bus] = t;
        }
        else if(i == tt.size()-1){//마지막 승객인 경우
            BTime t = BTime(busHour, busMin, false);
            arr[bus] = t;
        }
    }
    
    BTime bt = arr[n-1];
    if(bt.full == true){
        bt.minute --;
        if(bt.minute < 0){
            bt.hour--;
            bt.minute += 60;
        }
    }
    answer = intToTime(bt.hour, bt.minute);
    return answer;
}
