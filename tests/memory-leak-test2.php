<?php
ini_set('memory_limit', '16M');
use AkmalFairuz\ByteBuf\ByteBuf;

while(true){
    $byteBuf = ByteBuf::fromString(str_repeat("Hallo", 40000));
    for($i = 0; $i < 40000; $i++){
        $byteBuf->read(5);
    }
    usleep(1000 * 10);
    gc_enable();
    gc_collect_cycles();
    unset($byteBuf);
}