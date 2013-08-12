def replace(s):
    t = [c if c != ' ' else '%20' for c in s]
    return ''.join(t)


print replace('123456')
print replace('1 23 43 as')
