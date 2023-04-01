# The Chosen: At Night's End (Remastered)

This is a short Zork-like text-adventure I (re-)wrote. The original python version can be found [here](https://github.com/tifrueh/the-chosen).

Your objective is to find a pair of legendary swords and kill an evil king with them.

## How to install

### macOS (with Homebrew)

1. Tap my homebrew tap: `brew tap https://github.com/tifrueh/homebrew-mytap`

2. Install with `brew install the-chosen-remastered`

### Windows, macOS, Linux

You can download the ZIP archive or tarball from the latest release and build/install directly with [`meson`](https://mesonbuild.com/index.html).

1. Download and install a compiler toolchain and meson. To do that you can follow [this guide](https://mesonbuild.com/SimpleStart.html).

2. Extract the ZIP archive or tarball and navigate to the extracted folder in your terminal.

3. Compile with

    ~~~ text
    $ meson setup build
    $ cd build
    $ meson compile
    ~~~

4. Install with `meson install`

## How to play

As soon as you start the game, the copyright notice and the game version will appear. To continue, press the `ENTER` key.
You are now presented with an intro to the game. Type in your name and press `ENTER` again. Now the game really starts and you can see the description of the starting location.

~~~ text
Cellar
------
You are in a damp cellar. It's cold, the walls are all made of grey rock, and it's generally rather unpleasant
here. The only light is coming from a torch mounted to the north wall. You can also see the decaying body of
a long dead ... thing? (it is definitely not human) chained to the east wall. That must be where the
unbearable stench is coming from.
Beside the rotting corpse you notice a sword, placed just where the reach of the chained thing must have ended
when it was still alive. Quite cruel, if you think about it.
There is a ladder leading up.
~~~

Whenever you see the prompt (`>`), the game is waiting for you to type in your
instructions. When you have finished typing in your instructions, press the
`RETURN` key. The game will respond and the the prompt (`>`) will reappear.

Next to the prompt (`>`), try to type the following:

~~~ text
take the sword
~~~

and press the `ENTER` key. The game responds with this:

~~~ text
Taken.
~~~

You may respond to the game by typing:

~~~ text
examine the sword
~~~

and press the `ENTER` key. The game cooperates and tells you:

~~~ text
You notice that the sword is glowing faintly, indicating that a spell has been cast on it.
~~~
