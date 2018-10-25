#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int bb = 3;

struct Move {
    int x;
    int y;
    int z;
};

/*
    read_from_file: reads the board from a file
    args:
        char* inputfilename: filename to be read
        int board[][4][4]: array to store board

    returns: 0 if all is well; -2 if the file cannot be opened for reading
*/

int read_from_file( char* inputfilename, int board[][4][4] );

/*
    write_to_file: writes the board from a file
    args:
        char* outputfilename: filename to be written
        int board[4][4][4]: array to store board

    returns: 0 if all is well; -2 if the file cannot be opened for writing
*/

int write_to_file( char* outputfilename, int board[4][4][4] );

/*
    print_move_to_screen: prints the board so that the autograder should be able to read your answer
    args:
        Move m: struct storing the x,y,z coordinate of the square to move to

    returns: void
*/
void print_move_to_screen( Move m);


int evaluate(int b[4][4][4])
{
    // Checking for Rows for X or O victory.
    for (int z = 0; z < 4; z++)
    {
        /* code */
    
        for (int row = 0; row<3; row++)
        {
            if (b[z][row][0]==b[z][row][1] && b[z][row][1]==b[z][row][2] && b[z][row][2]==b[z][row][3])
            {
                if (b[z][row][0]==-1)
                   return +10;
                else if (b[z][row][0]==1)
                   return -10;
            }
        }
     
        // Checking for Columns for X or O victory.
        for (int col = 0; col<3; col++)
        {
            if (b[z][0][col]==b[z][1][col] && b[z][1][col]==b[z][2][col] && b[z][2][col]==b[z][3][col])
            {
                if (b[z][0][col]==-1)
                    return +10;
                else if (b[z][0][col]==1)
                    return -10;
            }
        }
     
        // Checking for Diagonals for X or O victory.
        if (b[z][0][0]==b[z][1][1] && b[z][1][1]==b[z][2][2] && b[z][2][2]==b[z][3][3])
        {
            if (b[z][0][0]==-1)
                return +10;
            else if (b[z][0][0]==1)
                return -10;
        }
        if (b[z][0][3]==b[z][1][2] && b[z][1][2]==b[z][2][1] && b[z][2][1]==b[z][3][0])
        {
            if (b[z][0][2]==-1)
                return +10;
            else if (b[z][0][2]==1)
                return -10;
        }
    }

    for (int x = 0; x < 4; x++)
        {
            /* code */
        
            for (int row = 0; row<3; row++)
            {
                if (b[row][x][0]==b[row][x][1] && b[row][x][1]==b[row][x][2] && b[row][x][2]==b[row][x][3])
                {
                    if (b[row][x][0]==-1)
                       return +10;
                    else if (b[row][x][0]==1)
                       return -10;
                }
            }
         
            // Checking for Columns for X or O victorx.
            for (int col = 0; col<3; col++)
            {
                if (b[0][x][col]==b[1][x][col] && b[1][x][col]==b[2][x][col] && b[2][x][col]==b[3][x][col])
                {
                    if (b[0][x][col]==-1)
                        return +10;
                    else if (b[0][x][col]==1)
                        return -10;
                }
            }
         
            // Checking for Diagonals for X or O victorx.
            if (b[0][x][0]==b[1][x][1] && b[1][x][1]==b[2][x][2] && b[2][x][2]==b[3][x][3])
            {
                if (b[0][x][0]==-1)
                    return +10;
                else if (b[0][x][0]==1)
                    return -10;
            }
            if (b[0][x][3]==b[1][x][2] && b[1][x][2]==b[2][x][1] && b[2][x][1]==b[3][x][0])
            {
                if (b[0][x][2]==-1)
                    return +10;
                else if (b[0][x][2]==1)
                    return -10;
            }
        }

    
    for (int y = 0; y < 4; y++)
        {
            /* code */
        
            for (int row = 0; row<3; row++)
            {
                if (b[row][0][y]==b[row][1][y] && b[row][1][y]==b[row][2][y] && b[row][2][y]==b[row][3][y])
                {
                    if (b[row][0][y]==-1)
                       return +10;
                    else if (b[row][0][y]==1)
                       return -10;
                }
            }
         
            // Checking for Columns for y or O victory.
            for (int col = 0; col<3; col++)
            {
                if (b[0][col][y]==b[1][col][y] && b[1][col][y]==b[2][col][y] && b[2][col][y]==b[3][col][y])
                {
                    if (b[0][col][y]==-1)
                        return +10;
                    else if (b[0][col][y]==1)
                        return -10;
                }
            }
         
            // Checking for Diagonals for y or O victory.
            if (b[0][0][y]==b[1][1][y] && b[1][1][y]==b[2][2][y] && b[2][2][y]==b[3][3][y])
            {
                if (b[0][0][y]==-1)
                    return +10;
                else if (b[0][0][y]==1)
                    return -10;
            }
            if (b[0][3][y]==b[1][2][y] && b[1][2][y]==b[2][1][y] && b[2][1][y]==b[3][0][y])
            {
                if (b[0][2][y]==-1)
                    return +10;
                else if (b[0][2][y]==1)
                    return -10;
            }
        }

            if (b[0][0][0]==b[1][1][1] && b[1][1][1]==b[2][2][2] && b[2][2][2]==b[3][3][3])
            {
                if (b[0][0][0]==-1)
                    return +10;
                else if (b[0][0][0]==1)
                    return -10;
            }
            if (b[0][0][3]==b[1][1][2] && b[1][1][2]==b[2][2][1] && b[2][2][1]==b[3][3][0])
            {
                if (b[0][0][3]==-1)
                    return +10;
                else if (b[0][0][3]==1)
                    return -10;
            }
            if (b[3][0][0]==b[2][1][1] && b[2][1][1]==b[1][2][2] && b[1][2][2]==b[0][3][3])
            {
                if (b[3][0][0]==-1)
                    return +10;
                else if (b[3][0][0]==1)
                    return -10;
            }
            if (b[0][3][0]==b[1][2][1] && b[1][2][1]==b[2][1][2] && b[2][1][2]==b[3][0][3])
            {
                if (b[0][3][0]==-1)
                    return +10;
                else if (b[0][3][0]==1)
                    return -10;
            }

    // Else if none of them have won then return 0
    return 0;
}

