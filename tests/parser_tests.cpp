#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "parser.hpp"

TEST_CASE("basic math") {
    Parser p;

    auto rpn = p.ToRPN("2*4+6");
    REQUIRE(p.EvaluateRPN(rpn) == 14);
}

TEST_CASE("precedence works") {
    Parser p;

    auto rpn = p.ToRPN("3+4*5+4^2%7");
    REQUIRE(p.EvaluateRPN(rpn) == 25);
}

TEST_CASE("multi-digit numbers") {
    Parser p;

    auto rpn = p.ToRPN("2323+123/4*5+12");
    REQUIRE(p.EvaluateRPN(rpn) == Catch::Approx(2488.75));
}

TEST_CASE("parantheses work") {
    Parser p;

    auto rpn = p.ToRPN("30+10+5*12+55x(45-2+(23-3))");
    REQUIRE(p.EvaluateRPN(rpn) == 3565);
}
