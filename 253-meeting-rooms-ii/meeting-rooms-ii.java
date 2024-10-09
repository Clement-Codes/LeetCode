class Solution {
    public int minMeetingRooms(int[][] intervals) {
        int start[] = new int[intervals.length];
        int end[] = new int[intervals.length];
        for (int i = 0; i < intervals.length; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        int s = 0, e = 0, result = 0, count = 0;
        while (s < intervals.length){
            if (start[s] < end[e]){
                count += 1;
                s += 1;
            }
            else{
                count -= 1;
                e += 1;
            }
            result = Math.max(result, count);
        }
        return result;
    }
}