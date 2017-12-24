from distutils.core import setup
from distutils.extension import Extension
examplemodule = Extension(name="func", sources=['func.c', ])
setup(name="func", ext_modules=[examplemodule])