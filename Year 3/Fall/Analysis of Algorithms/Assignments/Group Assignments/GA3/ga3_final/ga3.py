from collections import deque

def vidrach_itky_leda(input_file_path, output_file_path):

    # Read input file to array
    file_in = open(input_file_path, 'r')
    n = int(file_in.readline())
    matrix = []
    for i in range(0, n):
        row = list(map(int, file_in.readline().split(',')))
        matrix.append(row)

    # Get our solution
    answer = solve(matrix, n)

    # Write output file
    file_out = open(output_file_path, 'w')
    file_out.write(str(answer))
    file_out.write('\n')


def solve(matrix, n):

    # We describe a game state as a tuple of tuples of integers, ((a,b),(c,d))
    #     the first being the red token, the second being the blue token, and the two ints are x,y
    top_left = (0,0)
    bottom_right = (n-1,n-1)

    # States are of the form (Red, Blue) where red and blue are tuples
    initial_state = (top_left, bottom_right)
    final_state = (bottom_right, top_left)

    # Initialize things we wish to remember
    distance = dict()
    visited = dict()
    parent = dict()
    queue = deque()
    queue.append(initial_state)
    distance[initial_state] = 0

    # The when the queue is empty we have found all reachable states
    while len(queue) != 0:

        # Take the next item from the queue
        curr_state = queue.popleft()
        while curr_state in visited:
            curr_state = queue.popleft()

        # Check all the states we can get to from curr_state
        reachable = reachable_states(curr_state[0], curr_state[1], matrix, visited, n)
        for next_state in reachable:
            if next_state not in visited:
                parent[next_state] = curr_state
                queue.append(next_state)
                distance[next_state] = distance[curr_state] + 1
                if next_state == final_state:
                    return distance[next_state]

        # Mark the distance and mark visited 
        visited[curr_state] = True

    # If we never visit the final state, return -1
    return -1

def reachable_states(red, blue, matrix, visited, n):

    # Giving these names for readability
    red_x = red[0]
    red_y = red[1]
    blue_x = blue[0]
    blue_y = blue[1]

    # These determine how far we move the other token
    red_val = matrix[red_x][red_y]
    blue_val = matrix[blue_x][blue_y]

    # Array for valid reachable states
    result = []

    # These are all the possible moves
    red_right = ((red_x + blue_val, red_y),blue)
    red_down = ((red_x, red_y + blue_val),blue)
    red_left = ((red_x - blue_val, red_y),blue)
    red_up = ((red_x, red_y - blue_val),blue)

    blue_right = (red,(blue_x + red_val, blue_y))
    blue_down = (red,(blue_x, blue_y + red_val))
    blue_left = (red,(blue_x - red_val, blue_y))
    blue_up = (red,(blue_x, blue_y - red_val))

    # Create array so that we can iterate through
    all_directions = [red_right,
                      red_down,
                      red_left,
                      red_up,
                      blue_right,
                      blue_down,
                      blue_left,
                      blue_up]

    # From each direction only keep the valid unvisited onese
    for state in all_directions:
        if state not in visited:
            if is_valid_state(state, n):
                result.append(state)

    return result


# Function to check that a state is possible on game board
def is_valid_state(state, n):

    # Check that red and blue aren't on the same square
    if state[0] == state[1]:
        return False

    r_x = state[0][0]
    r_y = state[0][1]
    b_x = state[1][0]
    b_y = state[1][1]

    points = [r_x, r_y, b_x, b_y]

    # Check if each x and y lies on the grid
    for point in points:
        if not in_range(point, n):
            return False

    # If none of the checks fail return true
    return True


# Probably already a built in function but fuck it
def in_range(x, n):
    if 0 <= x and x < n:
        return True
    else:
        return False

