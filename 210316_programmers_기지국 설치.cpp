#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ans = 0;       
    vector<pair<int, int>> v; //전파가 안통하는 구간(st, end)
    if(stations[0] - w - 1 >= 1)
        v.push_back({1, stations[0] - w - 1});
    for(int i = 1; i < stations.size(); i++){
        int st = stations[i - 1] + w + 1;
        int ed = stations[i] - w - 1;
        if(st <= ed) v.push_back({st, ed});       
    }
    if(stations[stations.size() - 1] + w + 1 <= n)
        v.push_back({stations[stations.size() - 1] + w + 1, n});
    
    for(auto e: v){
        int len = e.second - e.first + 1;
        if(len <= w * 2 + 1) ans++;
        else{
            ans += len/(w * 2 + 1);
            if(len % (w * 2 + 1)) ans++;
        }           
    }  

    return ans;
}