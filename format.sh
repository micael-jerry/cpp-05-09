#!/bin/bash

find . \( -name "*.cpp" -o -name "*.hpp" \) -exec clang-format -i {} +

