export module TestSingleton;

import BrilliantSingleton;

export struct TestSingleton : public Brilliant::Singleton<TestSingleton>
{

};

export struct TestNotSingleton
{

};