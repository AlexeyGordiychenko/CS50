#include <stdio.h>
#include <ctype.h>

unsigned int hash(const char *word);

int main(int argc, char *argv[])
{
    printf("%u\n", hash(argv[1]) % 101);
}
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hashval = 0;
    for (hashval = 0; *word != '\0'; word++)
        hashval = tolower(*word) + 31*hashval;
    return hashval;
    //return toupper(word[0]) - 'A';
}