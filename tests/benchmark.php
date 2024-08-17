<?php

use AkmalFairuz\ByteBuf\ByteBuf;
use AkmalFairuz\ByteBuf\LE;

class SimpleBuf {
    private $buffer = "";
    private $offset = 0;

    public function __construct(string $initialBuffer = ""){
        $this->buffer = $initialBuffer;
    }

    public function write(string $buf): void {
        $this->buffer .= $buf;
        $this->offset += strlen($buf);
    }

    public function setOffset(int $offset): void {
        $this->offset = $offset;
    }

    public function read(int $length): string {
        $data = substr($this->buffer, $this->offset, $length);
        $this->offset += $length;
        return $data;
    }
}

// benchmark string concatenation vs bytebuf
$start = microtime(true);
$buffer = new SimpleBuf();
for($i = 0; $i < 40000; $i++){
    $buffer->write("Hallo");
}
echo "String concatenation: " . (microtime(true) - $start) . " seconds\n";
unset($buffer);

$start = microtime(true);
$byteBuf = ByteBuf::alloc(40000 * 5);
for($i = 0; $i < 40000; $i++){
    $byteBuf->write("Hallo");
}
echo "ByteBuf: " . (microtime(true) - $start) . " seconds\n";
unset($byteBuf);

// benchmark reading string vs bytebuf
$start = microtime(true);
$buffer = new SimpleBuf(str_repeat("Hallo", 40000));
for($i = 0; $i < 40000; $i++){
    $buffer->read(5);
}
echo "String reading: " . (microtime(true) - $start) . " seconds\n";
unset($buffer);

$start = microtime(true);
$byteBuf = ByteBuf::fromString(str_repeat("Hallo", 40000));
for($i = 0; $i < 40000; $i++){
    $byteBuf->read(5);
}
echo "ByteBuf reading: " . (microtime(true) - $start) . " seconds\n";

// benchmark pack() vs LE::writeTriad()

$start = microtime(true);
for($i = 0; $i < 80_000; $i++){
    substr(pack("N", 69420), 1);
}
echo "TRIAD pack(): " . (microtime(true) - $start) . " seconds\n";

$start = microtime(true);
for($i = 0; $i < 80_000; $i++){
    LE::writeTriad(69420);
}
echo "LE::writeTriad(): " . (microtime(true) - $start) . " seconds\n";

// benchmark pack() vs LE::writeInt()
$start = microtime(true);
for($i = 0; $i < 80_000; $i++){
    pack("N", -2487);
}
echo "INT pack(): " . (microtime(true) - $start) . " seconds\n";

$start = microtime(true);
for($i = 0; $i < 80_000; $i++){
    LE::writeInt(-2487);
}
echo "LE::writeInt(): " . (microtime(true) - $start) . " seconds\n";