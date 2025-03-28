#include "gtest/gtest.h"
#include "../ships/Interceptor.hpp"
#include "../ships/TIE.hpp"
#include "../ships/cargo/Destroyer.hpp"
#include "../ships/cargo/Shuttle.hpp"

#include <cmath>

TEST(ShipTest, ShipPrinting) {
    // Create an Interceptor with nickname "Red One"
    Interceptor interceptor1("Red One");
    // Create an Interceptor with nickname "Red Two"
    Interceptor interceptor2("Red Two");
    // Create a TIE with nickname "Black One"
    TIE tie("Black One");
    // Create a Destroyer with nickname "Star Destroyer" and cargo 150,000 tons
    Destroyer destroyer(150000, "Star Destroyer");
    // Create a Shuttle with nickname "Lambda Shuttle" and cargo 50 tons
    Shuttle shuttle(50, "Lambda Shuttle");

    // Expected output strings for each ship
    std::string expectedInterceptor1Output = "Red One [TIE/IN #1]\nweight : 5.00 tons\nmax speed : 110 MGLT";
    std::string expectedInterceptor2Output = "Red Two [TIE/IN #2]\nweight : 5.00 tons\nmax speed : 110 MGLT";
    std::string expectedTieOutput = "Black One [TIE/LN #1]\nweight : 6.00 tons\nmax speed : 100 MGLT";
    std::string expectedDestroyerOutput = "Star Destroyer [Super-class Star Destroyer #1]\nweight : 9000150000.00 tons\nmax speed : 40 MGLT\ncargo : 150000.0 tons (max : 250000.0)";
    std::string expectedShuttleOutput = "Lambda Shuttle [Lambda-class shuttle #1]\nweight : 410.00 tons\nmax speed : 54 MGLT\ncargo : 50.0 tons (max : 80.0)";

    // Check if the actual output matches the expected output for each ship
    std::ostringstream interceptor1Output;
    interceptor1Output << interceptor1;
    ASSERT_EQ(interceptor1Output.str(), expectedInterceptor1Output);

    std::ostringstream interceptor2Output;
    interceptor2Output << interceptor2;
    ASSERT_EQ(interceptor2Output.str(), expectedInterceptor2Output);

    std::ostringstream tieOutput;
    tieOutput << tie;
    ASSERT_EQ(tieOutput.str(), expectedTieOutput);

    std::ostringstream destroyerOutput;
    destroyerOutput << destroyer;
    ASSERT_EQ(destroyerOutput.str(), expectedDestroyerOutput);

    std::ostringstream shuttleOutput;
    shuttleOutput << shuttle;
    ASSERT_EQ(shuttleOutput.str(), expectedShuttleOutput);
}

TEST(ShipTest, InterceptorDefaultConstructor) {
    Interceptor interceptor;
    ASSERT_EQ(interceptor.model(), "TIE/IN");
    ASSERT_EQ(interceptor.weight(), 5.00);
    ASSERT_EQ(interceptor.speed(), 110);
}

TEST(ShipTest, InterceptorNicknameConstructor) {
    Interceptor interceptor;
    ASSERT_EQ(interceptor.model(), "TIE/IN");
    ASSERT_EQ(interceptor.weight(), 5.00);
    ASSERT_EQ(interceptor.speed(), 110);
}

TEST(ShipTest, TIENicknameConstructor) {
    TIE tie("Black One");
    ASSERT_EQ(tie.model(), "TIE/LN");
    ASSERT_EQ(tie.weight(), 6.00);
    ASSERT_EQ(tie.speed(), 100);
}

TEST(ShipTest, DestroyerCargoConstructor) {
    Destroyer destroyer(150000); // cargo: 150,000 tons
    ASSERT_EQ(destroyer.model(), "Super-class Star Destroyer");
    ASSERT_EQ(destroyer.emptyWeight(), (double) 9 * 1000000000); // 9 billion tons
    ASSERT_EQ(destroyer.speed(), 40);
    ASSERT_EQ(destroyer.cargoLimit(), 250000); // 250,000 tons
    ASSERT_EQ(destroyer.getCargo(), 150000); // 150,000 tons
}

TEST(ShipTest, DestroyerNoCargoConstructor) {
    Destroyer destroyer(0); // no cargo
    ASSERT_EQ(destroyer.model(), "Super-class Star Destroyer");
    ASSERT_EQ(destroyer.emptyWeight(), (double) 9 * 1000000000); // 9 billion tons
    ASSERT_EQ(destroyer.speed(), 40);
    ASSERT_EQ(destroyer.cargoLimit(), 250000); // 250,000 tons
    ASSERT_EQ(destroyer.getCargo(), 0); // no cargo
}

TEST(ShipTest, ShuttleCargoConstructor) {
    Shuttle shuttle(50); // cargo: 50 tons
    ASSERT_EQ(shuttle.model(), "Lambda-class shuttle");
    ASSERT_EQ(shuttle.emptyWeight(), 360.0);
    ASSERT_EQ(shuttle.speed(), 54);
    ASSERT_EQ(shuttle.cargoLimit(), 80.0);
    ASSERT_EQ(shuttle.getCargo(), 50); // 50 tons
}

TEST(ShipTest, ShuttleNoCargoConstructor) {
    Shuttle shuttle; // no cargo
    ASSERT_EQ(shuttle.model(), "Lambda-class shuttle");
    ASSERT_EQ(shuttle.emptyWeight(), 360.0);
    ASSERT_EQ(shuttle.speed(), 54);
    ASSERT_EQ(shuttle.cargoLimit(), 80.0);
    ASSERT_EQ(shuttle.getCargo(), 0); // no cargo
}

TEST(ShipTest, ShipEquality) {
    Interceptor interceptor("Red One");
    ASSERT_EQ(interceptor, interceptor);

    TIE tie("Black One");
    ASSERT_EQ(tie, tie);
}

TEST(ShipTest, ShipInequality) {
    Interceptor interceptor("Red One");
    TIE tie("Black One");
    ASSERT_NE(interceptor, tie);

    Interceptor interceptor1("Red One");
    Interceptor interceptor2("Red One");
    ASSERT_NE(interceptor1, interceptor2);

    TIE tie1("Black One");
    TIE tie2("Black One");
    ASSERT_NE(tie1, tie2);
}

TEST(ShipTest, ShipConsumption) {
    // Interceptor with speed 110 and weight 5.00 tons
    Interceptor interceptor;
    // Distance 1000 mio. km (1 billion km)
    double distance = 1000;
    // Expected consumption calculated using the provided formula
    double expectedConsumption =
            cbrt(interceptor.weight()) / 2.0 * log10(interceptor.weight() * static_cast<double>(interceptor.speed())) *
            log10(distance + 1);

    ASSERT_EQ(interceptor.consumption(distance), expectedConsumption);
}