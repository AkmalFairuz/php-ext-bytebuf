<?php

use AkmalFairuz\ByteBuf\ByteBuf;
use Akmalfairuz\ByteBuf\VarInt;
use AkmalFairuz\ByteBuf\LE;
use AkmalFairuz\ByteBuf\BE;

var_dump(get_class_methods(ByteBuf::class));
var_dump(get_class_methods(VarInt::class));
var_dump(get_class_methods(LE::class));
var_dump(get_class_methods(BE::class));