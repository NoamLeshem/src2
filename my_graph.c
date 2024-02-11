#include "my_mat.h"

int main(int argc, char *argv[])
{
    char choice = 0;
    int mat[LEN][LEN] = {{0}};
    while(1)
    {
        scanf("%c", &choice);
        if (choice == 'A')
            initMatrix(mat);
        else if (choice == 'B')
            findPath(mat, 0);
        else if (choice == 'C')
            findPath(mat, 1);
        else if (choice == 'D')
            return 0;
    }
}