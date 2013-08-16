#coding: utf-8

#判断一个链表中是否有环，以两个速度在同一节点同时出发看是否相遇即可，可以理解成环行路上两辆车以不同速度出发最后相遇。
#为了找到环中的起始节点，让一个从距链表起始位置环长度L处出发，另一个在链表起始处出发，相同速度前进，相遇处即是环起始位置。


class Node(object):
    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node


def find_ring_head(node):
    m = set()
    a, b = node.next_node.next_node, node.next_node
    cnt = 1
    while True:
        if a == b:
            b = b.next_node
            while b.value != a.value:
                cnt += 1
                b = b.next_node
            break
        a = a.next_node.next_node
        b = b.next_node
    a, b = node, node
    for i in range(cnt):
        a = a.next_node
    while True:
        if a == b:
            return a
        a = a.next_node
        b = b.next_node


q = Node('a')
w = Node('b')
e = Node('c')
r = Node('d')
t = Node('e')
q.next_node = w
w.next_node = e
e.next_node = r
r.next_node = t
t.next_node = e

print find_ring_head(q).value
