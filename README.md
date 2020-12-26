# numbers_and_letters_for_toddlers
Todlers can learn to recognize numbers and letters

This educational program requires to build at least:
-Qt 5.15.0
-PortAudio V19.6.0
-Bash or MSYS

It can therefore be ported to many platforms, among which Linux and Windows.

In order to build edit the prepare.sh file to set the paths to Qt and portaudio

Type in an MSYS/Bash session:
$ source prepare.sh
$ qmake
$ make

your binary will be available in the release folder.

There will soon be a build for the Windows 10 platform available as a download. 