bool isMovesLeft(int lol[4][4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(lol[i][j][k] == 0)
                    return true;
            }
        }
    }
    return false;
}

int minimax(int board[4][4][4], int d,bool isMax)
{
    if(d < bb)
    {

    int score = evaluate(board);
    cout<< isMax << " " << d << " " <<score<<endl;
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;
 
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;
 
    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;
 
    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;
 
        // Traverse all cells
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                for(int k=0;k<4;k++){


                    // Check if cell is empty
                    if (board[i][j][k]== 0)
                    {
                        // Make the move
                        board[i][j][k] = 1;
     
                        // Call minimax recursively and choose
                        // the maximum value

                        //if( d < large)
                        {
                        best = max( best,
                            minimax(board, d+1, !isMax) );
                             board[i][j][k] = 0;
                         }
                        // Undo the move
                        board[i][j][k] = 0;
                    }
                }
            }
        }
        cout<<"max "<<best<<endl;
        return best;
    }
 
    // If this minimizer's move
    else
    {
        int best = 1000;
 
        // Traverse all cells
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                for(int k=0;k<4;k++)
                {


                    // Check if cell is empty
                    if (board[i][j][k]== 0 )
                    {
                        // Make the move
                        board[i][j][k] = -1;
     
                        // Call minimax recursively and choose
                        // the minimum value
                       // if( d < large)
                        {
                        best = min(best,
                               minimax(board, d+1, !isMax));
                                board[i][j][k] = 0;
                         }
                        // Undo the move
                        board[i][j][k] = 0;
                    }
                }
            }
        }
       cout<<"min "<<best<<endl;
        return best;
    }
        
    }
}

