#include "gtest/gtest.h"
#include "../include/matrix.h"


TEST(APHW3TEST, test1)
{
    Matrix m;
    EXPECT_EQ(m.getRowSize(), 0);
    EXPECT_EQ(m.getColSize(), 0);
    EXPECT_EQ(m.getRowCapacity(), 2);
    EXPECT_EQ(m.getColCapacity(), 2);
}

TEST(APHW3TEST, test2)
{
    Matrix m(5);
    EXPECT_EQ(m.getRowSize(), 5);
    EXPECT_EQ(m.getColSize(), 5);
    EXPECT_EQ(m.getRowCapacity(), 8);
    EXPECT_EQ(m.getColCapacity(), 8);
}

TEST(APHW3TEST, test3)
{
    Matrix m{{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(m.getRowSize(), 2);
    EXPECT_EQ(m.getColSize(), 3);
    EXPECT_EQ(m.getRowCapacity(), 2);
    EXPECT_EQ(m.getColCapacity(), 4);
}

TEST(APHW3TEST, test4)
{
    Matrix m{{1, 2, 3, 4, 5}, {3, 4, 5, 4, 5}, {4, 5, 5, 4, 5}};
    Matrix m2{m};
    EXPECT_EQ(m2.getRowSize(), 3);
    EXPECT_EQ(m2.getColSize(), 5);
    EXPECT_EQ(m2.getRowCapacity(), 4);
    EXPECT_EQ(m2.getColCapacity(), 8);
    EXPECT_EQ(m.getMatrix()[2][3], m2.getMatrix()[2][3]);
}

TEST(APHW3TEST, test5)
{
    Matrix m {{1, 2, 3, 4, 5}, {3, 4, 5, 4, 5}, {4, 5, 5, 4, 5}};
    Matrix m2 {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3}};
    m.append(m2);
    EXPECT_EQ(m.getRowSize(), 3);
    EXPECT_EQ(m.getColSize(), 10);
    EXPECT_EQ(m.getRowCapacity(), 4);
    EXPECT_EQ(m.getColCapacity(), 16);
    m.append(m, 1);
    EXPECT_EQ(m.getRowSize(), 6);
    EXPECT_EQ(m.getColSize(), 10);
    EXPECT_EQ(m.getRowCapacity(), 8);
    EXPECT_EQ(m.getColCapacity(), 16);
}

TEST(APHW3TEST, test6)
{
    Matrix m {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Matrix m2{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Matrix prod{m * m2};
    EXPECT_EQ(prod.getRowSize(), 3);
    EXPECT_EQ(prod.getColSize(), 4);
    EXPECT_EQ(prod.getRowCapacity(), 4);
    EXPECT_EQ(prod.getColCapacity(), 4);
    EXPECT_EQ(prod.getMatrix()[1][0], 5);
    EXPECT_EQ(prod.getMatrix()[2][2], 11);
}

TEST(APHW3TEST, test7)
{
    Matrix m {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Matrix m2{{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
    Matrix summ{m + m2};
    EXPECT_EQ(summ.getRowSize(), 3);
    EXPECT_EQ(summ.getColSize(), 3);
    EXPECT_EQ(summ.getRowCapacity(), 4);
    EXPECT_EQ(summ.getColCapacity(), 4);
    EXPECT_EQ(summ.getMatrix()[1][1], 7);
    EXPECT_EQ(summ.getMatrix()[2][2], 12);
}

TEST(APHW3TEST, test8)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix m2{{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
    Matrix sub{m - m2};
    EXPECT_EQ(sub.getRowSize(), 3);
    EXPECT_EQ(sub.getColSize(), 3);
    EXPECT_EQ(sub.getRowCapacity(), 4);
    EXPECT_EQ(sub.getColCapacity(), 4);
    EXPECT_EQ(sub.getMatrix()[1][1], 11);
    EXPECT_EQ(sub.getMatrix()[2][2], -10);
}

TEST(APHW3TEST, test9)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix m2{{1, 2, 3}, {5, 6, 7}, {9, 10, 11}};
    m += m2;
    EXPECT_EQ(m.getRowSize(), 3);
    EXPECT_EQ(m.getColSize(), 3);
    EXPECT_EQ(m.getRowCapacity(), 4);
    EXPECT_EQ(m.getColCapacity(), 4);
    EXPECT_EQ(m.getMatrix()[1][1], 23);
    EXPECT_EQ(m.getMatrix()[2][2], 12);
}

TEST(APHW3TEST, test10)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix s{m++};
    EXPECT_EQ(s.getRowSize(), 3);
    EXPECT_EQ(s.getColSize(), 3);
    EXPECT_EQ(s.getRowCapacity(), 4);
    EXPECT_EQ(s.getColCapacity(), 4);
    EXPECT_EQ(s.getMatrix()[1][1], 17);
    EXPECT_EQ(s.getMatrix()[2][2], 1);

    EXPECT_EQ(m.getMatrix()[1][1], 18);
    EXPECT_EQ(m.getMatrix()[2][2], 2);
}

TEST(APHW3TEST, test11)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix s{++m};
    EXPECT_EQ(s.getRowSize(), 3);
    EXPECT_EQ(s.getColSize(), 3);
    EXPECT_EQ(s.getRowCapacity(), 4);
    EXPECT_EQ(s.getColCapacity(), 4);
    EXPECT_EQ(s.getMatrix()[1][1], 18);
    EXPECT_EQ(s.getMatrix()[2][2], 2);

    EXPECT_EQ(m.getMatrix()[1][1], 18);
    EXPECT_EQ(m.getMatrix()[2][2], 2);
}

TEST(APHW3TEST, test12)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[1][2], 9);
}

TEST(APHW3TEST, test13)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix m2 {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix m3 {{1, 8, 9}, {85, 17, 9}, {56, 9, -1}};
    EXPECT_EQ(m == m2, true);
    EXPECT_EQ(m2 == m3, false);
}

TEST(APHW3TEST, test14)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix m2 {{1, 8, 9}, {85, 17, 9}};
    Matrix m3 {{1, 8}, {85, 17}, {56, 9}, {56, 9}};
    Matrix m4 {{1, 8}, {85, 17}, {56, 9}, {56, 9}};
    EXPECT_EQ(m > m2, true);
    EXPECT_EQ(m2 < m3, true);
    EXPECT_EQ(m <= m3, true);
    EXPECT_EQ(m3 <= m4, true);
}

TEST(APHW3TEST, test15)
{
    Matrix m {{1, 8, 9}, {85, 17, 9}, {56, 9, 1}};
    Matrix m2 {{1, 8, 9}, {85, 17, 9}};
    Matrix m3 {{1, 8}, {85, 17}, {56, 9}, {56, 9}};
    Matrix m4 {{1, 8}, {85, 17}, {56, 9}, {56, 9}};
    EXPECT_EQ(m > m2, true);
    EXPECT_EQ(m2 < m3, true);
    EXPECT_EQ(m <= m3, true);
    EXPECT_EQ(m3 <= m4, true);
}

TEST(APHW3TEST, test16)
{
    Matrix A {{1, 2, 3}, {3, 0, 1}, {1, 1, 1}};
    Matrix b {{12}, {16}, {8}};
    Matrix x{A | b};
    ASSERT_NEAR(x[0][0], 5, 0.001);
    ASSERT_NEAR(x[1][0], 2, 0.001);
    ASSERT_NEAR(x[2][0], 1, 0.001);
}
