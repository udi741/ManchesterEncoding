# Manchester Encoding and Decoding

This code provides functions to encode and decode bytes arrays using Manchester encoding (THOMAS or IEEE standard).
<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/90/Manchester_encoding_both_conventions.svg/1920px-Manchester_encoding_both_conventions.svg.png" width="50%" height="50%" />
</p>

## Files

- `ManchesterEncoding.h`: Header file with function prototypes and definitions.
- `ManchesterEncoding.c`: Source file with encoding and decoding implementations.
- `main.c`: Usage exmaples.

## Functions

- `encodeManchester()`: Encodes bytes array using Manchester.
- `decodeManchester()`: Decodes Manchester encoded bytes array.

## Run Examples

1. Compile:
   gcc -o main main.c ManchesterEncoding.c
2. Run:
   ./main

This demonstrates encoding and decoding.