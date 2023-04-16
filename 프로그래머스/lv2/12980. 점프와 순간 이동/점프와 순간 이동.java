import java.util.*;

public class Solution {
    public int solution(int n) {
        int ans = 0;
        
        while (n > 0) {
            if (n % 2 == 0) {
                // 순간이동
                n = n/2;
            } else {
                // 점프
                ans++;
                n--;
            }
        }
        
        return ans;
    }
}