project(
  'misc-solver',
  'cpp',
  version : '0.0.1',
  default_options : [
    'cpp_std=c++20',
  ]
)

thread_dep = dependency('threads')

##################
# Command line interface
##################

entry = executable(
  'entry',
  'cmd/entry.cpp',
  dependencies : [thread_dep]
)

##################
# Benchmark
##################

benchmark_plane = executable(
  'benchmark_plane',
  'cmd/benchmark_plane.cpp',
  dependencies : [thread_dep]
)

benchmark_plane_old = executable(
  'benchmark_plane_old',
  'cmd/benchmark_plane_old.cpp',
  dependencies : [thread_dep]
)
