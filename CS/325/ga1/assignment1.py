'''
    This file contains the template for Assignment1.  You should fill the
    function <majority_party_size>.  The function, recieves two inputs:
      (1) n: the number of delegates in the room, and
      (2) same_party(int, int): a function that can be used to check if two members are
      in the same party.

    Your algorithm in the end should return the size of the largest party, assuming
    it is larger than n/2.

    I will use <python3> to run this code.
'''


def majority_party_size(n, same_party):
    '''
        n (int): number of people in the room.
        same_party (func(int, int)): This function determines if two delegates
            belong to the same party.  same_party(i,j) is True if i, j belong to
            the same party (in particular, if i = j), False, otherwise.

        return: The number of delegates in the majority party.  You can assume
            more than half of the delegates belong to the same party.
    '''
    # Call our recursive function with start at 0, and end at n-1
    result = recur(same_party, 0, n - 1)
    print(result)

    # Return the second half of the resulting tuple (int size)
    return result[1]


def recur(same_party, start, end):
    '''
        same_party (func(int, int)): Function to determine
            if two delegates are in the same party
        start: Index at which we start counting the delegates
        end: Index at which we end counting the delegates

        return: Returns a tuple (idx, size) of the index of some
            member of the majority party, and the size of the majority
            party within [start, end]
    '''
    # Base case: we return the index of the delegate
    #      and the size 1.
    if (end - start == 0):
        return (start, 1)

    # Otherwise, we run the else statement.
    else:

        # Average start and end to find midpoint.
        midpoint = (start + end) // 2

        # Recur upon each half of our array.
        a = recur(same_party, start, midpoint)
        b = recur(same_party, midpoint + 1, end)

        # If the majority party in each half matches, we simply
        #     add their amounts together. Since a[0] and b[0] are
        #     both indices of a delegate of the majority party,
        #     we just return (a[0], combined size).
        if same_party(a[0], b[0]):
            return (a[0], a[1] + b[1])

        # Otherwise, we must count the number of delegates in
        #     majority party for A and majority party for B
        else:

            # a[1] counts from start to midpoint, so we count how many
            #     delegates match the majority party of A from midpoint + 1
            #     to end and combine for total count
            a_count = count(same_party, midpoint + 1, end, a[0]) + a[1]

            # Similarly, we add b[1] and the count of matches to B's
            #     majority party from start to midpoint
            b_count = count(same_party, start, midpoint, b[0]) + b[1]
            if (a_count > b_count):
                return (a[0], a_count)
            else:
                return (b[0], b_count)


def count(same_party, start, end, x):
    '''
        same_party (func(int, int)): Function to determine
            if two delegates are in the same party
        start: Index at which we start counting the delegates
        end: Index at which we end counting the delegates
        x: The delegate whose party we are counting appearances of

        return: Returns the number of delegates between start and end with the same party as x
    '''
    # Variable in which to store the running sum.
    sum = 0
    for i in range(start, end + 1):

        # Increase the sum if we find matching element
        if (same_party(x, i)):
            sum = sum + 1

    # Return the sum after looping all the way through
    return sum

