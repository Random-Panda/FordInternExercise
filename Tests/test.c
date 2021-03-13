#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error: proper syntax is {testOutput.txt} {expectedOutput.txt} {outputSize}");
        exit(1);
    }

    FILE *testOutput = fopen(argv[1], "r");
    if (testOutput == NULL)
    {
        printf("Error: Input file does not exist");
        exit(1);
    }

    FILE *expectedOutput = fopen(argv[2], "r");
    if (expectedOutput == NULL)
    {
        printf("Error: cannot open output file");
        exit(1);
    }

    int testPass = 0;
    char buffer[50];

    for (int i = 0; i < *argv[3]; i++)
    {
        int givenVal, expectedVal;

        fgets(buffer, 50, testOutput);
        sscanf(buffer, "%d", &givenVal);

        fgets(buffer, 50, expectedOutput);
        sscanf(buffer, "%d", &expectedVal);

        if (givenVal != expectedVal)
        {
            printf("Test failed, line %d did not evaluate to the expected value", i + 1);
            testPass = 1;
        }
    }

    if (testPass == 0)
    {
        printf("All output matched, test passed");
    }

    fclose(expectedOutput);
    fclose(testOutput);

    return 0;
}
