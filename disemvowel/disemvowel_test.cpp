#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* test1;
  test1 = disemvowel((char*) "");
  ASSERT_STREQ("", test1);
  free(test1);
}

TEST(Disemvowel, HandleNoVowels) {
  char* test2;
  test2 = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", test2);
  free(test2);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* test3;
  test3 = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", test3);
  free(test3);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* test4;
  test4 = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", test4);
  free(test4);
}

TEST(Disemvowel, HandlePunctuation) {
  char* test5;
  test5 = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", test5);
  free(test5);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  char* test6;
  test6 = disemvowel(str);
  ASSERT_STREQ("xyz", test6);
  free(test6);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
