cryptographer_sources = [
  'main.cc',
  'mainwindow.h',
  'mainwindow.cc',
]

cryptographer_deps = [
   dependency('gtkmm-4.0'),
   dependency('cryptopp')
]

executable('cryptographer', cryptographer_sources,
  dependencies: cryptographer_deps,
  install: true,
)
