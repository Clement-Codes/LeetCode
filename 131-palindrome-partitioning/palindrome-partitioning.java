class Solution {
    public boolean palidrome(String s, int l, int r){
        while (l < r){
            if (s.charAt(l) != s.charAt(r)) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }

    public void partition(int i, String s, List<String> path, List<List<String>> result){
        if (i >= s.length()){
            result.add(List.copyOf(path));
            return;
        }
        for(int j = i; j < s.length(); j++){
            if (palidrome(s, i, j)){
                path.add(s.substring(i, j + 1));
                partition(j + 1, s, path, result);
                path.remove(path.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<List<String>>();
        List<String> path = new ArrayList<String>();
        partition(0, s, path, result);
        return result;
    }
}