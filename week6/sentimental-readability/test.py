import re

text = input("text: ")
#length = len(text)

a = 0
for i in text:
    if(i.isalpha()):
        a += 1
print(a)

#print(length)

words = re.split(" ", text)
#print(words)
print(len(words))

s = 0
for j in words:
    for k in j:
        if k == "." or k == "!" or k =="?":
            s += 1
print(s)