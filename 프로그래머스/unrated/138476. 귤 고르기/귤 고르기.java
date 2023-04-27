import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        int answer = 0;

        Arrays.sort(tangerine);
        
        int[] arr = new int[tangerine[tangerine.length-1]+1];
        for (int t : tangerine) {
            arr[t] += 1;
        }
        Arrays.sort(arr);
        
        int sum = 0;
        int cnt = 0;
        for (int i = arr.length-1; i >= 1; i--) {
            sum += arr[i];
            cnt++;
            if (k <= sum) {
                break;
            }
        }
        answer = cnt;
            
        return answer;
    }
}