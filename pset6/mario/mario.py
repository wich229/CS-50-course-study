
while True:
    try:
        h = int(input("Height: "))
        if h > 0 and h < 9:
            break
    except ValueError:
        print("That's not an int.")

# column
for i in range(h):
    dot = h - i
    # row
    for j in range(1, dot):
        print(" ", end="")
    
    for k in range(i+1):
        print("#", end="")
    # middle space
    # for l in range(2):
    #     print(" ", end="")
    
    # for l in range(i+1):
    #     print("#", end="")
    # # print next line
    print()