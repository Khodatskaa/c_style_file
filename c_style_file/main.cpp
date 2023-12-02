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
    while (fgets(InputString, 100, InputFile) != NULL)
    {
        size_t length = strlen(InputString);
        if (length > 0 && InputString[length - 1] == '\n')
        {
            InputString[length - 1] = '\0';
            length--;
        }

        for (size_t i = 0; i < length / 2; i++)
        {
            char temp = InputString[i];
            InputString[i] = InputString[length - i - 1];
            InputString[length - i - 1] = temp;
        }

        fputs(InputString, OutputFile);
    }

    fclose(InputFile);
    fclose(OutputFile);

    return 0;
}
