input1 = int(input('Input integer 1: '))
input2 = int(input('Input integer 2: '))

if input1 > input2:
    num1 = input1
    num2 = input2
else:
    num1 = input2
    num2 = input1

share = num1 // num2
remainder = num1 % num2

while remainder != 0:
    num1 = num2
    num2 = remainder
    share = num1 // num2
    remainder = num1 % num2
    
gcd = num2
lcm = int(input1 * input2 / gcd)

print(f'The least common multiple of {input1} and {input2} is {lcm}')
