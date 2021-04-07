import java.util.HashMap;

class Solution {
    public int solution(int X, int[] A) {
        // write your code in Java SE 8
        int answer = 0;
        int cnt = 0;
        HashMap<Integer, Boolean> leaf = new HashMap<>();

        for(int i = 0; i < A.length; i++){
            if(cnt == X) {
                break;
            }
            if(!leaf.containsKey(A[i])){
                leaf.put(A[i], true);
                cnt++;
                answer = i;
            }
        }

        if(cnt != X) return -1;
        return answer;
    }
}