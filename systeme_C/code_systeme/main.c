#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "StringVector.h"
#include "shell.h"
#include "commands.h"

int main()
{
    struct Shell shell;
    shell_init(&shell);
    shell_run(&shell);
    shell_free(&shell);
    return 0;
}