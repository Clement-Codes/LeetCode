class Solution {
public:
    struct comparator{
        bool operator()(const pair<int, char>& a, const pair<int, char>& b){
            return a.first < b.first;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, comparator> pq;
        string result = "";
        if (a > 0){
            pq.push(pair<int, char>(a, 'a'));
        }
        if (b > 0){
            pq.push(pair<int, char>(b, 'b'));
        } 
        if (c > 0){
            pq.push(pair<int, char>(c, 'c'));
        }
        while (pq.size() > 0){
            pair<int, char> first = pq.top();
            pq.pop();
            if (result.length() > 1 && result[result.size() - 1] == result[result.size() - 2] && result[result.size() - 1] == first.second){
                if (pq.size() == 0)
                    break;
                pair<int, char> second = pq.top();
                pq.pop();
                result += second.second;
                second.first -= 1;
                if (second.first > 0){
                    pq.push(second);
                }
            }
            else{
                result += first.second;
                first.first -= 1;
            }
            if (first.first > 0){
                pq.push(first);
            }
        }
        return result;
    }
};