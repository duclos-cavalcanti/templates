import pytest

from main import Solution

def test_a():
    S = Solution()
    input = [1, 2, 3, 1]
    assert True == S.containsDuplicates(input)

def test_b():
    S = Solution()
    input = [1, 2, 3, 4]
    assert False == S.containsDuplicates(input)

