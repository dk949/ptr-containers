#!/bin/sh
set -e

catch2_src_dir="$(dirname "$0")/Catch2/"
catch2_install_dir="$(dirname "$0")/Catch2-install/"

if ! [ -d "${catch2_src_dir}" ]; then
    git clone "https://github.com/catchorg/Catch2" "${catch2_src_dir}"
fi

cmake -S "${catch2_src_dir}" -B "${catch2_src_dir}/build" \
        -DBUILD_TESTING=OFF \
        -DCATCH_BUILD_TESTING=OFF \
        -DCATCH_BUILD_EXTRA_TESTS=OFF \
        -DCATCH_INSTALL_DOCS=OFF \
        -DCATCH_DEVELOPMENT_BUILD=OFF \
        -DCATCH_BUILD_EXAMPLES=OFF \
        -DCATCH_BUILD_FUZZERS=OFF \
        -DCATCH_ENABLE_WERROR=OFF \
        -DCATCH_BUILD_SURROGATES=OFF \
        -DCATCH_INSTALL_EXTRAS=ON
cmake --build "${catch2_src_dir}/build"
cmake --install "${catch2_src_dir}/build" --prefix "${catch2_install_dir}"

rm -rf "${catch2_src_dir}"