Move findBestMove(int board[4][4][4], int depth)
{ 
    int bestVal = -1000;
    Move bestMove;
    bestMove.x = -1;
    bestMove.y = -1;
    bestMove.z = -1;

    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
        
            for(int k=0;k<4;k++)
            {


                // Check if celll is empty
                if (board[i][j][k]== 0)
                {
                    // Make the move
                    board[i][j][k] = 1;

                    // compute evaluation function for this
                    // move.
                    int moveVal = minimax(board, 0, false);

                    // Undo the move
                    board[i][j][k] = 0;

                    // If the value of the current move is
                    // more than the best value, then update
                    // best/
                    if (moveVal > bestVal)
                    {
                        bestMove.x = j;
                        bestMove.y = k;
                        bestMove.z = i;
                        bestVal = moveVal;
                    }
                }
            }
        }
    }

    return bestMove;

}


int main( int argc, char* argv[] )
{
    char* inputfilename = NULL, *outputfilename = NULL;
    int board[4][4][4];
    Move m = {0,0,0};
    int ply = 0;

    // parse command-line arguments
    for( int i = 1; i < argc; i++ )
    {
        // input file
        if( !strcmp(argv[i], "-i" ) )
        {
            inputfilename = argv[i+1];
            i++;
        }
        // output file
        else if( !strcmp( argv[i], "-o") )
        {
            outputfilename = argv[i+1];
            i++;
        }
        // number of ply to search ahead
        else if( !strcmp( argv[i], "-p") )
        {
            ply = atoi(argv[i+1]);
            i++;
        }
    }

    // check to make sure command-line arguments have been specified
    if( inputfilename == NULL || outputfilename == NULL )
    {
        printf( "input and output filenames need to be specified on the command line (-i <filename> -o <filename>\n");
        return -1;
    }

    if( ply <= 0 )
    {
        printf( "need to have ply set to be greater than 0 (use -p <ply>)\n");
        return -1;
    }

    // debug info
    //printf( "input file: [%s]\n", inputfilename);
    //printf( "output file: [%s]\n", outputfilename);

    // read from file
    read_from_file( inputfilename, board );

    Move bestMove = findBestMove(board,ply);

    //cout<<"x "<<bestMove.x<<"y "<<bestMove.y<<"z "<<bestMove.z<<endl;
    // debug
    //printf( "starting tictactoe\n");

    //sleep(5);

    //debug into
    //printf( "finishing tictactoe\n");
    
    print_move_to_screen( m );

    //write board state to file and exit
    return write_to_file(outputfilename, board);
}

int read_from_file( char* inputfilename, int board[][4][4] )
{
    FILE *ifile = fopen( inputfilename, "r" );
    if( !ifile )
    {
        printf( "could not open input file [%s] for reading\n", inputfilename );
        return -2;
    }

    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            for( int k = 0; k < 4; k++ )
            {
                char c = '.';
                fscanf(ifile, " %c", &c );
                switch( c )
                {
                    case '.': board[i][j][k] = 0; break;
                    case 'x': board[i][j][k] = -1; break;
                    case 'o': board[i][j][k] = 1; break;
                    default: board[i][j][k] = 0; break;
                }

            }
        }
    }

    fclose( ifile );
    return 0;
}

int write_to_file( char* outputfilename, int board[4][4][4] )
{
    FILE *ofile = fopen( outputfilename, "w" );
    if( !ofile )
    {
        printf( "could not open output file [%s] for writing\n", outputfilename );
        return -2;
    }

    // iterate through all squares on the board
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            for( int k = 0; k < 4; k++ )
            {
                // write the appropriate character to the file
                switch( board[i][j][k])
                {
                    case 0: fprintf( ofile, "%c", '.'); break;
                    case 1: fprintf( ofile, "%c", 'o'); break;
                    case -1: fprintf( ofile, "%c", 'x'); break;
                    default: fprintf( ofile, "%c", '.'); break;
                }
            }
            fprintf( ofile, "\n");
        }
        fprintf( ofile, "\n");
    }

    // close the output file
    fclose (ofile);
    return 0;
}

void print_move_to_screen( Move m)
{
    printf( "%d %d %d\n", m.x, m.y, m.z);
}

