#include <string>
#include <vector>
#include <iostream>
#include <locale>

using namespace std;

bool comp(string a, string b){
    for(int i=0; i<a.length(); i++){
        if(a[i] <= 90){
            a[i] += 32;
        }
    }
    for(int i=0; i<b.length(); i++){
        if(b[i] <= 90){
            b[i] += 32;
        }
    }
    return a == b;
}

int solution(int cacheSize, vector<string> cities) {
    int time = 0;
    vector<string> cache;
    
    for(int i=0; i<cities.size(); i++){
        bool flag = 0;
        for(int j=0; j<cache.size(); j++){
            //cache hit
            if(comp(cities[i], cache[j])){
                flag = 1;
                time += 1;
                cache.erase(cache.begin()+j);
                cache.push_back(cities[i]);
                break;
            }
        }
        //cache miss
        if(!flag){
            time += 5;
            if(cacheSize != 0){
                if(cache.size() < cacheSize){
                    cache.push_back(cities[i]);
                }
                else{
                    cache.erase(cache.begin());
                    cache.push_back(cities[i]);
                }
            }
        }
    }
    return time;
}
