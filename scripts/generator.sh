#!/bin/sh

command -v ninja >/dev/null && echo 'Ninja' || echo 'Unix Makefiles'
