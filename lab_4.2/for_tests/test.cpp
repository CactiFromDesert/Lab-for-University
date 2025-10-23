#include <gtest/gtest.h>

#include "../task.hpp"
//#include "../utilits.hpp"

TEST(FileTest, ExtensionTest)
{
    std::string str_1 = "dfghj.ggg";
    std::string str_2 = ".ggg";

    auto str_3 = file_format(str_1);

    EXPECT_EQ(str_2, str_3.value());
}


TEST(FileTest, ExtensionTest)
{
    std::string str_1 = "dfghj.ggg";
    std::string str_2 = ".ggg";

    auto str_3 = file_format(str_1);

    EXPECT_EQ(str_2, str_3);
}

TEST(FileTest, NameTest)
{
    std::string str_1 = "dfghj.ggg";
    std::string str_2 = "dfghj";

    auto str_3 = file_name(str_1);

    EXPECT_EQ(str_2, str_3);
}

TEST(FileTest, LocationTest)
{
    std::string str_1 = "dfghj.ggg";
    std::string str_2 = "dfghj.ggg";

    auto str_3 = file_path(str_1);

    EXPECT_EQ(str_2, str_3);
}

TEST(FileTest, DiskNameTest)
{
    std::string str_1 = "dfghj.ggg";
    std::string str_2 = "__";

    auto str_3 = file_disk(str_1);

    EXPECT_EQ(str_2, str_3);
}

/*TEST(FileTest, RenameTest)
{
    std::string str_1 = "dfghj.ggg";
    std::string str_2 = "__";

    std::string str_3 = file_rename(str_1);

    EXPECT_EQ(str_2, str_3);
}

TEST(FileTest, CopyFileTest)
{
    std::string str_1 = "dfghj.ggg";
    std::string str_2 = "__";

    std::string str_3 = file_copy(str_1);

    EXPECT_EQ(str_2, str_3);
}*/