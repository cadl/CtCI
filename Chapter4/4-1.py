class Node(object):
    def __init__(self, val, left=None, right=None):
        self.value = val
        self.left = left
        self.right = right


def traverse_tree(node, depth):
    if not node:
        return (depth-1, depth-1)
    ret = [traverse_tree(node.left, depth+1), traverse_tree(node.right, depth+1)]
    max_depth = max(ret, key=lambda x: x[0])[0]
    min_depth = min(ret, key=lambda x: x[1])[1]
    return (max_depth, min_depth)


def is_balance((max_depth, min_depth)):
    if max_depth > min_depth + 1:
        return False
    else:
        return True


tree1 = Node(1, Node(2, Node(4, Node(5))), Node(3))
tree2 = Node(1, Node(2), Node(3, Node(4)))
tree3 = Node(1)
tree4 = None

print is_balance(traverse_tree(tree1, 0))
print is_balance(traverse_tree(tree2, 0))
print is_balance(traverse_tree(tree3, 0))
print is_balance(traverse_tree(tree4, 0))
