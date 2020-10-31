'''
    This file contains the template for Assignment2.  For testing it, I will place it
    in a different directory, call the function <vankin_max_score>, and check its output.
    So, you can add/remove  whatever you want to/from this file.  But, don't change the name
    of the file or the name/signature of the following function.

    Also, I will use <python3> to run this code.
'''

def vankin_max_score(input_file_path, output_file_path):
    '''
    This function will ontain your code, it will read the input from the file
    <input_file_path> and write to the file <output_file_path>.

    Params:
        input_file_path (str): full path of the input file.
        output_file_path (str): full path of the output file.
    '''

    # Open file
    file_in = open(input_file_path, 'r')
    n = int(file_in.readline())

    # Init our array
    array = []        
    for i in range(0,n):

        # Turn line of input nums into array
        row = list(map(int, file_in.readline().split(',')))
        array.append(row)

    file_in.close()

    # Solve
    max_length = solve_problem(array)

    # Write file out
    file_out = open(output_file_path, 'w')
    file_out.write(str(max_length) + '\n')


def solve_problem(array):
    '''
    This function will take a square array and find the max score
    for a Vankin game, using dynamic programming

    Params:
        array: n x n array of integers
        max_length: longest path to the edge (highest possible score)
    '''

    n = len(array)

    distance = [] # Max distance to edge
    visited = [] # Indicates if it is already computed

    # Initialize distance to value on square and visited to false
    for i in range(0,n):
        distance_init = []
        visited_init = []
        for j in range(0, n):
            distance_init.append(array[i][j])
            visited_init.append(False)
        distance.append(distance_init)
        visited.append(visited_init)

    # This is to start off recursion chain
    for i in range(0, n):
        for j in range(0, n):
            if not visited[i][j]:
                recur(array, distance, visited, i, j)

    # Worst case scenario we have 2n minimum values
    max_length = -100 * 2 * n
    for i in range(0,n):
        for j in range(0,n):

            # Either take the old max length, or distance[i][j],
            #     whichever is bigger
            max_length = max(max_length, distance[i][j])

    return max_length


def recur(array, distance, visited, i, j):
    '''
    This function recursively finds the max length from each square
    to the edge.

    Params:
        array: n x n array of integers (game board)
        distance: n x n array of integers (memoized max distances from
            each square to the edge)
        visited: n x n array of booleans keeping track of which values
            have already been computed
        i,j: row,column of current square of interest
    '''

    n = len(array)

    # Indicate we have already checked this square
    visited[i][j] = True

    # Case 1: Both down and right squares exist
    if i + 1 < n and j + 1 < n:
        if not visited[i + 1][j]:
            recur(array, distance, visited, i + 1, j)
        if not visited[i][j + 1]:
            recur(array, distance, visited, i, j + 1)
        distance[i][j] += max(distance[i + 1][j], distance[i][j + 1])

    # Case 2: Only down exists
    elif i + 1 < n:
        if not visited[i + 1][j]:
            recur(array, distance, visited, i + 1, j)
        distance[i][j] += max(0, distance[i + 1][j])

    # Case 3: Only right exists
    elif j + 1 < n:
        if not visited[i][j + 1]:
            recur(array, distance, visited, i, j + 1)
        distance[i][j] += max(0, distance[i][j + 1])

    # Case 4: We cannot move from bottom right corner,
    #     so we keep tile value as max distance


vankin_max_score('input0.in', 'input0.out')

