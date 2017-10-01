project('firmatac', ['c'])
conf_data = configuration_data()
conf_data.set('version', '0.1')

cc  = meson.get_compiler('c')

install_headers('includes/firmata.h')

src = files('src/firmata.c', 'src/serial.c', 'src/servo.c')

includes = include_directories('includes')

firmatac = static_library('firmatac', [src],
    install : false,
    include_directories : includes,
    dependencies: [])

if meson.is_subproject()
  # dep to make it easy to use as a Meson subproject
  firmatac_dep = declare_dependency(
    include_directories : includes,
    link_with : firmatac)
else
  message('Meson only supports building Firmata as a library!')
endif
