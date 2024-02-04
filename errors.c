#include "monty.h"

/**
 * err - Prints appropriate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => General error.
 * (2) => File access error.
 * (3) => Invalid instruction.
 * (4) => Memory allocation error.
 * (5) => Invalid push parameter.
 */
void err(int error_code, ...)
{
    va_list ag;

    va_start(ag, error_code);
    switch (error_code)
    {
        case 1:
            fprintf(stderr, "Error: An unspecified error occurred\n");
            break;
        case 2:
            fprintf(stderr, "Error: Unable to access the specified file\n");
            break;
        case 3:
            fprintf(stderr, "Error: Encountered an unknown instruction\n");
            break;
        case 4:
            fprintf(stderr, "Error: Failed to allocate memory\n");
            break;
        case 5:
            fprintf(stderr, "Error: Invalid parameter for push instruction\n");
            break;
        default:
            break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * more_err - handles additional errors.
 * @error_code: The error codes are the following:
 * (6) => Empty stack for pint.
 * (7) => Empty stack for pop.
 * (8) => Stack too short for operation.
 * (9) => Division by zero.
 */
void more_err(int error_code, ...)
{
    va_list ag;

    va_start(ag, error_code);
    switch (error_code)
    {
        case 6:
            fprintf(stderr, "Error: Unable to execute pint, stack is empty\n");
            break;
        case 7:
            fprintf(stderr, "Error: Unable to execute pop, stack is empty\n");
            break;
        case 8:
            fprintf(stderr, "Error: Unable to perform operation, stack is too short\n");
            break;
        case 9:
            fprintf(stderr, "Error: Division by zero detected\n");
            break;
        default:
            break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}

/**
 * string_err - handles string-related errors.
 * @error_code: The error codes are the following:
 * (10) ~> Invalid character value.
 * (11) ~> Empty stack.
 */
void string_err(int error_code, ...)
{
    va_list ag;

    va_start(ag, error_code);
    switch (error_code)
    {
        case 10:
            fprintf(stderr, "Error: Invalid character value encountered\n");
            break;
        case 11:
            fprintf(stderr, "Error: Unable to execute pchar, stack is empty\n");
            break;
        default:
            break;
    }
    free_nodes();
    exit(EXIT_FAILURE);
}
