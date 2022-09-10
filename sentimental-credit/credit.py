# TODO

# AMX 15-digit, start with 34-37
# MTC 16-digit, start with 51, 52, 53, 54, 55
# VIS 13-16 digit start with 4

def check_type(credit_numb):
    str_credit = str(credit_numb)

    first_two = str_credit[:2]
    n = len(str_credit)

    # check if it's 15 digit and start with 34 or 37
    if n == 15 and (int(first_two) == 34 or int(first_two) == 37):
        print('AMEX')
        return
    # check if it's 16-digit and start with 51, 52, 53, 54, 55
    if n == 16 and int(first_two) >= 51 and int(first_two) <= 55:
        print('MASTERCARD')
        return
    # check if it's 13-16 digit start with 4
    if n >= 13 and n <= 16 and int(first_two[0]) == 4:
        print('VISA')
        return
    # if it's none of all print invalid
    print('INVALID')
    return


def get_int():
    while True:
        try:
            credit_numb = int(input("Number: "))
            return credit_numb
        # if unable to convert credit into int do it again
        except:
            pass

# check if credit numb is valid with Luhn's algorithm


def luhn_checking(credit_numb):
    luhn_check = 0
    flag = True
    for s in str(credit_numb)[::-1]:
        # if it's odd digit do not multiply 2
        if flag:
            luhn_check += int(s)
            # switch variable
            flag = False
        else:
            if int(s) >= 5:
                # if the digit is more than 5 plus it seperately
                temp = int(s) * 2
                luhn_check += temp % 10
                luhn_check += temp // 10
            else:
                luhn_check += 2 * int(s)
            # switch variable
            flag = True
    # check if last digit is 0
    if luhn_check % 10 == 0:
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
