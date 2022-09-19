import csv
titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()
        try:
            titles[title] += 1
        except KeyError:
            titles[title] = 1


# for title in sorted(titles):
#     print(title)

def get_value(title):
    return titles[title]


# for title in sorted(titles, key = get_value, reverse=True):
#     print(f"{title}: {titles[title]}")

import random
a = []
for i in range(10):
    n = (10 - random.randint(0,10)) * 10
    n += (10 - random.randint(i,10))
    a.append(n)

print(a)

def last_digit(numb):
    return numb % 10
print(sorted(a.copy(), key = last_digit))

