#include <gtest/gtest.h>

#include "../task.hpp"

TEST(LabTest, palindromeTest)
{
    char a[] = " xsdfgh      gftyhb jjj";
    char b[] = "         gj      h j            g";
    char c[] ="k j       h j          k";
    char f[] = "f F   g f G f        F";
    EXPECT_FALSE(palindrome(a));
    EXPECT_TRUE(palindrome(b));
    EXPECT_TRUE(palindrome(c));
    EXPECT_TRUE(palindrome(f));

}


TEST(LabTest, CeasarTest1)
{
    char array_1[] = "aaaddd";
    const char* array_2 = "bbbeee";

    ceasar(array_1, 1);

    EXPECT_STREQ(array_1, array_2); 
}

TEST(LabTest, CeasarTest2)
{
    char array_1[] = "abcdefgh ijk";
    const char* array_2 = "cdefghij klm";

    ceasar(array_1, 2);

    EXPECT_STREQ(array_1, array_2); 
}

TEST(LabTest, CeasarTest3)
{
    char array_1[] = "zasbc nn zasdg";
    const char* array_2 = "efxgh ss efxil";

    ceasar(array_1, 5);

    EXPECT_STREQ(array_1, array_2); 
}

TEST(LabTest, CeasarTest4)
{
    char array_1[] = "jechfrcruur njfrjfg adsvt";
    const char* array_2 = "avtywitilli eawiawx rujmk";

    ceasar(array_1, 17);

    EXPECT_STREQ(array_1, array_2); 
}

TEST(LabTest, CeasarTest5)
{
    char array_1[] = "je   chfrcruu  r njfrjfg adsv      t";
    const char* array_2 = "av   tywitill  i eawiawx rujm      k";

    ceasar(array_1, 17);

    EXPECT_STREQ(array_1, array_2); 
}

TEST(LabTest, CeasarTest6)
{
    char array_1[] = "jechfrcruur njfrjfg adsvt";
    const char* array_2 = "xsqvtfqfiif bxtfxtu orgjh";

    ceasar(array_1, 560);

    EXPECT_STREQ(array_1, array_2); 
}

//!!!!!!!!!!!!!!!!!

TEST(ZFunctionTest, SubstringTest)
{
    //               012345678
    const char* a = "aabcaab";
    const char* b = "caa";

    int number = find_substring1(a, b, 0);

    EXPECT_EQ(number, 3);
}

TEST(ZFunctionTest, SubstringTest_2)
{
    //               012345678
    const char* a = "aabcaab";
    const char* b = "caa";

    int number = find_substring1(a, b, 3);

    EXPECT_EQ(number, 3);
}

TEST(ZFunctionTest, SubstringTest_3)
{
    //               012345678
    const char* a = "aabcaab";
    const char* b = "caasdfghjkldftfghufdertgvbhjuytrf";

    int number = find_substring1(a, b, 0);

    EXPECT_EQ(number, -1);
}

TEST(ZFunctionTest, SubstringTest_4)
{
    //               012345678
    const char* a = "aabcaab";
    const char* b = "caa";

    int number = find_substring1(a, b, 5);

    EXPECT_EQ(number, -1);
}

TEST(ZFunctionTest, SubstringTest_5)
{
    //               012345678
    const char* a = "aabcaab";
    const char* b = "aab";

    int number = find_substring1(a, b, 0);

    EXPECT_EQ(number, 0);
}

TEST(ZFunctionTest, SubstringTest_6)
{
    //               012345678
    const char* a = "aabcaab";
    const char* b = "aab";

    int number = find_substring1(a, b, 1);

    EXPECT_EQ(number, 4);
}

TEST(ZFunctionTest, ZFTest)
{
    const char* a = "aabcaab";
    int* b = new int[strlen(a)]{0, 1, 0, 0, 3, 1, 0};

    int* array = new int[strlen(a)];

    compute_z(a, array, strlen(a));

    for(size_t i = 0; i < strlen(a); ++i)
    {
        //std::cout << array[i] << "\n";
        EXPECT_EQ(array[i], b[i]);
    }
    delete[] array;
    delete[] b;
}

TEST(ZFunctionTest, ZFTest_2)
{
    const char* a = "abacaba";
    int* b = new int[strlen(a)]{0, 0, 1, 0, 3, 0, 1};

    int* array = new int[strlen(a)];

    compute_z(a, array, strlen(a));

    for(size_t i = 0; i < strlen(a); ++i)
    {
        EXPECT_EQ(array[i], b[i]);
    }
    delete[] array;
    delete[] b;
}

TEST(ZFunctionTest, ZFTest_3)
{
    const char* a = "aaaaa";
    int* b = new int[strlen(a)]{0, 4, 3, 2, 1};

    int* array = new int[strlen(a)];

    compute_z(a, array, strlen(a));

    for(size_t i = 0; i < strlen(a); ++i)
    {
        EXPECT_EQ(array[i], b[i]);
    }
    delete[] array;
    delete[] b;
}

//!!!!!!!!!!!!!!!!!!!!!!

TEST(ZFunctionTest, Substring2Test_1)
{
    //               012345678
    const char* a = "aabcaab";
    const char* b = "aab";

    auto number = find_substring2(a, b);

    EXPECT_EQ(number.first[0], 0);
    EXPECT_EQ(number.first[1], 4);
    
    delete[] number.first;
}

TEST(ZFunctionTest, Substring2Test_2)
{
    //               0123456789
    const char* a = "rtyyyrtyyyyrt";
    const char* b = "rt";

    auto number = find_substring2(a, b);

    EXPECT_EQ(number.first[0], 0);
    EXPECT_EQ(number.first[1], 5);
    EXPECT_EQ(number.first[2], 11);

    delete[] number.first;
}

TEST(ZFunctionTest, Substring2Test_4)
{
    //               0123456789
    const char* a = "aaaaaaaaaaaaaaaaaaaaaaaaaaa";
    const char* b = "a";

    auto number = find_substring2(a, b);

    for(size_t i = 0; i < number.second; ++i)
    {
        EXPECT_EQ(number.first[i], static_cast<int>(i));
    }  
    delete[] number.first;
}
