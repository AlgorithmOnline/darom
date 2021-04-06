class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        int sum[] = new int[A.length + 5];

        for (int i = 0; i < A.length; i++) {
            sum[i + 1] = sum[i] + A[i];
        }

        int answer = 1000000000;
        for (int i = 1; i < A.length; i++) {
            int diff = Math.abs(sum[i] - (sum[A.length] - sum[i]));
            if (diff < answer) answer = diff;
        }

        return answer;
    }
}