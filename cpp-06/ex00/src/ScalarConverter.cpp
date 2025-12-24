#include "../include/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string const &toConvert) {
	std::cout << ScalarUtils::detectScalarType(toConvert) << std::endl;
}