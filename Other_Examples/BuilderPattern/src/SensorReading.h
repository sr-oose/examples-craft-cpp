#ifndef SRC_SENSORREADING_H_
#define SRC_SENSORREADING_H_

#include <stdint.h>
#include <memory>

enum class SensorMode
{
	FULL_PRECISION, LOW_POWER
};

// Normally, implementation should be in seperate cpp file!

class SensorReading
{
public:
	SensorReading() = default;
	virtual ~SensorReading() = default;

	double getPressureInPascal() const {
		return pressureInPascal;
	}

	SensorMode getSensorMode() const {
		return sensorMode;
	}

	double getTempInCelsius() const {
		return tempInCelsius;
	}

	uint64_t getTimestamp() const {
		return timestamp;
	}

	void setPressureInPascal(double pressureInPascal) {
		this->pressureInPascal = pressureInPascal;
	}

	void setSensorMode(SensorMode sensorMode) {
		this->sensorMode = sensorMode;
	}

	void setTempInCelsius(double tempInCelsius) {
		this->tempInCelsius = tempInCelsius;
	}

	void setTimestamp(uint64_t timestamp) {
		this->timestamp = timestamp;
	}

private:
	uint64_t timestamp;
	double tempInCelsius;
	double pressureInPascal;
	SensorMode sensorMode;
};

#endif
