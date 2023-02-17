def main():
    # Get card number from user
    cardNumber = get_card()
    # Checksum
    checkSum = check_sum(cardNumber)
    # Check card length
    cardLength = length_cal(cardNumber)
    # Check starting digits
    startDigits = find_start(cardNumber)
    # Check card type
    cardType = check_card(cardLength, startDigits, checkSum)
    print(cardType)


def get_card():
    while True:
        try:
            # Prompt user for input
            cardNumber = int(input("Number: "))

            # Make sure value is positive
            if cardNumber <= 0:
                print("Only accepts positive value!")
                continue
            break

        except:
            # Make sure input is integer
            print("Only accepts integer!")
            continue

    return cardNumber


def check_sum(cardNumber):
    # Loop through each number
    totalFirst = 0
    totalSecond = 0
    while cardNumber > 0:

        # Get last digit
        for i in range(1):

            first = cardNumber % 10
            totalFirst += first
            cardNumber //= 10

        # Get second last digit
        for i in range(1):

            second = cardNumber % 10
            secondmult = second * 2

            if secondmult > 9:
                secondmult = (secondmult % 10) + 1

            totalSecond += secondmult
            cardNumber //= 10

    totalSum = totalFirst + totalSecond
    return totalSum


def length_cal(cardNumber):
    count = 0
    # Count the length of card number
    while cardNumber > 0:
        cardNumber //= 10
        count += 1

    return count


def find_start(cardNumber):
    # Get first two digit
    while cardNumber > 99:
        cardNumber //= 10

    # Get first digit if starts with 4
    if cardNumber >= 40 and cardNumber <= 49:
        cardNumber //= 10

    return cardNumber


def check_card(cardLength, startDigits, checkSum):

    lastnum = checkSum % 10

    # Check whether the last digit of checkSum is 0
    if lastnum == 0 and cardLength >= 13 and cardLength <= 16:

        # AMEX
        if cardLength == 15 and (startDigits == 34 or startDigits == 37):
            cardType = "AMEX"
            return cardType

        # MASTERCARD
        elif cardLength == 16 and (startDigits > 50 and startDigits < 56):
            cardType = "MASTERCARD"
            return cardType

        # VISA
        elif startDigits == 4:
            cardType = "VISA"
            return cardType

        else:
            cardType = "INVALID"
            return cardType

    else:
        cardType = "INVALID"
        return cardType


main()