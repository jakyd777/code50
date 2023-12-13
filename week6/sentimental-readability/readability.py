import re


def main():
    text_to_judge = input("Text: ")  # getting text from user
    letters_number = count_letters(text_to_judge)
    words_number = count_words(text_to_judge)
    sentences_number = count_sentences(text_to_judge)

    av_letters = letters_number / words_number * 100  # average number of letters per 100 words
    av_sentences = sentences_number / words_number * 100  # average number of sentences per 100 words
    index = (0.0588 * av_letters) - (0.296 * av_sentences) - 15.8  # Calculating index number
    if index < 1:
        print("Before Grade 1")  # decision making conditions for grade value
        return 0
    if index >= 16:
        print("Grade 16+")
        return 0
    if index >= 1 or index < 16:
        print(f"Grade {round(index)}")
        return 0


def count_letters(text):  # function for counting letters
    a = 0
    for i in text:
        if (i.isalpha()):
            a += 1
    return a


def count_words(text):  # function for counting words
    w = 0
    words = re.split(" ", text)
    w = len(words)
    return w


def count_sentences(text):  # function for counting sentences
    s = 0
    words = re.split(" ", text)
    for j in words:
        for k in j:
            if k == "." or k == "!" or k == "?":
                s += 1
    return s


if __name__ == "__main__":
    main()