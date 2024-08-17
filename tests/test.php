<?php

use AkmalFairuz\ByteBuf\ByteBuf;

$buffer1 = ByteBuf::alloc(128);
$buffer1->writeInt(-33);
$buffer1->writeFloat(3.14);
$buffer1->writeDouble(3.14159265359);
$buffer1->writeLInt(-33);
$buffer1->writeLFloat(3.14);
$buffer1->writeLDouble(3.14159265359);
$buffer1->writeVarInt(12345);
$buffer1->writeVarInt(1234567890);
$buffer1->writeShort(12345);
$buffer1->writeTriad(69420);
$buffer1->writeLTriad(69420);
$buffer1->writeLUnsignedTriad(-1);
$buffer1->writeUnsignedTriad(69420);

$buffer2 = ByteBuf::fromString($buffer1->toString());
var_dump($buffer2->readInt());
var_dump($buffer2->readFloat());
var_dump($buffer2->readDouble());
var_dump($buffer2->readLInt());
var_dump($buffer2->readLFloat());
var_dump($buffer2->readLDouble());
var_dump($buffer2->readVarInt());
var_dump($buffer2->readVarInt());
var_dump($buffer2->readShort());
var_dump($buffer2->readTriad());
var_dump($buffer2->readLTriad());
var_dump($buffer2->readLUnsignedTriad());
var_dump($buffer2->readUnsignedTriad());
