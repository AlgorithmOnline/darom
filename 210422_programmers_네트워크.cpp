#include <string>
#include <vector>
using namespace std;
int chk[201];

void dfs(int idx, vector<vector<int>> computers){
    chk[idx] = 1;
    for(int i = 0; i< computers[idx].size(); i++){
        if(!chk[i] && computers[idx][i] ){
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i< computers.size(); i++){
        if(!chk[i]){
            dfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}