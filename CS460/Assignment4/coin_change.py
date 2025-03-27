# Coin denominations and target amount
coins = [1, 3, 4]
amount = 6

# Initialize DP array
dp = [float('inf')] * (amount + 1)
dp[0]=0

# Array to track coins used
coins_used = [0] * (amount + 1)
knapsack = []

# TODO: Fill the dp array using dynamic programming
for i in range(len(coins)):
    for j in range(1,len(dp)):
        if j >= coins[i]:
            if dp[j-coins[i]]+1 < dp[j]:
                dp[j] = dp[j-coins[i]]+1
                coins_used[j]=coins[i]

# TODO: Backtrack to find the coins used
n = amount
for _ in range(dp[amount]):
    knapsack.append(coins_used[n])
    n -= coins_used[n]

# TODO: Print the minimum number of coins needed
if dp[amount] == float('inf'):
    print("No solution possible.")
else:
    print(f"Minimum coins needed to make ${amount}: {dp[amount]}")

# TODO: Print the coins used
print(f"Coins used: {knapsack}")
