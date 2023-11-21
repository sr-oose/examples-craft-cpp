#ifndef SRC_SENSORREADINGBUILDER_H_
#define SRC_SENSORREADINGBUILDER_H_

// Normally, implementation should be in seperate cpp file!

#include "SensorReading.h"

using SensorReadingPtr = std::shared_ptr<SensorReading>;

class SensorReadingBuilder {
public:
	SensorReadingBuilder()
	{
		reading = std::make_shared<SensorReading>();
		initReadingWithDefaults();
	}

	virtual ~SensorReadingBuilder() = default;

	SensorReadingBuilder& withSensorMode(SensorMode mode)
	{
		reading->setSensorMode(mode);
		return *this;
	}

	SensorReadingBuilder& withTempInCelsius(double temp)
	{
		reading->setTempInCelsius(temp);
		return *this;
	}

	SensorReadingBuilder& withPressureInPascal(double pressure)
	{
		reading->setPressureInPascal(pressure);
		return *this;
	}

	SensorReadingBuilder& withTimestamp(uint64_t timestamp)
	{
		reading->setTimestamp(timestamp);
		return *this;
	}

	SensorReadingPtr build()
	{
		return reading;
	}

private:
	SensorReadingPtr reading;

	void initReadingWithDefaults()
	{
		withSensorMode(SensorMode::FULL_PRECISION);
		withTempInCelsius(20.0);
		withPressureInPascal(101300.0);
		withTimestamp(1514761200000); // 2018-01-01T00:00:00.000
	}
};

#endif
