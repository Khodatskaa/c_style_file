#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    const char* File1Path = "file1.txt";
    const char* File2Path = "file2.txt";

    FILE* File1 = fopen(File1Path, "r");
    FILE* File2 = fopen(File2Path, "r");

    if (File1 == nullptr || File2 == nullptr)
    {
        perror("Error");
        return 1;
    }

    char line1[1000];
    char line2[1000];
    int lineNumber = 0;

    while (fgets(line1, sizeof(line1), File1) != nullptr && fgets(line2, sizeof(line2), File2) != nullptr)
    {
        lineNumber++;

        size_t len1 = strlen(line1);
        if (len1 > 0 && line1[len1 - 1] == '\n')
            line1[len1 - 1] = '\0';

        size_t len2 = strlen(line2);
        if (len2 > 0 && line2[len2 - 1] == '\n')
            line2[len2 - 1] = '\0';

        if (strcmp(line1, line2) != 0)
        {
            cout << "Mismatch at line: " << lineNumber << "\n";
            cout << "File1: " << line1 << "\n";
            cout << "File2: " << line2 << "\n";
            break;
        }
    }

    fclose(File1);
    fclose(File2);

    return 0;
}
