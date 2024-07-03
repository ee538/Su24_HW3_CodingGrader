#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(CheckValidExpression, Empty)
{
  CPPLib lib;
  EXPECT_EQ(lib.CheckValidExpression(""), 1);
}

TEST(CheckValidExpression, Test1)
{
  CPPLib lib;
  EXPECT_EQ(lib.CheckValidExpression("()"), 1);
  EXPECT_EQ(lib.CheckValidExpression("()[]"), 1);
  EXPECT_EQ(lib.CheckValidExpression("([])"), 1);
  EXPECT_EQ(lib.CheckValidExpression("({})"), 1);
  EXPECT_EQ(lib.CheckValidExpression("({(asdf)}).(123).[asdf]+{(asdfasdf)}"), 1);
  EXPECT_EQ(lib.CheckValidExpression("{2k++[5--*j]}"), 1);

  EXPECT_EQ(lib.CheckValidExpression("("), 0);
  EXPECT_EQ(lib.CheckValidExpression("(]"), 0);
  EXPECT_EQ(lib.CheckValidExpression("({)}"), 0);
}

TEST(CheckValidExpression, SingleOpen)
{
  CPPLib lib;

  EXPECT_EQ(lib.CheckValidExpression("("), 0);
  EXPECT_EQ(lib.CheckValidExpression("{"), 0);
  EXPECT_EQ(lib.CheckValidExpression("["), 0);
  EXPECT_EQ(lib.CheckValidExpression("a(a"), 0);
  EXPECT_EQ(lib.CheckValidExpression("a{a"), 0);
  EXPECT_EQ(lib.CheckValidExpression("a[a"), 0);
}

TEST(CheckValidExpression, SingleClosing)
{
  CPPLib lib;

  EXPECT_EQ(lib.CheckValidExpression("}"), 0);
  EXPECT_EQ(lib.CheckValidExpression("]"), 0);
  EXPECT_EQ(lib.CheckValidExpression(")"), 0);

  EXPECT_EQ(lib.CheckValidExpression("a}b"), 0);
  EXPECT_EQ(lib.CheckValidExpression("1]123"), 0);
  EXPECT_EQ(lib.CheckValidExpression("1)2"), 0);
}

TEST(CheckValidExpression, MultipleClosing)
{
  CPPLib lib;

  EXPECT_EQ(lib.CheckValidExpression("}}}}"), 0);
  EXPECT_EQ(lib.CheckValidExpression("]]"), 0);
  EXPECT_EQ(lib.CheckValidExpression("))"), 0);
}

//-----------------------------------------------------------------------------
TEST(IsPalindrome, Empty)
{
  CPPLib lib;

  std::cout << "Empty string" << std::endl;
  EXPECT_EQ(lib.IsPalindrome(""), 1);
}
TEST(IsPalindrome, Simple)
{
  CPPLib lib;

  EXPECT_EQ(lib.IsPalindrome("a"), 1);
  EXPECT_EQ(lib.IsPalindrome("aba"), 1);
  EXPECT_EQ(lib.IsPalindrome("abba"), 1);
  EXPECT_EQ(lib.IsPalindrome(" "), 1);
  EXPECT_EQ(lib.IsPalindrome("amanaplanacanalpanama"), 1);

  EXPECT_EQ(lib.IsPalindrome("ab"), 0);
  EXPECT_EQ(lib.IsPalindrome("abc"), 0);
}
//-----------------------------------------------------------------------------
TEST(OddChar, OddNumberOfCharacters)
{
  CPPLib lib;

  EXPECT_EQ(lib.OddChar(std::string("aaabb")), 'a');
  EXPECT_EQ(lib.OddChar(std::string("aab")), 'b');
  EXPECT_EQ(lib.OddChar(std::string("a")), 'a');
}
