#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void encryptCaesarCipher(const char* inputPath, const char* outputPath, int shift)
{
    FILE* inputFile = fopen(inputPath, "r");
    FILE* outputFile = fopen(outputPath, "w");

    if (inputFile == NULL || outputFile == NULL) 
    {
        perror("Error opening files");
        return;
    }

    int currentChar;

    while ((currentChar = fgetc(inputFile)) != EOF)
    {
        if (isalpha(currentChar)) 
        {
            char baseChar = isupper(currentChar) ? 'A' : 'a';
            currentChar = ((currentChar - baseChar + shift) % 26 + 26) % 26 + baseChar;
        }

        fputc(currentChar, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() 
{
    const char* InputPath = "input.txt";
    const char* OutputPath = "output.txt";
    int shift = 5;

    FILE* inputFile = fopen(InputPath, "r");
    FILE* outputFile = fopen(OutputPath, "w");

    if (inputFile == NULL || outputFile == NULL)
    {
        perror("Error opening files");
        return 1;
    }

    int currentChar;

    while ((currentChar = fgetc(inputFile)) != EOF) 
    {
        if (isalpha(currentChar)) 
        {
            char baseChar = isupper(currentChar) ? 'A' : 'a';
            currentChar = ((currentChar - baseChar + shift) % 26 + 26) % 26 + baseChar;
        }

        fputc(currentChar, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted using Caesar cipher and written to %s\n", OutputPath);

    return 0;
}
