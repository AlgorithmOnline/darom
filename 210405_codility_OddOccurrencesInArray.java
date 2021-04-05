import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        HashMap<Integer, Integer> isOdd = new HashMap<Integer, Integer>();
        int answer = 0;
        for (int i = 0; i < A.length; i++) {
            if (isOdd.containsKey(A[i])) {
                isOdd.put(A[i], isOdd.get(A[i]) + 1);
            } else {
                isOdd.put(A[i], 1);
            }
        }

        for(Map.Entry<Integer, Integer> e : isOdd.entrySet()){
            if(e.getValue() % 2 == 0) continue;
            else {
                answer = e.getKey(); break;
            }
        }
        return answer;
    }
}