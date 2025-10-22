#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "schemeValidator.h"
#include <criterion/criterion.h>

void runtest(char *input, int expected);

Test(coverage, validscheme1) {runtest("ab", 0);}


Test(coverage, validscheme2) {runtest("a", 0);}
Test(coverage, validscheme3) {runtest("a1", 0);}
Test(coverage, validscheme4) {runtest("a-", 0);}
Test(coverage, validscheme5) {runtest("a.", 0);}
Test(coverage, validscheme6) {runtest("a+1", 0);}
Test(coverage, validscheme7) {runtest("a-b1.c2+", 0);}
Test(coverage, validscheme8) {runtest("AB", 1);}
Test(coverage, validscheme9) {runtest("Ab", 1);}
Test(coverage, validscheme10) {runtest("Ab-C1.D2+", 1);}


Test(coverage, invalid_scheme1) {runtest("4a", -1);}
Test(coverage, invalid_scheme2) {runtest("-a", -1);}
Test(coverage, invalid_scheme3) {runtest(".a", -1);}
Test(coverage, invalid_scheme4) {runtest("+a", -1);}
Test(coverage, invalid_scheme5) {runtest("1", -1);}
Test(coverage, invalid_scheme6) {runtest("$a", -1);}
Test(coverage, invalid_scheme7) {runtest(" a", -1);}
Test(coverage, invalid_scheme8) {runtest("@a", -1);}
Test(coverage, invalid_scheme9) {runtest("#a", -1);}
Test(coverage, invalid_scheme10) {runtest(NULL, -1);}
Test(coverage, invalid_scheme11) {runtest("a/", -1);}
Test(coverage, invalid_scheme12) {runtest("a:", -1);}
Test(coverage, invalid_scheme13) {runtest("a?", -1);}
Test(coverage, invalid_scheme14) {runtest("a&", -1);}
Test(coverage, invalid_scheme15) {runtest("=a", -1);}
Test(coverage, invalid_scheme16) {runtest("", -1);}
Test(coverage, invalid_scheme17) {runtest(" ", -1);}

Test(coverage, test00) {  runtest("4",-1);  }

void runtest(char *input, int expected) {
  int actual = schemeValidator(input);
  cr_assert_eq(expected,actual);
}