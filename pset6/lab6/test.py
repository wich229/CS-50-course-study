import csv
import sys


if len(sys.argv) != 2:
    sys.exit("Usage: python tournament.py FILENAME")

teams = []
# TODO: Read teams into memory from file
team = {}
with open(sys.argv[1],"r") as file:
    reader = csv.DictReader(file)
    # print(list(reader))
    for row in reader:
        row['rating'] = int(row['rating'])
        teams.append(row)

print(teams)
   
