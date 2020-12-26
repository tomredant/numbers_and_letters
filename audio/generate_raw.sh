#!/bin/bash
for name in mp3/*.mp3; do  
  ffmpeg  -i 1.5seconds_idle.wav -i "$name" -filter_complex amix=inputs=2:duration=longest -ar 44100 -f s16le -acodec pcm_s16le -ss 00:00:00 -t 00:00:01.5 "${name%.*}.raw"
done 