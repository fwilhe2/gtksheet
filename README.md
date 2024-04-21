
Playground for [gtksheet](https://github.com/fpaquet/gtksheet).

How to build:

Dependencies on Fedora:

```
sudo dnf install make automake gcc gcc-c++ meson ninja-build gtk3-devel glade-devel gobject-introspection-devel gtk-doc
```

Dependencies on Debian:

```
apt-get -yqq --no-install-recommends install build-essential meson ninja-build libgtk-3-0 libgtk-3-dev libgladeui-dev gtk-doc-tools libgirepository1.0-dev
```

Perform Build:

```
meson setup build
ninja -C build
./build/gtksheet/testgtksheet
```

Edit [testgtksheet.c](gtksheet/testgtksheet.c)
