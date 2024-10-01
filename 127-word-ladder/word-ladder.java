class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) return 0;

        HashMap<String, List<String>> mapper = new HashMap<String, List<String>>();
        wordList.add(beginWord);

        for (String word: wordList){
            for (int i = 0; i < word.length(); i++){
                List<String> temp = mapper.getOrDefault(word.substring(0, i) + '*' + word.substring(i + 1, word.length()), new ArrayList<String>());
                temp.add(word);
                mapper.put(word.substring(0, i) + '*' + word.substring(i + 1, word.length()), temp);
            }
        }

        Queue<String> q = new LinkedList<String>();
        HashSet<String> visited = new HashSet<String>();
        q.add(beginWord);
        visited.add(beginWord);
        int result = 1;

        while(q.size()>0){
            int l = q.size();
            for(int i = 0; i < l; i++){
                String temp = q.poll();

                if (temp.equals(endWord)) return result;
                for (int j = 0; j < temp.length(); j++){
                    for (String t: mapper.getOrDefault(temp.substring(0, j) + "*" + temp.substring(j + 1, temp.length()), new ArrayList<String>())){
                        if (!visited.contains(t)){
                                q.add(t);
                                visited.add(t);
                        }
                    }
                }
            }

            result += 1;
        }
        return 0;
    }
}