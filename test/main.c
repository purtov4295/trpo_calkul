#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <functions.h>
#include <ctest.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(search_i_test, positive_numbers)
{
    // Given
    float a = 2;
    float b = 2;

    // When
    const int result = search_i(a, b);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(search_i_test,negative_numbers)
{
    // Given
    float a = -2.22;
    float b = -2;

    // When
    const int result = search_i(a, b);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(search_i_test, positive_and_negative_numbers)
{
    // Given
    float a = -2.22;
    float b = 2;

    // When
    const int result = search_i(a, b);

    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(search_j_test, exponentiation)
{
    // Given
    int i = 2;

    // When
    const int result = search_j(i);

    // Then
    const int expected = 100;
    ASSERT_EQUAL(expected, result);
}

CTEST(search_x_test, negative_numbers)
{
    // Given
    float a = -2.22, j2 = 100.0;
    int j1 = 100;

    // When
    const int result = search_x(a, j1, j2);

    // Then
    const int expected = -2.22;
    ASSERT_EQUAL(expected, result);
}

CTEST(search_x_test, positive_numbers)
{
    // Given
    float a = 2.22, j2 = 100.0;
    int j1 = 100;

    // When
    const int result = search_x(a, j1, j2);

    // Then
    const int expected = 2.22;
    ASSERT_EQUAL(expected, result);
}

CTEST(search_y_test, positive_numbers)
{
    // Given
    float b = 2.22, j2 = 100.0;
    int j1 = 100;

    // When
    const int result = search_y(b, j1, j2);

    // Then
    const int expected = 2.22;
    ASSERT_EQUAL(expected, result);
}

CTEST(search_y_test, negative_numbers)
{
    // Given
    float b = -2.22, j2 = 100.0;
    int j1 = 100;

    // When
    const int result = search_y(b, j1, j2);

    // Then
    const int expected = -2.22;
    ASSERT_EQUAL(expected, result);
}

//  SUM
CTEST(calculation_test, sum_negative_numbers)
{
    // Given
    float x = -2;
    float y = -2;

    // When
    const int result = sum(x, y);

    // Then
    const int expected = -4;
    ASSERT_EQUAL(expected, result);
}

CTEST(calculation_test, sum_positive_numbers)
{
    // Given
    float x = 2;
    float y = 2;

    // When
    const int result = sum(x, y);

    // Then
    const int expected = 4;
    ASSERT_EQUAL(expected, result);
}

CTEST(calculation_test, sum_positive_and_negative_numbers)
{
    // Given
    float x = 2;
    float y = -2;

    // When
    const int result = sum(x, y);

    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}