*This project has been created as part of the 42 curriculum by damorim-.*

# ft_printf

## Description

`ft_printf` is a 42 School project that consists of recoding a simplified,
personal version of the standard C library function `printf()`. The goal is
to deeply understand how variadic functions work in C — how a function can
accept a variable, unknown-at-compile-time number of arguments — and how a
format string is parsed character by character to decide what to do with
each argument.

The project is delivered as a static library, `libftprintf.a`, exposing a
single public function:

```c
int ft_printf(const char *format, ...);
```

`ft_printf` reproduces the behaviour of the original `printf` for the
following conversions:

| Conversion | Meaning                          |
|------------|-----------------------------------|
| `%c`       | Character                        |
| `%s`       | String                            |
| `%p`       | Pointer address (hexadecimal)     |
| `%d` / `%i`| Signed decimal integer            |
| `%u`       | Unsigned decimal integer          |
| `%x`       | Unsigned hexadecimal (lowercase)  |
| `%X`       | Unsigned hexadecimal (uppercase)  |
| `%%`       | A literal `%` character           |

Just like the original, the function returns the total number of characters
written to standard output, or `-1` if the format string is `NULL`.

This version relies on [`libft`](./libft), the personal C library built in
an earlier 42 project, for helpers such as `ft_strlen`, `ft_itoa`, and
`ft_calloc`.

## Instructions

### Compilation

The project is built with the provided `Makefile`, which compiles every
source file, builds `libft` as a dependency, and archives everything into
a single static library.

```sh
make        # builds libftprintf.a (compiles libft first)
make clean  # removes object files (project + libft)
make fclean # removes object files AND the compiled library
make re     # fclean + all
```

### Usage

To use `ft_printf` in your own project:

1. Copy the project folder (including the `libft` subfolder) into your
   project, or add it as a submodule.
2. Compile the library with `make`.
3. Include the header and link against the archive:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello, %s! You are %d years old (0x%x in hex).\n",
            "42", 21, 21);
    ft_printf("Characters written: %d\n", len);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
./my_program
```

### Testing

There is no bundled test suite in this repository. Manual testing was done
by comparing `ft_printf`'s output and return value against the system
`printf` for each conversion, including edge cases such as `NULL` strings
and pointers, `0`, negative numbers, and `%%`.

## Technical Choices — Algorithm & Data Structures

No complex data structure is needed for this project; the core challenge is
parsing and control flow, not data organisation. The design choices are:

- **Single left-to-right scan of the format string.** `ft_printf` walks the
  format string once, index by index. Every regular character is written
  directly with `write`; every `%` triggers a lookup at `check_format`,
  which reads the character right after the `%` to decide which conversion
  handler to call. This gives O(n) time complexity in the length of the
  format string (plus the cost of writing the arguments themselves), and
  needs no extra memory to hold the format string itself.

- **`va_list` for variadic arguments.** Since the number and types of
  arguments are only known at the call site, the C standard `<stdarg.h>`
  mechanism (`va_start`, `va_arg`, `va_end`) is used to walk the argument
  list in the same order as the conversions appear in the format string.
  This mirrors exactly how the real `printf` is implemented.

- **One static function per conversion.** Each conversion (`%c`, `%s`,
  `%p`, `%d`/`%i`, `%u`, `%x`, `%X`, `%%`) is isolated in its own function
  and its own file, following the 42 norm (one function's worth of logic
  per file, no more than ~25 lines per function). This keeps `check_format`
  a simple dispatcher and makes each conversion independently testable and
  readable.

- **Recursion for base conversion.** Printing an integer in a base other
  than 10 (`%x`, `%X`, and the hex digits of `%p`) is done recursively:
  the function calls itself on `n / 16` before writing the current digit
  `n % 16`. This naturally prints digits most-significant-first without
  needing to build and reverse a string first, at the cost of using the
  call stack instead of heap memory.

- **`ft_itoa` for base-10 conversion.** `%d`/`%i` reuse `ft_itoa` from
  `libft`, which already handles the sign and the `INT_MIN` edge case
  correctly, avoiding duplicated, error-prone integer-to-string logic.
  `%u` uses a dedicated unsigned counterpart (`ft_unsigned_itoa`) since
  unsigned integers cannot go through the signed `ft_itoa` without risking
  overflow on values above `INT_MAX`.

- **Defensive `NULL` handling.** `%s` on a `NULL` pointer prints `(null)`
  and `%p` on a `NULL` pointer prints `(nil)`, matching glibc's `printf`
  behaviour, so the library doesn't crash on the same inputs a real
  program might pass it.

## Resources

Classic references used while working on the topic:

- [`printf(3)` — Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html) — reference for conversion specifiers and return value semantics.
- [C Standard, §7.21.6.1 `fprintf`](https://en.cppreference.com/w/c/io/fprintf) — cppreference page detailing the formal behaviour `printf`-family functions must follow.
- [`stdarg.h` — cppreference](https://en.cppreference.com/w/c/variadic) — documentation on `va_list`, `va_start`, `va_arg`, `va_end` and how variadic functions work in C.
- GeeksforGeeks.
- Youtube.

### AI Usage

An AI assistant (Claude) was used strictly as a documentation and review
aid, **not** to write or debug the C implementation itself:

- Drafting and structuring this `README.md` (Description, Instructions,
  Technical Choices, and Resources sections) from the existing source code
  and Makefile.
- Explaining, in the "Technical Choices" section above, the reasoning
  behind design decisions (single-pass parsing, recursion for base
  conversion, `va_list` usage) that were already implemented in the code,
  so they could be documented clearly and accurately.

All `ft_printf` logic — the format-string parser, the variadic argument
handling, and every conversion function — was designed, written, and
debugged manually, in line with the 42 evaluation requirement that the
code itself reflects the student's own understanding.