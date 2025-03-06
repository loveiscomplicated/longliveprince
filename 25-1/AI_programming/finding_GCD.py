def gcd():
    try:
        a = int(input("Enter first number: "))
        b = int(input("Enter second number: "))
    except ValueError:
        print("Please enter a valid number")
    
    GCD = None

    if a < b: 
        m = b
        n = a
        
    elif a > b:
        m = a
        n = b
        
    else:
        GCD = a
        
    while GCD == None:
        R = m % n
        if R == 0:
            GCD = n
            break
        else:
            m = n
            n = R
            continue
        
    print(f"The GCD of {a} and {b} is {GCD}")
    
        
    
    
while True:
    gcd()
    print("\n")
    user_input = input("Do you want to continue? (y/n): ")
    if user_input == "n":
        break
