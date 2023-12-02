#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() 
{
    const char* InputPath = "input.txt";
    const char* OutputPath = "output.txt";

    FILE* inputFile = fopen(InputPath, "r");
    FILE* outputFile = fopen(OutputPath, "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        perror("Error opening files");
        return 1;
    }

    int charCount = 0, lineCount = 0, vowelCount = 0, consonantCount = 0, digitCount = 0;
    int currentChar;

    while ((currentChar = fgetc(inputFile)) != EOF) 
    {
        charCount++;

        if (currentChar == '\n') 
        {
            lineCount++;
        }
        else if (isalpha(currentChar))
        {
            char lowercaseChar = tolower(currentChar);
            if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' || lowercaseChar == 'u')
            {
                vowelCount++;
            }
            else 
            {
                consonantCount++;
            }
        }
        else if (isdigit(currentChar)) 
        {
            digitCount++;
        }

        fputc(currentChar, outputFile);
    }

    if (charCount > 0 && fgetc(outputFile) != '\n') 
    {
        lineCount++;
    }

    /*%d is a format specifier for integers*/
    fprintf(outputFile, "\nNumber of characters: %d\n", charCount);
    fprintf(outputFile, "Number of lines: %d\n", lineCount);
    fprintf(outputFile, "Number of vowels: %d\n", vowelCount);
    fprintf(outputFile, "Number of consonants: %d\n", consonantCount);
    fprintf(outputFile, "Number of digits: %d\n", digitCount);

    printf("Statistics written to %s\n", OutputPath);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
