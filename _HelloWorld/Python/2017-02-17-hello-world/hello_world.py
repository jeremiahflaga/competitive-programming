#
# Skeleton file for the Python "Hello World" exercise.
#
# Feb 17, 2017

"""
Hello World
===============================
Greet the user by name, or by saying "Hello, World!" if no name is given.

"Hello, World!" is the traditional first program for beginning programming in a new language.

Note: You can skip this exercise by running:

exercism skip $TRACK_ID hello-world

Specification
==================================
Write a Hello World! function that can greet someone given their name. The function should return the appropriate greeting.

For an input of "Alice", the response should be "Hello, Alice!".

If a name is not given, the response should be "Hello, World!"
"""

def hello(name=''):
    if name == '' or name is None:
        return 'Hello, World!'
    else:
        return 'Hello, {}!'.format(name)
