import time
import random

N = 1000000

# gen random array
rand = [random.randint(0,N) for i in range(N)]


def stopwatch(func):
    # get the start time
    st = time.time()

    # do the function
    print(func())
    # get the end time
    et = time.time()

    # get the execution time
    elapsed_time = et - st
    print(f"{func.__name__}: {elapsed_time} seconds")

def dict_version():
    # return number of non dubplicated numbers
    non_dub = []
    dict_numb = {}
    for num in rand:
        dict_numb[num] = True
    for num in rand:
        if dict_numb[num]:
            non_dub.append(num)
            dict_numb[num] = False
    n_non_dub = len(non_dub)
    return n_non_dub

def check_list():
    non_dub = []
    for num in rand:
        if num not in non_dub:
            non_dub.append(num)

    n_non_dub = len(non_dub)
    return n_non_dub

stopwatch(dict_version)

stopwatch(check_list)