<?php

ini_set('memory_limit', '16M');
use AkmalFairuz\ByteBuf\ByteBuf;

while(true){
    $byteBuf = ByteBuf::fromString(str_repeat("Hallo", 31000));
    $x = 0;
    while(true){
        try{
            $x++;
            echo "Attempt $x\n";
            for($i = 0; $i < 100; $i++){
            $byteBuf->readVarInt();
            }
        }catch(\Exception $e){
            die($e->getMessage());
            echo "PASSED\n";
            break;
        }
    }
    usleep(1000 * 50);
    gc_enable();
    gc_collect_cycles();
    unset($byteBuf);
    echo "Current memory usage: " . (memory_get_usage(true) / 1024) . " kilobytes\n";
}