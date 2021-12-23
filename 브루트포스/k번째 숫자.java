import java.util.Arrays;

public class Solution {
    public int[] solution(int[] answers, int[][] commands){
        int[] answer = new int[commands.length];
        for(int i = 0; i < commands.length; i++){
            int start = commands[i][0] - 1;
            int end = commands[i][1] - 1;
            int[] newArr = new int[end - start + 1];
            System.arraycopy(answers, start, newArr, 0, newArr.length);
            Arrays.sort(newArr);
            answer[i] = newArr[commands[i][2] - 1];
        }
        return answer;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] array = {1, 5, 2, 6, 3, 7, 4};
        int[][] commands = {
                {2, 5, 3},
                {4, 4, 1},
                {1, 7, 3}
        };
        int[] answer = s.solution(array, commands);
        for(int i = 0; i < answer.length; i++){
            System.out.println(answer[i]);
        }
    }
}

