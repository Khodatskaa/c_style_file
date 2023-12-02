#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    const char* InputPath = "test.txt";
    const char* OutputPath = "output.txt";

    FILE* InputFile;
    FILE* OutputFile;

    InputFile = fopen(InputPath, "r");
    OutputFile = fopen(OutputPath, "w");

    if (InputFile == nullptr || OutputFile == nullptr)
    {
        perror("Error");
        return 1;
    }

    char word[100];
    int wordLength = 0;

    while (fscanf(InputFile, "%99s", word) == 1)
    {
        if (wordLength >= 7)
        {
            fprintf(OutputFile, "%s\n", word);
        }

        wordLength = 0;
    }

    fclose(InputFile);
    fclose(OutputFile);

    return 0;
}
