#include "doctest.h"

#include <vector>
#include <lexer/lexer.hpp>
#include <lexer/tokens.hpp>

TEST_CASE("Tokenize basic primitives") {
    std::vector<Token> res;

    res = LEXER("69420", "").result();
    CHECK(res[0].tkType == tk_integer);
    CHECK(res[0].keyword == "69420");

    res = LEXER("5.32006", "").result();
    CHECK(res[0].tkType == tk_decimal);
    CHECK(res[0].keyword == "5.32006");

    res = LEXER("\"A blazing fast language\"", "").result();
    CHECK(res[0].tkType == tk_string);
    CHECK(res[0].keyword == std::string("A blazing fast language"));

    res = LEXER("True", "").result();
    CHECK(res[0].tkType == tk_true);
}

TEST_CASE("Tokenize variable declarations") {
  std::vector<Token> res = LEXER("int test = 23", "").result();

  REQUIRE(res.size() == 5);

  CHECK(res[0].tkType == tk_identifier);
  CHECK(res[1].tkType == tk_identifier);
  CHECK(res[2].tkType == tk_assign);
  CHECK(res[3].tkType == tk_integer);
  CHECK(res[4].tkType == tk_eof);
}

TEST_CASE("Tokenize if-else statements") {
  std::vector<Token> res =
      LEXER("if test:\n    print(\"true!\")\nelse:\n    print(\"false!\")", "")
          .result();

  REQUIRE(res.size() == 18);

  SUBCASE("Emit ident and dedent tokens") {
    CHECK(res[3].tkType == tk_ident);
    CHECK(res[8].tkType == tk_dedent);
    CHECK(res[11].tkType == tk_ident);
    CHECK(res[16].tkType == tk_dedent);
  }

  SUBCASE("Emit if and else tokens") {
    CHECK(res[0].tkType == tk_if);
    CHECK(res[2].tkType == tk_colon);

    CHECK(res[9].tkType == tk_else);
    CHECK(res[10].tkType == tk_colon);
  }
}
