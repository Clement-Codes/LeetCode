class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s: strs){
            encoded += to_string(s.length()) + '#' + s; 
        }
        cout << encoded;
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i<s.length()){
            int j = i;
            while(s[j]!='#'){
                j+=1;
            }
            string in = s.substr(i, j-i);
            int index = stoi(in);
            decoded.push_back(s.substr(j+1, index));
            i = j+1+index;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));