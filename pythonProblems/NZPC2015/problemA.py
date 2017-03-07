outputArray = []

while True:
	tallestPeople = [0.00]
	outputString = ""
	groupsInput = int(input())
	if groupsInput == 0:
		break
	for i in range(groupsInput):
		personInput = input()
		personHeight = float(personInput.split()[1])
		if personHeight >= tallestPeople[0]:
			if personHeight != tallestPeople[0]:
				outputString = personInput.split()[0]
			else:
				outputString += (" " + personInput.split()[0])
			tallestPeople[0] = personHeight
	outputArray.append(outputString)

for b in outputArray:
	print(b)