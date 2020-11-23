#!/usr/bin/env python3
from distutils.core import setup, Extension

module1 = Extension("pysoc", sources=["pysoc.c"])

setup(name="pysoc", version="1.0", description="This is a demo package", ext_modules=[module1])
