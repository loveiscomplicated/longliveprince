base_integer = input('Enter the base integer: ')
integer_1 = input('Enter leftmost digit: ')
integer_2 = input('Enter the next digit: ')
integer_3 = input('Enter the next digit: ')
integer_4 = input('Enter the last digit: ')

num = integer_1 + integer_2 + integer_3 + integer_4
result = int(num, base = int(base_integer))

print(f'Your input is {num} in base {base_integer}')
print(f'The value is {result} in base 10')