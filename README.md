
Playground for [gtksheet](https://github.com/fpaquet/gtksheet).

How to build:

```
apt-get -yqq --no-install-recommends install build-essential meson ninja-build libgtk-3-0 libgtk-3-dev libgladeui-dev gtk-doc-tools libgirepository1.0-dev
meson setup build
ninja -C build
./build/gtksheet/testgtksheet
```

Edit [testgtksheet.c](gtksheet/testgtksheet.c)