Zak Sakata
CSE310
Project 1
Language: C++

test_1.txt, test_2.txt, ..., test_10.txt are the 10 (posted) test cases, each worth 3 points, for a total of 30 points. These tests, as well as the unposted test cases, are all or nothing: there is no partial credit.

Each test_i.txt, i = 1, 2, ..., 10, contains a set of keyboard commands, which may be one or more of the following:
S
C n
R
W
I f k
D f
K f i v
See the project description for what each of these keyboard commands means.

o_test_1.txt, o_test_2.txt, ..., o_test_10.txt are the expected output for each of the 10 test cases test_1.txt, test_2.txt, ..., test_10.txt. That is, each test_i.txt has a corresponding o_test_i.txt, i = 1, 2, ..., 10, that denotes the expected output for its respective keyboard command.

The bash script run_tests automates testing for you. To do this, enter
"chmod u+x run_tests" and then "./run_tests".

For more information on how to perform testing, see the week 6 recitation slides.