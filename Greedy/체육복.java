import java.util.*;

public class Solution {
    public static int solution(int n, int[] lost, int[] reserve) {
        // 여벌의 운동복을 갖고 있는 사람이 운동복을 도난당했을 경우 --> 남은 운동복 : 1
        int answer = 0;
        int[] current = new int[n + 1];
        for (int i = 0; i < lost.length; i++) {
            current[lost[i]]--;
        }
        for (int i = 0; i < reserve.length; i++) {
            current[reserve[i]]++;
        }
        // for(int i = 1; i < current.length; i++){
        // System.out.printf("%d ", current[i]);
        // } System.out.println("");
        int idx = 1;
        while (idx < current.length) {
            if (current[idx] == 1) {
                if (idx > 1 && current[idx - 1] == -1) {
                    current[idx - 1]++;
                    current[idx]--;
                } else if (idx < current.length - 1 && current[idx + 1] == -1) {
                    current[idx + 1]++;
                    current[idx]--;
                }
            }
            idx++;
        }
        // for(int i = 1; i < current.length; i++){
        // System.out.printf("%d ", current[i]);
        // } System.out.println("");
        for (int i = 1; i < current.length; i++) {
            if (current[i] >= 0) {
                answer++;
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int lenLost, lenReserve;
        lenLost = sc.nextInt();
        int[] lost = new int[lenLost];
        for (int i = 0; i < lenLost; i++) {
            lost[i] = sc.nextInt();
        }
        lenReserve = sc.nextInt();
        int[] reserve = new int[lenReserve];
        for (int i = 0; i < lenReserve; i++) {
            reserve[i] = sc.nextInt();
        }
        System.out.println(solution(n, lost, reserve));
    }
}