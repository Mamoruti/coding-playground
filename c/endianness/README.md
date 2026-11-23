# Endianness in C

## What's the point of this exercise?

To understand how integers are represented in memory and how endianness affects the order of bytes written to a binary file.

The question gives us an unsigned integer (`0xDEADD00D`) and asks what the first four bytes of `output.bin` will contain.

## Concepts to remember

- **Endianness:** The order in which bytes of a multibyte value are stored in memory.
- **Little-endian:** Least significant byte first. Used by Intel x86-64.
- **Big-endian:** Most significant byte first.
- **Hexadecimal:** Two hex digits represent one byte.
- **`sizeof(unsigned int)`:** Returns the size in bytes (4 on my machine).
- **`&ui`:** Gives the memory address of the variable.
- **`fwrite()`:** Writes raw bytes from memory to a file.

## Running the code

Compile using the Makefile:

```bash
make
```

Execute:

```bash
./endianness
```

Inspect the binary file:

```bash
xxd -g 1 output.bin
```

Output:

```text
00000000: 0d d0 ad de    ....
```

The `00000000` is the **file offset**, measured relative to the beginning of `output.bin`. It isn't padding or part of the file's contents.

`xxd` displays the file's bytes in hexadecimal. The `-g 1` option separates them into groups of one byte.

## Checking memory with GDB

Commands used:

```gdb
gdb ./endianness
break main
run
next
next
print/x ui
x/4xb &ui
```

Results:

```text
$2 = 0xdeadd00d
0x7fffffffdd8c: 0x0d 0xd0 0xad 0xde
```

`print/x ui` shows the integer's value in hexadecimal.

`x/4xb &ui` examines four individual bytes in memory, starting at the address of `ui`.

**Something I learned:** GDB stops *before* executing the displayed line. I initially inspected `ui` before it was initialized and saw an unexpected value. Stepping over the initialization fixed that.

## Takeaway

The integer is written as `DE AD D0 0D`, but because Intel is little-endian, its bytes are stored as `0D D0 AD DE`.

`fwrite()` copies these raw bytes to the file, which explains why the file has the same byte order as the memory inspected with GDB.

This matters when working with binary files, memory debugging and network protocols.
