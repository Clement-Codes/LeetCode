class Twitter:

    def __init__(self):
        self.followers = defaultdict(set)
        self.feeds = defaultdict(list)
        self.count = 0

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.feeds[userId].append([self.count, tweetId])
        self.count -= 1

    def getNewsFeed(self, userId: int) -> List[int]:
        self.followers[userId].add(userId)
        news = []
        for f in self.followers[userId]:
            if f in self.feeds:
                index = len(self.feeds[f]) - 1
                news.append([self.feeds[f][index][0], self.feeds[f][index][1], index, f])
        heapq.heapify(news)
        result = []
        print(news)
        while news and len(result) < 10:
            
            temp = heapq.heappop(news)
            result.append(temp[1])
            if temp[2] - 1 >=0:
                heapq.heappush(news, [self.feeds[temp[3]][temp[2] - 1][0], self.feeds[temp[3]][temp[2] - 1][1], temp[2] - 1, temp[3]])

        return result

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followers[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followers[followerId]:
            self.followers[followerId].remove(followeeId)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)