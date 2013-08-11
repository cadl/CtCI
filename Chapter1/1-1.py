def is_unique(str):
    flag = 0
    for char in str:
        if flag & 1 << (ord(char) - ord('a')) != 0:
            return False
        flag = flag | 1 << (ord(char) - ord('a'))
    return True


print is_unique('aabcdd')
print is_unique('')
print is_unique('abc')
