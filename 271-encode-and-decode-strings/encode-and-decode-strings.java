public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        String encoded = "";
        for(String s: strs){
            encoded += Integer.valueOf(s.length()) + "#" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        List<String> decoded= new ArrayList<String>();
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s.charAt(j) != '#'){
                j+=1;
            }
            int index = Integer.valueOf(s.substring(i,j));
            decoded.add(s.substring(j+1, j+1+index));
            i = j+1+index;
        }
        return decoded;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));