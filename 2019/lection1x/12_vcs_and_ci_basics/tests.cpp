#define BOOST_TEST_DYN_LINK

#define BOOST_TEST_MODULE DiceTest
#include <boost/test/unit_test.hpp>

#include "dice.hpp"

BOOST_AUTO_TEST_CASE(BasicTest)
{
    Dice d6(6);
    for(int i = 0; i < 1000; i++) {
        int res = d6.roll();
        BOOST_REQUIRE( 1 <= res && res <= 6 );
    }
}
