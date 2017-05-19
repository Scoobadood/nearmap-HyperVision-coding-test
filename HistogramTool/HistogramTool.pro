TEMPLATE = subdirs

SUBDIRS += src tests app
CONFIG += ordered

tests.depends = src
app.depends = tests
