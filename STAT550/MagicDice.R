diceA=c(3,3,5,5,7,7)
diceB=c(2,2,4,4,9,9)
diceC=c(1,1,6,6,8,8)

n=10000
simlist=numeric(n)

# Dice A beats dice B
for (i in 1:n) {
  diceARoll=sample(diceA, 1)
  diceBRoll=sample(diceB, 1)
  success = if (diceARoll>diceBRoll) 1 else 0
  simlist[i]=success
}
mean(simlist)

# Dice B beats dice C
for (i in 1:n) {
  diceBRoll=sample(diceB, 1)
  diceCRoll=sample(diceC, 1)
  success = if (diceBRoll>diceCRoll) 1 else 0
  simlist[i]=success
}
mean(simlist)

# Dice C beats dice A
for (i in 1:n) {
  diceCRoll=sample(diceC, 1)
  diceARoll=sample(diceA, 1)
  success = if (diceCRoll>diceARoll) 1 else 0
  simlist[i]=success
}
mean(simlist)
