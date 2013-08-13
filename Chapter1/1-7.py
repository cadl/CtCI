def set_zero(m):
    length = len(m)
    flag_x = [False for x in range(length)]
    flag_y = [False for x in range(length)]
    for i in range(length):
        for j in range(length):
            if m[i][j] == 0:
                flag_x[i] = True
                flag_y[j] = True
    for i in range(length):
        for j in range(length):
            if flag_x[i] or flag_y[j]:
                m[i][j] = 0
    return m


a = [[1, 1, 0, 0], [1, 0, 1, 1], [1, 0, 1, 1], [1, 1, 1, 1]]


for i in range(4):
    print ''.join(str(x) for x in a[i])

b = set_zero(a)

for i in range(4):
    print ''.join(str(x) for x in b[i])
