# TODO

# AMX 15-digit, start with 34-37
# MTC 16-digit, start with 51, 52, 53, 54, 55
# VIS 13-16 digit start with 4

def check_type(credit_numb):
    str_credit = str(credit_numb)

    first_two = str_credit[:2]
    n = len(str_credit)
    print(n)
    print(first_two)
    if n == 15 and int(first_two) >= 34 and int(first_two) <= 37:
        print('AMEX')
        return
    if n == 16 and int(first_two) >= 51 and int(first_two) <= 55:
        print('MASTERCARD')
        return
    if n >= 13 and n <= 16 and int(first_two[0]) == 4:
        print('VISA')
        return
    print('INVALID')
    return


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

    if luhn_check%10 == 0:
        return True
    return False



def main():
    credit_numb = get_int()

    if not luhn_checking(credit_numb):
        print('INVALID')
        return
    check_type(credit_numb)
    return

main()