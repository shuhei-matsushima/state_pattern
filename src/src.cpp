#include <iostream>
#include <thread>

class SceneState
{
public:

	virtual void Print() = 0;
};

class CreditScene :public SceneState
{
public:

	void Print()
	{
		std::cout << "credit\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ
	}
};

class TitleScene :public SceneState
{
public:

	void Print()
	{
		std::cout << "title\n";

		std::this_thread::sleep_for(std::chrono::seconds(3));// 3 秒待つ
	}
};

class OpeningScene :public SceneState
{
public:

	void Print()
	{
		std::cout << "opening\n";

		std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ
	}
};

class DemoScene :public SceneState
{
public:
	void Print()
	{
		std::cout << "demo\n";

		std::this_thread::sleep_for(std::chrono::seconds(5));// 5 秒待つ
	}
};


enum SceneType
{
	Credit, Title, Opening, Demo, Max
};

class Scene
{
private:
	SceneType sceneType;
	SceneState* sceneState;
	SceneState* sceneMachines[Max];
	int count = 0;

	CreditScene credit;
	TitleScene title;
	OpeningScene opening;
	DemoScene demo;

public:
	Scene()
	{
		sceneMachines[Credit] = &credit;
		sceneMachines[Title] = &title;
		sceneMachines[Opening] = &opening;
		sceneMachines[Demo] = &demo;
		SetScene(Credit);
	}

	void SetScene(SceneType type)
	{
		sceneState = sceneMachines[type];
		sceneType = type;
	}

	void Print()
	{
		sceneState->Print();

		count = sceneType;
		count++;
		if (count == Max)
		{
			count = 0;
		}
		SceneType next = (SceneType)count;
		if (sceneType != next)
		{
			SetScene(next);
		}
	}
};

int main()
{
	Scene scene;

	while (true)
	{
		scene.Print();
	}
}