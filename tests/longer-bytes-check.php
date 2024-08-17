<?php

use AkmalFairuz\ByteBuf\LE;
use AkmalFairuz\ByteBuf\BE;

var_dump(LE::readInt(LE::writeInt(-33) . "LOLOLOLOL"));
var_dump(BE::readInt(BE::writeInt(-33) . "LOLOLOLOL"));