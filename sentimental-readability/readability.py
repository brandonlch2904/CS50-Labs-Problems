def main():
    # Get text
    Text = input("Text: ")
    # Number of letters
    letters = letter_count(Text)
    print(letters)
    # Number of words
    words = word_count(Text)
    print(words)
    # Number of sentences
    sentences = sentence_count(Text)
    print(sentences)
    # Counting grades
    value = count_grade(letters, words, sentences)

    if value < 1:
        print("Before Grade 1")
    elif value > 0 and value < 16:
        print(f"Grade: {value}")
    else:
        print("Grade 16+")


def letter_count(Text):
    # Count number of letters
    letters = 0
    length = len(Text)

    for i in range(length):
        if Text[i].isupper() or Text[i].islower():
            letters += 1

    return letters


def word_count(Text):
    # Count number of words
    words = 1
    length = len(Text)

    for i in range(length):
        if Text[i].isspace():
            words += 1

    return words


def sentence_count(Text):
    # Count number of sentences
    sentences = 0
    ascii = 0
    length = len(Text)

    for i in range(length):
        ascii = ord(Text[i])
        if ascii == 46 or ascii == 63 or ascii == 33:
            sentences += 1

    return sentences


def count_grade(letters, words, sentences):
    # Count value for grade
    L = letters / words * 100
    S = sentences / words * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    value = round(index)
    return value


main()
