class Node():
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.left = Node(0,0)
        self.right = Node(0,0)
        self.left.next = self.right
        self.right.prev = self.left
        self.store = {}

    def remove(self, n):
        p, nn = n.prev, n.next
        p.next = nn
        nn.prev = p
        
    
    def add(self, n):
        p = self.right.prev
        p.next = n
        n.prev = p
        self.right.prev = n
        n.next = self.right

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key in self.store:
            temp = self.store[key]
            self.remove(temp)
            self.add(temp)
            return temp.value
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
        if key in self.store:
            self.remove(self.store[key])
            del self.store[key]


        self.store[key] = Node(key, value)
        self.add(self.store[key])
        
        if len(self.store)  > self.capacity:
            del self.store[self.left.next.key]
            self.remove(self.left.next)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)