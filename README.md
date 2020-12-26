# numbers_and_letters_for_toddlers
Todlers can learn to recognize numbers and letters

This educational program requires to build at least:
-Qt 5.15.0
-PortAudio V19.6.0
-MSYS

It can therefore be ported to many platforms, among which Linux and Windows.
Build scripts will soon be available.
There will soon be a build available for downlod for the Windows 10 platform. 

In order to build edit the prepare.sh file to set the paths to Qt and portaudio

Type in an MSYS session:
$ source prepare.sh
$ qmake
$ make

your binary will be available in the release folder.