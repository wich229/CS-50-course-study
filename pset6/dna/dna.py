import csv
import sys


def main():
    
    # Ensure correct usage
    if len(sys.argv) != 3:
        print("Usage: python tournament.py CSV text.file")
        sys.exit(1)
    
    # - STRS list -
    strs = []
    with open(sys.argv[1], "r") as file:
        reader1 = csv.reader(file)
        strs = file.readline().strip().split(",")
        strs.pop(0)
  
    print(strs)

    # - DNA dict - 
    dna_data = []
    with open(sys.argv[1], "r") as file:
        reader2 = csv.DictReader(file)
        dna_data = list(reader2)
        
    print(reader2)
    
    # - DNA_sequence -
    with open(sys.argv[2], "r") as file:
        reader = csv.reader(file)
        dna_sequence = file.readline().rstrip()
        
    # print(dna_sequence)
    
    # finding the person or no match
    tmp = repeatsFinder(dna_sequence, strs)
    # print(tmp)
    result = matching(tmp, strs, dna_data)
    print(result)
    

def repeatsFinder(dna_sequence, strs):
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
    
    return tmp


def matching(tmp, strs, dna_data):
    for i in range(len(dna_data)):
        counter = 0
        for j in range(len(strs)):
            if dna_data[i][strs[j]] == tmp[strs[j]]:
                counter += 1
        if counter == len(strs):
            return dna_data[i]['name']
            exit(0)
        else:
            continue

    return "No match"
    exit(1)
    
    
if __name__ == "__main__":
    main()
    
#  ------ note ------
# a[start:stop]  items start through stop-1
# a[start:]      items start through the rest of the array
# a[:stop]       items from the beginning through stop-1
# a[:]           a copy of the whole array