# Copyright 2026 Scott K Logan
# Licensed under the Apache License, Version 2.0

import subprocess
import sys

from overlay_setuptools.overlay_func import overlay_func


def test_func():
    assert overlay_func() == [
        'underlay_cmake',
        'underlay_meson',
        'underlay_setuptools',
        'overlay_setuptools',
    ]


def test_executable():
    stdout = subprocess.check_output([
        'overlay_setuptools',
    ]).strip()
    assert b'\n'.join((
        b'underlay_cmake',
        b'underlay_meson',
        b'underlay_setuptools',
        b'overlay_setuptools',
    )) == stdout


def test_pep338():
    stdout = subprocess.check_output([
        sys.executable, '-m', 'overlay_setuptools.overlay_func',
    ]).strip()
    assert b'\n'.join((
        b'underlay_cmake',
        b'underlay_meson',
        b'underlay_setuptools',
        b'overlay_setuptools',
    )) == stdout
