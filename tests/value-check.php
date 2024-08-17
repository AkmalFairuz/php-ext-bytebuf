<?php

$buffer = new AkmalFairuz\ByteBuf\ByteBuf("", 0);
$buffer->writeInt(-33);
$buffer->writeFloat(3.14);
$buffer->writeTriad(12345);
$buffer->writeLInt(-41298);
$buffer->setOffset(0);

if($buffer->read(4) === pack("N", -33)){
    echo "writeInt() test passed\n";
}else{
    echo "writeInt() test failed\n";
}

if($buffer->read(4) === pack("G", 3.14)){
    echo "writeFloat() test passed\n";
}else{
    echo "writeFloat() test failed\n";
}

if($buffer->read(3) === substr(pack("N", 12345), 1)){
    echo "writeTriad() test passed\n";
}else{
    echo "writeTriad() test failed\n";
}

if($buffer->read(4) === pack("V", -41298)){
    echo "writeLInt() test passed\n";
}else{
    echo "writeLInt() test failed\n";
}