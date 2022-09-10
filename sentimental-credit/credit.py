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
    flag = True
    for s in str(credit_numb):
        if flag:
            luhn_check += int(s)
            flag = False
        else:
            luhn_check += 2 * int(s)
            flag = True
    print(luhn_check)
    str_luhn = str(luhn_check)
    if str_luhn[-1] == '0':
        return True
    return False

def main():
    credit_numb = get_int()

    print(luhn_checking(credit_numb))

main()