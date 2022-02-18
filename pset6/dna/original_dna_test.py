import csv
import sys

# Ensure correct usage
if len(sys.argv) != 3:
    print("Usage: python tournament.py CSV text.file")
    sys.exit(1)

# - DNA dict -
# - STRS list -
# Read the dna/dna_data into memory from csv

strs = []
with open(sys.argv[1], "r") as file:
    reader1 = csv.reader(file)
    strs = file.readline().strip().split(",")
    strs.pop(0)

# print(strs)

dna_data = []
with open(sys.argv[1], "r") as file:
    reader2 = csv.DictReader(file)
    dna_data = list(reader2)
    
# print(dna_data)
   
# - DNA_sequence -
# Read the data_text into memory from text.file
with open(sys.argv[2], "r") as file:
    reader = csv.reader(file)
    dna_sequence = file.readline().rstrip()
        
# print(dna_sequence)

tmp = {}
for i in range(len(strs)):
    L = len(strs[i])
    max_counter = 0
    
    for j in range(len(dna_sequence)):
        counter = 0
        
        if dna_sequence[j: j + L] == strs[i]:
            counter += 1
            
            while dna_sequence[j: j + L] == dna_sequence[j + L: j + (2 * L)]:
                counter += 1
                j += L
            
            if counter > max_counter:
                max_counter = counter
                
    tmp[strs[i]] = str(max_counter)
 
#     print(max_counter)
# print(tmp)


for i in range(len(dna_data)):
    counter = 0
    for j in range(len(strs)):
        if dna_data[i][strs[j]] == tmp[strs[j]]:
            counter += 1
    if counter == len(strs):
        print(dna_data[i]['name'])
        exit(0)
    else:
        continue

print("No match")
exit(1)


#  ------ note ------
# a[start:stop]  items start through stop-1
# a[start:]      items start through the rest of the array
# a[:stop]       items from the beginning through stop-1
# a[:]           a copy of the whole array