# Readme
ACM (Asterisk Channel Monitor) is a realtime channels activity monitoring tool for Asterisk PBX. Build with Qt GUI toolkit.

## Prerequisites
To build AstChanMon you'll need Qt GUI toolkit version 4.6 or later.
### Qt libraries (>= 4.6)
* Qt Core
* Qt Gui
* Qt Network

## Binaries
### Current version:
* Windows 32 bit (VC2010 OpenGL, Qt 5.1.1) [TBA]
* Linux 64 bit (GCC 4.4.7 20120313 (Red Hat 4.4.7-4), Qt 5.2.1) [TBA]

### Old version:
* [astchanmon.exe](https://github.com/rudilee/AstChanMon/blob/master/build/astchanmon.exe) - Windows 32 bit.
* [astchanmon](https://github.com/rudilee/AstChanMon/blob/master/build/astchanmon) - Linux 64 bit, shared linked.

## Usage
  Before able to live monitor your Asterisk PBX server, you need to add an AMI account to manager.conf file with at least read permission. Input your Asterisk PBX server address and AMI account credentials using Session Manager, Save then double click Session Name from the Session list.

## Screenshot
![alt tag](https://raw.githubusercontent.com/rudilee/AstChanMon/master/screen.png)
