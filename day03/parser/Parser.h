
#include "../data/input.h"
#include <istream>

namespace day03
{
class Parser
{
public:
    Parser();

    MulList parse(std::istream &inputStream) const;

private:
};
} // namespace day03
