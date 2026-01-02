# How does it work?

<video src="https://github.com/user-attachments/assets/c9090b09-48de-46d7-b876-a4389e759afe"></video>
An explainer recording. See it in full-screen mode.

## Smooth Scroller
<video src="https://github.com/user-attachments/assets/dd6a8a89-4170-4827-9254-261d21dddf94"></video>

# Compiling

## As a standalone application

```
mkdir build

cd build
make -S ../standalone/ .
make

./LRCScroll
```

@see [plugin/](plugin/) folder to compile as a plugin for LMMS.

# Features / Progress

* [x] Prominent color, font and sizing
* [x] Copy-paste shortcuts enabled
* [x] Press __F9 key__ to place timestamp in front of the line
* [ ] Reset timer with a button to re-tag
* [ ] Scroll the text in:
  * [ ] transparent window
  * [ ] frameless window scroll
  * [ ] readonly text
  * [ ] Hover on hide scroller
* [ ] Button changes the text to tag current line or start a tag

# Scroller Features

* [ ] Press __F10 key__ to start the scroller.
* [ ] Focused in/out event handled
* [ ] Synchronized with song editor or song.h
* [ ] Smooth scroll at 30 fps, slow and easy to eyes
* [ ] Complete lyrics scroll
* [ ] Current timestamp to be highlighted
* [ ] A lot of shortcuts enabled

# Resources

* https://en.wikipedia.org/wiki/LRC_(file_format)

# ToDo

* F9/F10 switch editor or scroller.
* Timetag to align with LMMS Host
* Speed to align wtih LMMS BMP + automations.
* Synchronize keys between LMMS Play/Pause and scrolling habit.