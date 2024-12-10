class Solution {
    public int maximumLength(String s) {
        HashMap<String, Integer> memo = new HashMap<String, Integer>();
        for (int i = 0; i < s.length(); i++){
            StringBuilder ss = new StringBuilder();
            for (int j = i; j < s.length(); j++){
                if (ss.length() == 0 || ss.toString().charAt(ss.length() - 1) == s.charAt(j))
                {
                    ss.append(s.charAt(j));
                    memo.put(ss.toString(), 1 + (memo.containsKey(ss.toString()) ? memo.get(ss.toString()) : 0));
                }
                else{
                    break;   
                }
            }
        }
        int result = 0;
        for(Map.Entry<String, Integer> i: memo.entrySet()){
            if (i.getValue() > 2 && result < i.getKey().length())
                result = i.getKey().length();
        }
        return result == 0 ? -1 : result;
    }
}