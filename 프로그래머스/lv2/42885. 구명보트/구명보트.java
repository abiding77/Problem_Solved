import java.util.Arrays;

class Solution {
    public int solution(int[] people, int limit) {
        Arrays.sort(people);
        int ssize = people.length;
        int answer = 0;
        int left = 0, right = ssize - 1;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
            answer++;
        }
        return answer;
    }
}