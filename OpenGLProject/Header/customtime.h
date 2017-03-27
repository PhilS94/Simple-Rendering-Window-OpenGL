#ifndef TIMER_H
#define TIMER_H

class CustomTime {
public:
	CustomTime() {
		time = 0;
	};

	void incrementTime() {
		time += 1;
	};

	long getTime() {
		return time;
	};

private:
	unsigned long time;
};
#endif // !TIMER_H