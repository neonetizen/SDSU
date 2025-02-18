# creating a 20 sided dice
d20=c(1:20)

# roll 1000 times
simlist=numeric(1000)
for (i in 1:1000) {
  roll=sample(d20, 1, replace=T)
  simlist[i]=roll
}

# finding mean which should be ~10.5 to check
mean(simlist)