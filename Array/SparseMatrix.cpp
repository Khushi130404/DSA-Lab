// Write a program to check whether matrix is sparse matrix or not.
//And if it is sparse matrix then convert it into non sparse matrix.

#include <stdio.h>

int main()
{
    int row,cols,column,noz=0;

    printf("\nEnter the number of rows: ");
    scanf("%d",&row);
    printf("\nEnter the number of columns: ");
    scanf("%d",&cols);

    int sparse[row][cols];
    printf("\nEnter the Matrix elements...");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("\nSparse[%d][%d]: ",i+1,j+1);
            scanf("%d",&sparse[i][j]);

            if(sparse[i][j]!=0)
            {
                noz++;
            }
        }
    }

    if(noz < (row*cols)/2)
    {
        printf("\nEntered matrix is a SPARSE MATRIX...!\n");
        int nonSparse[noz][3];
        int k=0;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(sparse[i][j]!=0)
                {
                    nonSparse[k][0] = i;
                    nonSparse[k][1] = j;
                    nonSparse[k][2] = sparse[i][j];
                    k++;
                }
            }
        }
        printf("\nNon - Sparse Matrix...\n");
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<3; j++)
            {
                printf("%d\t",nonSparse[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nEntered matrix is a DENSE MATRIX...!");
    }

    return 0;
}