def subset(s):
    if not s:
        return [[]]
    a = s.pop()
    sub = subset(s)
    return sub + [x + [a] for x in sub]


s = [1, 2, 3, 4, 5]

a = subset(s)
a.sort()
print a, len(a)
