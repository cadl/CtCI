import random


class BSTreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None


class BSTree(object):
    def __init__(self):
        self.pa = None

    def insert(self, node):
        if not self.pa:
            self.pa = node
        else:
            now = self.pa
            while now:
                if node.val < now.val:
                    if now.left:
                        now = now.left
                    else:
                        now.left = node
                        node.parent = now
                        break
                else:
                    if now.right:
                        now = now.right
                    else:
                        now.right = node
                        node.parent = now
                        break
    def show(self, node):
        if node:
            self.show(node.left)
            print node.val
            self.show(node.right)

    def successor_of(self, node):
        if node.right:
            now = node.right
            while now.left:
                now = now.left
            return now
        else:
            now =  node
            while not now.parent.left == now:
                now = now.parent
            return now.parent


l = [random.randrange(1, 10) for i in range(10)]
print l
l = map(lambda x: BSTreeNode(x), l)
bstree = BSTree()
for i in l:
    bstree.insert(i)
bstree.show(bstree.pa)
print "%d's successor is %s" % (l[4].val, bstree.successor_of(l[4]).val)
