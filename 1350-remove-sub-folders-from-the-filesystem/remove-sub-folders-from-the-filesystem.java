class Solution {
    public List<String> removeSubfolders(String[] folder) {
        List<String> result = new ArrayList<String>();
        HashSet<String> cache = new HashSet<String>();
        for (String i: folder) cache.add(i);
        for (String i: folder){
            result.add(i);
            for (int j = 0; j < i.length(); j++){
                if (i.charAt(j) == '/' && cache.contains(i.substring(0, j))){
                    result.remove(result.size() -1 );
                    break;
                }
            }
        }
        return result;
    }
}