#include "SensorReadingBuilder.h"
#include <gtest/gtest.h>


TEST(suite, testWithBuilderPattern) {
	SensorReadingPtr testReading
		= SensorReadingBuilder()
			.withPressureInPascal(110000.0)
			.withTempInCelsius(40.0)
			.build();

	// Call function under test with testReading as Argument

	// Assert results

}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
