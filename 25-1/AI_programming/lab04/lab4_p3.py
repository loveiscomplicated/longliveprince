# getting the user input to the program
user = int(input("Enter the taxable income in USD: "))

# initialize the result and then use if, elif, else
result = 0

if user <= 750:
    result = user * 0.02
    
elif user > 750 and user <= 2250:
    result += 7.5
    result += (user - 750) * 0.03
    
elif user > 2250 and user <= 3750:
    result += 37.5
    result += (user - 2250) * 0.06
    
elif user > 3750 and user <= 5250:
    result += 82.5
    result += (user - 3750) * 0.09
    
elif user > 5250 and user <= 7000:
    result += user * 0.03
    result += (user - 5250) * 0.1
    
else:
    result += user * 0.04
    result += (user - 7000) * 0.12
    

print(f"Tax due: {round(result)} USD")
print(f"Final income: {round(user - result)} USD")    