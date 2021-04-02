class Solution {
    public int[] solution(int[] A, int K) {
        // write your code in Java SE 8
        if(A.length <= 0) return A;
        K %= A.length;
        if(K == 0) return A;

        int[] ans = new int[A.length];
        int idx = 0;
        for(int i = A.length-K; i < A.length; i++){
            ans[idx++] = A[i];
        }
        for(int i = 0; i<A.length-K; i++){
            ans[idx++] = A[i];
        }

        return ans;
    }
}