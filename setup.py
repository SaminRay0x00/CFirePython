from distutils.core import setup , Extension

module = Extension('calcmath', sources = ['calcmath.c'])
setup(name = 'PackageName',
	version = '1.0',
	description = 'this is a package for my module',
	ext_modules = [module],
	author = "Ramin Farajpour Cami"
)

