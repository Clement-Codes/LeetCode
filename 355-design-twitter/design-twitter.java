class Twitter {
    HashMap<Integer, HashSet<Integer>> followers;
    HashMap<Integer, List<List<Integer>>> feeds;
    int count = 0;

    public Twitter() {
        followers = new HashMap<Integer, HashSet<Integer>>();
        feeds = new HashMap<Integer, List<List<Integer>>>();
    }
    
    public void postTweet(int userId, int tweetId) {
        List<Integer> temp1 = new ArrayList<Integer>(Arrays.asList(count, tweetId));
        List<List<Integer>> temp2;
        if(feeds.containsKey(userId)){
            temp2 = feeds.get(userId);
        }else{
            temp2 = new ArrayList<List<Integer>>();
        }
        temp2.add(temp1);
        feeds.put(userId, temp2);
        count += 1;
    }
    
    public List<Integer> getNewsFeed(int userId) {

        HashSet<Integer> temp1;
        if(followers.containsKey(userId)){
            temp1 = followers.get(userId);
        }else{
            temp1 = new HashSet<Integer>();
        }
        temp1.add(userId);
        followers.put(userId, temp1);
        PriorityQueue <List<Integer>> pq = new PriorityQueue <>(new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> o1, List<Integer> o2) {
                return Integer.compare(o2.get(0), o1.get(0));
            }
        });
        for(int i: followers.get(userId)){
            if(feeds.containsKey(i)){
                int index = feeds.get(i).size() - 1;
                List<Integer> temp2 = new ArrayList<Integer>(Arrays.asList(feeds.get(i).get(index).get(0), feeds.get(i).get(index).get(1), index - 1, i));
                pq.add(temp2);
            }
        }
        List<Integer> result = new ArrayList<Integer>();
        while (pq.size()> 0 && result.size() < 10){
            List<Integer> temp = pq.peek();
            result.add(temp.get(1));
            int index = temp.get(2);
            if (index >= 0){
                int userIds = temp.get(3);
                List<Integer> temp2 = new ArrayList<Integer>(Arrays.asList(feeds.get(userIds).get(index).get(0), feeds.get(userIds).get(index).get(1), Integer.valueOf(temp.get(2) - 1), temp.get(3)));
                pq.add(temp2);
            } 
            pq.remove();
        }
        return result;
    }
    
    public void follow(int followerId, int followeeId) {
        HashSet<Integer> temp;
        if(followers.containsKey(followerId)){
            temp = followers.get(followerId);
        }else{
            temp = new HashSet<Integer>();
        }
        temp.add(followeeId);
        followers.put(followerId, temp);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (followers.containsKey(followerId)){
            HashSet<Integer> temp = followers.get(followerId);
            temp.remove(followeeId);
            followers.put(followerId, temp);
        }
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */