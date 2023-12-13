string = input("Number: ")
rev_string = string[::-1]
#for i in range(len(string)):
    #print(rev_string[i])
#number = int(rev_string)
sum1 = 0
sum2 = 0
#for i in range(len(str(number))):
for i in range(len(rev_string)):
    if (i % 2 == 0):
        sum1 += int(rev_string[i])
print(rev_string)
print(sum1)
#for i in range(len(str(number))):
for i in range(len(rev_string)):
    if (i % 2 == 1):
        num2 = 2 * int(rev_string[i])
        print(num2)
        if num2 > 9:
            num2 = (num2 // 10) +  (num2 % 10)
            print(num2)
        sum2 += num2
    print(sum2)
sum = sum1 + sum2
print(sum)
if sum % 10 == 0:
    print("TRUE")
else:
    print("FALSE")

