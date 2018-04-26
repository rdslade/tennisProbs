#include "Player.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>

using namespace std;
bool checkPlayerEquals(Player &p, string name, double serve, double ret){
  return p.getName() == name &&
         p.getServePercentage() == serve &&
         p.getReturnPercentage() == ret;
}

TEST(test_Player_default_ctor){
  Player p;
  ASSERT_TRUE(checkPlayerEquals(p, "", 0, 0));
}

TEST(test_Player_ctor){
  Player p ("Player1", .6, .3);
  ASSERT_TRUE(checkPlayerEquals(p, "Player1", .6, .3));
}

TEST(test_Player_ctor_only_name){
  Player p ("Player1");
  ASSERT_TRUE(checkPlayerEquals(p, "Player1", 0, 0));
}

TEST(test_Player_print){
  Player p ("Player1", .6, .3);
  ostringstream correct;
  correct << "Player1, Serve: 0.6, Return: 0.3" << endl;
  ostringstream out;
  out << p;
  ASSERT_EQUAL(correct.str(), out.str());
}

TEST_MAIN()
