class Node(object):
    def __init__(self, val):
        self.value = val
        self.next_node = None


def remove_dup(pa):
    a = pa
    while a:
        b = a.next_node
        p = a
        while b:
            if b.value == a.value:
                p.next_node = b.next_node
            else:
                p = b
            b = b.next_node
        a = a.next_node
    return a


def print_list(pa):
    while pa:
        print pa.value
        pa = pa.next_node


l = [Node(i/3) for i in range(10)]        

for i in range(9):
    l[i].next_node = l[i+1]

print_list(l[0])

print "-" * 20
remove_dup(l[0])

print_list(l[0])
