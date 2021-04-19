import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
         int[] answer = new int[commands.length];

        for(int i = 0; i < commands.length; i++){
            List<Integer> cut = new ArrayList<>();
            for(int j = commands[i][0] - 1; j < commands[i][1]; j++){
                cut.add(array[j]);
            }
            cut.sort(null); // 이때 null은 Comparator.naturalOrder()와 같음
            answer[i] = cut.get(commands[i][2] - 1);
        }

        return answer;
    }
}