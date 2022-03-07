#include <gtest/gtest.h>

#include "Tuple.h"



TEST(Tuple, Constructor) {
    t::Tuple<int, int, int> t(1, 2, 3);
    EXPECT_EQ(1, t.get<0>());
    EXPECT_EQ(2, t.get<1>());
    EXPECT_EQ(3, t.get<2>());
    
}

TEST(Tuple , multipleTypeConstructor)
{
    t::Tuple<int, std::string, int> t(1, "coucou", 3);
    EXPECT_EQ(1, t.get<0>());
    EXPECT_EQ("coucou", t.get<1>());
    EXPECT_FALSE(t.get<1>() == "toto");
    EXPECT_EQ(3, t.get<2>());
  
}

TEST(Tuple , multipleTypeConstructorComplex)
{
  t::Tuple<int , std::vector<int>, std::string> t(1, {1,2,3}, "coucou");
  EXPECT_EQ(1, t.get<0>());
  EXPECT_EQ(1, t.get<1>()[0]);
  EXPECT_EQ(2, t.get<1>()[1]);
  EXPECT_EQ(3, t.get<1>()[2]);
  EXPECT_EQ(std::vector<int>({1,2,3}), t.get<1>());
  EXPECT_EQ("coucou", t.get<2>());

}

TEST(Tuple , EqualityOperator)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 2, "coucou");

  EXPECT_TRUE(t == t2);

}

TEST(Tuple , EqualityOperatorNotEqual)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 2, "toto");
  
  EXPECT_FALSE(t == t2);
  
}

TEST(Tuple , EqualityOperatorNotEqual2)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 3, "coucou");

  EXPECT_FALSE(t == t2);

}

TEST(Tuple , InequalityOperator)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 2, "coucou");

  EXPECT_FALSE(t != t2);
}

TEST(Tuple , InequalityOperatorNotEqual)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 2, "toto");

  EXPECT_TRUE(t != t2);
}

TEST(Tuple , InequalityOperatorNotEqual2)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 3, "coucou");

  EXPECT_TRUE(t != t2);
}

TEST(Tuple , LTOperator)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 2, "coucou");

  EXPECT_FALSE(t < t2);
}

TEST(Tuple , LTOperator2)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 3, "toto");

  EXPECT_TRUE(t < t2);
}

TEST(Tuple , LTOperatorFalse)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 0, "toto");

  EXPECT_FALSE(t < t2);
}

TEST(Tuple , LTOperatorDoubleType)
{
  t::Tuple<int , double , std::string> t(1, 2.0f, "coucou");
  t::Tuple<int , double , std::string> t2(1, 5.0f, "toto");

  EXPECT_TRUE(t < t2);
}

TEST(Tuple , GTOperator)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 2, "coucou");

  EXPECT_FALSE(t > t2);

}

TEST(Tuple , GTOperator2)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 3, "toto");

  EXPECT_FALSE(t > t2);
}

TEST(Tuple , GTOperatorTrue)
{
  t::Tuple<int , int , std::string> t(1, 2, "coucou");
  t::Tuple<int , int , std::string> t2(1, 0, "toto");

  EXPECT_TRUE(t > t2);
}


TEST(Tuple , PlusDifferentType)
{
  t::Tuple<int , int > t(1, 2);
  t::Tuple<int , double  > t2(1, 3.0);

  t::Tuple <int , double > t3 = t + t2;
  EXPECT_EQ(2, t3.get<0>());
  EXPECT_EQ(5.0, t3.get<1>());


}





// ...


TEST(Tuple , makeTupleBase)
{
  t::Tuple<int , int , std::string> t = t::makeTuple(1, 2, std::string("coucou"));
  EXPECT_EQ(1, t.get<0>());
  EXPECT_EQ(2, t.get<1>());
  EXPECT_EQ("coucou", t.get<2>());
}


TEST(Tuple , makeTupleautoType)
{
  auto t = t::makeTuple(1, 2, std::string("coucou"), std::vector<int>{1,2,3}, std::vector<int>{1,2,3,4});
  EXPECT_EQ(1, t.get<0>());
  EXPECT_EQ(2, t.get<1>());
  EXPECT_EQ("coucou", t.get<2>());
  EXPECT_EQ(std::vector<int>({1,2,3}), t.get<3>());
  EXPECT_EQ(std::vector<int>({1,2,3,4}), t.get<4>());

}

// TEST(Tuple , concatenateOperator)
// {
//   t::Tuple<int> t1(1);
//   t::Tuple<int> t2(2);

//   auto t3 = std::move(t1) | std::move(t2);

//   EXPECT_EQ(1, t3.get<0>());
//   EXPECT_EQ(2, t3.get<1>());

// }

// TEST(Tuple , concatenateOperatorString)
// {
//   t::Tuple<std::string> t1("hello");
//   t::Tuple<std::string> t2("world");

//   auto t3 = std::move(t1) | std::move(t2);

//   EXPECT_EQ("hello", t3.get<0>());
//   EXPECT_EQ("world", t3.get<1>());

// }

// TEST(Tuple , concatenateOperatorMultipleElements)
// {
//   t::Tuple<int, int> t1(1,2);
//   t::Tuple<int, int> t2(3,4);

//   auto t3 = std::move(t1) | std::move(t2);

//   EXPECT_EQ(1, t3.get<0>());
//   EXPECT_EQ(2, t3.get<1>());
//   EXPECT_EQ(3, t3.get<2>());
//   EXPECT_EQ(4, t3.get<3>());
// }












int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
