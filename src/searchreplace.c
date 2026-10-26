/*
 * CSE 220 Homework 6: command line parsing, file I/O, and search and replace.
 *
 * Name:
 * SBU ID:
 *
 * Write all of your code in this file. Only this file is collected, so it must
 * be self contained. Helper functions are encouraged, and they will not
 * interfere with grading.
 *
 * Do not change include/searchreplace.h or anything under tests/ other than
 * the three test files under tests/.
 */
#include "searchreplace.h"

int main(int argc, char *argv[])
{
    /*
     * TODO: Part 1, validate the command line arguments.
     *
     * Check the errors in exactly this order and return the matching macro
     * from hw6.h as soon as one applies. Return the names, never the numbers.
     *
     *   1. MISSING_ARGUMENT        fewer than 7 arguments, argv[0] included
     *   2. DUPLICATE_ARGUMENT      any of -s, -r, -l, -w given more than once
     *   3. INPUT_FILE_MISSING      the input file cannot be opened for reading
     *   4. OUTPUT_FILE_UNWRITABLE  the output file cannot be written
     *   5. S_ARGUMENT_MISSING      -s absent, or its argument absent
     *   6. R_ARGUMENT_MISSING      -r absent, or its argument absent
     *   7. L_ARGUMENT_INVALID      a line number is missing or unparseable,
     *                              or start_line is greater than end_line
     *   8. WILDCARD_INVALID        -w was given and -s is not a valid pattern
     *
     * The order matters as much as the codes. A command line with two faults
     * must report the one that comes first in this list.
     *
     * The input file is argv[argc - 2] and the output file is argv[argc - 1].
     * The argument after -s, -r or -l must not itself start with '-'.
     * Use getopt to walk the options, and strtol with strtok for -l.
     * Unknown options are ignored rather than reported.
     *
     * When you return an error code, leave the output file alone. Do not
     * create it and do not truncate it.
     */

    /*
     * TODO: Part 2, simple search and replace.
     *
     * Copy the input file to the output file, replacing every occurrence of
     * the search text with the replacement text. The search text may appear
     * anywhere, including in the middle of a word. Lines outside the -l range
     * are copied through unchanged, and line numbers start at 1.
     *
     * Read a line at a time with fgets and a buffer of MAX_LINE bytes. Look at
     * strstr for finding the search text.
     */

    /*
     * TODO: Part 3, wildcard search and replace.
     *
     * Active only when -w is given. The search text then carries exactly one
     * '*', either at the start or at the end, and whole words are replaced.
     *
     *   "foo*"  replaces every word that begins with foo
     *   "*foo"  replaces every word that ends with foo
     *
     * A word is a run of alphanumeric characters. What ends a word is any
     * character that isspace or ispunct says is whitespace or punctuation, and
     * also the start of a line, the end of a line, and the end of the file.
     * Use those two functions rather than listing characters yourself.
     *
     * Watch the boundaries: a word can sit at the very start of a line, right
     * after a punctuation mark, or at the very end of the file.
     */

    (void)argc;
    (void)argv;
    return 0;
}
