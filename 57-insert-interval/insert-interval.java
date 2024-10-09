class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for (int i = 0; i < intervals.length; i++){
            if(newInterval[1] < intervals[i][0]){
                result.add(Arrays.asList(newInterval[0], newInterval[1]));
                for (int j = i; j < intervals.length; j++)
                    result.add(Arrays.asList(intervals[j][0], intervals[j][1]));
                int r[][] = new int[result.size()][result.get(0).size()];
                for (int ii = 0; ii < r.length; ii++)
                    for (int j = 0; j < r[0].length; j++)
                        r[ii][j] = result.get(ii).get(j);
                return r;
            }
            else if(newInterval[0] > intervals[i][1]){
                result.add(Arrays.asList(intervals[i][0], intervals[i][1]));
            }
            else{
                newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
                newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            }
        }
        result.add(Arrays.asList(newInterval[0], newInterval[1]));
        int r[][] = new int[result.size()][result.get(0).size()];
        for (int i = 0; i < r.length; i++)
            for (int j = 0; j < r[0].length; j++)
                r[i][j] = result.get(i).get(j);
        return r;
    }
}