project(
        'the-chosen-remastered', 'cpp',
        default_options: ['cpp_std=c++17'],
        version: '1.0.0-alpha.2'
)

incdir = include_directories('include')

srcs = ['src/character.cpp',
        'src/customstring.cpp',
        'src/game.cpp',
        'src/gameentity.cpp',
        'src/item.cpp',
        'src/main.cpp',
        'src/parser.cpp',
        'src/player.cpp',
        'src/tui.cpp',
        'src/world.cpp']

ncurses = dependency('ncurses')

executable(
        meson.project_name(), 
        srcs, 
        include_directories: incdir,
        dependencies: ncurses,
        install: true
)
