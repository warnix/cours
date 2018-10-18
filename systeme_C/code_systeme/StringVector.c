#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "StringVector.h"

void string_vector_init(struct StringVector *this, size_t capacity)
{
    this->capacity = capacity;
    this->size = 0;
    this->strings = malloc(capacity * sizeof(char *));
}

void string_vector_free(struct StringVector *this)
{
    for (size_t i = 0; i < this->size; i++)
    {
        free(this->strings[i]);
    }
    free(this->strings);
}

void string_vector_add(struct StringVector *this, const char *begin,
                       const char *end)
{
    if (this->capacity == this->size)
    {
        this->capacity *= 2;
        this->strings = realloc(this->strings, this->capacity * sizeof(char *));
    }
    this->strings[this->size++] = strndup(begin, end - begin);
}

size_t string_vector_size(const struct StringVector *this)
{
    return this->size;
}

char *string_vector_get(const struct StringVector *this, size_t index)
{
    return this->strings[index];
}

struct StringVector split_line(char *line)
{
    struct StringVector tokens;
    string_vector_init(&tokens, 8);
    char *start = NULL; // where the current token starts. NULL if no token
    for (char *p = line; (*p != '\0'); p++)
    {
        if (start == NULL)
        {
            if (!isspace(*p))
            {
                // starting a new token
                start = p;
            }
        }
        else if (start != NULL)
        {
            if (isspace(*p))
            {
                string_vector_add(&tokens, start, p);
                start = NULL;
            }
        }
    }
    return tokens;
}
char *string_vector_space(char *dest, char *strings[], size_t number)
{
    char *target = dest;
    *target;
    for (size_t i = 1; i < number; i++)
    {
        if (i > 1)
        {
            strcat(target, " ");
            target++;
        }
        strcat(target, strings[i]);
        target += strlen(strings[i]);
    };
    return dest;
}
