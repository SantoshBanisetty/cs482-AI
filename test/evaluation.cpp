// C++ program to compute evaluation function for
// Tic Tac Toe Game.
#include<stdio.h>
#include<algorithm>
#include <iostream>
using namespace std;
 
//int count = 3;
// Returns a value based on who is winning
// b[3][3] is the Tic-Tac-Toe board
int evaluate(int b[4][4][4])
{
    // Checking for Rows for X or O victory.
    for (int z = 0; z < 4; z++)
    {
        /* code */
    
        for (int row = 0; row<4; row++)
        {
            if (b[z][row][0]==b[z][row][1] && b[z][row][1]==b[z][row][2] && b[z][row][2]==b[z][row][3])
            {
                
                if (b[z][row][0]==1)
                    {
                        cout << "a" << endl;
                        return +10;
                    }
                else if (b[z][row][0]==-1)
                   return -10;
            }
        }
     
        // Checking for Columns for X or O victory.
        for (int col = 0; col<4; col++)
        {
            if (b[z][0][col]==b[z][1][col] && b[z][1][col]==b[z][2][col] && b[z][2][col]==b[z][3][col])
            {
                
                if (b[z][0][col]==1)
                                        {
                        cout << "b" << endl;
                        return +10;
                    }
                else if (b[z][0][col]==-1)
                    return -10;
            }
        }
     
        // Checking for Diagonals for X or O victory.
        if (b[z][0][0]==b[z][1][1] && b[z][1][1]==b[z][2][2] && b[z][2][2]==b[z][3][3])
        {
            
            if (b[z][0][0]==1)
                                    {
                        cout << "c" << endl;
                        return +10;
                    }
            else if (b[z][0][0]==-1)
                return -10;
        }
        if (b[z][0][3]==b[z][1][2] && b[z][1][2]==b[z][2][1] && b[z][2][1]==b[z][3][0])
        {
            
            if (b[z][0][3]==1)
                                    {
                        cout << z << " " <<"d" << endl;
                        return +10;
                    }
            else if (b[z][0][3]==-1)
                return -10;
        }
    }

    for (int x = 0; x < 4; x++)
        {
            /* code */
        
            for (int row = 0; row<4; row++)
            {
                if (b[row][x][0]==b[row][x][1] && b[row][x][1]==b[row][x][2] && b[row][x][2]==b[row][x][3])
                {
                    
                    if (b[row][x][0]==1)
                                           {
                        cout << "e" << endl;
                        return +10;
                    }
                    else if (b[row][x][0]==-1)
                       return -10;
                }
            }
         
            // Checking for Columns for X or O victorx.
            for (int col = 0; col<4; col++)
            {
                if (b[0][x][col]==b[1][x][col] && b[1][x][col]==b[2][x][col] && b[2][x][col]==b[3][x][col])
                {
                    
                    if (b[0][x][col]==1)
                                            {
                        cout << "f" << endl;
                        return +10;
                    }
                    else if (b[0][x][col]==-1)
                        return -10;
                }
            }
         
            // Checking for Diagonals for X or O victorx.
            if (b[0][x][0]==b[1][x][1] && b[1][x][1]==b[2][x][2] && b[2][x][2]==b[3][x][3])
            {
                
                if (b[0][x][0]==1)
                                        {
                        cout << "g" << endl;
                        return +10;
                    }
                else if (b[0][x][0]==-1)
                    return -10;
            }
            if (b[0][x][3]==b[1][x][2] && b[1][x][2]==b[2][x][1] && b[2][x][1]==b[3][x][0])
            {
                
                if (b[0][x][3]==1)
                                        {
                        cout << "h" << endl;
                        return +10;
                    }
                else if (b[0][x][3]==-1)
                    return -10;
            }
        }

    
    for (int y = 0; y < 4; y++)
        {
            /* code */
        
            for (int row = 0; row<4; row++)
            {
                if (b[row][0][y]==b[row][1][y] && b[row][1][y]==b[row][2][y] && b[row][2][y]==b[row][3][y])
                {
                    
                    if (b[row][0][y]==1)
                                           {
                        cout << "i" << endl;
                        return +10;
                    }
                    else if (b[row][0][y]==-1)
                       return -10;
                }
            }
         
            // Checking for Columns for y or O victory.
            for (int col = 0; col<4; col++)
            {
                if (b[0][col][y]==b[1][col][y] && b[1][col][y]==b[2][col][y] && b[2][col][y]==b[3][col][y])
                {
                    
                    if (b[0][col][y]==1)
                                            {
                        cout << "j" << endl;
                        return +10;
                    }
                    else if (b[0][col][y]==-1)
                        return -10;
                }
            }
         
            // Checking for Diagonals for y or O victory.
            if (b[0][0][y]==b[1][1][y] && b[1][1][y]==b[2][2][y] && b[2][2][y]==b[3][3][y])
            {
                
                if (b[0][0][y]==1)
                                        {
                        cout << "k" << endl;
                        return +10;
                    }
                else if (b[0][0][y]==-1)
                    return -10;
            }
            if (b[0][3][y]==b[1][2][y] && b[1][2][y]==b[2][1][y] && b[2][1][y]==b[3][0][y])
            {
                
                if (b[0][3][y]==1)
                                        {
                        cout << "l" << endl;
                        return +10;
                    }
                else if (b[0][3][y]==-1)
                    return -10;
            }
        }

            if (b[0][0][0]==b[1][1][1] && b[1][1][1]==b[2][2][2] && b[2][2][2]==b[3][3][3])
            {
                
                if (b[0][0][0]==1)
                                        {
                        cout << "m" << endl;
                        return +10;
                    }
                else if (b[0][0][0]==-1)
                    return -10;
            }
            if (b[0][0][3]==b[1][1][2] && b[1][1][2]==b[2][2][1] && b[2][2][1]==b[3][3][0])
            {
                
                if (b[0][0][3]==1)
                                        {
                        cout << "n" << endl;
                        return +10;
                    }
                else if (b[0][0][3]==-1)
                    return -10;
            }
            if (b[3][0][0]==b[2][1][1] && b[2][1][1]==b[1][2][2] && b[1][2][2]==b[0][3][3])
            {
                
                if (b[3][0][0]==1)
                                        {
                        cout << "o" << endl;
                        return +10;
                    }
                else if (b[3][0][0]==-1)
                    return -10;
            }
            if (b[0][3][0]==b[1][2][1] && b[1][2][1]==b[2][1][2] && b[2][1][2]==b[3][0][3])
            {
                
                if (b[0][3][0]==1)
                                        {
                        cout << "p" << endl;
                        return +10;
                    }
                else if (b[0][3][0]==-1)
                    return -10;
            }

    // Else if none of them have won then return 0
    return 0;
}
 
