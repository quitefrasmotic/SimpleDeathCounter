# SimpleDeathCounter

<p align="center">
  <img src="/img/linux-showcase.png" alt="Linux Showcase">
</p>

## A dead simple, streamer-controlled OBS death counter for Windows and Linux

This app simply provides a **global keyboard shortcut** which is used to increase a number inside a text file which OBS shows with the Text source's "Read from file" option.

**Therefore, setup is very easy:** 
- Run the app
- Create a Text source in OBS
- Check "Read from file"
- Select "deaths.txt" ~~in `%AppData%\simple-death-counter\` on Windows, or `~/.config/simple-death-counter/` on Linux.~~

**NOTE:** This location isn't implemented yet, right now it's in the bin/ folder where the app is installed. Because of this, make sure to install the app where it has permission to write - e.g. your Documents folder.<br/><br/>

<table>
  <tr>
    <td>
      <img src="/img/obs-showcase.png" alt="OBS Showcase">
    </td>
    <td>
      <img src="/img/windows-showcase.png" alt="Windows Showcase" width="700px">
    </td>
  </tr>
</table>

## More details
Written in C++ using the Qt 5 Framework, this app provides an exceedingly lightweight and native experience on both Windows and Linux. It uses the amazing [QHotkey by Skycoder42](https://github.com/Skycoder42/QHotkey).

**Linux note:** Unfortunately this app doesn't support global hotkeys on Wayland due to the protocol's immaturity in this area. However, work on this seems to be progressing.

This is also, perhaps obviously if you look at the code, a project I used to learn C++ and Qt. Because of this, there may be bugs and inefficiencies - sorry!

## Building
I've only tested building on Linux - my CMake config may not work for other platforms.
### CMake
```
$ cd SimpleDeathCounter
$ cmake -B build -S .
$ cmake --build build
```
Then to package (NSIS using MINGW, tar.xz using Linux):
```
$ cd build
$ cpack -C CPackConfig.cmake
```

## Licensing
Project|License
-------|--------
SimpleDeathCounter|GPL-3.0
[Qt 5](https://doc.qt.io/qt-5/)|LGPL-3.0
[QHotkey](https://github.com/Skycoder42/QHotkey)|BSD-3-Clause
