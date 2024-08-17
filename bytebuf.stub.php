<?php

namespace AkmalFairuz\ByteBuf {

class ByteBuf {
    public static function fromString(string $buffer): ByteBuf {}
    /** 
     * @param int $initialCapacity examples: 16, 64, 128, 512
     */
    public static function alloc(int $initialCapacity): ByteBuf {}

    public function __construct(string $buffer, int $offset){}

    public function write(string $buf): void {}
    public function read(int $length): string {}
    public function toString(): string {}
    public function remaining(): string {}
    public function setOffset(int $offset): void {}
    public function getOffset(): int {}
    public function getUsedBufferLength(): int {}

    public function writeByte(int $value): void {}
    public function readByte(): int {}

    public function writeUnsignedByte(int $value): void {}
    public function readUnsignedByte(): int {}

    public function writeShort(int $value): void {}
    public function readShort(): int {}

    public function writeUnsignedShort(int $value): void {}
    public function readUnsignedShort(): int {}

    public function writeLShort(int $value): void {}
    public function readLShort(): int {}

    public function writeLUnsignedShort(int $value): void {}
    public function readLUnsignedShort(): int {}

    public function writeTriad(int $value): void {}
    public function readTriad(): int {}

    public function writeUnsignedTriad(int $value): void {}
    public function readUnsignedTriad(): int {}

    public function writeLTriad(int $value): void {}
    public function readLTriad(): int {}

    public function writeLUnsignedTriad(int $value): void {}
    public function readLUnsignedTriad(): int {}

    public function writeInt(int $value): void {}
    public function readInt(): int {}

    public function writeUnsignedInt(int $value): void {}
    public function readUnsignedInt(): int {}

    public function writeLInt(int $value): void {}
    public function readLInt(): int {}

    public function writeLUnsignedInt(int $value): void {}
    public function readLUnsignedInt(): int {}

    public function writeLong(int $value): void {}
    public function readLong(): int {}

    public function writeUnsignedLong(int $value): void {}
    public function readUnsignedLong(): int {}

    public function writeLLong(int $value): void {}
    public function readLLong(): int {}

    public function writeLUnsignedLong(int $value): void {}
    public function readLUnsignedLong(): int {}

    public function writeFloat(float $value): void {}
    public function readFloat(): float {}

    public function writeLFloat(float $value): void {}
    public function readLFloat(): float {}

    public function writeDouble(float $value): void {}
    public function readDouble(): float {}

    public function writeLDouble(float $value): void {}
    public function readLDouble(): float {}

    public function writeVarInt(int $value): void {}
    public function readVarInt(): int {}

    public function writeUnsignedVarInt(int $value): void {}
    public function readUnsignedVarInt(): int {}

    public function writeVarLong(int $value): void {}
    public function readVarLong(): int {}

    public function writeUnsignedVarLong(int $value): void {}
    public function readUnsignedVarLong(): int {}
}

class ByteBufException extends \RuntimeException {}

class LE {

    private function __construct(){}

    public static function writeShort(int $value): string {}
    public static function readShort(string $buffer): int {}

    public static function writeUnsignedShort(int $value): string {}
    public static function readUnsignedShort(string $buffer): int {}

    public static function writeTriad(int $value): string {}
    public static function readTriad(string $buffer): int {}

    public static function writeUnsignedTriad(int $value): string {}
    public static function readUnsignedTriad(string $buffer): int {}

    public static function writeInt(int $value): string {}
    public static function readInt(string $buffer): int {}

    public static function writeUnsignedInt(int $value): string {}
    public static function readUnsignedInt(string $buffer): int {}

    public static function writeLong(int $value): string {}
    public static function readLong(string $buffer): int {}

    public static function writeUnsignedLong(int $value): string {}
    public static function readUnsignedLong(string $buffer): int {}

    public static function writeFloat(float $value): string {}
    public static function readFloat(string $buffer): float {}

    public static function writeDouble(float $value): string {}
    public static function readDouble(string $buffer): float {}
}

class BE {

    private function __construct(){}

    public static function writeShort(int $value): string {}
    public static function readShort(string $buffer): int {}

    public static function writeUnsignedShort(int $value): string {}
    public static function readUnsignedShort(string $buffer): int {}

    public static function writeTriad(int $value): string {}
    public static function readTriad(string $buffer): int {}

    public static function writeUnsignedTriad(int $value): string {}
    public static function readUnsignedTriad(string $buffer): int {}

    public static function writeInt(int $value): string {}
    public static function readInt(string $buffer): int {}

    public static function writeUnsignedInt(int $value): string {}
    public static function readUnsignedInt(string $buffer): int {}

    public static function writeLong(int $value): string {}
    public static function readLong(string $buffer): int {}

    public static function writeUnsignedLong(int $value): string {}
    public static function readUnsignedLong(string $buffer): int {}

    public static function writeFloat(float $value): string {}
    public static function readFloat(string $buffer): float {}

    public static function writeDouble(float $value): string {}
    public static function readDouble(string $buffer): float {}
}

class VarInt {

    private function __construct(){}

    public static function writeInt(int $value): string {}
    public static function readInt(string $buffer, int &$offset): int {}

    public static function writeUnsignedInt(int $value): string {}
    public static function readUnsignedInt(string $buffer, int &$offset): int {}

    public static function writeLong(int $value): string {}
    public static function readLong(string $buffer, int &$offset): int {}

    public static function writeUnsignedLong(int $value): string {}
    public static function readUnsignedLong(string $buffer, int &$offset): int {}
}

}

// TODO: since class_aliases with internal class won't work in PHP < 8.3 we need to add this manually
// remove this when pocketmine require PHP >= 8.3
namespace pocketmine\utils {
    class BinaryDataException extends \RuntimeException {}
}