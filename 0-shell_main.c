#include "shell.h"

/**
 * main - main function for the shell
 * 1. prompt <-----
 * 2. input       |
 * 3. parse       |
 * 4. execute -----
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * Return: the string of the line
 */

int main(int argc__attribute__((unused)), char **argv)
{
char *line;
char **args;
int cmd_type;
(void) argv;
signal(SIGINT, ctrl_C);
while (1)
{
print(" ($) ", STDOUT_FILENO);
line = _getline();
if (line == NULL)
{
if (isatty(STDIN_FILENO))
break;
}
args = tokenize(line, DELIM);
cmd_type = check_command(args[0]);
shell_execute(args, cmd_type);
}
return (1);
}
