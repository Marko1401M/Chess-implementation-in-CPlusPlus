cmake_minimum_required(VERSION 3.0)


project(PROJEKAT)

set(CMAKE_CXX_STANDARD 14)


set(PROJEKAT_SOURCE_FILES
                Chess/Figure/figura.h
                Chess/Figure/figura.cpp
                Chess/Figure/pijun.h
                Chess/Figure/pijun.cpp
                Chess/Figure/top.h
                Chess/Figure/top.cpp
                Chess/Figure/lovac.h
                Chess/Figure/lovac.cpp
                Chess/Figure/kraljica.h
                Chess/Figure/kraljica.cpp
                Chess/Figure/kralj.h
                Chess/Figure/kralj.cpp	
                Chess/Figure/skakac.h
                Chess/Figure/skakac.cpp
                Chess/Igra/tabla.h
                Chess/Igra/tabla.cpp
                Chess/Igra/potez.h
                Chess/Igra/potez.cpp
                Chess/Igra/polje.h
                Chess/Igra/polje.cpp
                Chess/Izuzeci/nevalidan_potez_exception.h
                Chess/Izuzeci/potez_izvan_table_exception.h
                Chess/Izuzeci/igrac_nije_na_potezu_exception.h
                Chess/Izuzeci/prazno_polje_exception.h
                Chess/Igra/main.cpp)



add_executable(PROJEKAT ${PROJEKAT_SOURCE_FILES})
