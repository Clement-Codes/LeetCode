class Solution {
    public int minGroups(int[][] intervals) {
        int[] start = new int[intervals.length];
        int[] end = new int[intervals.length];
        for (int i = 0; i < intervals.length; i++){
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        Arrays.sort(start);
        Arrays.sort(end);
        int count = 0, result = 0, i = 0, j = 0;
        while (i < intervals.length && j < intervals.length){
            if (start[i] <= end[j]){
                count += 1;
                i += 1;
            }
            else{
                count -= 1;
                j += 1;
            }
            result = Math.max(result, count);
        }
        return result;
    }
}