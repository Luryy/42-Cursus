#!/bin/sh
find . -type f -name "*.sh" | sed 's/\.sh$//' | sed -r "s/^\.\/(.+\/)*//"