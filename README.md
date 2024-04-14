#Description

This C file contains functions for string manipulation and file reading, including functions to get the length of a string, find a character in a string, join two strings, get a line from a string, and create a new string from the remaining characters after a newline.
Functions

  * ft_strlen
        Description: Calculates the length of a string.
        Parameters: char *s - Pointer to the string.
        Returns: size_t - Length of the string.

   * ft_strchr
        Description: Finds the first occurrence of a character in a string.
        Parameters: char *s - Pointer to the string, int c - Character to find.
        Returns: char * - Pointer to the first occurrence of the character, or NULL if not found.

   * ft_strjoin
        Description: Concatenates two strings.
        Parameters: char *left_str - Pointer to the left string, char *buff - Pointer to the right string.
        Returns: char * - Pointer to the concatenated string, or NULL if memory allocation fails.

   * ft_get_line
        Description: Extracts a line from a string until a newline character.
        Parameters: char *left_str - Pointer to the string.
        Returns: char * - Pointer to the extracted line, or NULL if not found.

   * ft_new_left_str
        Description: Creates a new string with the remaining characters after a newline.
        Parameters: char *left_str - Pointer to the string.
        Returns: char * - Pointer to the new string, or NULL if the newline is not found or memory allocation fails.

## Usage

    Include the get_next_line.h header file.
    Use the provided functions in your C program as needed.
