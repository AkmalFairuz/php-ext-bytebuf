<?php
use AkmalFairuz\ByteBuf\ByteBuf;
use AkmalFairuz\ByteBuf\LE;
use AkmalFairuz\ByteBuf\BE;
use AkmalFairuz\ByteBuf\VarInt;
ini_set('memory_limit', '8M');
$z = 0;
while(true){
    $z++;
    for($i = 0; $i < 100_000; $i++){
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

        $buffer1->setOffset(0);
        $buffer1->readInt();
        $buffer1->readFloat();
        $buffer1->readDouble();
        $buffer1->readLInt();
        $buffer1->readLFloat();
        $buffer1->readLDouble();
        $buffer1->readVarInt();
        $buffer1->readVarInt();
        $buffer1->readShort();
        $buffer1->readTriad();
        $buffer1->readLTriad();

        

        LE::writeInt(-33);
        LE::writeFloat(3.14);
        LE::writeDouble(3.14159265359);
        LE::writeTriad(12345);
        LE::writeTriad(12345);
        LE::writeTriad(12345);
        LE::writeTriad(12345);
        LE::writeTriad(12345);
        LE::writeTriad(12345);
        BE::writeTriad(12345);
        BE::writeTriad(12345);
        BE::writeTriad(12345);
        BE::writeTriad(12345);

        $offsetz = 0;
        VarInt::readInt(VarInt::writeInt(12345), $offsetz);
        unset($buffer1);
    }
    usleep(1000);
    gc_enable();
    gc_collect_cycles();
    echo "[#$z] Current memory usage: " . (memory_get_usage(true) / 1024) . " kilobytes\n";
}