import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[2];
        
        //[탈락조건]
        //1. 이전 단어 끝말잇기 실패
        //2. 같은 단어 말하기
        int cnt = 1;
        List<String> list = new ArrayList<>();
        list.add(words[0]);
        for (int i = 1; i < words.length; i++) {
            if (words[i].charAt(0) == words[i-1].charAt(words[i-1].length()-1) &&
                !list.contains(words[i])) {
                list.add(words[i]);
                cnt++;
            } else {
                break;
            }
        }
        if (list.size() != words.length) {
            answer[0] = cnt % n + 1;
            answer[1] = list.size() / n + 1;
        }
        return answer;
    }
}