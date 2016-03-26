import sys

class Node:
    def __init__(self, key, l=None, r=None, p=None):
        self.key = key
        self.left = l
        self.right = r
        self.parent = p

def LCA(root, key1, key2):
    if root is None:
        return None

    if key1 < root.key and key2 < root.key:
        return LCA(root.left, key1, key2)

    if key1 > root.key and key2 > root.key:
        return LCA(root.right, key1, key2)

    return root
         
if __name__ == '__main__':
    # open file
    f = open(sys.argv[1], 'r')
    
    # build tree, hard coded
    root = Node(30)
    root.left = Node(8)
    root.right = Node(52)
    root.right.parent = root
    root.left.parent = root
    root.left.left = Node(3)
    root.left.right = Node(20)
    root.left.left.parent = root.left
    root.left.right.parent = root.left
    root.left.right.left = Node(10)
    root.left.right.right = Node(29)
    root.left.right.left.parent = root.left.right
    root.left.right.right.parent = root.left.right

    # find LCAs
    lines = f.readlines()
    for l in lines:
        data = l.split()
        print LCA(root, int(data[0]), int(data[1])).key
