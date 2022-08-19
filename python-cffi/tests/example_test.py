import pytest
from main import my_add, my_sub, my_mul

def test_add():
    """Description

    @param param:  Description
    @type  param:  Type

    @return:  Description
    """
    a = 1
    b = 1
    res = my_add(a, b)
    assert res == (a + b), "Add doesnt work"

    return

def test_sub():
    """Description

    @param param:  Description
    @type  param:  Type

    @return:  Description
    """
    a = 4
    b = 1
    res = my_sub(a, b)
    assert res == (a - b), "Sub doesnt work"

    return

def test_mul():
    """Description

    @param param:  Description
    @type  param:  Type

    @return:  Description
    """
    a = 2
    b = 2
    res = my_mul(a, b)
    assert res == (a * b), "Mul doesnt work"

    return
