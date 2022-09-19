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

for title in titles:
    print(f"{title}: {titles[title]}")
