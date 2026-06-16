*This project has been created as part of the 42 curriculum by <fbachman>*

# ft_printf()

## Description
The main goal of this project is to recode the `printf()` function from the standard `libc` (`stdio.h`). This project introduces the concept of **variadic arguments** in C, allowing a function to accept a variable number of inputs.

## Overview
he recoded `ft_printf()` function replicates the exact behavior of the original `printf()`, managing memory efficiently and handling formatting flags accurately.

The following conversions are supported:
• `%c` Prints a single character.
• `%s` Prints a string (as defined by the common C convention).
• `%p` The void * pointer argument has to be printed in hexadecimal format.
• `%d` Prints a decimal (base 10) number.
• `%i` Prints an integer in base 10.
• `%u` Prints an unsigned decimal (base 10) number.
• `%x` Prints a number in hexadecimal (base 16) lowercase format.
• `%X` Prints a number in hexadecimal (base 16) uppercase format.
• `%%` Prints a percent sign.

## Algorithm & Data Structure Justification

### Data Structure: Variadic Arguments (`va_list`)
Since `printf` must accept an unpredictable number of parameters of varying types, standard fixed-parameter arrays or structures are insufficient. The project utilizes the native `va_list` data structure (provided by `<stdarg.h>`). 
**Justification:** A `va_list` acts as a continuous memory pointer that moves forward through the stack frame to fetch parameters on demand. This ensures `O(1)` memory overhead, as it doesn't duplicate data into arrays or linked lists, keeping the memory footprint minimal and safe.

### Algorithm: The Dispatcher Pattern
The core logic relies on a single-pass string parsing algorithm paired with a Dispatcher Pattern:
• **Iterative Traversal:** The format string is read character by character (`O(N)` time complexity).
• **Flag Detection:** If a `%` character is found, control is passed to a dispatcher function (`ft_dispatcher`).
• **Type Casting & Printing:** The dispatcher uses conditional branching to identify the specifier, dynamically extract the corresponding data type using `va_arg`, track the exact printed character count via a pointer (`int *count`), and render it to stdout.

**Justification:** This architecture separates data parsing from data printing. It eliminates the need for complex nested loops, prevents memory fragmentation by printing directly to file descriptor 1 on the fly, and allows easy scalability if more formatting flags need to be added in the future.

## Instructions

### Compilation & Installation

To compile the library, clone this repository and run `make` at the root directory:

```bash
git clone (git-url) (repo-name)
cd (repo-name)
make
```

Available Makefile Commands
• make — Compiles the source files, handles the internal libft compilation, and creates the libftprintf.a library.

• make clean — Removes all compiled object files (.o) from both the ft_printf and libft directories.

• make fclean — Deletes all object files as well as the generated libftprintf.a and libft.a libraries.

• make re — Cleans all compiled files and recompiles the entire library from scratch (equivalent to make fclean followed by make).

### Usage & Examples

To use ft_printf in your code, include the header and compile your files along with the libftprintf.a static library.

Example Code (main.c)

#include "ft_printf.h"

int main(void)
{
    ft_printf("%s!!\n", "Hello world");
    ft_printf("Hex: %x | Pointer: %p\n", 255, &main);
    return (0);
}
Compilation Command
Bash
cc main.c libftprintf.a -I. -o program_executable
Output
Plaintext
Hello world!!
Hex: ff | Pointer: 0x5560b4a2d1a0

## Resources

### References
• [Acelera Notion] - (https://rodsmade.notion.site/Acelera-Printf-9b57272e356c45968455fe31b47952fc)
• [Geeks for Geeks] - Variadic Functions in C - (https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
• [Microsoft Learn] - Variadic Functions in C - (https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/va-arg-va-copy-va-end-va-start?view=msvc-170)

### AI Usage
• Bug detection
• Architecture validation