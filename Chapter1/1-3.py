def remove_dup(s):
    s = list(s)
    length = len(s)
    p_index = 0
    for i in range(length):
        flag = False
        j = 0
        for j in range(p_index):
            if s[i] == s[j]:
                flag = True
                break
        if flag == False:
            s[p_index] = s[i]
            p_index += 1
    return ''.join(s[:p_index])


print remove_dup('aabc')
print remove_dup('abccc')
print remove_dup('abcccd')
print remove_dup('aaaaaa')
print remove_dup('')
