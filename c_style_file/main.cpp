#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    char InputPath[] = "test.txt";
    char OutputPath[] = "output.txt";

    FILE* InputFile;
    FILE* OutputFile;

    InputFile = fopen(InputPath, "r");
    OutputFile = fopen(OutputPath, "w");

    if (InputFile == NULL || OutputFile == NULL)
    {
        perror("Error");
        return 0;
    }

    char InputString[100];
    char lastLineWithoutSpace[100];
    size_t lastLineWithoutSpaceLength = 0;
    bool foundLineWithoutSpace = false;

    while (fgets(InputString, 100, InputFile) != NULL)
    {
        bool lineHasSpace = false;
        for (int i = 0; InputString[i] != '\0'; ++i)
        {
            if (InputString[i] == ' ')
            {
                lineHasSpace = true;
                break;
            }
        }

        if (!lineHasSpace)
        {
            foundLineWithoutSpace = true;
            for (size_t i = 0; i < sizeof(lastLineWithoutSpace) - 1 && InputString[i] != '\0'; ++i)
            {
                lastLineWithoutSpace[i] = InputString[i];
                lastLineWithoutSpaceLength = i + 1;
            }

            lastLineWithoutSpace[lastLineWithoutSpaceLength] = '\0';
        }

        fputs(InputString, OutputFile);
    }

    if (foundLineWithoutSpace)
    {
        for (int i = 0; i < 12; ++i)
        {
            fputs("\n-------------\n", OutputFile);
        }
    }

    fclose(InputFile);
    fclose(OutputFile);

    return 0;
}
