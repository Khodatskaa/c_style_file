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
        fputs(InputString, OutputFile);
    }

    fclose(InputFile);
    fclose(OutputFile);

    return 0;
}
