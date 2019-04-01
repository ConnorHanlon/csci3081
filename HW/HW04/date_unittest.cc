#include "gtest/gtest.h"

#include <iostream>
#include <math.h>

#include "date.h"

using namespace std;

class DateTest : public ::testing::Test {
 public:
  void SetUp( ) {
    // code here will execute just before the test ensues
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
};



TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";

  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";

  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestWithNewLine){
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  string e_out1 = "12-31-1999\n";
  string e_out2 = "07-04-1776\n";
  string e_out3 = "10-31-2018\n";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintUsDate(true);
  string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, e_out1);
  EXPECT_EQ(output2, e_out2);
  EXPECT_EQ(output3, e_out3);
}

TEST_F(DateTest, PrintUsDateTestWithoutNewLine){
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween

  string e_out1 = "12-31-1999";
  string e_out2 = "07-04-1776";
  string e_out3 = "10-31-2018";

  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintUsDate(false);
  string output2 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  string output3 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(output1, e_out1);
  EXPECT_EQ(output2, e_out2);
  EXPECT_EQ(output3, e_out3);
}

TEST_F(DateTest, GetDateTests){
  Date b_day(1995, 10, 11);
  Date y2k(1999, 12, 31);
  Date ind_day(1776, 7, 4);

  //GetDateTests
  EXPECT_EQ("1995-10-11", b_day.GetDate());
  EXPECT_EQ("1999-12-31", y2k.GetDate());
  EXPECT_EQ("1776-07-04", ind_day.GetDate());

  //GetUsDateTests
  EXPECT_EQ("10-11-1995", b_day.GetUsDate());
  EXPECT_EQ("12-31-1999", y2k.GetUsDate());
  EXPECT_EQ("07-04-1776", ind_day.GetUsDate());
}

TEST_F(DateTest, OverloadedPlusTests){
  Date b_day(1995, 10, 11);
  Date y2k(1999, 12, 31);
  Date rand_day(1776, 7, 9);

  //add 1 to a date
  Date new_d1 = b_day + 1;
  EXPECT_EQ("1995-10-12", new_d1.GetDate());

  //add 1 day, changes year, month, day
  Date new_d2 = y2k + 1;
  EXPECT_EQ("2000-01-01", new_d2.GetDate());

  //add 2 days
  Date new_d3 = rand_day + 2;
  EXPECT_EQ("1776-07-11", new_d3.GetDate());

  //add 365, changes year
  Date new_d4 = b_day + 365;
  EXPECT_EQ("1996-10-10", new_d4.GetDate());

  //add 0
  Date new_d5 = b_day + 0;
  EXPECT_EQ("1995-10-11", new_d5.GetDate());

  //add -1
  Date new_d6 = b_day + (-1);
  EXPECT_EQ("1995-10-10", new_d6.GetDate());
}

TEST_F(DateTest, OverloadedMinusTests){
  Date b_day(1995, 10, 11);
  Date aftery2k(2000, 01, 01);
  Date rand_day(1776, 7, 9);

  //subtract 1
  string e_out1 = "1995-10-10";
  Date new_d1 = b_day - 1;
  EXPECT_EQ(e_out1, new_d1.GetDate());

  //Test change to year, month, day
  string e_out2 = "1999-12-31";
  Date new_d2 = aftery2k - 1;
  EXPECT_EQ(e_out2, new_d2.GetDate());

  //subtract multiple
  string e_out3 = "1776-07-04";
  Date new_d3 = rand_day - 5;
  EXPECT_EQ(e_out3, new_d3.GetDate());

  //subtract over years
  string e_out4 = "1994-10-11";
  Date new_d4 = b_day - 365;
  EXPECT_EQ(e_out4, new_d4.GetDate());

  //subtract 0
  string e_out5 = "1776-07-09";
  Date new_d5 = rand_day - 0;
  EXPECT_EQ(e_out5, new_d5.GetDate());
}

TEST_F(DateTest, EpochTest){
  Date epoch1(0);
  Date epoch2(-1);
  Date epoch3(86401);
  Date epoch4(31536000);
  Date epoch5(-31536000);

  string e_out1 = "1970-01-01";
  string e_out2 = "1969-12-31";
  string e_out3 = "1970-01-02";
  string e_out4 = "1971-01-01";
  string e_out5 = "1969-01-01";

  //tests standard 0 input
  EXPECT_EQ(e_out1, epoch1.GetDate());

  //test that days change correctly
  EXPECT_EQ(e_out2, epoch2.GetDate());
  EXPECT_EQ(e_out3, epoch3.GetDate());

  //test adding enough seconds to change years
  EXPECT_EQ(e_out4, epoch4.GetDate());
  EXPECT_EQ(e_out5, epoch5.GetDate());

}

TEST_F(DateTest, VoidConstructorTest){
  time_t t = time(0);
  tm* today = localtime(&t);

  //years since 1900
  int year = today->tm_year + 1900;
  //months since jan ranging from 0-11
  int month = today->tm_mon + 1;
  //days since January
  int day = today->tm_mday;

  Date expected_date(year, month, day);
  Date date_today;

  EXPECT_EQ(date_today.GetDate(), expected_date.GetDate());
}
/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  *
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */

TEST_F(DateTest, DaysBetweenTests) {

  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";

  Date jan_first(2000, 01, 01);
  Date jan_sec(2000, 01, 02);
  Date jan_nextyr(2001, 01, 01);
  Date feb_first(2000, 02, 01);
  Date june_5(2000, 06, 05);
  Date june_03(2003, 06, 05);
  Date y2k(1999, 12, 31);
  Date dec_last(2000, 12, 31);
  Date ad(0001, 01, 01);


  //Between jan1 and jan1
  EXPECT_EQ(jan_first.DaysBetween(jan_first), 0);

  //Between Jan1 and Jan2
  EXPECT_EQ(jan_first.DaysBetween(jan_sec), 1);

  //between Jan1 and Feb1
  EXPECT_EQ(jan_first.DaysBetween(feb_first), 31);

  //Between Dec 31st and Jan1st
  EXPECT_EQ(jan_first.DaysBetween(y2k), 1);

  //between jan first and june fifth
  EXPECT_EQ(jan_first.DaysBetween(june_5), 156);

  //between jan and christmas
  EXPECT_EQ(jan_first.DaysBetween(dec_last), 365);

  //between next years january and the year previous jan
  EXPECT_EQ(jan_nextyr.DaysBetween(jan_first), 366);

  //Three years -> days between 2000-06-05 and 2003-05-05
  EXPECT_EQ(june_5.DaysBetween(june_03), 1095);

  //Long time between dates
  EXPECT_EQ(ad.DaysBetween(jan_first), 730119);
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
