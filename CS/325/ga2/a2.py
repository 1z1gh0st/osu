def solve_problem(array):
    n = len(array)

    min_distance = -100

    # Init to min distance, unvisited for each square of the matrix
    distance = []
    visited = []
    for i in range(0,n):
        distance_init = []
        visited_init = []
        for j in range(0,n):
            distance_init.append(-100)
            visited_init.append(False)
        distance.append(distance_init)
        visited.append(visited_init)

    distance[0][0] = array[0][0]
    for i in range(0,n):
        for j in range(0,n):
            if not visited[i][j]:
                depth_first_search(i, j, array, distance, visited)

    # Take max distance
    max_length = max(distance[n-1])
    for i in range(0,n):
        max_length = max(distance[i][n-1], max_length)
    return max_length

def depth_first_search(i, j, array, distance, visited):

    print(i,j)

    n = len(array)

    # Indicate that we have visited
    visited[i][j] = True

    # Check square below
    if (i+1 < n):
        if not visited[i+1][j]:
            depth_first_search(i+1, j, array, distance, visited)

        # Choose max
        distance[i][j] = max(distance[i+1][j] + array[i+1][j], distance[i][j])

    # Check square right
    if (j+1 < n):
        if not visited[i][j+1]:
            depth_first_search(i, j+1, array, distance, visited)

        # Choose max
        distance[i][j] = max(distance[i][j+1] + array[i][j+1], distance[i][j])

a = [[1, 2, 3],
    [2, -10, -20],
    [-20, 20, -10]]

b = [[5,-2],[-3,1]]

print(solve_problem(a))

print(solve_problem(b))
