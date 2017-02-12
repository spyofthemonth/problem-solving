def switch(x):
	return {"S": 10, "Q": 5, "A": 7, "L": -8, "F": 4, "D": -5, "E": -10}[x]

politiciansDict = {} # 1: Bill Bloggs
polScoresDict = {} # Bill Bloggs: 10
actionDict = {} # 1: S

numOfPol = int(input())
for i in range(numOfPol):
	polInput = input()
	splitPolInput = polInput.split(" ", 1)
	politiciansDict[splitPolInput[0]] = splitPolInput[1]

numOfAct = int(input())
for b in range(numOfAct):
	actionInput = input()
	splitActInput = actionInput.split(" ", 1)
	if splitActInput[0] in actionDict.keys():
		actionDict[splitActInput[0]] = str(actionDict[splitActInput[0]] + " " + splitActInput[1])
	else:	
		actionDict[splitActInput[0]] = splitActInput[1]

for c in politiciansDict:
	if politiciansDict.get(c) not in polScoresDict:
		polScoresDict[politiciansDict.get(c)] = 0

for key in actionDict:
	for action in actionDict.get(key).split(" "):
		try:
			polScoresDict[politiciansDict.get(key)] += switch(action)
		except:
			polScoresDict[politiciansDict.get(key)] = switch(action)

highestScore = max(polScoresDict.values())
lowestScore = min(polScoresDict.values())
highestScorePols = []
lowestScorePols = []
for politician in polScoresDict:
	if polScoresDict.get(politician) == highestScore:
		highestScorePols.append(politician)
	if polScoresDict.get(politician) == lowestScore:
		lowestScorePols.append(politician)

sortedPol = sorted(politiciansDict)
for d in sortedPol:
	while True:
		if int(d) < int(sortedPol[sortedPol.index(d)-1]) and sortedPol.index(d) != 0:
			sortedPol.insert(sortedPol.index(d)-1, sortedPol.pop(sortedPol.index(d)))
		else:
			break

sortedPol.reverse()
for e in sortedPol:
	for hScorePol in highestScorePols:
		if politiciansDict.get(e) == hScorePol:
			highestScorePols.insert(0, highestScorePols.pop(highestScorePols.index(hScorePol)))
			break
	for lScorePol in lowestScorePols:
		if politiciansDict.get(e) == lScorePol:
			lowestScorePols.insert(0, lowestScorePols.pop(lowestScorePols.index(lScorePol)))
			break

print(str(highestScore) + " " + " ".join(highestScorePols))
print(str(lowestScore) + " " + " ".join(lowestScorePols))