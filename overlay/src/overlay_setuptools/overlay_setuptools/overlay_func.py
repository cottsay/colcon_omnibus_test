# Copyright 2026 Scott K Logan
# Licensed under the Apache License, Version 2.0

import ctypes
from ctypes.util import find_library
import itertools
import sys

from underlay_setuptools.underlay_func import underlay_func


def _from_native(lib_name):
    lib_file = find_library(lib_name)
    lib = ctypes.cdll.LoadLibrary(lib_file)
    func = getattr(lib, lib_name + '_func')
    func.restype = ctypes.POINTER(ctypes.c_char_p)
    func_free = getattr(lib, lib_name + '_free')
    arr = func()
    try:
        res = [s.decode() for s in itertools.takewhile(lambda s: s, arr)]
    finally:
        func_free(arr)
    return res


def overlay_func():
    return [
        *_from_native('underlay_cmake'),
        *_from_native('underlay_meson'),
        *underlay_func(),
        'overlay_setuptools',
    ]


def main():
    print('\n'.join(overlay_func()))


if __name__ == '__main__':
    sys.exit(main())
