class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingDouble(a -> a[0]));
        List<List<Integer>> temp = new ArrayList<List<Integer>>();
        temp.add(Arrays.asList(intervals[0][0],intervals[0][1]));
        for (int i = 1; i < intervals.length; i++){
            int last = temp.get(temp.size() - 1).get(1);
            if (last >= intervals[i][0]){
                temp.get(temp.size() - 1).set(1, Math.max(last, intervals[i][1]));
            }
            else{
                temp.add(Arrays.asList(intervals[i][0],intervals[i][1]));
            }
        }
        int result[][] = new int[temp.size()][temp.get(0).size()];
        for (int i = 0; i < temp.size(); i++)
            for (int j = 0; j < temp.get(0).size(); j++)
                result[i][j] = temp.get(i).get(j);
        return result;
    }
}