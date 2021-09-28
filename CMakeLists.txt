project (dband_mp C)

add_executable(dband_mp.o src/main.c src/file.c src/parse_xy.c src/calc_band.c)
set (CMAKE_C_FLAGS "-Wall -O3 -lxml2")
