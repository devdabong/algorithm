import java.util.*;

class Solution {
    public int calGcd(int a, int b) {
        int big = Math.max(a, b);
        int small = Math.min(a, b);
        int n = 0;
        while (big % small > 0) {
            n = big % small;
            big = small;
            small = n;
        }
        return small;
    }
    public int solution(int[] arr) {
        int answer = 0;
        
        Arrays.sort(arr);
        int gcd = calGcd(arr[0], arr[1]);
        int lcm = arr[0] * arr[1] / gcd;
        
        for (int i = 2; i < arr.length; i++) {
            int a = lcm;
            int b = arr[i];
            gcd = calGcd(a, b);
            lcm = a * b / gcd;
        }
        answer = lcm;
        
        return answer;
    }
}