// Driver code
int main()
{
    int board[4][4][4] =
    {   {   { -1, 0, 0, 0},
            { 0, 0, 0, 0},
            { 0, 0, 0, 0},
            { 0, 0, 0, 0}    },
        {   
            { 1, 0, 0, 0},
            { 0, -1, 0, 0},
            { 0, 0, -1, 0}, 
            { 0, 0, 0, 0}    },
        {   
            { 0, 0, 0, 0},
            { 0, 1, 0, 0},
            { 0, 0, 1, 0},
            { 0, 0, 0, 1}    },
        {   
            { 0, 0, 1, 0},
            { 0, 0, 0, 0},
            { 0, 0, 0, 0},
            { 0, 0, 0, 0}    }
    };
  
    int value = evaluate(board);
    //printf("%d, %d, %d\n", board[1][0][0], board[1][1][1], board[1][2][2]);
    printf("The value of this board is %d\n", value);
    return 0;
}




// // C++ program to compute evaluation function for
// // Tic Tac Toe Game.
// #include<stdio.h>
// #include<algorithm>
// using namespace std;
 
// // Returns a value based on who is winning
// // b[3][3] is the Tic-Tac-Toe board
// int evaluate(char b[3][3])
// {
//     // Checking for Rows for X or O victory.
//     for (int row = 0; row<3; row++)
//     {
//         if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
//         {
//             if (b[row][0]==-1)
//                return +10;
//             else if (b[row][0]==1)
//                return -10;
//         }
//     }
 
//     // Checking for Columns for X or O victory.
//     for (int col = 0; col<3; col++)
//     {
//         if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
//         {
//             if (b[0][col]==-1)
//                 return +10;
//             else if (b[0][col]==1)
//                 return -10;
//         }
//     }
 
//     // Checking for Diagonals for X or O victory.
//     if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
//     {
//         if (b[0][0]==-1)
//             return +10;
//         else if (b[0][0]==1)
//             return -10;
//     }
//     if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
//     {
//         if (b[0][2]==-1)
//             return +10;
//         else if (b[0][2]==1)
//             return -10;
//     }
 
//     // Else if none of them have won then return 0
//     return 0;
// }
 
// // Driver code
// int main()
// {
//     char board[3][3] =
//     {
//         { -1, 0, 1},
//         { 0, -1, 1},
//         { 0, 0, 1}
//     };
 
//     int value = evaluate(board);
//     printf("The value of this board is %d\n", value);
//     return 0;
// }