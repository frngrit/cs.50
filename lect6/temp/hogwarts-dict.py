import csv

houses = {
    "Slytherin": 0,
    "Ravenclaw": 0,
    "Hufflepuff": 0,
    "Gryffindor": 0,
}

with open("characters.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader: #go over all row
        #row is dict which key is col's name
        house = row['house']
        houses[house] += 1

for house in houses:
    print(f"{house}: {houses[house]}")