#coding:utf-8

class Node(object):
    def __init__(self, val, next_node=None):
        self.val = val
        self.next_node = next_node


class Stack(object):
    def __init__(self):
        self.top = None

    def push(self, val):
        n = Node(val)
        if self.top:
            n.next_node = self.top
        self.top = n

    def pop(self):
        n = self.top
        self.top = self.top.next_node
        return n

    def is_empty(self):
        if self.top:
            return False
        else:
            return True


class Queue(object):
    def __init__(self):
        self.stack_a = Stack()
        self.stack_b = Stack()

    def push(self, val):
        self.stack_a.push(val)

    def pop(self):
        while not self.stack_a.is_empty():
            self.stack_b.push(self.stack_a.pop().val)
        n = self.stack_b.pop()
        while not self.stack_b.is_empty():
            self.stack_a.push(self.stack_b.pop().val)
        return n


q = Queue()
q.push(1)
q.push(2)
q.push(3)

print q.pop().val
print q.pop().val
print q.pop().val
