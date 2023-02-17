# Prompt user for height of pyramid
while True:
    try:
        # Only accepts value of 1 to 8
        height = int(input("Height: "))
        if height <= 0 or height >= 9:
            print("Only accepts 1 - 8")
            continue
        break
    except:
        print("Only accepts integer!")
        continue


for x in range(height):
    # Print spaces
    for y in range(height - (x+1)):
        print(" ", end="")

    # Print symbol
    print("#" * (x+1), end="")

    # Print spaces in between
    print(" " * 2, end="")

    # Print symbol
    print("#" * (x+1))
