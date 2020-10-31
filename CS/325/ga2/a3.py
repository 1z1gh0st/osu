def solve_problem(array):

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

    # This is to start off recursion chain, generalizable to larger problems
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



# Tests from pdf

a = [[1, 2, 3],
    [2, -10, -20],
    [-20, 20, -10]]

b = [[5,-2],[-3,1]]

print(solve_problem(a))
print(solve_problem(b))
