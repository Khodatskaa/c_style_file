#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    char inputPath[] = "test.txt";
    char outputPath[] = "output.txt";

    FILE* inputFile;
    FILE* outputFile;

    inputFile = fopen(inputPath, "r");
    outputFile = fopen(outputPath, "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    char word[100];

    while (fgets(buffer, 100, inputFile) != NULL)
    {
        int i = 0;
        int bufferLength = strlen(buffer);

        while (i < bufferLength)
        {
            while (i < bufferLength && !isalpha(buffer[i]))
            {
                i++;
            }

            int wordStart = i;
            while (i < bufferLength && isalpha(buffer[i]))
            {
                i++;
            }

            int wordLength = i - wordStart;

            if (wordLength >= 7)
            {
                int j;
                for (j = 0; j < wordLength; j++)
                {
                    word[j] = buffer[wordStart + j];
                }
                word[j] = '\0';

                fputs(word, outputFile);
                fputs(" ", outputFile);
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    cout << "Words have been written to output.txt" << endl;

    return 0;
}
