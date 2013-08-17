class Node(object):
    def __init__(self, value, next_node=None):
        self.value = value
        self.next_node = next_node


class Stack(object):
    def __init__(self):
        self.top = None
        self.count = 0

    def push(self, value):
        n = Node(value)
        self.count += 1
        if self.top:
            n.next_node = self.top
            self.top = n
        else:
            self.top = n

    def pop(self):
        tmp = self.top.value
        self.top = self.top.next_node
        self.count -= 1
        return tmp


class SetOfStack(Stack):
    def __init__(self, size=2):
        self.size = size
        super(SetOfStack, self).__init__()

    def push(self, value):
        if not self.top or self.top.value.count >= self.size:
            super(SetOfStack, self).push(Stack())
        self.top.value.push(value)

    def pop(self):
        if self.top.value.count == 0:
            super(SetOfStack, self).pop()
        return self.top.value.pop()


stack = SetOfStack()
for i in range(5):
    stack.push(i)

for i in range(5):
    print stack.pop()
