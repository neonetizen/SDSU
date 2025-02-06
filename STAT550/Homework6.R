# 1.41 Modify the code in the R script CoinFlip.R to simulate the probability of
# getting exactly one head in four coin tosses.
# R: SIMULATING THE PROBABILITY OF THREE HEADS IN THREE COIN TOSSES
#
# CoinFlip.R
# Trial
trial <- sample(0:1,4,replace=TRUE)
# Success
if (sum(trial)==1) 1 else 0
# Replication
n <- 10000 # Number of repetitions
simlist <- numeric(n) # Initialize vector
for (i in 1:n) {
  trial <- sample(0:1, 3, replace=TRUE)
  success <- if (sum(trial)==3) 1 else 0
  simlist[i] <- success }
mean(simlist)

# 1.43 Use R to simulate the probability of getting at least 8 in the sum of two
# dice rolls.

n = 10000
simlist = numeric(n)
dice=c(1,2,3,4,5,6)
for (i in 1:n) {
  trial = sample(dice, 2, replace=T)
  success = if (sum(trial)>=8) 1 else 0
  simlist[i] = success
}
mean(simlist)

# 1.44 Use R to simulate the probability in Exercise 1.30.
# (1.30 A tetrahedron dice is four-sided and labeled with 1, 2, 3, and 4.
# When rolled it lands on the base of a pyramid and the number rolled is the
# number on the base. In five rolls, what is the probability of
# rolling at least one 2?)

n = 10000
simlist = numeric(n)
dice = c(1,2,3,4)
for (i in 1:n) {
  trial = sample(dice, 5, replace=T)
  success = if (2 %in% trial) 1 else 0
  simlist[i] = success
}
mean(simlist)
