#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
    std::vector<int> column1;
    std::vector<int> column2;

    std::ifstream inputFile("input");
    if (!inputFile) {
        std::cerr << "Please provide input.txt" << std::endl;
        return 1;
    }
    int col1, col2;
    while (inputFile >> col1 >> col2) {
        column1.push_back(col1);
        column2.push_back(col2);
    }
    inputFile.close();

    // Sort vectors in descending order
    sort(column1.begin(), column1.end(), std::greater<int>());
    sort(column2.begin(), column2.end(), std::greater<int>());

    // Part 1
    // std::vector<int> result;
    // for (size_t i = 0; i < column1.size(); ++i) {
    //     result.push_back(std::abs(column1[i] - column2[i]));
    // }

    // int sum
    //     = accumulate(result.begin(), result.end(),
    //     0);

    // std::cout << "The sum of the absolute difference of the sorted lists is: "
    //           << sum << std::endl;

    // return 0;

    // Part 2
    std::vector<int> counts;
    for(const int& i : column1) 
        counts.push_back(count(column2.begin(), column2.end(), i));

    std::vector<int> product;
    for (size_t i = 0; i < column1.size(); ++i) {
        product.push_back(column1[i] * counts[i]);
    }

    int sum
        = accumulate(product.begin(), product.end(),
        0);

    std::cout << "The sum of the absolute difference of the sorted lists is: "
              << sum << std::endl;
}