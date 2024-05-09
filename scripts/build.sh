#! /bin/sh

cmake -DGLFW_BUILD_DOCS=off -S ../ -B ../build
cmake --build ../build