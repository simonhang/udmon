udmon is a small UDisks monitor programm for linux systems not using a full
featured graphical environment like KDE, Gnome or Xfce. Instead it seems to be useful for systems
running openbox or the like.

I wrote this small pice of code because I could not find any program that fits my needs and I like
to code even so I am not very good at it :)

udmon needs only a recent QT installation and a desktop environment which provides a system tray. Thats all.
On startup nothing else happens then a small icon is shown in your tray. Right click to configure. Set the program
to open when a USB stick or any removable device is attached. After attaching a device the program should start
with the mounted device path opened. I tested this with qtfm. After you dont need the device right click und
click the remove entry. That is all the application does.