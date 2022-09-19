import csv
import re


titles = {}

counter = 0
with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        # try:
        #     titles[title] += 1
        # except KeyError:
        #     titles[title] = 1

        if re.search("^(OFFICE|THE.OFFICE)$", title):
            counter += 1

print(counter)
# for title in sorted(titles):
#     print(title)

# def get_value(title):
#     return titles[title]


# for title in sorted(titles, key = lambda title: titles[title], reverse=True):
#     print(f"{title}: {titles[title]}")

# from random import randint
# a = [ i * 10 + (10 - randint(i,10)) for i in range(10)]
# print(a)
# print(sorted(a, key = lambda x: x % 10))