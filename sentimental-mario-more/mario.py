# TODO

while True:
    try:
        # convert string input into int input
        n = int(input("Height: "))
        # check if n > 0 if true then break the loop
        if n >= 1 and n <= 8:
            break
    except:
        # if n is unable to convert to int re prompt
        pass

for i in range(n):
    # print the space and #
    print(f"{' '*(n-i-1)}{'#'*(i+1)}  {'#'*(i+1)}")