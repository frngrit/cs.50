# TODO
import re

# prompt for user's string
text = input("Text: ")

# count for text length
i = len(text)

# count for letter in text
all_letters = re.findall("[a-zA-z]", text)
letters = len(all_letters)

# count for sentences
all_stoppers = re.findall("[.?!]", text)
sentences = len(all_stoppers)

# count for words
all_words = text.split()
words = len(all_words)

# calculate for index
index = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8
index = round(index)

# check if index more than or equal 16
if index >= 16:
    print("Grade 16+")
# check if index less than or equal 1
elif index <= 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")