# Modify the location of executable outputs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

# Target: main
add_executable(main
    main.c
)
target_compile_features(main PUBLIC c_std_17)
