#include <stdlib.h>


char **split_string(char *str, char *delimiters);
int is_delimiter(char ch, char *delimiters);
int get_word_length(char *str, char *delimiters);
int get_word_count(char *str, char *delimiters);
char *get_next_word(char *str, char *delimiters);


/**
 * split_string - splits a string into words
 *
 * @str: string to be split into words
 * @delimiters: delimiters to use for word splitting
 *
 * Return: 2D array of pointers to each word
 */


char **split_string(char *str, char *delimiters)
{
    char **words = NULL;
    int word_count, word_length, n, i = 0;


    if (str == NULL || !*str)
        return (NULL);
    word_count = get_word_count(str, delimiters);


    if (word_count == 0)
        return (NULL);
    words = malloc((word_count + 1) * sizeof(char *));
    if (words == NULL)
        return (NULL);
    while (i < word_count)
    {
        word_length = get_word_length(str, delimiters);
        if (is_delimiter(*str, delimiters))
        {
            str = get_next_word(str, delimiters);
        }
        words[i] = malloc((word_length + 1) * sizeof(char));
        if (words[i] == NULL)
        {
            while (i >= 0)
            {
                i--;
                free(words[i]);
            }
            free(words);
            return (NULL);
        }
        n = 0;
        while (n < word_length)
        {
            words[i][n] = *(str + n);
            n++;
        }
        words[i][n] = '\0'; /* set end of str */
        str = get_next_word(str, delimiters);
        i++;
    }
    words[i] = NULL; /* last element is null for iteration */
    return (words);
}


/**
 * is_delimiter - checks if a character is a delimiter
 *
 * @ch: character to be checked
 * @delimiters: pointer to a null-terminated array of delimiters
 *
 * Return: 1 (success) or 0 (failure)
 */


int is_delimiter(char ch, char *delimiters)
{
    int i = 0;


    while (delimiters[i])
    {
        if (delimiters[i] == ch)
            return (1);
        i++;
    }
    return (0);
}


/**
 * get_word_length - gets the word length of the current word in a string
 *
 * @str: string to get the word length from the current word
 * @delimiters: delimiters to use for word splitting
 *
 * Return: word length of the current word
 */


int get_word_length(char *str, char *delimiters)
{
    int word_length = 0, pending = 1, index = 0;


    while (*(str + index))
    {
        if (is_delimiter(str[index], delimiters))
            pending = 1;
        else if (pending)
        {
            word_length++;
        }
        if (word_length > 0 && is_delimiter(str[index], delimiters))
            break;
        index++;
    }
    return (word_length);
}


/**
 * get_word_count - gets the word count of a string
 *
 * @str: string to get the word count from
 * @delimiters: delimiters to use for word splitting
 *
 * Return: the word count of the string
 */


int get_word_count(char *str, char *delimiters)
{
    int word_count = 0, pending = 1, index = 0;


    while (*(str + index))
    {
        if (is_delimiter(str[index], delimiters))
            pending = 1;
        else if (pending)
        {
            pending = 0;
            word_count++;
        }
        index++;
    }
    return (word_count);
}


/**
 * get_next_word - gets the next word in a string
 *
 * @str: string to get the next word from
 * @delimiters: delimiters to use for word splitting
 *
 * Return: pointer to the first character of the next word
 */


char *get_next_word(char *str, char *delimiters)
{
    int pending = 0;
    int index = 0;


    while (*(str + index))
    {
        if (is_delimiter(str[index], delimiters))
            pending = 1;
        else if (pending)
            break;
        index++;
    }
    return (str + index);
}
