project(
        'the-chosen-remastered', 'cpp',
        default_options: ['cpp_std=c++17'],
        version: 'dev'
)

incdir = include_directories('include', 'configuration-files')

conf_data = configuration_data()
conf_data.set('version', meson.project_version())

subdir('configuration-files')

srcs = ['src/character.cpp',
        'src/cli.cpp',
        'src/customstring.cpp',
        'src/game.cpp',
        'src/gameentity.cpp',
        'src/item.cpp',
        'src/main.cpp',
        'src/parser.cpp',
        'src/player.cpp',
        'src/resources.cpp',
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

install_data('resources/the-chosen.png')
install_man('resources/man/the-chosen-remastered.6')
