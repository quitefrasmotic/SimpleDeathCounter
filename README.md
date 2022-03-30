# SimpleDeathCounter
## A dead-simple, streamer-controlled OBS death counter for Windows and Linux

This app simply provides a **global keyboard shortcut** which is used to increase a number inside a text file which OBS shows with the Text source's "Read from file" option.

## More details
Written in C++ using the Qt 5 Framework, this app provides an exceedingly lightweight and native experience on both Windows and Linux. It uses the amazing [QHotkey by Skycoder42](https://github.com/Skycoder42/QHotkey).

**Linux note:** Unfortunately this app doesn't support global hotkeys on Wayland due to the protocol's immaturity in this area. However, work on this seems to be progressing.

<sub>This is also, perhaps obviously if you look at the code, a project I used to learn C++ and Qt. Because of this, there may be bugs and inefficiencies - sorry!</sub>

## Building
### CMake
```
$ cd SimpleDeathCounter
$ cmake -B build -S .
$ cmake --build build
```

## Licensing
Project|License
-------|--------
SimpleDeathCounter|GPL-3.0
[Qt 5](https://doc.qt.io/qt-5/)|LGPL-3.0
[QHotkey](https://github.com/Skycoder42/QHotkey)|BSD-3-Clause
