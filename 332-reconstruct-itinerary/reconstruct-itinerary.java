class Solution {
    public void dfs(HashMap<String, List<String>> m, List<String> result, String node){
        if (m.containsKey(node)){
            List<String> temp = m.get(node);
            while (temp.size()>0){
                String t = temp.get(0);
                temp.remove(0);
                m.put(node, temp);
                dfs(m, result, t);
            }
        }
        result.add(node);
    }

    public List<String> findItinerary(List<List<String>> tickets) {
        HashMap<String, List<String>> mapper = new HashMap<String, List<String>>();
        for (List<String> temp: tickets){
            List<String> t = mapper.getOrDefault(temp.get(0), new ArrayList<String>());
            t.add(temp.get(1));
            mapper.put(temp.get(0), t);
        }

        for (Map.Entry<String, List<String>>i: mapper.entrySet()){
            Collections.sort(mapper.get(i.getKey()));
        }

        List<String> result = new ArrayList<String>();
        dfs(mapper, result, "JFK");

        Collections.reverse(result);
        return result.size() == tickets.size() + 1 ? result : new ArrayList<String>();         
    }
}