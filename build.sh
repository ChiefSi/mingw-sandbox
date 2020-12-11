#!/bin/bash -ex

mkdir -p _build _inst
cd _build && \
	cmake \
		-DCMAKE_TOOLCHAIN_FILE=../x86_64-w64-mingw32.cmake \
		-DCMAKE_INSTALL_PREFIX=../_inst \
		..
