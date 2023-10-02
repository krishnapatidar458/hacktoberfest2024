def check(list1, val):
    for x in list1:
        if val >= x:
            return False
    return True
	
# Taking list input from user
input_list = input("Enter a list of numbers separated by spaces: ")
list1 = [int(item) for item in input_list.split()]

# Taking input from user for 'val'
val = int(input("Enter a value: "))

if check(list1, val):
    print("Yes")
else:
    print("No")
