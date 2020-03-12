main(argc, char* argv[])
    players = 0
    columns = 0
    rows = 0
	if (argc > 3)
		players = atoi(argv[1])
        columns = atoi(argv[2])
        rows = atoi(argv[3])
        board = create_board(rows, columns)
        print_board(board, rows, columns)
        if (players == 1)
            one_player(board, rows, columns)
        else if (players == 2)
            two_player(board, rows, columns)
        else
            print "Error. Cannot have more than two players."  
    else
        print "More arguments required:"  
        print "    [program name] [player count] [columns] [rows]"  
    // print_board(array)
    return 0

create_board(rows, columns)
	board = new * [rows]
	for (i = 0 i < rows i++)
		board[i] = new int[columns]
        for (j = 0 j < columns j++)
            board[i][j] = 0
	return board

print_board(board, rows, columns)
    print "  "
    for (i = 0 i < columns i++)
        print i + 1 << "   "
    print '\n'
    for (row = 0 row < rows row++)
        for (col = 0 col < columns col++)
            print "| " << board[row][col] << " "
            //print "Row: " << row << " Col: " << col print 
        print "|"  
    
one_player(board, rows, columns)
    // input = get_int(between 0 and 1)
    bool first_move = false
    bool game_over = false
    print "Would you like to go first?" print 
    print "    (0) No" print 
    print "    (1) Yes" print 
    print " > "
    input first_move
    if (first_move)
        player_move(board, rows, columns, 1)
        print_board(board, rows, columns)
    while (1)
        win = 0
        computer_move(board, rows, columns)
        print_board(board, rows, columns)
        win = winner(board, rows, columns)
        if (win != 0)
            if (win < 3)
                print "Player " __ " has won!" 
            else
                print "Tie game." 
            break
        player_move(board, rows, columns, 1)        
        print_board(board, rows, columns)
        win = winner(board, rows, columns)
        if (win != 0)
            if (win < 3)
                print "Player " __ " has won!"
            else
                print "Tie game."
            break
        
two_player(board, rows, columns)
    bool game_over = false
    while (1)
        win = 0
        print "Player 1. "
        player_move(board, rows, columns, 1)
        print_board(board, rows, columns)
        win = winner(board, rows, columns)
        if (win != 0)
            if (win < 3)
                print "Player " __ " has won!" 
            else
                print "Tie game." 
            break
        print "Player 2. "
        player_move(board, rows, columns, 2)
        print_board(board, rows, columns)
        win = winner(board, rows, columns)
        if (win != 0)
            if (win < 3)
                print "Player " __ " has won!"  
            else
                print "Tie game."  
            break
        
player_move(board, rows, columns, player)
    column_chosen = 0
    bool done = false
    print "In which column would you like to place a piece? : "
    input column_chosen
    do
        for (i = rows - 1 i >= 0 i--)
            if (board[i][column_chosen - 1] == 0)
                board[i][column_chosen - 1] = player
                done = true
                break
            else if (board[0][column_chosen - 1] != 0)
                print "Column full, please select a different column : "
                input column_chosen
                break
     while (!done)

computer_move(board, rows, columns)
    column_chosen = 0
    bool done = false
    srand(time(NULL))
    column_chosen = rand() % columns
    do
        for (i = rows - 1 i >= 0 i--)
            if (board[i][column_chosen] == 0)
                board[i][column_chosen] = 2
                done = true
                break
            else if (board[0][column_chosen] != 0)
                column_chosen = rand() % columns
                break   
     while (!done)

winner(board, rows, columns)
    empty_spaces = 0
    for (i = 0 i < rows i++)
        for (j = 0 j < columns j++)    
            if (board[i][j] == 0)
                empty_spaces++
            // TODO: check for four in a row here
    if (empty_spaces == 0)
        return 3
    return 0