#include <iostream>
#include <random>
#include <chrono>

int main() {
    using namespace std::chrono;

    std::cout << "MT19937 sucks! \n";

    auto start_date = 1477008000000000000; // 2016 - 10 - 21
    auto now = high_resolution_clock::now().time_since_epoch().count();

    for (auto entropy = start_date; entropy < now; entropy++) {
        auto entropy2 = high_resolution_clock::duration(entropy);

        std::cout << entropy2.count() << std::endl;
        std::cout << static_cast<uint32_t>(entropy2.count()) << std::endl;

        std::mt19937 rg = std::mt19937(static_cast<uint32_t>(entropy2.count()));

        std::cout << "["; 

        for (int i = 0; i < 32; ++i) {
            std::uniform_int_distribution<uint16_t> distribution(std::numeric_limits<uint8_t>::min(), std::numeric_limits<uint8_t>::max());
            const auto seed = static_cast<uint8_t>(distribution(rg));

            std::cout << int(seed) << ",";
        };

        std::cout << "]" << std::endl;

    }

    return 0;
}
