# About KarateMp3
Here is my c++ audio solution with gif visualizer!
I decided to create this because i like cool visualisers and i was bored.
It currently plays only mp3 and ogg files.
You can download it for free for your linux (and windows soon!) system.
Due to apple's own compiler and lack of mac machines in my house it will not be avalible (never ever) on mac systems.

# Dependencies
To make my thing to work in 100% you need `mpv`, SDL2 + SDL2_mixer and `ogg123`

You can install these trough pacman:
```sudo pacman -S mpv sdl2 sdl2_mixer```

Or apt:
```sudo apt install mpv sdl2 sdl_mixer sdl2-dev sdl_mixer-dev```

Why? `mpv` is for playing and controlling a visualizer. Yes, it is bloated.

# Installation
Installation is very easy, just copy downloaded code into your desired directory.
Gif with visualization should be in `$HOME/.config/KarateMp3/visualisation/vis.gif`
Config file should be in `$HOME/.config/KarateMp3/config.conf`

(AUR coming soon. maybe.)

# Compilation
To compile it for yourself, you don't need any additional libraries than the runtime ones.
Just type `g++ -L/usr/lib -lSDL2 -lSDL2_mixer /path/to/main.cpp -o /path/to/compiled/binary`

It's that easy actually. maybe i missed something idk.
