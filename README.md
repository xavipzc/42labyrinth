# 42 Labyrinth

## Description

This is an interfaced ray tracer engine on MAC OSX environment (we may support linux platforms later);

This is a FPS like inspired by the Wolfenstein 3D's game using ray-casting technic;
The goal of this project was to represent a dynamic view of a labyrinth and move into it;
I turn it into a little game, you have to find the way out !

### Features

- Menu;
- TXT file map;
- Collision;
- Fast mode;
- Save last position;
- Sounds effect;

### Environment

* Mac OSX

## Dependencies

* MinilibX

### Installation

``` bash
$> wget http://files.achedeuzot.me/42/mlx/mlx-macosx-sierra-2016-10-17.tgz
$> tar -xzf mlx-macosx-sierra-2016-10-17.tgz
$> cd minilibx_macos
$> make
$> sudo cp mlx.h /usr/X11/include
$> sudo cp libmlx.a /usr/X11/lib
```

## Launch binary

``` bash
$> make fclean && make && ./wolf3d
```

## Media

![screen1](images/screen1.png)
![screen2](images/screen2.png)
![screen3](images/screen3.png)
![screen4](images/screen4.png)
![screen5](images/screen5.png)

## Authors

Xavier Pouzenc
xpouzenc@student.42.fr
