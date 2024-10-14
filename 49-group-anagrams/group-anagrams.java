import java.util.HashMap;
import java.util.Vector;
import java.util.ArrayList;


class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> result = new ArrayList<List<String>>();
        HashMap<List<Integer>, List<String>> cache = new HashMap<List<Integer>, List<String>>();
        for (String str: strs){
            List<Integer>temp = new ArrayList<Integer>(Collections.nCopies(26,0));
            for (char i: str.toCharArray()){
                temp.set(i - 'a', temp.get(i - 'a') + 1);
            }
            List<String> t = cache.getOrDefault(temp, new ArrayList<String>());
            t.add(str);
            cache.put(temp, t);
        }
        return new ArrayList<>(cache.values());










        // List<List<String>> result = new ArrayList<List<String>>();
        // HashMap<List<Integer>, List<String>> results = new HashMap<List<Integer>, List<String>>();
        // for(String s: strs){
        //     List<Integer> count = new ArrayList<Integer>();
        //     for(int i = 0; i < 26; i++){
        //         count.add(0);
        //     }
        //     for(int c = 0; c < s.length(); c++){
        //         int index = (int)s.charAt(c) - (int)'a';
        //         count.set(index, count.get(index) + 1) ;
        //     }
        //     if(results.get(count) == null){
        //         List<String> temp = new ArrayList<String>();
        //         temp.add(s);
        //         results.put(count, temp);
        //     }else{
        //         results.get(count).add(s);
        //     }
        // }
        // for(List<String> i : results.values()){
        //      result.add(i);
        // }
        // return result;
    }
}