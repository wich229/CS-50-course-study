
# Getting User Input
text = input("text: ")
print(text)

# letters
n = len(text)
letters_sum = 0

for i in range(n):
    
    if text[i].isalpha():
        letters_sum += 1
    else:
        letters_sum = letters_sum + 0

print(f"letters: {letters_sum}")

# words ( 32 is ascii code "space")
words_sum = 0

for l in range(n):
    
    if text[l] == chr(32):
        words_sum += 1
    else:
        words_sum = words_sum + 0
        
words_sum = words_sum + 1
print(f"words: {words_sum}")

# sentences ( 33 = ! / 46 = . / 63 = ?)

sentences_sum = 0

for j in range(n):
    
    if text[j] == chr(33) or text[j] == chr(46) or text[j] == chr(63):
        sentences_sum += 1
    else:
        sentences_sum = sentences_sum + 0
        
print(f"sentences: {sentences_sum}")

# Putting it into Coleman-Liau index: index = 0.0588 * L - 0.296 * S - 15.8
# L is the average number of letters per 100 words in the text;  L=letters/words*100;
# S is the average number of sentences per 100 words in the text.  S=sentences/words*100;
# grad X; the number will be round (四捨五入);

L = float(letters_sum) / float(words_sum) * 100
S = float(sentences_sum) / float(words_sum) * 100
grade = float(0.0588 * L - 0.296 * S - 15.8)

# lower than 1="Before Grade 1"; higher than 16="Grade 16+"

if int(round(grade)) < 0:
    print("Before Grade 1")
elif int(round(grade)) > 16:
    print("Grade 16+")
else:
    print(f"Grade {int(round(grade))}")