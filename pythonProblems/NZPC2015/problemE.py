def switch(x):
	return{"R":0.55,"G":0.7,"B":0.8,"Y":0.85,"O":0.9,"W":0.95}[x]

numOfCustomers = int(input())
outputArray = []

for i in range(numOfCustomers):
	customerInput = input()
	inputArray = customerInput.split()

	newPrice = float(inputArray[0]) * switch(inputArray[1])
	if inputArray[2] == "C":
		newPrice *= 0.95
	if inputArray[3] == "P":
		if len(("$" + str(round(newPrice,2)))) == 5:
			outputArray.append(("$" + str(round(newPrice,2)) + "0"))
		else:
			outputArray.append(("$" + str(round(newPrice,2))))
	elif inputArray[3] == "C":
		outputArray.append(("$" + str(round(newPrice,1)) + "0"))
		
for b in outputArray:
	print(b)