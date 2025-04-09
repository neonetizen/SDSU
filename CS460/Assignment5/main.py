def can_multiply(matrices):
    # TODO: Implement this function
    """ Check if matrices can be multiplied in given order.
    Return bool: True if possible, False otherwise """
    for i in range(len(matrices)-1):
        if matrices[i][1] != matrices[i+1][0]:
            return False
    return True

def matrix_chain_order(matrices):
    """ Find the best order of paranthesis for multiplication.
    Check if matrices can be multiplied in given order, before proceeding.
    Return tuple: (minimum operations, optimal order string) """
    # TODO: Implement DP algorithm
    # TODO: Build optimal order
    

def main():
    # Example
    matrices = [(30, 35), (35, 15), (15, 5), (5, 10), (10, 20), (20, 25)]
    can_mult = can_multiply(matrices)
    print(f"Can multiply matrices: {can_mult}")
    #if can_mult:
    #    min_ops, order = matrix_chain_order(matrices)
    #    print(f"Minimum operations: {min_ops}")
    #    print(f"Optimal order: {order}")

if __name__ == "__main__":
    main()

