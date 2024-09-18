import java.util.Vector;
import java.util.HashMap;

class TimeMap {
    HashMap<String, Vector<Pair<String, Integer>>> time = new HashMap<String, Vector<Pair<String, Integer>>>();

    public TimeMap() {
        
    }
    
    public void set(String key, String value, int timestamp) {
        if(!time.containsKey(key)){
            Vector<Pair<String, Integer>> temp = new Vector<Pair<String, Integer>>();
            time.put(key, temp);
        }
        Pair<String, Integer> temp = new Pair<String, Integer>(value, timestamp);
        Vector<Pair<String, Integer>> temp2 = time.get(key);
        temp2.add(temp);
        time.put(key, temp2);
    }
    
    public String get(String key, int timestamp) {
        String result = "";
        if(!time.containsKey(key)) return result;
        Vector<Pair<String, Integer>> times = time.get(key);
        int l = 0;
        int r = times.size() - 1;
        while(l<=r){
            int m = l + ((r - l) / 2);

            if(times.get(m).getValue() == timestamp){
                result = times.get(m).getKey();
                break;
            }
            else if(times.get(m).getValue() < timestamp){
                result = times.get(m).getKey();
                l = m + 1;
            }
            else{
                r= m - 1;
            }
        }
        return result;
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */