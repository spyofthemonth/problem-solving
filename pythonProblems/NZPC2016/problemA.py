prices = []
numOfPresents = int(input())

for i in range(numOfPresents):
	prices.append(float(input()))

lowest = 1000
for b in prices:
	if b < lowest:
		lowest = b

secondLowest = 1000
for c in prices:
	if c < secondLowest and c != lowest:
		secondLowest = c

secondLowestString = str(secondLowest)

if len(secondLowestString) < 5:
	secondLowestString += "0"

print(secondLowestString);