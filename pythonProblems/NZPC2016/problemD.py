inputArray = []

while True:
	stringInput = input()
	if stringInput == "#":
		break
	inputArray.append(stringInput)

for i in inputArray:
	properPalin = False
	for b in i:
		forwards = i.replace(b,"", 1)
		backwards = forwards [::-1]
		if forwards == backwards:
			print(forwards)
			properPalin = True
			break;
	if properPalin == False:
		print("not possible")