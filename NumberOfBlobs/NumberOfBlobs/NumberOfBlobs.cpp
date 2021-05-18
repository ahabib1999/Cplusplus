
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

int RecursiveBlobSearch(char grid[22][72], int row, int column);
int ReadFileAndReturnBlobs(char grid[22][72], const int NUMROWS, const int NUMCOLUMNS);

// Function Protypes

                                        // *****************************************************************\\
                                        // * Function Name: main *                                        \\
                                        // * Description: Start of the program *                            \\
                                        // * Parameter Description: N/A *                                   \\
                                        // * Date: 02/18/2021 *                                             \\
                                        // * Author: Akbar Habib. *                                         \\
                                        // * Referenes: Place here any references where you may have *      \\
                                        // * gotten the idea for the code or algorithm. You should *        \\
                                        // * reference any code you use from the book and class. *          \\
                                        // *****************************************************************\\

int main()
{
    int numberofblobs;
    const int NUMROWS = 22;
    const int NUMCOLUMNS = 72;
    char grid[NUMROWS][NUMCOLUMNS];

    numberofblobs = ReadFileAndReturnBlobs(grid, NUMROWS, NUMCOLUMNS);

    cout << "Number of Blobs: " << numberofblobs << endl;
    cout << endl;

    return 0;
}

                                        // *****************************************************************\\
                                        // * Function Name: ReadFileAndReturnBlobs *                        \\
                                        // * Description: Reads the input ile, stores data in 2d Array *    \\
                                        // * And searches through the array to find number of blobs *       \\
                                        // * Parameter Description:                                         \\
                                        // * grid[22][72] (char[][]): 2d array for saving file contents *   \\
                                        // * NUMROWS (const int): max number of rows *                      \\
                                        // * NUMCOLUMNS (const int): max number of columns *                \\                                
                                        // * Date: 02/13/2021 *                                             \\
                                        // * Author: Akbar Habib. *                                         \\
                                        // * Referenes: Place here any references where you may have *      \\
                                        // * gotten the idea for the code or algorithm. You should *        \\
                                        // * reference any code you use from the book and class. *          \\
                                        // *****************************************************************\\

int ReadFileAndReturnBlobs(char grid[22][72], const int NUMROWS, const int NUMCOLUMNS)
{
    ifstream blobfile;
    blobfile.open("blob.txt");
    char currentchar = ' ';

    if (!blobfile.is_open())
    {
        cout << "File does not exist" << endl;
        return 0;
    }

    for (int row = 1; row < NUMROWS; row++)
    {
        for (int column = 1; column < NUMCOLUMNS; column++)
        {
            blobfile.get(currentchar);

            if (currentchar != '/n')
            {
                grid[row][column] = (char)currentchar;
            }
        }
    }

    blobfile.close();

    int numberofblobs = 0;

    if (sizeof(grid) == 0)
    {
        cout << "Number of Blobs" << numberofblobs << endl;
        return 0;
    }

    for (int row = 1; row < NUMROWS; row++)
    {
        for (int column = 1; column < NUMCOLUMNS; column++)
        {
            if (grid[row][column] == 'X')
            {
                numberofblobs += RecursiveBlobSearch(grid, row, column);
            }
        }
    }

    return numberofblobs;
}

                                        // *****************************************************************\\
                                        // * Function Name: RecursiveBlobSearch *                           \\
                                        // * Description: Recursive method to search array for blobs  *     \\
                                        // * Parameter Description:  *                                      \\
                                        // * grid[22][72] (char[][]): 2d array for saving file contents *   \\
                                        // * row (int): Current row *                                       \\
                                        // * column (int): Current column *                                 \\
                                        // * Date: 02/13/2021 *                                             \\
                                        // * Author: Akbar Habib. *                                         \\
                                        // * Referenes: Place here any references where you may have *      \\
                                        // * gotten the idea for the code or algorithm. You should *        \\
                                        // * reference any code you use from the book and class. *          \\
                                        // *****************************************************************\\

int RecursiveBlobSearch(char grid[22][72], int row, int column)
{
    if (row < 1 || row >= 22 || column < 1 || column >= 72 || grid[row][column] == ' ')
    {
        return 0;
    }

    grid[row][column] = ' ';
    RecursiveBlobSearch(grid, row - 1, column - 1);
    RecursiveBlobSearch(grid, row - 1, column);
    RecursiveBlobSearch(grid, row - 1, column + 1);
    RecursiveBlobSearch(grid, row, column + 1);
    RecursiveBlobSearch(grid, row + 1, column + 1);
    RecursiveBlobSearch(grid, row + 1, column);
    RecursiveBlobSearch(grid, row + 1, column - 1);
    RecursiveBlobSearch(grid, row, column - 1);
    return 1;
}
