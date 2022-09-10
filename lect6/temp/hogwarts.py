import csv

houses = {
    "Slytherin": 0,
    "Ravenclaw": 0,
    "Hufflepuff": 0,
    "Gryffindor": 0,
}

with open("characters.csv", "r") as file:
    reader = csv.reader(file)
    next(reader) #ignore the first line of the file
    for row in reader: #go over all row
        #there's three cols in CSV file
        #row is list of three string
        house = row[1]
        houses[house] += 1

for house in houses:
    print(f"{house}: {houses[house]}")