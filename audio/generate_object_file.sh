#!/bin/bash
cd mp3
ld -r -b binary -o ../audio.raw.o  *.raw
cd ../