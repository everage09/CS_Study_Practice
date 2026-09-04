class Singleton {
private:
	Singleton() = default;
	Singleton(const Singleton& ref) = delete;
	Singleton(Singleton&& ref) = delete;
	Singleton& operator=(const Singleton& ref) = delete;
	~Singleton() = default;
public:
	static Singleton& getInstance()
	{
		static Singleton s;
		return s;
	}
	int value = 72;
};