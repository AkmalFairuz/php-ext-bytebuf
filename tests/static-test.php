<?php

use AkmalFairuz\ByteBuf\LE;
use AkmalFairuz\ByteBuf\BE;
use AkmalFairuz\ByteBuf\VarInt;

if(LE::writeInt(-33) === pack("V", -33)){
    echo "writeInt() test passed\n";
}else{
    echo "writeInt() test failed\n";
}

if(BE::writeFloat(3.14) === pack("G", 3.14)){
    echo "writeFloat() test passed\n";
}else{
    echo "writeFloat() test failed\n";
}

$offsetz = 0;
if(VarInt::readInt(VarInt::writeInt(12345), $offsetz) === 12345 && $offsetz === 3){
    echo "VarInt test passed\n";
}else{
    echo "VarInt test failed\n";
}