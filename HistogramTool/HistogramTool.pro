TEMPLATE = subdirs

SUBDIRS += src tests app
CONFIG += ordered
CONFIG += c++11

tests.depends = src
app.depends = tests
