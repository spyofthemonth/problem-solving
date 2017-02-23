output = {}
counter = 0
while True:
	numOfPeople = int(input())
	if numOfPeople == 0:
		break

	tallestArr = ["",0.00]
	for i in range(numOfPeople):
		personInput = input()
		personArr = personInput.split(" ", 1)
		if float(personArr[1]) > tallestArr[-1]:
			tallestArr[0] = personArr[0]
			tallestArr[1] = float(personArr[1])
		elif float(personArr[1]) == tallestArr[-1]:
			tallestArr.append(personArr[0])
			tallestArr.append(float(personArr[1]))
			print(tallestArr)
	for b in range(len(tallestArr)):
		if (b % 2) == 0 or b == 0:
			counter += 1
			output[counter] = []
			output[counter].append(tallestArr[b])	
for c in output:
	for d in range(len(output[c])):
		print(output[c][d])
