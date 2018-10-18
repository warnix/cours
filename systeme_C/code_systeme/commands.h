#ifndef COMMANDS_H
#define COMMANDS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "StringVector.h"

typedef void (*Action)(
    struct Shell *,
    const struct StringVector *);
Action get_action(char *name);

#endif /* COMMANDS_H */