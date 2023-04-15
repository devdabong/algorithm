import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        Map<Integer, Integer> map = new HashMap<>();
        int sum = brown + yellow; 
        for (int i = 1; i <= sum; i++) {
            if (sum % i == 0 && sum / i > 2 && i > 2) {
                map.put(i, sum/i);
            }
        }
        for (int key : map.keySet()) {
            int val = map.get(key);
            if (yellow == (key-2)*(val-2)) {
                answer[0] = Math.max(key, val);
                answer[1] = Math.min(key, val);
                break;
            }
        }
        
        
        return answer;
    }
}