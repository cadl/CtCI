class Node(object):
    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node


def remove_node(node):
    if node.next_node == None:
        return False
    value = node.next_node.value
    node.next_node = node.next_node.next_node
    node.value = value
    return True


def show_list(node):
    while node:
        print node.value, 
        node = node.next_node
    print ''


a = Node(3, Node(4, Node(5)))
pa = Node(1, Node(2, a))

show_list(pa)
remove_node(a)
show_list(pa)
