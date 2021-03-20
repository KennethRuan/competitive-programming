a = int(input())
b = int(input())
num = ['2','3','4','5','7']
counter = 0
for i in range(a,b):
    digits = list(str(i))
    flippable = 0
    #Eliminating numbers that don't have rotateable digits
    if any(x in num for x in digits) == False:
        #If 6 is in the number check if 9 is in opposite index
        if '6' in digits:
            indices = [g for g, y in enumerate(digits) if y == "6"] #Finds index of all 6s
            for y in range(len(indices)):
                if digits[-(indices[y])-1] == '9' and digits.count('6') == digits.count('9'):
                    flippable -= 0
                else:
                    flippable -= 1
            #Removes all 6s and 9s from digits
            for y in range(len(digits)):
                if digits[y] == '6' or digits[y] == '9': 
                    digits[y] = ""
            #Checks if 6s and 9s and flippable and if without the 6s and 9s the number is a palindrome
            if flippable == 0 and digits == digits[::-1]:
                counter+=1
        #If there are no 6s then the number can't have 9s, also checks if number is a palindrome
        elif ('9' not in digits) and (digits == digits[::-1]):
            counter+=1
print(counter)