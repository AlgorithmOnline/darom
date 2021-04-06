class Solution {
    public int solution(int[] A) {
        // write your code in Java SE 8
        long answer = (A.length + 1L) * (A.length + 2L)/ 2L;

        for(int i = 0; i < A.length; i++){
            answer -= A[i];
        }

        return (int)answer;
    }
}