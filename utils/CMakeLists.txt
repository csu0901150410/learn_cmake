add_library(UtilsLib)

target_sources(UtilsLib
    PRIVATE
        ls_math.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            ls_math.h
)
