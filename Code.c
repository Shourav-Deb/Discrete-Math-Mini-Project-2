#include <stdio.h>                                                                                                                            //Code created by Shourav Deb
#include <stdlib.h>
#include<time.h>


int main()
{

    int i, j, m, n;

    printf("Enter the column dimension of the matrix: ");
    scanf("%d", &n);

    int **mat = (int **)malloc(n * sizeof(int *));     // Dynamic space allocation //
    for (i=0; i<n; i++)
        mat[i] = (int *)malloc(n * sizeof(int));


    for(i = 0; i < n; i++)  // Creating Matrix //
    {
        for(j = 0; j < n; j++)
        {
            mat[i][j]=rand()%2;      /*
            printf("%d",mat[i][j]);  */   // Remove comment to Represent Matrix //
        }
 /*       printf("\n");     */            // Remove comment to Represent Matrix //
    }

    struct timespec start, end;   //  Time Compute Start //
    clock_gettime(CLOCK_REALTIME, &start);

    //equivalence
    int isequivalence=1; // is 1 mean reaction is equivalence //

    //Reflexive
    int isReflexive=1;
    for(i = 0; i < n; i++) // o(n) //
    {
        if(mat[i][i]==0)
            isReflexive=0;
    }

    //Symmetric
    int isSymmetric=1;
    for(i = 0; i < n; i++)   // o(n^2) //
    {
        for(j = 0; j < n; j++)
        {
            if(mat[i][j]!=mat[j][i])
                isSymmetric=0;
        }
    }

    //Anti-Symmetric
    int isAntiSymmetric=1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mat[i][j]== -mat[j][i])
                isAntiSymmetric=0;
        }
    }



    //Transitive
    int isTransitive =1;
    for(i = 0; i < n; i++)   // o(n^3) //
    {
        for(j = 0; j < n; j++)
        {
            for( int k=0; k<n; k++)
            {
                if(mat[i][j] && mat[j][k] && !mat[k][i])
                    isTransitive=0;
            }
        }
    }

    if(!isReflexive || !isTransitive || !isSymmetric)
        isequivalence=0;

    clock_gettime(CLOCK_REALTIME, &end);    //  Time Compute End //
    double nanos = (double)(end.tv_nsec - start.tv_nsec); // conversion nano to mili //
    double ms = nanos/1000000;


    printf("\n\n|| Verified Property's ||\n\n");
    if(isReflexive=1)
        printf("Matrix is Reflexive.\n");
    else
    {
        printf("Matrix is Not Reflexive.\n");
    }

    if(isTransitive=1)
        printf("Matrix is Transitive.\n");
    else
    {
        printf("Matrix is Not Transitive.\n");
    }

    if(isSymmetric=1)
        printf("Matrix is Symmetric.\n");

    else
    {
        printf("Matrix is Not Symmetric.\n");
    }

    if(isAntiSymmetric=1)
        printf("Matrix is Anti-Symmetric.\n");

    else
    {
        printf("Matrix is Not Anti-Symmetric.\n");
    }

    if(isequivalence=1)
        printf("Matrix is Equivalence.\n");

    else
    {
        printf("Matrix is Not Equivalence.\n");
    }




    printf("\t\tComputational Time_(except printing time)= %.2f ms.\n\n\n",ms);


    return 0;
}                                                                                                                            //Code created by Shourav Deb
