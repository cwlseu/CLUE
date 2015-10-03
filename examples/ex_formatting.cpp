// This shows the use of formatting

#include <clue/formatting.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace clue;
using std::string;

struct User {
    int id;
    string name;
    double score;
};

int main() {
    std::vector<User> users {
        {1, "Alice", 85.0},
        {2, "Bob",   69.2},
        {3, "Nina",  92.5},
        {4, "Mary",  78.3},
        {5, "Mike", 100.0},
        {6, "Tom",   88.6},
        {7, "John",  83.2}
    };

    // width setting
    size_t widths[] = {3, 5, 7};
    size_t row_len = 5;
    for (size_t i = 0; i < 3; ++i) {
        row_len += (widths[i] + 5);
    }
    string sepline(row_len, '-');

    // print header
    std::cout << sepline << std::endl;
    std::cout << str("  |  ",
        withf("id",    align_left(widths[0])), "  |  ",
        withf("name",  align_left(widths[1])), "  |  ",
        withf("score", align_left(widths[2])), "  |  "
    ) << std::endl;
    std::cout << sepline << std::endl;

    // print records
    for (const auto& u: users) {
        std::cout << str("  |  ",
            withf(u.id, dec() | fmt::padzeros | align_right(widths[0])), "  |  ",
            withf(u.name, align_left(widths[1])), "  |  ",
            withf(u.score, fixed().precision(2) | align_right(widths[2])), "  |  "
        ) << std::endl;
    }
    std::cout << sepline << std::endl;

    // The codes above shows the following table to the console:
    //
    // -----------------------------------
    //   |  id   |  name   |  score    |
    // -----------------------------------
    //   |  001  |  Alice  |    85.00  |
    //   |  002  |  Bob    |    69.20  |
    //   |  003  |  Nina   |    92.50  |
    //   |  004  |  Mary   |    78.30  |
    //   |  005  |  Mike   |   100.00  |
    //   |  006  |  Tom    |    88.60  |
    //   |  007  |  John   |    83.20  |
    // -----------------------------------
    //

    return 0;
}
