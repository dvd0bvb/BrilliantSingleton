module;
#include <cassert>

export module BrilliantSingleton;

export namespace Brilliant
{
	//Singleton base class
	//Single-ness enforced at runtime via asserts
	//Doesn't require a GetInstance() type method but requires inheritance
	template<class T>
	class Singleton
	{
	public:
		Singleton()
		{
			assert(pInstance == nullptr);
			pInstance = reinterpret_cast<T*>(this);
		}

		virtual ~Singleton()
		{
			assert(pInstance != nullptr);
			pInstance = nullptr;
		}

		Singleton(const Singleton&) = delete;
		Singleton& operator= (const Singleton&) = delete;

	private:
		static T* pInstance;
	};

	template<class T> T* Singleton<T>::pInstance = nullptr;

	//Singleton class where instance is lazy evaluated via GetInstance() method
	//Requires T to be default constructable
	template<class T>
	class LazySingleton
	{
	public:
		static T& GetInstance()
		{
			static T tInstance;
			return tInstance;
		}

		LazySingleton(const LazySingleton&) = delete;
		LazySingleton& operator= (const LazySingleton&) = delete;

	private:
		LazySingleton() = default;
	};
}