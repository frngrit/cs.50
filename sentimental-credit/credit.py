# TODO

# AMX 15-digit, start with 34-37
# MTC 16-digit, start with 51, 52, 53, 54, 55
# VIS 13-16 digit start with 4

def get_int():
    while True:
        try:
            credit_numb = int(input("Number: "))
            return credit_numb
        except:
            pass

# check if credit numb is valid with Luhn's algorithm
def luhn_checking(credit_numb):
    luhn_check = 0
    flag = False
    for s in str(credit_numb):
        if flag:
            luhn_check += int(s)
            flag = False
        else:
            if int(s) > 5:
                temp = int(s) * 2
                luhn_check += temp % 10
                luhn_check += temp // 10
            else:
                luhn_check += 2 * int(s)
            flag = True
        print(luhn_check)




    if luhn_check%10 == 0:
        return True
    return False

def main():
    credit_numb = get_int()

    print(luhn_checking(credit_numb))

main()