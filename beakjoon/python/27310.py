user_input = input()

l = len(user_input)
countcolon = 0
count_ = 0
for i in l:
    if i == ':':
        countcolon += 1
    elif i == '_':
        count_ += 1

print(l + countcolon + count_)