#include <stdio.h>
#include <math.h>
int main()
{   
    printf("WELCOME TO MATOPS\n");
    printf("__________________\n");
    int choice;
    printf("CHOOSE OPERATIONS:\n");
    printf("1. MATRIX MULTIPLICATION\n");
    printf("2. DETERMINANT (upto 3 * 3 matrix)\n");
    printf("3. INVERSE\n");
    printf("4. CHARACTERSTIC EQUATION\n");
    printf("5. EIGEN VALUE\n");
    printf("6. EIGEN VECTOR\n");
    printf("7. TRANSPOSE OF A MATERIX\n");
    printf("ENTER YOUR CHOICE:");
    scanf("%d", &choice);
    int detA;
    if (choice == 1)
    {
        unsigned int r1, c1, r2, c2;
        printf("ENTER THE NUMBER OF ROWS OF MATRIX A:-\n");       //Taking input for the dimensions of matrix A and B and using unsigned int to make sure dimension of matrix are not negative.
        scanf("%u", &r1);
        printf("\nENTER THE NUMBER OF COLUMN OF MATRIX A:-\n");
        scanf("%u", &c1);
        printf("\nENTER THE NUMBER OF ROWS IN MATRIX B:-\n");
        scanf("%u", &r2);
        printf("\nENTER THE NUMBER OF COLUMN IN MATRIX B:-\n");
        scanf("%u", &c2);
        if (r1 == 0 || c1 == 0 || r2 == 0 || c2 == 0)            //Checking rows and column are not equal to zero.
        {
            printf("\nROWS AND COLUMNS MUST BE GREATER THAN ZERO.\n");
        }
        else if (c1 != r2)
        {
            printf("\nSORRY! THE MULTIPLICATION OF THE MATRIX IS NOT POSSIBLE.");
        }
        else
        {
            int arr1[r1][c1],arr2[r2][c2],arr3[r1][c2], i, j, k;
            printf("\nENTER THE ELEMENTS OF MATRIX A:-\n");
            
            //Input Matrix A
            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c1; j++)
                {
                    scanf("%d", &arr1[i][j]);
                }
            }
            printf("\nENTER THE ELEMENTS OF MATRIX B:-\n");
            
            //Input Matrix B
            for (i = 0; i < r2; i++)
            {
                for (j = 0; j < c2; j++)
                {
                    scanf("%d", &arr2[i][j]);
                }
            }
            printf("\nTHE RESULT OF MULTIPLICATION OF MATRIX A AND MATRIX B IS:-\n");
            for (i = 0; i < r1; i++)
            {   
                
                for (j = 0; j < c2; j++)                     //resultant matrix
                {
                    arr3[i][j] = 0;
                    for (k = 0; k < c1; k++)
                    {
                        arr3[i][j] += arr1[i][k] * arr2[k][j];
                    }
                    printf("%d\t", arr3[i][j]);
            }
                printf("\n");
    
            }
        }
    }
    else if (choice == 2)
    {
        unsigned int r1, c1;
        printf("ENTER THE NUMBER OF ROWS OF MATRIX A:-\n");
        scanf("%u", &r1);     
        printf("\nENTER THE NUMBER OF COLUMN OF MATRIX A:-\n");
        scanf("%u", &c1);
        int arr1[r1][c1];
        if (r1 != c1)
        {
            printf("DETERMINANT DOES NOT EXIST\n");
        }
        else if (r1 == c1)
        {
            printf("ENTER THE ELEMENTS OF MAT A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%d", &arr1[i][j]);
                }
            }
            if (r1 == 1)
            {
                detA = arr1[0][0];
                printf("DETERMINANAT OF MATRIX A IS : %d", detA);
            }
            else if (r1 == 2)
            {
                detA = arr1[0][0] * arr1[1][1] - (arr1[0][1] * arr1[1][0]);
                printf("DETERMINANT OF MATRIX A IS : %d", detA); 
            }
            else if (r1 == 3)
            {
                detA = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1])
                      - arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0])
                      + arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0]);
                printf("DETERMINANT OF MATRIX A IS :%d", detA);

            }
        }

    }
    else if (choice == 3)
    {
        unsigned int r1, c1;
        printf("ENTER THE NUMBER OF ROWS OF MATRIX A:-\n");      
        scanf("%u", &r1);
        printf("\nENTER THE NUMBER OF COLUMN OF MATRIX A:-\n");
        scanf("%u", &c1);
        float arr1[r1][c1];
        float inv[r1][c1];
        if (r1 != c1)
        {
            printf("INVERSE DOES NOT EXIST\n");
        }
        else if (r1 != 2 && r1 != 3 && r1 != 1)
        {
            printf("ONLY 1X1, 2X2 AND 3X3 MATRIX SUPPORTED\n");
        }
        else if (r1 == 1)
        {   
            printf("ENTER ELEMENTS OF MATRIX A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%f", &arr1[i][j]);
                }
            }
            detA = arr1[0][0];
            inv[0][0] = 1/detA; 
            if (detA == 0)
            {
                printf("INVERSE DOES NOT EXIST");
            }
            else if (detA != 0)
            {
                printf("INVERSE OF MATRIX A IS : \n");
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        printf("%.2f\n", inv[i][j]);
                    }
                }
            }          
        }
        else if (r1 == 2)
        {   printf("ENTER ELEMENTS OF MATRIX A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%f", &arr1[i][j]);
                }
            }
            detA = arr1[0][0] * arr1[1][1] - (arr1[0][1] * arr1[1][0]);
            if (detA == 0)
            {
                printf("INVERSE DOES NOT EXIST");
            }
            else if (detA != 0)
            {
                inv[0][0] = arr1[1][1]/detA;
                inv[0][1] = -arr1[0][1]/detA;
                inv[1][0] = -arr1[1][0]/detA;
                inv[1][1] = arr1[0][0]/detA;
                printf("INVERSE OF MATRIX A IS : \n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    printf("%.2f\t", inv[i][j]);
                }
                printf("\n");
            }
            }
        }
        else if (r1 == 3)
        {
            printf("ENTER ELEMENTS OF MATRIX A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%f", &arr1[i][j]);
                }
            }
            detA = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1])
                   - arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0])
                   + arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0]);
            if (detA == 0)
            {
                printf("INVERSE DOES NOT EXIST");
            }
            else if (detA != 0)
            {
                inv[0][0]=(arr1[1][1]*arr1[2][2]-arr1[1][2]*arr1[2][1])/detA;
                inv[0][1]=-(arr1[0][1]*arr1[2][2]-arr1[0][2]*arr1[2][1])/detA;
                inv[0][2]=(arr1[0][1]*arr1[1][2]-arr1[0][2]*arr1[1][1])/detA;

                inv[1][0]=-(arr1[1][0]*arr1[2][2]-arr1[1][2]*arr1[2][0])/detA;
                inv[1][1]=(arr1[0][0]*arr1[2][2]-arr1[0][2]*arr1[2][0])/detA;
                inv[1][2]=-(arr1[0][0]*arr1[1][2]-arr1[0][2]*arr1[1][0])/detA;

                inv[2][0]=(arr1[1][0]*arr1[2][1]-arr1[1][1]*arr1[2][0])/detA;
                inv[2][1]=-(arr1[0][0]*arr1[2][1]-arr1[0][1]*arr1[2][0])/detA;
                inv[2][2]=(arr1[0][0]*arr1[1][1]-arr1[0][1]*arr1[1][0])/detA;
                for (int i = 0; i < r1; i++)
                {
                for (int j = 0; j < c1; j++)
                {
                    printf("%.2f\t", inv[i][j]);
                }
                printf("\n");
                }
            }
        }
    }
    else if (choice == 4)
    {
        unsigned int r1, c1;
        printf("ENTER THE NUMBER OF ROWS OF MATRIX A:-\n");      
        scanf("%u", &r1);
        printf("\nENTER THE NUMBER OF COLUMN OF MATRIX A:-\n");
        scanf("%u", &c1);
        int arr1[r1][c1];
        if (r1 != c1)
        {
            printf("characteric equation is only defined for square matrix.");
        }
        else if(r1 != 2 && r1 != 3)
        {
            printf("only 2x2 and 3x3 matrix is supported");
        }
        else if(r1 == 2)
        {
            printf("ENTER ELEMENTS OF MATRIX A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%d", &arr1[i][j]);
                }
            }
            detA = arr1[0][0] * arr1[1][1] - (arr1[0][1] * arr1[1][0]);
            int traceA = arr1[0][0] + arr1[1][1];
            printf("CHARATERSTIC EQUATION OF MATRIX A IS:\n");
            printf("λ² - %dλ + %d", traceA, detA);
        }
        else if (r1 == 3)
        {   
            printf("ENTER ELEMENTS OF MATRIX A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%d", &arr1[i][j]);
                }
            }
            detA = arr1[0][0]*(arr1[1][1]*arr1[2][2] - arr1[1][2]*arr1[2][1])
                   - arr1[0][1]*(arr1[1][0]*arr1[2][2] - arr1[1][2]*arr1[2][0])
                   + arr1[0][2]*(arr1[1][0]*arr1[2][1] - arr1[1][1]*arr1[2][0]);
            int traceA = arr1[0][0] + arr1[1][1] + arr1[2][2];
            int sum_principle_minors = arr1[1][1] * arr1[2][2] - arr1[1][2] * arr1[2][1]
                                       + arr1[0][0] * arr1[2][2] - arr1[0][2] * arr1[2][0]
                                       + arr1[0][0] * arr1[1][1] - arr1[0][1] * arr1[1][0];
            printf("CHARATERSTIC EQUATION OF MATRIX A IS:\n");
            printf("λ³ - %dλ² + %dλ - %d", traceA, sum_principle_minors, detA);

        }
    }
    else if (choice == 5)
    {
        unsigned int r1, c1;
        printf("ENTER THE NUMBER OF ROWS OF MATRIX A:-\n");      
        scanf("%u", &r1);
        printf("\nENTER THE NUMBER OF COLUMN OF MATRIX A:-\n");
        scanf("%u", &c1);
        int arr1[r1][c1];
        if (r1 != c1)
        {
            printf("EIGEN VALUES ARE ONLY DEFINED FOR A SQUARE MATRIX\n");
        }
        else if(r1 != 2)
        {
            printf("ONLY 2x2 MARRIX ARE SUPPORTED\n");
        }
        else if (r1 == 2)
        {
            printf("ENTER ELEMENTS OF MATRIX A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%d", &arr1[i][j]);
                }
            }
            detA = arr1[0][0] * arr1[1][1] - (arr1[0][1] * arr1[1][0]);
            int traceA = arr1[0][0] + arr1[1][1];
            int discriminant = traceA * traceA - 4 * detA;
            float eigen_value1 = (traceA + sqrt(discriminant))/2;
            float eigen_value2 = (traceA - sqrt(discriminant))/2;
            printf("EIGEN VALUE OF MATRIX A IS : %f and %f", eigen_value1, eigen_value2);
        }
    }
    else if (choice == 6)
    {
        unsigned int r1, c1;
        printf("ENTER THE NUMBER OF ROWS OF MATRIX A:-\n");      
        scanf("%u", &r1);
        printf("\nENTER THE NUMBER OF COLUMN OF MATRIX A:-\n");
        scanf("%u", &c1);
        int arr1[r1][c1];
        if (r1 != c1)
        {
            printf("EIGEN VECTOR ARE ONLY DEFINED FOR A SQUARE MATRIX\n");
        }
        else if(r1 != 2)
        {
            printf("ONLY 2x2 MARRIX ARE SUPPORTED\n");
        }
        else if (r1 == 2)
        {
            printf("ENTER ELEMENTS OF MATRIX A:\n");
            for (int i = 0; i < r1; i++)
            {
                for (int j = 0; j < c1; j++)
                {
                    scanf("%d", &arr1[i][j]);
                }
            }
            detA = arr1[0][0] * arr1[1][1] - (arr1[0][1] * arr1[1][0]);
            int traceA = arr1[0][0] + arr1[1][1];
            int discriminant = traceA * traceA - 4 * detA;
            float eigen_value1 = (traceA + sqrt(discriminant))/2;
            float eigen_value2 = (traceA - sqrt(discriminant))/2;
            printf("EIGEN VECTOR FOR 2x2 MATRIX ARE:\n");
            printf("X₁ = %.2d\n", arr1[0][1]);
            printf("     %.2f\n", eigen_value1 - arr1[0][0]);
            printf("X₂ = %.2d\n", arr1[0][1]);
            printf("     %.2f", eigen_value2 - arr1[0][0]);
        }
    }
    else if (choice == 7)
    {
        unsigned int r1, c1;
        printf("ENTER THE NUMBER OF ROWS OF MATRIX A:-\n");      
        scanf("%u", &r1);
        printf("\nENTER THE NUMBER OF COLUMN OF MATRIX A:-\n");
        scanf("%u", &c1);
        int arr1[r1][c1];
        printf("ENTER ELEMENTS OF MATRIX A:\n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        }
        printf("THE TRANSPOSE OF THE MATRIX A IS:\n");
        for (int i = 0; i < c1; i++)
        {
            for (int j = 0; j < r1; j++)
            {
                printf("%d\t", arr1[j][i]);
            }
            printf("\n");
        }

    }
    return 0;
}