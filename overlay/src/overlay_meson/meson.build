project(
  'overlay_meson', 'c',
  version: '1.0.0',
  license: 'Apache-2.0',
  default_options: [
    'warning_level=3',
  ],
)

underlay_cmake = dependency('underlay_cmake',
  modules: [
    'underlay_cmake::underlay_cmake_lib',
  ],
  version: '>=1.0.0')
underlay_meson = dependency('underlay_meson', version: '>=0.0.1')

headers = include_directories('include')

lib = library(meson.project_name(),
  [
    'src/' + meson.project_name() + '_lib.c',
  ],
  include_directories: headers,
  dependencies: [
    underlay_cmake,
    underlay_meson,
  ],
  install: true,
)

exe = executable(meson.project_name(),
  [
    'src/' + meson.project_name() + '_exe.c',
  ],
  link_with: [
    lib,
  ],
  include_directories: headers,
  install: true,
)

install_headers(
  'include/' + meson.project_name() + '/' + meson.project_name() + '.h',
  subdir: meson.project_name(),
)

pkg = import('pkgconfig')
pkg.generate(
  name: meson.project_name(),
  description: 'Meson project in overlay',
  libraries: [lib],
)

test_func = executable('test_func',
  [
    'test/test_func.c',
  ],
  link_with: [
    lib,
  ],
  include_directories: headers,
)
test('test_func', test_func)
