*This project has been created as part of the 42 curriculum by <fbachman>*

# Custom C Library

## Description
This project involves coding a C library that includes numerous general-purpose functions to be used in future programs within the 42 curriculum. The goal is to re-create standard C library functions (such as those in `<string.h>`, `<ctype.h>`, and `<stdlib.h>`), as well as additional utility functions, to deeply understand data structures, memory management, and low-level operations.

---

## Library Overview

### 1. Libc Functions
Re-implementation of standard functions:

* `ft_isalpha` – Check for an alphabetic character.
* `ft_isdigit` – Check for a digit (0 through 9).
* `ft_isalnum` – Check for an alphanumeric character.
* `ft_isascii` – Check whether a character fits into the ASCII character set.
* `ft_isprint` – Check for any printable character.
* `ft_strlen` – Calculate the length of a string.
* `ft_memset` – Fill memory with a constant byte.
* `ft_bzero` – Zero a byte string.
* `ft_memcpy` – Copy memory area.
* `ft_memmove` – Copy memory area with handling for overlapping areas.
* `ft_strlcpy` – Size-bounded string copying.
* `ft_strlcat` – Size-bounded string concatenation.
* `ft_toupper` – Convert a lowercase letter to uppercase.
* `ft_tolower` – Convert an uppercase letter to lowercase.
* `ft_strchr` – Locate the first occurrence of a character in a string.
* `ft_strrchr` – Locate the last occurrence of a character in a string.
* `ft_strncmp` – Compare two strings up to a specified number of bytes.
* `ft_memchr` – Scan memory for a character.
* `ft_memcmp` – Compare memory areas.
* `ft_strnstr` – Locate a substring in a string, searching up to a specific length.
* `ft_atoi` – Convert a string to an integer.
* `ft_calloc` – Allocate memory and initialize all bytes to zero.
* `ft_strdup` – Duplicate a string by allocating dynamic memory.

### 2. Additional Functions
Non-standard utility functions designed to manipulate strings, memory, and file descriptors:

* `ft_substr` – Extract a substring from a string at a specific index.
* `ft_strjoin` – Concatenate two strings into a newly allocated string.
* `ft_strtrim` – Trim specific characters from the beginning and end of a string.
* `ft_split` – Split a string into an array of strings using a delimiter character.
* `ft_itoa` – Convert an integer into a string (ASCII representation).
* `ft_strmapi` – Apply a function to each character of a string, creating a new string.
* `ft_striteri` – Apply a function to each character of a string, modifying it in place.
* `ft_putchar_fd` – Output a character to a given file descriptor.
* `ft_putstr_fd` – Output a string to a given file descriptor.
* `ft_putendl_fd` – Output a string followed by a newline to a given file descriptor.
* `ft_putnbr_fd` – Output an integer to a given file descriptor.

### 3. Linked Lists
Functions created to manipulate and manage singly linked list data structures:

* `ft_lstnew` – Create a new list element.
* `ft_lstadd_front` – Add a new element at the beginning of a list.
* `ft_lstsize` – Count the number of elements in a list.
* `ft_lstlast` – Return the last element of a list.
* `ft_lstadd_back` – Add a new element at the end of a list.
* `ft_lstdelone` – Free the memory of a specific list element's content.
* `ft_lstclear` – Delete and free an entire list.
* `ft_lstiter` – Iterate over a list and apply a function to the content of each element.
* `ft_lstmap` – Iterate over a list and apply a function to create a new list.
---

## Instructions

### Compilation & Installation

To compile the library, clone this repository and run `make` at the root directory:

```bash
git clone [git@vogsphere-v2.42sp.org.br:vogsphere/intra-uuid-9bcf1cec-7a6e-42c8-b482-d87edc3d22a1-7439599-fbachman] [repo-name]
cd [repo-name]
make

Available Makefile Commands
make — Compiles the source files and creates the libft.a library (runs the default all rule).

make clean — Removes all compiled object files (.o) from the directory.

make fclean — Deletes all object files as well as the generated libft.a library.

make re — Cleans all compiled files and recompiles the entire library from scratch (equivalent to make fclean followed by make).