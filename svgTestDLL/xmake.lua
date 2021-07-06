target("library")
set_kind("shared")
add_files("*.cpp")

target("test")
set_kind("binary")
add_files("*.cpp")
add_deps("library")