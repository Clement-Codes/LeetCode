class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        encodedStr = ""
        for s in strs:
            encodedStr += str(len(s)) + "#" + s
        return encodedStr

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        i = 0
        decodedStr = []
        while i<len(s):
            j = i
            while s[j] != "#":
                j += 1
            index = int(s[i:j])
            decodedStr.append(s[j+1: j+1+index])
            i = j +1+index
            
        return decodedStr


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))