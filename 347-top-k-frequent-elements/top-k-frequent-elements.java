import java.util.HashMap;
import java.util.Vector;
import java.util.Map;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> counts = new HashMap<Integer, Integer> ();
        Vector<Vector<Integer>> bucket = new Vector<Vector<Integer>> (); 

        Vector<Integer> result = new Vector<Integer>();

        for(int i: nums){
            if(counts.get(i)==null){
                counts.put(i, 1);
            }else{
                counts.put(i, counts.get(i) + 1);
            }
        }

        for(int i = 0; i < nums.length + 1; i++){
            Vector<Integer> temp = new Vector<Integer>();
            bucket.add(temp);
        }

        for(Map.Entry<Integer, Integer> kv: counts.entrySet()){
            bucket.get(kv.getValue()).add(kv.getKey());
        }

        for(int i = bucket.size()-1; i>=0; i--){
            if(!bucket.get(i).isEmpty()){
                for(int j: bucket.get(i)){
                    result.add(j);
                }
                if(result.size() == k){
                    break;
                }
            }
        }
        System.out.println(counts);
        int results[] = new int[result.size()];
        int i =0;
        for (int temp : result){
            results[i] = temp;
            i++;
        }
        return results;
    }
}