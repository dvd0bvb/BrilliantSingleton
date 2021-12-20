#include <iostream>
import TestSingleton;
import BrilliantSingleton;

int main()
{
	try
	{
		TestSingleton s1;
		//TestSingleton s2; //the assert fails

		auto s3 = Brilliant::LazySingleton<TestNotSingleton>::GetInstance();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
}