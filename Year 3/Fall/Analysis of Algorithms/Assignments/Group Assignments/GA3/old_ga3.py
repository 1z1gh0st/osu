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
    top_left = (0,0)
    bottom_right = (n-1,n-1)
    red = top_left
    blue = bottom_right

    # States are of the form (Red, Blue) where red and blue are tuples
    initial_state = (top_left, bottom_right)
    final_state = (bottom_right, top_left)
    distance = [(initial_state, 0)]
    visited = [initial_state]
    queue = []
    parent = dict()

    # Get our first reachable states TODO: maybe consolidate this into the while loop somehow?
    init_reachable = reachable_states(initial_state[0], initial_state[1], matrix, n)
    for state in init_reachable:
        parent[state] = initial_state
        queue.append(state)
        if state == final_state:
            return 1
    i = 2

    # The when the queue is empty we have found all reachable states
    while len(queue) != 0:

        # TODO: find a better way to implement this queue
        old_queue = queue.copy()
        queue.clear()

        # Check all the reachable states
        for state1 in old_queue:
            reachable = reachable_states(state1[0], state1[1], matrix, n)
            for state2 in reachable:
                if state2 not in visited:
                    parent[state2] = state1
                    queue.append(state2)

            # Mark the distance and mark visited 
            distance.append((state1, i-1))
            visited.append(state1)

            if state1 == final_state:

                # TODO: delete print before turning in
                print_path(parent, initial_state, state1, n)
                return i-1
        i += 1
    return -1

# TODO: delete before turning in
def print_path(parent, init, state, n):
    curr = state
    while curr != init:
        print_state(curr, n)
        curr = parent[curr]
    print_state(init, n)

def reachable_states(red, blue, matrix, n):

    # Giving these names for readability
    red_x = red[0]
    red_y = red[1]
    blue_x = blue[0]
    blue_y = blue[1]

    red_val = matrix[red_x][red_y]
    blue_val = matrix[blue_x][blue_y]

    # Array for valid reachable states
    result = []

    # LMFAOOOOO this might be the worst fucken code i ever wrote
    # TODO: maybe make this shit less garbage bruh its sooooooo baaaaad
    # Red left
    if red_x + blue_val < n and (red_x + blue_val != blue_x or red_y != blue_y):
        result.append(((red_x + blue_val, red_y), (blue_x, blue_y)))

    # Red right
    if red_x - blue_val >= 0 and (red_x - blue_val != blue_x or red_y != blue_y):
        result.append(((red_x - blue_val, red_y), (blue_x, blue_y)))

    # Red down
    if red_y + blue_val < n and (red_x != blue_x or red_y + blue_val != blue_y):
        result.append(((red_x, red_y + blue_val), (blue_x, blue_y)))

    # Red up
    if red_y - blue_val >= 0 and (red_x != blue_x or red_y - blue_val != blue_y):
        result.append(((red_x, red_y - blue_val), (blue_x, blue_y)))

    # Blue left
    if blue_x + red_val < n and (red_x != blue_x + red_val or red_y != blue_y):
        result.append(((red_x, red_y), (blue_x + red_val, blue_y)))

    # Blue right
    if blue_x - red_val >= 0 and (red_x != blue_x - red_val or red_y != blue_y):
        result.append(((red_x, red_y), (blue_x - red_val, blue_y)))

    # Blue down
    if blue_y + red_val < n and (red_x != blue_x or red_y != blue_y + red_val):
        result.append(((red_x, red_y), (blue_x, blue_y + red_val)))

    # Blue up
    if blue_y - red_val >= 0 and (red_x != blue_x or red_y != blue_y - red_val):
        result.append(((red_x, red_y), (blue_x, blue_y - red_val)))

    return result

# TODO: delete before turning this in
def print_state(state, n):
    print()
    print()
    for i in range(0,n):
        for j in range(0,n):
            if (i,j) == state[0]:
                print("R", end = "")
            elif (i,j) == state[1]:
                print("B", end = "")
            else:
                print(".", end = "")
        print()

# describe a game state as ((Rx, Ry), (Bx, By))
# from each state there are at most 8 reachables states, one of which we already have visited
# maybe do BFS using queue???


#vidrach_itky_leda("test1.in", "test1.out")
#vidrach_itky_leda("test2.in", "test2.out")
vidrach_itky_leda("test3.in", "test3.out")
#vidrach_itky_leda("test4.in", "test4.out")
