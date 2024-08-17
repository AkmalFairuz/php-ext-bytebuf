# ByteBuf extension for PHP

This extension provides a high performance byte buffer implementation for PHP. Replacement for `pack()`, `unpack()`, and [pmmp/BinaryUtils](https://github.com/pmmp/BinaryUtils)

⚠️ **This extension is still under development. There is a possibility that this extension will crash or behave incorrectly.**

## Performance

- ByteBuf uses exponential growth for buffer size to prevent frequent memory allocation.
- `LE` & `BE` performance is ~2x faster than `pack()` and `unpack()`

### Comparison with [pmmp/BinaryUtils](https://github.com/pmmp/BinaryUtils)
- `ByteBuf->read` and `ByteBuf->write` performance is ~2x faster
- VarInt reading and writing performance is ~9x faster
- Triad reading and writing performance is ~3x faster

### Comparison with [pmmp/ext-encoding](https://github.com/pmmp/ext-encoding)
- `ByteBuf->read` performance is ~1.5x faster

## Documentation
Self-explanatory, see [bytebuf.stub.php](bytebuf.stub.php) and [tests](tests)

## TODO
- Reusable ByteBuf to reduce memory allocation
- More tests

## How to build?
1. Make sure you have PHP development environment installed and downloaded the PHP Source Code. See: [Windows](https://wiki.php.net/internals/windows/stepbystepbuild_sdk_2), [Linux](https://github.com/php/php-src?tab=readme-ov-file#building-php-source-code)
2. Clone this repository to `/path/to/php-src/ext/bytebuf`
3. To build on Windows, you need to run terminal via `phpsdk-vs17-x64.bat`. Run the following commands:
```bash
cd /path/to/php-src

buildconf
./configure --enable-bytebuf (...other options)
make # For Linux
nmake # For Windows
```