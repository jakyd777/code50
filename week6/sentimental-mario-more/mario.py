def main():
    height = get_height()
    for i in range(height):
        a = i + 1
        b = height - a
        print(" " * b + "#" * a + " " * 2 + "#" * a)


def get_height():
    while True:
        try:
            h = int(input("Height: "))
            if (h > 0 and h < 9):
                return h
        except ValueError:
            print("Not a valid value")


main()