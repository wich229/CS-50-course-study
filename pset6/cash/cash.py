# from cs50 import get_float


# get number from user
# n = cash number
while True:
    try:
        # n = get_float("change owed: ")
        n = float(input("change owed: "))
        if n > 0:
            break
    except ValueError:
        print("That's not an number.")
        
# covert the dollars to cents
cents = round(n * 100)
# print(cents)

# qn = quarter number, dn = dime number, nn = nickel number, pn = penny number
qn = int(cents / 25)
# printf("%i\n",qn);

dn = int((cents % 25) / 10)
# printf("%i\n",dn);
     
nn = int((cents % 25 % 10) / 5)
# printf("%i\n",nn);
    
pn = int(cents - qn * 25 - dn * 10 - nn * 5)
# printf("%i\n",pn);

# print out the number of the coins;
coins = qn + dn + nn + pn
print(coins)