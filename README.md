Product XML Refactoring Kata
============================

For practising approval testing and refactoring duplication.

Instructions
------------

It seems to me that adding tests to functional code is much easier than adding
tests to stateful code. In this repo there are several functions and a fair
amount of duplication. Your first task is to add test cases that will be good
enough to support refactoring. I suggest using a coverage tool that also
shows branch coverage. You might also try some mutation testing to assess how
good your tests are.

Then when you're happy with your test coverage, your next task is to
remove the duplication. (Note there is a branch 'with_tests' if you
want to jump straight to this part of the exercise)

You might find it helpful to use the refactoring steps:

1. Identify
2. Prepare
3. Extract
4. Clean

I also suggest you use automated tool support as much as possible.

Credits
-------

This exercise was inspired by the "Replace Implicit Tree with Composite"
refactoring described in the book "Refactoring to Patterns" by Joshua Kerievsky.
