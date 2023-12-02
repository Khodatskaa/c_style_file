#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    char InputPath[] = "test.txt";
    char OutputPath[] = "output.txt";

    FILE* InputFile;
    FILE* OutputFile;

    InputFile = fopen(InputPath, "w");
    OutputFile = fopen(OutputPath, "r");

    if (InputFile == NULL || OutputFile == NULL)
    {
        perror("Error");
        return 0;
    }

    char InputString[100];
    while (fgets(InputString, 100, InputFile) != NULL)
    {
        // Remove newline character
        size_t length = strlen(InputString);
        if (length > 0 && InputString[length - 1] == '\n')
        {
            InputString[length - 1] = '\0';
            length--;
        }

        // Reverse the line
        for (size_t i = 0; i < length / 2; i++)
        {
            char temp = InputString[i];
            InputString[i] = InputString[length - i - 1];
            InputString[length - i - 1] = temp;
        }

        // Write reversed line to the output file
        fputs(InputString, OutputFile);
        fputc('\n', OutputFile);  // Add newline character
    }

    fclose(InputFile);
    fclose(OutputFile);

    return 0;
}
