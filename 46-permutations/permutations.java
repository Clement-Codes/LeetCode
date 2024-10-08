class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> temp = new ArrayList<Integer>();
        result.add(temp);
        for(int i: nums){
            List<List<Integer>> permutations = new ArrayList<List<Integer>>();
            for(List<Integer> t: result){
                for(int j = 0; j < t.size() + 1; j++){
                    List<Integer> tt = new ArrayList<Integer>(t);
                    tt.add(j, i);
                    permutations.add(tt);
                }
            }
            result = permutations;
        }
        return result;
        // if (nums.length == 0){
        //     List<List<Integer>> temp = new ArrayList<List<Integer>>();
        //     List<Integer> temp2 = new ArrayList<Integer>();
        //     temp.add(temp2);
        //     return temp;
        // } 
        // List<List<Integer>> per = permute(Arrays.copyOfRange(nums, 1, nums.length));
        // List<List<Integer>> result = new ArrayList<List<Integer>>();
        // for(int ii: nums) System.out.println(ii);
        // System.out.println(per);
        // for(List<Integer> t: per){
            
        //     for(int j = 0; j < t.size() + 1; j++){
        //         List<Integer> tt = new ArrayList<Integer>(t);
        //         tt.add(j, nums[0]);
        //         result.add(tt);
        //     }
        // }
        // return result;
    }
}