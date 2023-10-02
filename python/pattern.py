def pypart(n):
    # Loop through each row up to n
    for i in range(1, n + 1):
        # Print the star pattern for the current row using string multiplication
        # i.e., for i=3, it'll print "* * * "
        print("* " * i)

# Driver Code

# Prompt the user to enter the desired number of rows
n = int(input("Enter the number of rows: "))

# Call the function to print the pattern for the specified number of rows
pypart(n)
