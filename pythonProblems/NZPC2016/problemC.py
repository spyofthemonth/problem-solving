inputArray = []

while True:
	yearInput = int(input())
	if yearInput == 0:
		break;
	inputArray.append(yearInput)

for i in inputArray:
	if (i <= 1918 and i >= 1914) or (i <= 1945 and i >= 1939):
		print(str(i) + " Games cancelled")
	elif (i % 4) == 0 and i >= 1896:
		if i > 2020:
			print(str(i) + " No city yet chosen")
		else:
			print(str(i) + " Summer Olympics")
	else:
		print(str(i) + " No summer games") 
