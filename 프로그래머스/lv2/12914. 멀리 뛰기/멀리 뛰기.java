class Solution {
    public long solution(int n) {
        long answer = 0;
        
        //피보나치 수열 f(n) = f(n-2) + f(n-1)
        //DP bottom-up 
        long[] arr = new long[n+1];
        if (n <= 2) {
            return n;
        } else {
        	arr[0] = 1;
        	arr[1] = 1;
        	for (int i = 2; i <= n; i++) {
        	    arr[i] = (arr[i-2] + arr[i-1]) % 1234567;
        	}
        	answer = arr[n];
        }
        return answer;
    }
}