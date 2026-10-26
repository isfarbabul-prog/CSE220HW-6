# CSE 220 Homework 6 Starter Kit

Read the assignment description first. It has the full rules, the error codes
and their order, all the examples, and the grading breakdown. This file only
covers how to build and run things.

## What is in here

    Makefile                     builds bin/searchreplace and bin/run_tests
    include/searchreplace.h      constants and error codes, do not change
    src/searchreplace.c          write your program here
    tests/provided_tests.c       the provided tests, do not change
    tests/test_helpers.h         helpers used by the tests, do not change
    tests/test_part1_args.c      your Part 1 tests, at least 10 of your own
    tests/test_part2_simple.c    your Part 2 tests, at least 5 of your own
    tests/test_part3_wildcard.c  your Part 3 tests, at least 5 of your own
    tests.in.orig/               input files for the tests, safe from make test
    tests.out.exp/               expected output files for the provided tests

## Building and running

    make           build your program and the tests
    make test      build if needed, then run every graded test
    make valgrind  run the valgrind checks, which are feedback only
    make clean     remove build/, bin/, tests.in/ and tests.out/

The Makefile compiles with `-Wall -Wextra -Wshadow -Wdouble-promotion
-Wformat=2 -Wundef -pedantic -Werror`, so any warning stops the build. The kit
compiles as given, and every test fails until you implement the program. That
is expected.

**`make test` deletes `tests.in` and `tests.out` every run.** Keep your own
input files in `tests.in.orig`, which is never touched. The tests copy what
they need from there into `tests.in`.

To run one suite, quote the glob:

    ./bin/run_tests --filter 'part1_args/*'

## Criterion

The tests use Criterion. It is already installed in the terminal of the
CodeGrade code editor, along with gcc, make and valgrind, so `make test` and
`make valgrind` work there with no setup. Open the editor, click the terminal
icon at the bottom left, and run your commands there. Your files are the same
ones you hand in.

On your own machine, install Criterion first:

    macOS (Homebrew):   brew install criterion
    Ubuntu or Debian:   sudo apt install libcriterion-dev

The Makefile finds Criterion through pkg-config, and falls back to
`-lcriterion` if pkg-config does not know about it.

## Valgrind

Valgrind runs your program on a simulated processor and watches every memory
access, so it catches reads of uninitialized memory, writes past the end of a
buffer, use after free, and leaks.

**The valgrind checks are not graded.** Nothing valgrind reports can cost you
points on this homework. You still get the report, because valgrind is required
for Homework 8 and this is a gentle place to meet it.

Run them yourself on Linux with:

    make valgrind

They are skipped during an ordinary `make test`, so your normal runs stay
quick, and `make valgrind` never fails your build. If a report is hard to read,
bring it to a recitation or to your TAs in office hours.

## What you have to write

* The whole program in `src/searchreplace.c`, in three parts: validate the
  arguments, simple search and replace, then wildcard search and replace.
  Helper functions inside that file are encouraged.
* Criterion tests in the three part files, worth 15 points in total:
  at least 10 of your own in `tests/test_part1_args.c`, at least 5 in
  `tests/test_part2_simple.c`, and at least 5 in `tests/test_part3_wildcard.c`.
  The sample tests already in those files are only examples and do not count
  toward the minimums. Part 1 asks for more because it has eight error codes
  and an order to check them in.
* Your name and SBU ID in a comment at the top of every file you write.

Only `src/searchreplace.c` is used to test your program, so keep all of your
program code in that one file.

## Two things that catch people out

* **Input lines are at most 199 characters** plus the newline, which is what
  `MAX_LINE` in `searchreplace.h` allows for. Read a line at a time with `fgets`.
* **Newlines.** On Windows a line ends with two characters, on Linux and macOS
  with one. Testing happens on Linux, so write your files with Linux newlines.

## Submitting

You submit through CodeGrade, not as a ZIP file. Open the HW6 link on
Brightspace and CodeGrade opens with all of the files above already in its
editor. Edit `src/searchreplace.c` and the three test files there. If you built and
tested on your own machine, copy your finished versions into the editor. Then
hand in.

Do not delete or rename any file. Changes to the Makefile,
`include/searchreplace.h`, `tests/provided_tests.c` and `tests/test_helpers.h`
are ignored when your code is tested, and they are flagged for the TAs to
review.
