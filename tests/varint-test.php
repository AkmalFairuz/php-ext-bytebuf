<?php

use AkmalFairuz\ByteBuf\VarInt;

// consistency test
$v = VarInt::writeInt(12345);
$offset = 0;
if(VarInt::readInt($v, $offset) === 12345){
    echo "consistency writeInt() test passed\n";
}else{
    echo "consistency writeInt() test failed\n";
}