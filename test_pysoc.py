import pysoc


def test_pysoc_print():
    assert pysoc.print() == None


def test_pysoc_print_int():
    assert pysoc.print_int(123456) == None


def test_pysoc_return_1():
    retval = pysoc.return_1()
    assert retval == 1
    assert type(retval) == int


def test_pysoc_return_True():
    retval = pysoc.return_true()
    assert retval == True
    assert type(retval) == bool


def test_pysoc_raise_pysoc_error():
    try:
        pysoc.raise_pysoc_error()
    except pysoc.PysocError:
        return
    assert 0
