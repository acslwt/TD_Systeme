#include <stdio.h>
#include <stdlib.h> // malloc
#include <stdbool.h>

char **strsplit(const char *s, const char sep)
{
    int s_lenght = 0; //? usefull?
    int sep_count = 0;

    while (s[s_lenght] != '\0')
    {
        if (s[s_lenght] == sep)
        {
            sep_count++;
        }
        s_lenght++;
    }
    printf("Le texte fait %i caractères et il y a %i separateurs : %c\n", s_lenght, sep_count, sep);

    int word_count;

    if (s[s_lenght - 1] == sep)
    {
        word_count = sep_count;
    }
    else
    {
        word_count = sep_count + 1;
    }
    char **words = (char **)malloc(sizeof(char *) * word_count + 1);
    words[word_count] = NULL;

    int previous_length = 0;
    for (int j = 0; j < word_count; j++)
    {
        int word_char_count = 0; // contains the number of characters the current word has
        while (s[previous_length + word_char_count] != sep)
        {
            word_char_count++;
        }

        char *word = (char *)malloc(sizeof(char) * (word_char_count) + 1);
        word[word_char_count] = '\0';
        for (int k = 0; k < word_char_count; k++)
        {
            word[k] = s[previous_length + k];
        }
        words[j] = word;
        previous_length += word_char_count + 1;
    }

    return words;
}

void print_list_of_words(char **words)
{
    int i = 0;
    while (words[i] != NULL)
    {
        printf("%i :  %s\n", i, words[i]);
        i++;
    }
}
/*
words should end by NULL
*/
void free_list_of_words(char **words)
{
    int i = 0;
    while (words[i] != NULL)
    {
        free(words[i]);
    }
}

int main(int argc, char const *argv[])
{

    char **words = strsplit("salut,a,tous,cest,david,lafarge,pokemon,on,se,retrouve", ',');
    print_list_of_words(words);
    free_list_of_words(words);

    return 0;
}