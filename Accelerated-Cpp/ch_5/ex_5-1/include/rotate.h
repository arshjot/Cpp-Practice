#ifndef GUARD_ROTATE_H
#define GUARD_ROTATE_H
 
#include <iostream>
#include <string>
#include <vector>
 
struct Rotated_line
{
    std::vector<std::string> first_half;
    std::vector<std::string> second_half;
};
 
bool compare(const Rotated_line&, const Rotated_line&);
std::vector<Rotated_line> rotate(const std::vector<std::string>&);
 
#endif