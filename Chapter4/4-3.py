import time

class Tree(object):
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def tree_insert(tree, vals):
    length = len(vals)
    if length == 0:
        return 0
    mid_val = vals[length/2]
    tree.val = mid_val
    left_tree = Tree()
    right_tree = Tree()
    tree.left = left_tree
    tree.right = right_tree
    a = tree_insert(left_tree, vals[:length/2])
    b = tree_insert(right_tree, vals[length/2+1:])
    return a + b + 1


def tree_output(tree):
    if tree.val:
        tree_output(tree.left)
        print tree.val, 
        tree_output(tree.right)


a = range(10)
tree = Tree()
print tree_insert(tree, a)
tree_output(tree)
