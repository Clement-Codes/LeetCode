#include<unordered_map>
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timemap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        string result = "";

        auto& timestamps = timemap[key];

        int l = 0, r = timestamps.size() - 1;

        while(l <= r){
            int m = l + ((r - l) / 2);
            if(timestamps[m].first <= timestamp){
                result = timestamps[m].second;
                l = m + 1; 
            }
            else r = m - 1;
            
        }
        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */