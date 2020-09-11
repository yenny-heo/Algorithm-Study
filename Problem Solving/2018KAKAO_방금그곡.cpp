#include <iostream>
#include <string>
#include <vector>

using namespace std;
int calInterval(string s){
    int aHour = stoi(s.substr(0, 2));
    int bHour = stoi(s.substr(6, 2));
    int aMin = stoi(s.substr(3, 2));
    int bMin = stoi(s.substr(9, 2));
    int intervalH = bHour - aHour;
    int intervalM = bMin - aMin;
    int interval = intervalH * 60 + intervalM;
    
    return interval;
}
string Name(string s){
    s = s.substr(12);
    string name;
    for(int i=0; i<s.length(); i++){
        if(s[i] == ','){
            name = s.substr(0, i);
            break;
        }
    }
    return name;
}
string curTune(string s){
    string tune;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == ','){
            tune = s.substr(i+1);
            break;
        }
    }
    return tune;
}
vector<string> splitTunes(string tune){
    vector<string> a;
    for(int i=0; i<tune.length(); i++){
        if(tune[i+1] != '#'){
            string split = "";
            split += tune[i];
            a.push_back(split);
        }
        else{
            a.push_back(tune.substr(i, 2));
            i++;
        }
    }
    return a;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<string> mySplit = splitTunes(m);
    
    int curTime = 0;
    int curSong = 0;
    string curName = Name(musicinfos[0]);
    int interval = calInterval(musicinfos[0]);
    vector<string> curSplit = splitTunes(curTune(musicinfos[0]));
    int myTime = 0;
    int radioLen = 0;
    while(1){
        if(curTime >= interval){//next song
            curTime = 0;
            curSong++;
            if(musicinfos.size() <= curSong){
                break;
            }
            curName = Name(musicinfos[curSong]);
            interval = calInterval(musicinfos[curSong]);
            curSplit = splitTunes(curTune(musicinfos[curSong]));
            myTime = 0;
        }
        else{
            int len = curSplit.size();
            if(curSplit[curTime%len] == mySplit[myTime]){
                curTime++;
                myTime++;
                if(mySplit.size() == myTime){
                    if(interval > radioLen){
                        answer = curName;
                        radioLen = interval;
                    }
                    curTime = interval;
                    continue;
                }
            }
            else{
                if(myTime == 0) curTime++;
                else myTime = 0;
            }
        }
    }
    return answer;
}
