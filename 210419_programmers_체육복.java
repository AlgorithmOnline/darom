class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n - lost.length;
        int[] chk = new int[31];
        for(int i = 0; i<lost.length; i++){
            chk[lost[i]]--;
        }
        for(int i = 0; i<reserve.length; i++){
            chk[reserve[i]]++;
        }

        for(int i = 0; i < reserve.length; i++){
            if(chk[reserve[i]] == 0) { answer++; continue; }
            if(chk[reserve[i] - 1] < 0){
                chk[reserve[i] - 1]++; chk[reserve[i]]--;
                answer++;
            }
            else if(chk[reserve[i] + 1] < 0){
                chk[reserve[i] + 1]++; chk[reserve[i]]--;
                answer++;
            }
        }

        return answer;
    }
}