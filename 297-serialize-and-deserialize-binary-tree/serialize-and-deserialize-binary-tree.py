# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        self.serializeResult = []
        self.serializeDFS(root)
        return ','.join(self.serializeResult)

    def serializeDFS(self, root):

        if not root: 
            self.serializeResult.append('N')
            return
        
        self.serializeResult.append(str(root.val))
        self.serializeDFS(root.left)
        self.serializeDFS(root.right)



    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        self.i = 0
        self.d = data.split(',')
        return self.deserializeDFS()

    def deserializeDFS(self):
        if self.d[self.i] == 'N':
            self.i += 1
            return None
        node = TreeNode(int(self.d[self.i]))
        self.i += 1
        node.left = self.deserializeDFS()
        node.right = self.deserializeDFS()
        return node

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))