import pytest
import sys

sys.path.append('src') # hacky

import main

def test_inc():
    assert 2 == main.inc(1)

def test_inc_fail():
    assert 2 == main.inc(2)
