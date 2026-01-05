# Copyright 2026 Scott K Logan
# Licensed under the Apache License, Version 2.0

import subprocess
import sys

from underlay_setuptools.underlay_func import underlay_func


def test_func():
    assert underlay_func() == [
        'underlay_setuptools',
    ]


def test_executable():
    stdout = subprocess.check_output([
        'underlay_setuptools',
    ]).strip()
    assert b'underlay_setuptools' == stdout


def test_pep338():
    stdout = subprocess.check_output([
        sys.executable, '-m', 'underlay_setuptools.underlay_func',
    ]).strip()
    assert b'underlay_setuptools' == stdout
