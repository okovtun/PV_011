#include<iostream>
#include<conio.h>
using namespace std;

const unsigned int DEFAULT_TANK_VOLUME = 60;
const unsigned int MIN_FUEL_LEVEL = 5;
const unsigned int DEFAULT_ENGINE_CONSUMPTION = 8;

class Tank
{
	const unsigned int VOLUME;
	double fuel_level;
	unsigned int min_level;
public:
	unsigned int get_volume()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	unsigned int get_min_level()const
	{
		return min_level;
	}
	void set_fuel_level(double fuel)
	{
		if (fuel < 0)return;
		if (this->fuel_level + fuel < VOLUME)
			fuel_level += fuel;
		else
			fuel_level = VOLUME;
	}
	explicit Tank(int volume) :VOLUME(volume >= 40 && volume <= 120 ? volume : DEFAULT_TANK_VOLUME)
	{
		/*if (volume >= 40 && volume <= 120)
			this->volume = volume;
		else
			this->volume = 60;*/
			//this->VOLUME = volume >= 40 && volume <= 120 ? volume : DEFAULT_TANK_VOLUME;
		fuel_level = 0;
		min_level = MIN_FUEL_LEVEL;
		cout << "TankReady:\t" << this << endl;
	}
	~Tank()
	{
		cout << "TankIsOver:\t" << this << endl;
	}
	void info()const
	{
		cout << "Volume:\t" << VOLUME << endl;
		cout << "Fuel:\t";
		if (fuel_level < 10)cout << 0;
		cout << fuel_level << endl;
		cout << "MinFuel:";
		if (min_level < 10)cout << 0;
		cout << min_level << endl;
	}
};

class Engine
{
	//Engine properties:
	unsigned int volume;
	unsigned int power;
	double consumption;	//liters per 100 km
	double consumption_per_second;	//liters per second

	//Engine state:
	bool started;
public:
	double get_consumption()const
	{
		return consumption;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	explicit Engine(double consumption)
	{
		/*if (consumption >= 4 && consumption <= 25)
			this->consumption = consumption;
		else
			consumption = 8;*/
		this->consumption = consumption >= 4 && consumption <= 25 ? consumption : DEFAULT_ENGINE_CONSUMPTION;
		this->consumption_per_second = consumption * 5e-5; //consumption * 5*10^-4
		started = false;
		cout << "EngineReady:\t" << this << endl;
	}
	~Engine()
	{
		cout << "EngineIsOver:\t" << this << endl;
	}

	bool is_started()const
	{
		return started;
	}
	void start()
	{
		started = true;
	}
	void stop()
	{
		started = false;
	}
	void info()const
	{
		cout << "Consumption:\t\t" << consumption << endl;
		cout << "ConsumptionPerSec:\t" << consumption_per_second << endl;
	}
};

class Car
{
	Engine engine;
	Tank tank;
	const unsigned int MAX_SPEED;
	unsigned int speed;
	bool driver;
public:
	/*Car(const Engine& engine, const Tank& tank) :engine(engine), tank(tank)
	{
		cout << "CarIsReady:\t" << this << endl;
	}*/
	Car(double consumption, unsigned int volume, const unsigned int MAX_SPEED) :
		engine(consumption), tank(volume), MAX_SPEED(MAX_SPEED >= 90 && MAX_SPEED <= 400 ? MAX_SPEED : 250), speed(0)
	{
		//this->engine = consumption;
		//this->MAX_SPEED = MAX_SPEED;
		driver = false;
		cout << "CarIsReady:\t" << this << endl;
	}
	~Car()
	{
		cout << "CarIsOver:\t" << this << endl;
	}

	void get_in()
	{
		driver = true;
	}
	void get_out()
	{
		driver = false;
	}
	bool driver_inside()const
	{
		return driver;
	}

	void fill(unsigned int fuel)
	{
		tank.set_fuel_level(fuel);
	}

	void start()
	{
		engine.start();
	}
	void stop()
	{
		engine.stop();
	}

	void display()const
	{
		system("CLS");
		cout << "Engine is " << (engine.is_started() ? "started" : "stopped") << endl;
		cout << "Fuel level:\t" << tank.get_fuel_level() << "\t";
		if (tank.get_fuel_level() < tank.get_min_level()) cout << "LOW FUEL";
		cout << endl;
		cout << "Speed:    " << speed << "\t";
		cout << "MaxSpeed: " << MAX_SPEED << endl;
	}
	void info()const
	{
		cout << "Engine:\n"; engine.info();
		cout << "Tank:\n"; tank.info();
		cout << "Engine is " << (engine.is_started() ? "started" : "stopped") << endl;
		cout << "Speed:\t" << speed << "km/h\n";
		cout << "MaxSpeed:\t" << MAX_SPEED << "km/h\n";
	}
};

//#define TANK_CHECK
//#define ENGINE_CHECK

#define Escape	27
#define Enter	13

void main()
{
	setlocale(LC_ALL, "");
#ifdef TANK_CHECK
	Tank tank(35);
	tank.info();
	cout << "\n-----------------------------\n";
	tank.set_fuel_level(30);
	tank.info();
	cout << "\n-----------------------------\n";
	tank.set_fuel_level(40);
	tank.info();
#endif // TANK_CHECK

#ifdef ENGINE_CHECK
	Engine engine(10);
	engine.info();
#endif // ENGINE_CHECK

	//Car car(Engine(10), Tank(80));
	Car car(10, 50, 250);
	//car.info();

	cout << "Press Enter to get in" << endl;
	cout << "Press F to to fill the car" << endl;

	char key;
	do
	{
		key = _getch();
		switch (key)
		{
		case 'F':
		case 'f':
			unsigned int fuel;
			cout << "Введите объем топлива: "; cin >> fuel; cout << endl;
			car.fill(fuel);
			break;
		case 'S':
		case 's':
			if (car.driver_inside())
				car.start();
		case Enter:	
			if (car.driver_inside())car.get_out();
			else car.get_in(); break;
		case Escape: cout << "Get out" << endl; break;
		}
		if(car.driver_inside())car.display();
		else system("CLS");
	} while (key != 27);
}