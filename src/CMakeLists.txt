add_library(mylib)
target_sources(mylib PUBLIC FILE_SET CXX_MODULES FILES mylib.cpp)
target_compile_features(mylib PUBLIC cxx_std_20)
