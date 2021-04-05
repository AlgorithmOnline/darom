class Solution {
    public int solution(int X, int Y, int D) {
        // write your code in Java SE 8
        int answer = 0;
        int diff = Y - X;
        answer = diff / D;
        if(diff % D != 0) answer += 1;

        return answer;
    }
}