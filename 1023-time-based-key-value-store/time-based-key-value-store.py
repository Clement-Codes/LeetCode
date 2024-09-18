class TimeMap:

    def __init__(self):
        self.timemap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.timemap:
            self.timemap[key] = []
        self.timemap[key].append([value, timestamp])

    def get(self, key: str, timestamp: int) -> str:
        result = ""
        values = self.timemap.get(key, [])
        l = 0
        r = len(values) - 1
        while l <= r:
            m = l + ((r - l) // 2)

            if values[m][1] == timestamp:
                result = values[m][0]
                break
            elif values[m][1] < timestamp:
                result = values[m][0]
                l = m + 1
            else:
                r = m - 1

        return result


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)