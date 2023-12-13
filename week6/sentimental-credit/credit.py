def main():    # main function to get input from user
    while True:
        try:
            number = input("Number: ")
            int_number = int(number)
            if int_number > 0:  # checkong if input is positive integer
                break
        except ValueError:  # in case of invalid input (not integer) printing error message
            print("Invalid input")

    if card_check(number):  # calling card validation function
        print_card_brand(number)  # printing card brand
    else:
        print("INVALID")


def card_check(card_num):
    rev_card_number = card_num[::-1]  # reversing string
    sum1 = 0
    sum2 = 0
    for i in range(len(rev_card_number)):  # computing sum of odd integers in revers string
        if (i % 2 == 0):
            sum1 += int(rev_card_number[i])
    for i in range(len(rev_card_number)):   # computing sum of even integers in revers string
        if (i % 2 == 1):
            num2 = 2 * int(rev_card_number[i])
            if num2 > 9:
                num2 = (num2 // 10) + (num2 % 10)
            sum2 += num2
    sum = sum1 + sum2
    if sum % 10 == 0:  # returning True if sum is ending with 0
        return True
    else:
        return False


def print_card_brand(card_num):
    card_number = int(card_num)
    if (card_number >= 34e13 and card_number < 35e13) or (card_number >= 37e13 and card_number < 38e13):
        print("AMEX")  # checking if card is AMEX number
    elif card_number >= 51e14 and card_number < 56e14:
        print("MASTERCARD")  # checking if card is MASTERCARD number
    elif (card_number >= 4e12 and card_number < 5e12) or (card_number >= 4e15 and card_number < 5e15):
        print("VISA")  # checking if card is VISA number
    else:
        print("INVALID")


if __name__ == "__main__":
    main()