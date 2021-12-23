import java.util.Scanner;
import java.util.Arrays;

public class Solution {
    public int[] solution(int[] answers){
        int[] answer = new int[1];
        int[] count = new int[3];
        int[][] lotto = {
                {1, 2, 3, 4, 5},
                {2, 1, 2, 3, 2, 4, 2, 5},
                {3, 3, 1, 1, 2, 2, 4, 4, 5, 5},
        };
        for(int i = 0; i < answers.length; i++){
            for(int j = 0; j < lotto.length; j++){
                if(answers[i] == lotto[j][i % lotto[j].length]){
                    count[j]++;
                }
            }
        }
        int max = count[0];
        int maxIdx = 0;
        for(int i = 1; i < count.length; i++){
            if(max < count[i]){
                max = count[i];
                maxIdx = i;
            }
        }
        System.out.printf("max: %d%n", max);
        answer[0] = maxIdx;
        for(int i = 0; i < count.length; i++){
            if(maxIdx == i) continue;
            if(max == count[i]){
                int n = answer.length;
                answer = Arrays.copyOf(answer, n + 1);
                answer[n] = i;
            }
        }
        Arrays.sort(answer);
        return answer;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] answers = new int[5];
        int[] answer = {};
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 5; i++) {
            answers[i] = sc.nextInt();
        }
        answer = s.solution(answers);
        for(int i = 0; i < answer.length; i++){
            System.out.println(answer[i] + 1);
        }
    }
}
