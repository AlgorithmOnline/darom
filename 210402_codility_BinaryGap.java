import java.util.ArrayList;

class Solution {
    public int solution(int N) {
        // write your code in Java SE 8
        String str = Integer.toBinaryString(N);
        ArrayList<Integer> Idx = new ArrayList<Integer>();

        for(int i = 0; i<str.length(); i++){
            if(str.charAt(i) == '1'){
                Idx.add(i);
            }
        }

        if(Idx.size() == 0) return 0;
        int Max = 0;
        int preIdx = 0, curIdx;
        for(int i = 1; i < Idx.size(); i++){
            curIdx = i;
            if(Idx.get(curIdx) - Idx.get(preIdx) -1 > Max) Max = Idx.get(curIdx) - Idx.get(preIdx) -1;
            preIdx = curIdx;
        }

        return Max;
    }
}