import java.util.Deque;
import java.util.ArrayDeque;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> q = new ArrayDeque<Integer>();
        int result[] = new int[nums.length+1-k];
        int l = 0;
        int r = 0;
        while(r < nums.length){
            while ( q.size() > 0 && nums[q.peekLast()] < nums[r]) q.removeLast();
            q.addLast(r);

            if (l > q.peekFirst()) q.removeFirst();

            if (r+1 >= k){
                l += 1;
                result[(r+1) - k] = nums[q.peekFirst()];
            }
            r += 1;
        }
        return result;
    }
}